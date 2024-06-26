#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <thread>
#include "utils/utils.h"

#include "sort.h"

using namespace std;

enum SortingAlgo{
	UNKNOWN_SORT = -1,
	BINARY_INSERTION_SORT = 0,
	BUBBLE_SORT = 1,
	COUNTING_SORT = 2,
	FLASH_SORT = 3,
	HEAP_SORT = 4,
	INSERTION_SORT = 5,
	MERGE_SORT = 6,
	QUICK_SORT = 7,
	RADIX_SORT = 8,
	SELECTION_SORT = 9,
	SHAKER_SORT = 10,
	SHELL_SORT = 11,
};

static vector<string> sortingAlgo = {
	"binary-insertion-sort",
	"bubble-sort",
	"counting-sort",
	"flash-sort",
	"heap-sort",
	"insertion-sort",
	"merge-sort",
	"quick-sort",
	"radix-sort",
	"selection-sort",
	"shaker-sort",
	"shell-sort",
};

static vector<string> algoName = {
	"Binary Insertion Sort",
	"Bubble Sort",
	"Counting Sort",
	"Flash Sort",
	"Heap Sort",
	"Insertion Sort",
	"Merge Sort",
	"Quick Sort",
	"Radix Sort",
	"Selection Sort",
	"Shaker Sort",
	"Shell Sort",
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
		 << "       sgp -l >> List all supported sorting algorithms\n";
#ifdef COMMAND_TEST
	cout << "       sgp -t >> Run test\n";
#endif
}

int* cloneArray(const int* a, int n) {
	int *clone_a{new int[n]};
	for (int i = 0; i < n; i++) {
		clone_a[i] = a[i];
	}
	// memcpy(clone_a, a, sizeof(int) * n);
	return clone_a;
}

Result sort(SortingAlgo algo, int *a, int n, const char *outputFile = nullptr) {
	if (algo == UNKNOWN_SORT) {
		return {-1, 0};
	}
	int *clone_a = cloneArray(a, n);
	//cout << "Sorting " << algoName[algo] << "\n";
	Result r;
	switch (algo) {
		case SortingAlgo::BINARY_INSERTION_SORT:
			r = binaryInsertionSort(clone_a, n);
			break;
		case SortingAlgo::BUBBLE_SORT:
			r = bubbleSort(clone_a, n);
			break;
		case SortingAlgo::COUNTING_SORT:
			r = countingSort(clone_a, n);
			break;
		case SortingAlgo::FLASH_SORT:
			r = flashSort(clone_a, n);
			break;
		case SortingAlgo::HEAP_SORT:
			r = heapSort(clone_a, n);
			break;
		case SortingAlgo::INSERTION_SORT:
			r = insertionSort(clone_a, n);
			break;
		case SortingAlgo::MERGE_SORT:
			r = mergeSort(clone_a, n);
			break;
		case SortingAlgo::QUICK_SORT:
			r = quickSort(clone_a, n);
			break;
		case SortingAlgo::RADIX_SORT:
			r = radixSort(clone_a, n);
			break;
		case SortingAlgo::SELECTION_SORT:
			r = selectionSort(clone_a, n);
			break;
		case SortingAlgo::SHAKER_SORT:
			r = shakerSort(clone_a, n);
//			printf("T1");
//			printf("C: %lld  - T: %f\n", r.cmps, r.time);
			delete[] clone_a;

			clone_a = cloneArray(a, n);
			r = shakerSort3(clone_a, n);
//			printf("T3");
//			printf("C: %lld  - T: %f\n", r.cmps, r.time);
			break;
		case SortingAlgo::SHELL_SORT:
			r = shellSort(clone_a, n);
			break;
		default:
			break;
	}
	if (outputFile != nullptr && *outputFile != '\0') { // if outputFile is not empty, write the file
		writeFile(outputFile, clone_a, n);
	}
	delete[] clone_a;
	return r;
}

void refSort(SortingAlgo algo, int *a, int n, Result *r, const char *outputFile = nullptr) {
	*r = sort(algo, a, n, outputFile);
}

void printAlgoList() {
	cout << "Here is the list of all algorithms: \n";
	cout << "No)    Name                    Tag\n";
	for (int i = 0; i < algoName.size(); i++) {
		printf("%2d)  %-21s - %s\n", i + 1, algoName[i].c_str(), sortingAlgo[i].c_str());
	}
}

void logGenerateDataInfo(int *a, int n, InputOrder order, const char *outputFile = nullptr) {
	cout << "Input order: ";
	switch (order) {
		case InputOrder::ORDER_RAND:
			cout << "Random\n";
			GenerateData(a, n, 0);
			break;
		case InputOrder::ORDER_SORTED:
			cout << "Sorted\n";
			GenerateData(a, n, 1);
			break;
		case InputOrder::ORDER_REV:
			cout << "Reverse sorted\n";
			GenerateData(a, n, 2);
			break;
		case InputOrder::ORDER_NSORTED:
			cout << "Near sorted\n";
			GenerateData(a, n, 3);
			break;
		default:
			break;
	}
	if (outputFile != nullptr && *outputFile != '\0') {
		writeFile(outputFile, a, n);
	}
}

