#include "../utils/utils.h"

Result shakerSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();

	bool swapped;
	do {
		swapped = false;
		for (int i = 0; ++r.cmps && i < n - 1; i++) {
			if (++r.cmps && a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (++r.cmps && !swapped) break;
		swapped = false;
		for (int i = n - 1; ++r.cmps && i > 0; i--) {
			if (++r.cmps && a[i] < a[i - 1]) {
				Swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
	} while (++r.cmps && swapped);

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}
