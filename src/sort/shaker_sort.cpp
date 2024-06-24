#include "../utils/utils.h"

/// Unoptimized!
//Result shakerSort(int *a, int n) {
//	Result r;
//	auto start = chrono::high_resolution_clock::now();
//	bool swapped;
//	do {
//		swapped = false;
//		for (int i = 0; ++r.cmps && i < n - 1; i++) {
//			if (++r.cmps && a[i] > a[i + 1]) {
//				Swap(a[i], a[i + 1]);
//				swapped = true;
//			}
//		}
//		if (++r.cmps && !swapped) break;
//		swapped = false;
//		for (int i = n - 1; ++r.cmps && i > 0; --i) {
//			if (++r.cmps && a[i] < a[i - 1]) {
//				Swap(a[i], a[i - 1]);
//				swapped = true;
//			}
//		}
//	} while (++r.cmps && swapped);
//
//	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
//	//(std::chrono::high_resolution_clock::now() - start).count();
//	r.time = duration.count();
//	return r;
//}

Result shakerSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	int left = 0;
	int right = n - 1;

	bool swapped = true;
	while (left < right) {
		swapped = false;
		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
		--right;
		for (int i = right - 1; i >= left; --i) {
			if (a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
			}
		}
		++left;
	}

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}
