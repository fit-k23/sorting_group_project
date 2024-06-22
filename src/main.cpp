#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#include "sort/insertion_sort.cpp"
#include "sort/merge_sort.cpp"
#include "sort/selection_sort.cpp"

#include "utils/utils.h"

using namespace std;

enum SortingAlgo{
	UNKNOWN_SORT = -1,
	HEAP_SORT = 0,
	INSERTION_SORT = 1,
	MERGE_SORT = 2,
	SELECTION_SORT = 3
};

static vector<string> sortingAlgo = {
	"heap-sort",
	"insertion-sort",
	"merge-sort",
	"selection-sort",
	"quick-sort",
};

static vector<string> algoName = {
	"Heap Sort",
	"Merge Sort",
	"Selection Sort",
	"Quick Sort",
};

SortingAlgo getSortingAlgoFromText(char* s) {
	for (int i = 0; i < sortingAlgo.size(); i++) {
		if (strcmp(s, sortingAlgo[i].c_str()) == 0) {
			return (SortingAlgo) i;
		}
	}
	return SortingAlgo::UNKNOWN_SORT;
}

void printAlgoHelp() {
	for (const auto & i : sortingAlgo) {
		cout << i << "\n";
	}
}

void printHelp() {
	cout << "SGP is a tool for measuring time and comparisons of sorting algorithms\n\n"
		 << "Usage: sgp [arguments]\n"
		 << "       sgp -a [algorithm] [input filename] [output param]\n"
		 << "       sgp -a [algorithm] [input size] [input order] [output param]\n"
		 << "       sgp -a [algorithm] [input size] [output param]\n\n"
		 << "       sgp -c [algorithm1] [algorithm2] [input filename]\n"
		 << "       sgp -c [algorithm1] [algorithm2] [input size] [input order]\n\n"
		 << "       sgp -l List all supported sorting algorithms\n";
}

int* cloneArray(const int* a, int n) {
	int *clone_a{new int[n]};
	for (int i = 0; i < n; i++) {
		clone_a[i] = a[i];
	}
	// memcpy(clone_a, a, sizeof(int) * n);
	return clone_a;
}

Result sort(SortingAlgo algo, int *a, int n) {
	if (algo == UNKNOWN_SORT) {
		return {-1, 0};
	}
	writeFile("input.txt", a, n);
	int *clone_a = cloneArray(a, n);
	Result r;
	switch (algo) {
		case SortingAlgo::HEAP_SORT:
			break;
		case SortingAlgo::INSERTION_SORT:
			r = insertionSort(clone_a, n);
			writeFile("output.txt", clone_a, n);
			break;
		case SortingAlgo::MERGE_SORT:
			r = mergeSort(clone_a, n);
			break;
		case SortingAlgo::SELECTION_SORT:
			r = selectionSort(clone_a, n);
			writeFile("output.txt", clone_a, n);
			break;
		default:
			break;
	}
	delete[] clone_a;
	return r;
}

void printAlgoList() {
	cout << "No)    Name            Tag\n";
	for (int i = 0; i < algoName.size(); i++) {
		printf("%d)  %-15s - %s\n", i + 1, algoName[i].c_str(), sortingAlgo[i].c_str());
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printHelp();
		return 0;
	}
	int *a1 = nullptr;
	int n = 0;

	if (strcmp(argv[1], "-a") == 0) {
		cout << "ALGORITHM MODE\n";
		OutputMode oMode = OutputMode::NONE;
		if (argc < 5) {
			printAlgoHelp();
			return 0;
		}
		SortingAlgo algo = getSortingAlgoFromText(argv[2]);
		if (algo == SortingAlgo::UNKNOWN_SORT) {
			// TODO: send help
			return 0;
		}
		cout << "Algorithm: " << algoName[algo] << '\n';
		if (isValidInputNumber(argv[3])) {
			InputOrder iOrder = getInputOrder(argv[4]);
			cout << "Input size: " << argv[3] << '\n';
			if (iOrder == InputOrder::ORDER_UNKNOWN) {
				printHelp();
				return 0;
			}
			cout << "Input order: " << (iOrder == 0 ? "Random" : (iOrder == 1 ? "Near sorted" : (iOrder == 2 ? "Sorted" : "Reverse sorted"))) << '\n';
			n = stoi(argv[3]);
			a1 = new int[n];

			GenerateData(a1, n, iOrder);
			oMode = getOutputMode(argv[5]);
		} else if (fileExist(argv[3])) {
			a1 = readFile(argv[3], n);
			cout << "Input file: " << argv[3] << "\n";
			cout << "Input size: " << n << "\n";
			oMode = getOutputMode(argv[4]);
		} else {
			printHelp();
			return 0;
		}
		Result r = sort(algo, a1, n);
		if (oMode == OutputMode::NONE) {
			printHelp();
			return 0;
		}
		cout << "--------------------------\n";
		cout << "Running time (if required): ";
		if (oMode == BOTH || oMode == TIME) {
			cout << r.time << " (ms)";
		}
		cout << '\n';
		cout << "Comparisons (if required): ";
		if (oMode == BOTH || oMode == COMP) {
			cout << r.cmps << " (times)";
		}
		cout << '\n';
	} else if (strcmp(argv[1], "-c") == 0) {
		SortingAlgo algo1 = getSortingAlgoFromText(argv[2]);
		SortingAlgo algo2 = getSortingAlgoFromText(argv[3]);
		if (algo1 == UNKNOWN_SORT || algo2 == UNKNOWN_SORT) {
			printAlgoHelp();
		}
	} else if (strcmp(argv[1], "-l") == 0) {
		printAlgoList();
	} else {
		printf("wtf\n");
		printHelp();
	}

	delete[] a1;
	return 0;
}
