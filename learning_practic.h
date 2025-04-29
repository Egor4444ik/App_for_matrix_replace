#ifndef LEARNING_PRACTIC_H
#define LEARNING_PRACTIC_H
#include <QTableWidget>

typedef int telem;
typedef telem* tstr;
typedef tstr* tmatr;

void inputmatr(tmatr a, QTableWidget* table, int str, int sto);
void outputmatr(tmatr a, int str, int sto);
void sort_obmenF(tmatr a, int str, int sto);
void zeroOutNonSortingRegion(tmatr a, int str, int sto);

#endif
