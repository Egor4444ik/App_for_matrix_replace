#include <iostream>
#include <cmath>
#include "learning_practic.h"
#include <QTableWidget>

using namespace std;

// Собственные типы данных
typedef int telem;  // Определение типа значений элементов массива
typedef telem* tstr; // Определение типа "указатель на telem" (строка матрицы)
typedef tstr* tmatr; // Определение типа "указатель на указатель на telem" (матрица)

// Объявление функций
void inputmatr(tmatr a, int str, int sto);
void outputmatr(tmatr a, int str, int sto);
void sort_obmenF(tmatr a, int str, int sto);
void zeroOutNonSortingRegion(tmatr a, int str, int sto);


// Ввод элементов матрицы
void inputmatr(tmatr a, QTableWidget* table, int str, int sto)
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
void zeroOutNonSortingRegion(tmatr a, int str, int sto) {
    int center = str / 2;

    for (int i = 0; i < str; i++) {
        for (int j = 0; j < sto; j++) {
            // Determine if the element should be zeroed.
            if ( i-center<=-abs(center-j) )
                *(*(a + i) + j) = 0;
        }
    }
}

// Сортировка элементов массива по убыванию методом обмена с флагом перестановки
void sort_obmenF(tmatr a, int str, int sto) {
    int i, j, k, flag;
    telem z;
    for (j = 0; j < sto; j++) {
        k = str; // Начальное количество не отсортированных элементов
        do {
            flag = 0;
            for (i = 0; i < k - 1; i++) {
                if (*(*(a + i) + j) < *(*(a + i + 1) + j)) {
                    z = *(*(a + i) + j);
                    *(*(a + i) + j) = *(*(a + i + 1) + j);
                    *(*(a + i + 1) + j) = z;
                    flag = 1;
                }
            }
            k--;
        } while (flag);
    }
}


// Вывод матрицы
void outputmatr(tmatr a, int str, int sto)
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
