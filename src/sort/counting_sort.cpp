#include "../utils/utils.h"

Result countingSort(int* a, int n) {
    Result r;
    auto start = chrono::high_resolution_clock::now();
    int max = a[0];

    //find the maxium element from the given array
    for (int i = 0; ++r.cmps && i < n; i++)
        if (++r.cmps && a[i] > max) max = a[i];
    //create an array that counts the number of occurences of each element
    vector <int> count(max+1);
    for (int i = 0; ++r.cmps && i < n; i++) {
        count[a[i]]++;
    }
    //update the given array into ascending order
    for (int i = 0, j = 0; ++r.cmps && (i < n && j <= max); j++) {
        while (++r.cmps && count[j] > 0) {
            count[j]--;
            a[i++] = j;
        }
    }
    chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
    r.time = duration.count();
    return r;
}

