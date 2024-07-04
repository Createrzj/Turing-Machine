//
// Created by icy on 24-6-27.
//

#include "../include/QuickSort.h"

using namespace std;

QVector<int> intNumbers;

QuickSort::QuickSort() {
}

void QuickSort::Preprocess(QString &input) {
    // 预处理，将QString转换为int进行快速排序
    QStringList numbers = input.split("，", QString::SkipEmptyParts);
    intNumbers.clear();
    foreach(const QString &number, numbers) {
        int num = number.toInt();
        intNumbers.append(num);
    }
}

void QuickSort::quickSort(QVector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int QuickSort::partition(QVector<int> &arr, int low, int high) {
    int pivot = arr[high];  // 选择基准为最后一个元素
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort::quickSortf(QVector<float> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionf(arr, low, high);
        quickSortf(arr, low, pivotIndex - 1);
        quickSortf(arr, pivotIndex + 1, high);
    }
}

int QuickSort::partitionf(QVector<float> &arr, int low, int high) {
    float pivot = arr[high];  // 选择基准为最后一个元素
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
