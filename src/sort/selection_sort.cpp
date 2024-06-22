#include "../utils/utils.h"

Result selectionSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; ++r.cmps && i < n - 1; i++) {
		int cur = i;
		for (int j = i + 1; ++r.cmps && j < n; j++) {
			if (++r.cmps && a[j] < a[cur]) cur = j;
		}

		if (++r.cmps && cur != i) Swap(a[cur], a[i]);
	}
	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}
