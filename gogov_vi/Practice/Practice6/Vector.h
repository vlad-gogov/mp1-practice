#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct {
    int dim;
    float* val;
} Vector;

// Пародия на конструктор по умолчанию
void New(Vector*);
// Создание вектора
int Create(int , Vector*);
// Ввод вектора
void Input(Vector);
// Вывод вектора
void Output(Vector);
// Удаление вектора
int Delete(Vector*);
// Суммирование векторов
int Sum(Vector, Vector, Vector*);
// Разность векторов
int Sub(Vector, Vector, Vector*);
// Скалярное произведение векторов
int Scal(Vector, Vector, double*);
// Угол между векторами
int Angle(Vector, Vector, double*);
// Длина вектора
int Len(Vector, double*);

#endif