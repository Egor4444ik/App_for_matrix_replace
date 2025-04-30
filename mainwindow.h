#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QSpinBox>
#include <QPushButton>
#include "learning_practic.h"
#include <QItemDelegate>
#include <QWidget>
#include <QModelIndex>
#include <QLineEdit>

class NumericDelegate : public QItemDelegate {
public:
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
                          const QModelIndex& index) const override {
        QLineEdit* editor = new QLineEdit(parent);
        QIntValidator* validator = new QIntValidator(editor);
        editor->setValidator(validator);
        return editor;
    }
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void processMatrix();

private:
    QSpinBox *nSpinBox;
    QTableWidget *inputTable;
    QTableWidget *outputTable;
    QPushButton *processButton;

    void displayMatrix(Matrix matrix, QTableWidget *table, int size);
    void clearTable(QTableWidget *table);
};

#endif
