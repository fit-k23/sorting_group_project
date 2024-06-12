#include <iostream>
#include <cstring>
#include <vector>
#include "utils/result.h"

using namespace std;

enum SortingAlgo{
	UNKNOWN_SORT = -1,
	HEAP_SORT = 0,
	MERGE_SORT = 1,
};

static vector<string> sortingAlgo = {
	"heap-sort",
	"merge-sort",
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
	cout << "heap-sort\n";
	cout << "merge-sort\n";
}

void printHelp() {
	cout << "ain't no help!\n";
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printHelp();
		return 0;
	}

	if (strcmp(argv[1], "-a") == 0) {
		if (argc < 3) {
			printAlgoHelp();
			return 0;
		}
		SortingAlgo algo = getSortingAlgoFromText(argv[2]);
		switch (algo) {
			case SortingAlgo::HEAP_SORT:
				cout << "CHosen heap\n";
				break;
			case SortingAlgo::MERGE_SORT:
				cout << "CHosen merge\n";
				break;
			default:
				printAlgoHelp();
		}
	} else if (strcmp(argv[0], "-c") == 0) {
		SortingAlgo algo1 = getSortingAlgoFromText(argv[2]);
		SortingAlgo algo2 = getSortingAlgoFromText(argv[3]);
		if (algo1 == UNKNOWN_SORT || algo2 == UNKNOWN_SORT) {
			printAlgoHelp();
		}
	} else {
		printHelp();
	}

	cout << "----------------\n";
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << "\n";
	}

	return 0;
}
