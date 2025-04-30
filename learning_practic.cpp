#include <iostream>
#include <cmath>
#include "learning_practic.h"
#include <QTableWidget>

using namespace std;

// Собственные типы данных
typedef int MatrixElem;  // Определение типа значений элементов массива
typedef MatrixElem* MatrixRow; // Определение типа "указатель на MatrixElem" (строка матрицы)
typedef MatrixRow* Matrix; // Определение типа "указатель на указатель на MatrixElem" (матрица)

// Объявление функций
void inpuMatrix(Matrix a, int str, int sto);
void outpuMatrix(Matrix a, int str, int sto);
void sort_obmenF(Matrix a, int str, int sto);
void zeroOutNonSortingRegion(Matrix a, int str, int sto);


// Ввод элементов матрицы
void inpuMatrix(Matrix a, QTableWidget* table, int str, int sto)
{
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < sto; j++) {
            QTableWidgetItem* item = table->item(i, j);
            if (item && !item->text().isEmpty()) {
                a[i][j] = item->text().toInt();
            } else {
                a[i][j] = 0;
            }
        }
    }
}

// Обнуление элементов внутри треугольника
void zeroOutNonSortingRegion(Matrix a, int str, int sto) {
    int center = str / 2;
    int y;
    int f;

    for (int i = 0; i < str; i++) {
        for (int j = 0; j < sto; j++) {
            y = i - center;
            f = center-j;
            if ( (f > 0) and (y <= - f - 1) or (f <= 0) and (y <= f - 2) )
                *(*(a + i) + j) = 0;
        }
    }
}

// Сортировка элементов массива по убыванию методом обмена с флагом перестановки
void sort_obmenF(Matrix a, int str, int sto) {
    int i, j, k, flag;
    MatrixElem z;
    int center = str / 2;
    int y;
    int f;

    for (j = 0; j < sto; j++) {
        k = str; // Начальное количество не отсортированных элементов
        do {
            flag = 0;
            for (i = 0; i < k - 1; i++) {
                y = i - center;
                f = center-j;
                if ( (f > 0) and (y > - f - 1) or (f <= 0) and (y > f - 2) )
                {
                    if (*(*(a + i) + j) < *(*(a + i + 1) + j)) {
                        z = *(*(a + i) + j);
                        *(*(a + i) + j) = *(*(a + i + 1) + j);
                        *(*(a + i + 1) + j) = z;
                        flag = 1;
                    }
                }
            }
            k--;
        } while (flag);
    }
}


// Вывод матрицы
void outpuMatrix(Matrix a, int str, int sto)
{
    int i, j;
    cout.width(4);
    for (i = 0; i < str; i++) {
        for (j = 0; j < sto; j++) {
            cout.width(4); // ширина поля для выводимого параметра
            cout << a[i][j];
        }
        cout <<endl;
    }
}
