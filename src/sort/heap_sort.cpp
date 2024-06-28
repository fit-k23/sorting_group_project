#include "../utils/utils.h"

// heap sort
void heapRebuild(int *a, int pos, int n, long long &cmps) {
    bool isHeap = false;
    while ((++cmps && 2 * pos + 1 < n) && (++cmps && !isHeap)) {
        int j = 2 * pos + 1;
        if ((++cmps && j + 1 < n) && (++cmps && a[j + 1] > a[j])) ++j;

        if (++cmps && a[pos] >= a[j]) isHeap = true;
        else {
            swap(a[pos], a[j]);
            pos = j;
        }
    }
}

Result heapSort(int *a, int n) {
    Result r;
    auto start = chrono::high_resolution_clock::now();

    // construct a heap
    for (int i = n / 2 - 1; ++r.cmps && i >= 0; --i) heapRebuild(a, i, n, r.cmps);

    for (int i = n - 1; ++r.cmps && i > 0; --i) {
        swap(a[0], a[i]);
        heapRebuild(a, 0, i, r.cmps);
    }
    chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
    r.time = duration.count();
    return r;
} 