void logOutputInfo(Result r, OutputMode oMode) {
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
}

int main(int argc, char **argv) {
//	printf("%d\n", argc);
	if (argc < 2) {
		printHelp();
		return 0;
	}
	int *a1 = nullptr;
	int n = 0;

	// no switch?
	if (strcmp(argv[1], "-a") == 0) {
		cout << "ALGORITHM MODE\n";
		OutputMode oMode;
		if (argc < 5) {
			printAlgoHelp();
			return 0;
		}
		SortingAlgo algo = getSortingAlgoFromText(argv[2]);
		if (algo == SortingAlgo::UNKNOWN_SORT) {
			// TODO: send help
			return 0;
		}
		Result r;
		cout << "Algorithm: " << algoName[algo] << '\n';
		if (isValidInputNumber(argv[3])) { // command 1
			cout << "Input size: " << argv[3] << '\n';
			n = stoi(argv[3]);
			a1 = new int[n];
			if (argc == 5) { // command 3
				oMode = getOutputMode(argv[4]);
				cout << '\n';
				logGenerateDataInfo(a1, n, ORDER_RAND, "input_1.txt");
				r = sort(algo, a1, n);
				logOutputInfo(r, oMode);
				cout << '\n';
				logGenerateDataInfo(a1, n, ORDER_SORTED, "input_2.txt");
				r = sort(algo, a1, n);
				logOutputInfo(r, oMode);
				cout << '\n';
				logGenerateDataInfo(a1, n, ORDER_REV, "input_3.txt");
				r = sort(algo, a1, n);
				logOutputInfo(r, oMode);
				cout << '\n';
				logGenerateDataInfo(a1, n, ORDER_NSORTED, "input_4.txt");
				r = sort(algo, a1, n);
				logOutputInfo(r, oMode);
				delete[] a1;
				return 0;
			}
			InputOrder iOrder = getInputOrder(argv[4]);

			if (iOrder == InputOrder::ORDER_UNKNOWN) {
				printHelp();
				return 0;
			}
			logGenerateDataInfo(a1, n, iOrder, "input.txt");
			oMode = getOutputMode(argv[5]);
		} else if (fileExist(argv[3])) { // command 2
			a1 = readFile(argv[3], n);
			cout << "Input file: " << argv[3] << "\n";
			cout << "Input size: " << n << "\n";
			oMode = getOutputMode(argv[4]);
		} else {
			printHelp();
			return 0;
		}
		r = sort(algo, a1, n, "output.txt");
		if (oMode == OutputMode::NONE) { // send help
			printHelp();
			return 0;
		}
		logOutputInfo(r, oMode);
	} else if (strcmp(argv[1], "-c") == 0) { // command 4, 5
		SortingAlgo algo1 = getSortingAlgoFromText(argv[2]);
		SortingAlgo algo2 = getSortingAlgoFromText(argv[3]);
		Result r1;
		Result r2;
		if (algo1 == UNKNOWN_SORT || algo2 == UNKNOWN_SORT) {
			printAlgoHelp();
		}
		cout << "COMPARE MODE\n";
		printf("Algorithm: %21s | %-21s\n", algoName[algo1].c_str(), algoName[algo2].c_str());
		if (isValidInputNumber(argv[4])) { // command 5
			cout << "Input size: " << argv[4] << '\n';
			n = stoi(argv[4]);
			a1 = new int[n];
			InputOrder iOrder = getInputOrder(argv[5]);
			if (iOrder == InputOrder::ORDER_UNKNOWN) {
				printHelp();
				return 0;
			}
			GenerateData(a1, n, iOrder);
			writeFile("input.txt", a1, n);

			// run 2 algorithms in different threads to save time! magik :D
			thread t1(refSort, algo1, a1, n, &r1, nullptr);
			thread t2(refSort, algo2, a1, n, &r2, nullptr);
			t1.join();
			t2.join();

			cout << "--------------------------------------------------------------\n";
			printf("Running time: %18f | %-18f  (ms)\n", r1.time, r2.time);
			printf("Comparisons:  %18lld | %-18lld  (times)\n", r1.cmps, r2.cmps);
		} else if (fileExist(argv[3])) { // command 4
			a1 = readFile(argv[3], n);
			cout << "Input file: " << argv[3] << "\n";
			cout << "Input size: " << n << "\n";
		} else { // send help
			printHelp();
			return 0;
		}
//		thread ag1(sort(algo1))
	} else if (strcmp(argv[1], "-l") == 0) { // extra command for display all algorithms
		printAlgoList();
	} else {
		printHelp();
	}

	delete[] a1;
	return 0;
}
