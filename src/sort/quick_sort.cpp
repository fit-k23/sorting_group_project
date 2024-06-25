#include "../utils/utils.h"

int medianOfThree(Result &r, int *a, int first, int last) {
    int mid = (first + last) / 2;
    r.cmps += 3;
    if ((a[first] > a[mid]) ^ (a[first] > a[last])) return first;
    r.cmps += 3;
    if ((a[mid] > a[first]) ^ (a[mid] > a[last])) return mid;
    return last;
}

int partition(Result &r, int *a, int first, int last) {
    int pivotIndex = medianOfThree(r, a, first, last);
    int pivotValue = a[pivotIndex];
    Swap(a[pivotIndex], a[last]);
    pivotIndex = first;
    for (int i = first; ++r.cmps && i < last; ++i) {
        if (++r.cmps && a[i] <= pivotValue) {
            Swap(a[i], a[pivotIndex++]);
        }
    }
    Swap(a[pivotIndex], a[last]);
    return pivotIndex;
}

void quickSortRecur(Result &r, int *a, int first, int last) {
    if (++r.cmps && first < last) {
        int pivotIndex = partition(r, a, first, last);
        quickSortRecur(r, a, first, pivotIndex - 1);
        quickSortRecur(r, a, pivotIndex + 1, last);
    }
}

Result quickSort(int *a, int n) {
    Result r;
    auto start = chrono::high_resolution_clock::now();
    
    quickSortRecur(r, a, 0, n - 1);
    
    chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
    r.time = duration.count();
    return r;
} 