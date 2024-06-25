#include "../utils/utils.h"

// radix sort
void sortByDigit(int *a, int n, int exp10, long long &cmps) {
    int *tmp = new int[n];
    int counter[10] = {0};

    // x / 10^i equates to getting rid of (i - 1) last digits of x
    // x % 10 equates to getting the last digit of x

    // count occurences of current last digits
    for (int i = 0; ++cmps && i < n; ++i) {
        int digit = (a[i] / exp10) % 10;
        ++counter[digit];
    }

    // calculate prefix sum to get the final exact position of each digit
    for (int i = 1; ++cmps && i < 10; ++i) counter[i] += counter[i - 1];

    // array tmp is sorted according to sorted digits (tmp = new a)
    // traverse backwards since position of each digit is being the final one
    for (int i = n - 1; ++cmps && i >= 0; --i) {
        int digit = (a[i] / exp10) % 10;
        tmp[--counter[digit]] = a[i];
    }

    // now update array a
    for (int i = 0; ++cmps && i < n; ++i) a[i] = tmp[i];

    delete[] tmp;
}

Result radixSort(int *a, int n) {
    Result r;
    auto start = chrono::high_resolution_clock::now();

    // maximum number in array will have maximum number of digits in array
    int mx = a[0];
    for (int i = 1; ++r.cmps && i < n; ++i) 
        if (++r.cmps && mx < a[i]) 
            mx = a[i];

    // traverse through each digit
    for (int exp10 = 1; ++r.cmps && mx / exp10 > 0; exp10 *= 10) {
        sortByDigit(a, n, exp10, r.cmps);
    }
    chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
    r.time = duration.count();
    return r;
}