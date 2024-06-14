#ifndef SORTING_GROUP_PROJECT_UTILS_H
#define SORTING_GROUP_PROJECT_UTILS_H

#include <cstring>
#include <chrono>

#include "DataGenerator.cpp"
#include "file.h"
#include "result.h"

bool isValidInputNumber(char *s) {
	for (int i = 0; s[i]; s++)
		if (s[i] > '9' || s[i] < '0')
			return false;
	return true;
}

enum InputOrder{
	UNKNOWN_ORDER = -1,
	RAND = 0,
	NSORTED = 1,
	SORTED = 2,
	REV = 3
};

enum class InputOrderC{
	UNKNOWN = -1,
	RAND = 0,
	NSORTED = 1,
	SORTED = 2,
	REV = 3
};

InputOrder getInputOrder(char *s) {
	if (strcmp(s, "-rand") == 0) {
		return InputOrder::RAND;
	}
	if (strcmp(s, "-nsorted") == 0) {
		return InputOrder::NSORTED;
	}
	if (strcmp(s, "-sorted") == 0) {
		return InputOrder::SORTED;
	}
	if (strcmp(s, "-rev") == 0) {
		return InputOrder::REV;
	}
	return InputOrder::UNKNOWN_ORDER;
}

enum OutputMode{
	UNKNOWN_OUTPUT_MODE = -1,
	TIME = 0,
	COMP = 1,
	BOTH = 2,
};

OutputMode getOutputMode(char* s) {
	if (strcmp(s, "-time") == 0) {
		return OutputMode::TIME;
	}
	if (strcmp(s, "-comp") == 0) {
		return OutputMode::COMP;
	}
	if (strcmp(s, "-both") == 0) {
		return OutputMode::BOTH;
	}
	return OutputMode::UNKNOWN_OUTPUT_MODE;
}

#endif //SORTING_GROUP_PROJECT_UTILS_H
