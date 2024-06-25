#include "../utils/utils.h"

Result bubbleSort(int *a, int n) {
    Result r;
    auto start = chrono::high_resolution_clock::now();
    
    bool swapped;
    for (int i = 0; ++r.cmps && i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; ++r.cmps && j < n - i - 1; ++j) {
            if (++r.cmps && a[j] > a[j + 1]) {
                Swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        // If there were no swaps between any two elements by inner loop then break
        if (++r.cmps && !swapped) break;
    }
    
    chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
    r.time = duration.count();
    return r;
} 