#include "mainwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Настройка интерфейса
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Поле ввода n
    QLabel *nLabel = new QLabel("Введите n (размер матрицы 2n+1):");
    nSpinBox = new QSpinBox();
    nSpinBox->setMinimum(0); // Минимальное n
    nSpinBox->setMaximum(20);

    // Кнопка обработки
    processButton = new QPushButton("Обработать");

    // Таблицы
    inputTable = new QTableWidget();
    outputTable = new QTableWidget();

    // Компоновка
    layout->addWidget(nLabel);
    layout->addWidget(nSpinBox);
    layout->addWidget(processButton);
    layout->addWidget(new QLabel("Исходная матрица:"));
    layout->addWidget(inputTable);
    layout->addWidget(new QLabel("Результат:"));
    layout->addWidget(outputTable);

    setCentralWidget(centralWidget);
    connect(processButton, &QPushButton::clicked, this, &MainWindow::processMatrix);

    // Автоматическое обновление при изменении данных
    connect(inputTable, &QTableWidget::cellChanged, this, &MainWindow::processMatrix);

    // Обновление размера таблицы при изменении n
    connect(nSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), [this](int value) {
        int size = 2 * value + 1;
        inputTable->setRowCount(size);
        inputTable->setColumnCount(size);
        outputTable->setRowCount(size);
        outputTable->setColumnCount(size);
    });

    inputTable->setItemDelegate(new NumericDelegate());
    outputTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::processMatrix() {
    int n = nSpinBox->value();
    int size = 2 * n + 1;

    // Выделение памяти
    tmatr matrix = new tstr[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new telem[size];
    }

    // Заполнение и обработка
    inputmatr(matrix, inputTable, size, size);
    displayMatrix(matrix, inputTable, size);

    sort_obmenF(matrix, size, size);
    zeroOutNonSortingRegion(matrix, size, size);

    displayMatrix(matrix, outputTable, size);

    // Освобождение памяти
    for (int i = 0; i < size; i++) delete[] matrix[i];
    delete[] matrix;
}

void MainWindow::displayMatrix(tmatr matrix, QTableWidget *table, int size) {
    table->setRowCount(size);
    table->setColumnCount(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            QTableWidgetItem* item = table->item(i, j);
            if (!item) {
                item = new QTableWidgetItem();
                table->setItem(i, j, item);
            }
            item->setText(QString::number(matrix[i][j]));
        }
    }
}

void MainWindow::clearTable(QTableWidget *table) {
    table->clear();
    table->setRowCount(0);
    table->setColumnCount(0);
}
