#ifndef LEARNING_PRACTIC_H
#define LEARNING_PRACTIC_H
#include <QTableWidget>

typedef int MatrixElem;
typedef MatrixElem* MatrixRow;
typedef MatrixRow* Matrix;

void inpuMatrix(Matrix a, QTableWidget* table, int str, int sto);
void outpuMatrix(Matrix a, int str, int sto);
void sort_obmenF(Matrix a, int str, int sto);
void zeroOutNonSortingRegion(Matrix a, int str, int sto);

#endif
