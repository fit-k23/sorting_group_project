#include "../utils/utils.h"

/// DOCs: https://www.geeksforgeeks.org/insertion-sort-algorithm/
Result insertionSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	int key, j;
	for (int i = 1; ++r.cmps && i < n; ++i) {
		key = a[i];
		j = i - 1;

		// move elements from 0 to i - 1 that are greater than key to one pos ahead of their pos
		while ((++r.cmps && j >= 0) && (++r.cmps && a[j] > key)) {
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = key;
	}
	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	r.time = duration.count();
	return r;
}
