//
// Created by icy on 24-6-27.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "../ui/ui_turing.h"
#include "Library.h"
extern QVector<int> intNumbers;
class QuickSort {
public:
    QuickSort();

    void Preprocess(QString &input);

    void quickSort(QVector<int> &arr, int low, int high);

    int partition(QVector<int> &arr, int low, int high);

private:

};

#endif //QUICKSORT_H
