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
	ORDER_UNKNOWN = -1,
	ORDER_RAND = 0,
	ORDER_SORTED = 1,
	ORDER_REV = 2,
	ORDER_NSORTED = 3,
};

InputOrder getInputOrder(char *s) {
	if (strcmp(s, "-rand") == 0) {
		return InputOrder::ORDER_RAND;
	}
	if (strcmp(s, "-nsorted") == 0) {
		return InputOrder::ORDER_NSORTED;
	}
	if (strcmp(s, "-sorted") == 0) {
		return InputOrder::ORDER_SORTED;
	}
	if (strcmp(s, "-rev") == 0) {
		return InputOrder::ORDER_REV;
	}
	return InputOrder::ORDER_UNKNOWN;
}

enum OutputMode{
	NONE = -1,
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
	return OutputMode::NONE;
}

#endif //SORTING_GROUP_PROJECT_UTILS_H
