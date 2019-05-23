#include "Vector.h"
#include <stdio.h>
#include <locale.h>

void main()
{
    Vector a, b, c;
    int op, n, code;
    double rez;
    setlocale(LC_ALL, "Russian");
    New(&a);
    New(&b);
    New(&c);

    printf("Введите размерность первого вектора: ");
    scanf("%d", &n);
    code = Create(n, &a);
    if(code)
        printf("Создан вектор длины 0.\n");
    else
    {
        printf("Введите координаты вектора через пробелы: ");
        Input(&a);
        Output(&a);
    }


    printf("Введите размерность второго вектора: ");
    scanf("%d", &n);
    code = Create(n, &b);
    if (code)
        printf("Создан вектор длины 0.\n");
    else
    {
        printf("Введите координаты вектора через пробелы: ");
        Input(&b);
        Output(&b);
    }


    printf("1. Сложить два вектора.\n2. Вычитание векторов.\n");
    printf("3. Скалярное произведение векторов.\n4. Угол между векторами.\n");
    printf("5. Вывести длину первого вектора.\n6. Вывести длину второго вектора.\n");
    printf("Выберите операцию: ");
    scanf("%d", &op);
    printf("Результат: ");
    switch (op)
    {
    case 1:
        code = Sum(a, b, &c);
        if (code)
            printf("Не возможно сложить два вектора разной длины.");
        else
            Output(&c);
        break;
    case 2:
        code = Sub(a, b, &c);
        if (code)
            printf("Не возможно вычесть два вектора разной длины.");
        else
            Output(&c);
        break;
    case 3:
        code = Scal(a, b, &rez);
        if (code)
            printf("Не возможно получить скалярное произведение двух векторов разной длины.");
        else
            printf("%.lf", rez);
        break;
    case 4:
        code = Angle(a, b, &rez);
        if (code == 1)
            printf("Не возможно посчитать угол между двумя векторами разной длины.");
        if (code == 2)
            printf("Не существует угла между вектором и точкой.");
        else
            printf("%.5lf град.", rez);
        break;
    case 5:
        code = Len(a, &rez);
        if (code)
            printf("Не возможно посчитать длину нулевого вектора.");
        else
            printf("%.lf", rez);
        break;
    case 6:
        code = Len(b, &rez);
        if (code)
            printf("Не возможно посчитать длину нулевого вектора.");
        else
            printf("%lf", rez);
        break;
    }
}