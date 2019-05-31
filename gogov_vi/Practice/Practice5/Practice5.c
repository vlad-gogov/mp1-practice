﻿#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#define BUFFER 2048 

void swapint(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
void swaplong(ULONGLONG *n1, ULONGLONG *n2)
{
    ULONGLONG tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}


int ListDirectoryContents(const wchar_t *sDir, wchar_t ***filenames, ULONGLONG **filesize)
{
    int l = 0;
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    sPath = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
        return -1;

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            l++;
        }
    } while (FindNextFile(hFind, &fdFile));

    hFind = FindFirstFile(sPath, &fdFile);
    *filenames = (wchar_t**)malloc(l * sizeof(wchar_t*));
    *filesize = (ULONGLONG*)malloc(l * sizeof(ULONGLONG));
    l = 0;
    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            (*filenames)[l] = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
            (*filesize)[l] = fileSize;
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf((*filenames)[l], L"%s", sPath);
            l++;
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    free(sPath);
    return l;
}

void choose(ULONGLONG* size ,int n, int* newId)
{
    int i, j, minidx;
    ULONGLONG min;
    for (i = 0; i < n; i++)
    {
        min = size[i];
        minidx = i;
        for (j = i + 1; j < n; j++)
        {
            if (size[j] < min)
            {
                min = size[j];
                minidx = j;
            }
        }
        size[minidx] = size[i];
        swapint(newId + minidx, newId + i);
        size[i] = min;
    }
}

void insert(ULONGLONG* size, int n, int* newId)
{
    int i, j;
    ULONGLONG tmp;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        tmp = size[i];
        while ((j >= 0) && (size[j] > tmp))
        {
            size[j + 1] = size[j];
            newId[j + 1] = newId[j];
            newId[j] = i;
            size[j--] = tmp;
        }
    }
}

void bubble(ULONGLONG* size, int n, int* newId)
{
    int i, j;
    ULONGLONG tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (size[j - 1] > size[j])
            {
                tmp = size[j];
                size[j] = size[j - 1];
                size[j - 1] = tmp;
                swapint(newId + j, newId + j - 1);
            }
        }
    }
}

int countingsort(ULONGLONG* size, int n, int *newId)
{
    ULONGLONG *arr, k, max = size[n - 1], min = size[0], *a;
    int i, b = 0, j;
    for (i = 0; i < n; i++)
    {
        if (size[i] < min)
            min = size[i];
    }
    for (i = 0; i < n; i++)
    {
        if (size[i] > max)
            max = size[i];
    }
    k = max - min + 1;
    if (k * (ULONGLONG)sizeof(int) > (ULONGLONG)UINT_MAX)
        return 1;
    arr = (ULONGLONG*)malloc(k * sizeof(ULONGLONG));
    for (i = 0; i < k; i++) 
        arr[i] = 0;
    for (i = 0; i < n; i++)
    {
        arr[size[i] - min]++;
    }
    a = (ULONGLONG*)malloc(n * sizeof(ULONGLONG)); // Нужен для записи отсортированного массива
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < arr[i]; j++)
            a[b++] = i + min;
    }
    for (j = 0; j < n; j++)
        arr[j] = a[j];
    free(a);
    b = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if ((arr[i] == size[j]))
            {
                newId[b] = j;
                size[j] = -1;
                b++;
                break;
            }
    }
    free(arr);
    return 0;
}

