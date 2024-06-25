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

/// Ref: https://en.wikipedia.org/wiki/Cocktail_shaker_sort
Result shakerSort2(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	int left = 0;
	int right = n - 1;
	while (++r.cmps && left < right) {
		// reset swapped flag
		bool swapped = false;
		// loop from left to right then compare like normal bubble sort
		for (int i = left; ++r.cmps && i < right; i++) {
			if (++r.cmps && a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		// if no swap was made, the array is sorted!
		if (++r.cmps && !swapped) {
			break;
		}
		--right; // minus the right edge by 1 as right is at its correct spot
		// same as before but in reverse
		for (int i = right - 1; ++r.cmps && i >= left; --i) {
			if (++r.cmps && a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
			}
		}
		++left; // add the left edge by 1 as left is at its correct spot
	}

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}

Result shakerSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	int left = 0;
	int right = n - 1;
	int lastSwap = 0;
	while (++r.cmps && left < right) {
		// reset swapped flag
//		bool swapped = false;
		// loop from left to right then compare like normal bubble sort
		for (int i = left; ++r.cmps && i < right; i++) {
			if (++r.cmps && a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
//				swapped = true;
				lastSwap = i;
			}
		}
		// if no swap was made, the array is sorted!
//		if (++r.cmps && !swapped) {
//			break;
//		}
		right = lastSwap;
//		--right; // minus the right edge by 1 as right is at its correct spot
		// same as before but in reverse
		for (int i = right; ++r.cmps && i > left; --i) {
			if (++r.cmps && a[i] < a[i - 1]) {
				Swap(a[i], a[i - 1]);
				lastSwap = i;
			}
		}
		left = lastSwap;
//		++left; // add the left edge by 1 as left is at its correct spot
	}

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}

Result shakerSort3(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	int left = 0;
	int right = n - 1;
	int lastSwap = 0;
	while (++r.cmps && left < right) {
		// reset swapped flag
		bool swapped = false;
		// loop from left to right then compare like normal bubble sort
		for (int i = left; ++r.cmps && i < right; i++) {
			if (++r.cmps && a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				swapped = true;
				lastSwap = i;
			}
		}
		// if no swap was made, the array is sorted!
		if (++r.cmps && !swapped) {
			break;
		}
		right = lastSwap;
//		--right; // minus the right edge by 1 as right is at its correct spot
		// same as before but in reverse
		for (int i = right; ++r.cmps && i > left; --i) {
			if (++r.cmps && a[i] < a[i - 1]) {
				Swap(a[i], a[i - 1]);
				lastSwap = i;
			}
		}
		left = lastSwap;
//		++left; // add the left edge by 1 as left is at its correct spot
	}

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}


Result shakerSort4(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	int left = 0;
	int right = n - 1;
	int lastSwap = 0;
	int i;
	while (++r.cmps && left < right) {
		// reset swapped flag
		bool swapped = false;
		// loop from left to right then compare like normal bubble sort
		for (i = left; ++r.cmps && i < right; i++) {
			if (++r.cmps && a[i] > a[i + 1]) {
				Swap(a[i], a[i + 1]);
				swapped = true;
			}
		}
		// if no swap was made, the array is sorted!
		if (++r.cmps && !swapped) {
			break;
		}
		right = i;
//		--right; // minus the right edge by 1 as right is at its correct spot
		// same as before but in reverse
		for (i = right; ++r.cmps && i > left; --i) {
			if (++r.cmps && a[i] < a[i - 1]) {
				Swap(a[i], a[i - 1]);
				lastSwap = i;
			}
		}
		left = lastSwap;
//		++left; // add the left edge by 1 as left is at its correct spot
	}

	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	//(std::chrono::high_resolution_clock::now() - start).count();
	r.time = duration.count();
	return r;
}
