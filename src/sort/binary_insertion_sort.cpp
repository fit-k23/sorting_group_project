#include "../utils/utils.h"

int binarySearch(Result &r, int *a, int key, int low, int high) {
    while (++r.cmps && low <= high) {
        int mid = (low + high) / 2;
        if (++r.cmps && a[mid] == key) return mid + 1; // lowest element greater than key
        if (++r.cmps && a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

Result binaryInsertionSort(int *a, int n) {
    Result r;
    auto start = chrono::high_resolution_clock::now();

    int key, pos;    
    for (int i = 1; ++r.cmps && i < n; ++i) {
        key = a[i];
        pos = binarySearch(r, a, key, 0, i - 1);
        for (int j = i; ++r.cmps && j > pos; --j) {
            a[j] = a[j - 1];
        }
        a[pos] = key;
    }
    
    chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
    r.time = duration.count();
    return r;
} 