void quicksort(ULONGLONG* size, int n1, int n2, int* newid)
{
    ULONGLONG p = size[(n1 + n2) / 2];;
    int i = n1, j = n2;
    do {
        while (size[i] < p) i++;
        while (size[j] > p) j--;

        if (i <= j) {
            if (size[i] > size[j])
            {
                swaplong(size + i, size + j);
                swapint(newid + i, newid + j);
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < n2)
        quicksort(size, i, n2, newid);
    if (n1 < j)
        quicksort(size, n1, j, newid);
}

void merge(ULONGLONG* copy_size, int* id_file, int l, int m, int r)
{
    int i, j, k = 0;
    ULONGLONG *arr;
    int n = r - l + 1;
    int *tmpId;
    tmpId = (int*)malloc(n * sizeof(int));
    arr = (ULONGLONG*)malloc(n * sizeof(ULONGLONG));
    for (i = 0; i < n; i++)
        tmpId[i] = id_file[i + l];
    i = l;
    j = m + 1;
    while ((i <= m) && (j <= r))
    {
        if (copy_size[i] <= copy_size[j])
        {
            arr[k] = copy_size[i];
            tmpId[k] = id_file[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = copy_size[j];
            tmpId[k] = id_file[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        arr[k] = copy_size[i];
        tmpId[k] = id_file[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        arr[k] = copy_size[j];
        tmpId[k] = id_file[j];
        k++;
        j++;
    }
    for (k = l; k <= r; k++)
    {
        copy_size[k] = arr[k - l];
        id_file[k] = tmpId[k - l];
    }
    free(arr);
    free(tmpId);
}

void mergesort(ULONGLONG* copy_size, int* id_file, int l, int r)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    mergesort(copy_size, id_file, l, m);
    mergesort(copy_size, id_file, m + 1, r);
    merge(copy_size, id_file, l, m, r);
}

void menu()
{
    printf("\n");
    printf("Вид сортировки:\n");
    printf("1.Сортировка выбором\n");
    printf("2.Сортировка вставками\n");
    printf("3.Пузырьковая сортировка\n");
    printf("4.Сортировка подсчета\n");
    printf("5.Быстрая сортировка\n");
    printf("6.Сортировка слиянием\n");
    printf("Выберите способ сортировки: ");
}

void print_newId(ULONGLONG *filesize, wchar_t **fileNames, int count_files, int* newId)
{
    int i;
    printf("\nОтсортированный список файлов:\n");
    for (i = 0; i < count_files; i++)
        wprintf(L"Файл: %s Размер: %lld байт\n", fileNames[newId[i]], filesize[newId[i]]);
    printf("\n");
}

void entpath(wchar_t** path)
{
    char* b;
    *path = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
    b = (char*)malloc(BUFFER * sizeof(char));
    printf("Укажите путь к файлам (вместо \\ пишите /): ");
    fgets(b, BUFFER, stdin);
    b[strlen(b) - 1] = '\0';
    swprintf(*path, BUFFER, L"%hs", b);
    free(b);
}

void main()
{
    wchar_t *path;
    wchar_t **fileNames;
    ULONGLONG* size, *filesize;
    int *fileId, err;
    int men, i, count_files;
    clock_t begin, end;
    double time_spent;
    setlocale(LC_ALL, "Russian");
    printf("Файловый менеджер.\nДля закрытия программы нажмите на крестик.\n");
    while (1) 
	{
        entpath(&path);
        count_files = ListDirectoryContents(path, &fileNames, &filesize);
        if (count_files == -1)
        {
            printf("Неверно введен путь. Попробуйте снова\n");
            continue;
        }
        if (count_files == 0)
        {
            printf("В папке отсутствуют файлы. Попробуйте снова\n");
            continue;
        }
        err = 0;
        size = (ULONGLONG*)malloc(count_files * sizeof(ULONGLONG));
        fileId = (int*)malloc(count_files * sizeof(int));
        for (i = 0; i < count_files; i++)
        {
            fileId[i] = i;
            size[i] = filesize[i];
        }
        printf("Файлов найдено: %d\n", count_files);
        for (i = 0; i < count_files; i++)
            wprintf(L"Файл: %s Размер: %lld байт\n", fileNames[i], filesize[i]);
        menu();
        scanf("%d%*с", &men);
        switch (men) 
        {
        case 1:
            begin = clock();
            choose(size, count_files, fileId);
            end = clock();
            break;
        case 2:
            begin = clock();
            insert(size, count_files, fileId);
            end = clock();
            break;
        case 3:
            begin = clock();
            bubble(size, count_files, fileId);
            end = clock();
            break;
        case 4:
            begin = clock();
            err = countingsort(size, count_files, fileId);
            end = clock();
            break;
        case 5:
            begin = clock();
            quicksort(size, fileId[0], fileId[count_files - 1], fileId);
            end = clock();
            break;
        case 6:
            begin = clock();
            mergesort(size, fileId, fileId[0], fileId[count_files - 1]);
            end = clock();
            break;
        default:
            menu();
            scanf("%d", &men);
        }
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        if (err != 1)
        {
            print_newId(filesize, fileNames, count_files, fileId);
            printf("Время сортировки данных: %.3lf секунд\n", time_spent);
            printf("-----------------------------------------------------------\n");
        }
        else
        {
            printf("Диапазон размеров файлов большой ");
            printf("для сортировки подсчетом.\n");
            printf("Попробуйте снова, не используя сортироку подсчетом.\n");
        }
        getchar();
        free(fileId);
        free(size);
        free(filesize);
        for (i = 0; i < count_files; i++)
            free(fileNames[i]);
        free(fileNames);
        count_files = 0;
    }
}