#include "../utils/utils.h"

/// DOCs: https://www.geeksforgeeks.org/shellsort/
Result shellSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	// start with big gap then divide it by 2 each run
	for (int gap = n / 2; ++r.cmps && gap > 0; gap /= 2) {

		// sort sub-list using insertion sort
		for (int i = gap; ++r.cmps && i < n; ++i) {
			int temp = a[i];

			int j;
			// shift earlier gap-sorted elements up until the correct location for a[i] is found
			for (j = i; (++r.cmps && j >= gap) && (++r.cmps && a[j - gap] > temp); j -= gap)
				a[j] = a[j - gap];

			// put temp (the original a[i]) in its correct location
			a[j] = temp;
		}
	}

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	r.time = duration.count();
	return r;
}
