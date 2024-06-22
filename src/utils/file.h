#ifndef SORTING_GROUP_PROJECT_FILE_H
#define SORTING_GROUP_PROJECT_FILE_H

#include <filesystem>
#include <fstream>

using namespace std;

// https://stackoverflow.com/a/24750132/24078702
bool fileExist(const char *fileName) {
	return filesystem::exists(fileName);
}

int* readFile(char* fileName, int &n) {
	ifstream file(fileName);
	if (!file.is_open()) return nullptr;

	file >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		file >> a[i];
	}
	file.close();
	return a;
}

#include <vector>
vector<int> readFile2Vector(char* fileName, int &n) {
	ifstream file(fileName);
	if (!file.is_open()) {
		return {};
	}
	file >> n;
	vector<int> a;
	a.reserve(n);
	for (int i = 0; i < n; i++) {
		file >> a[i];
	}
	file.close();
	return a;
}

void writeFile(char* fileName, int* a, int n) {
	ofstream file(fileName);
	if (!file.is_open()) {
		return;
	}
	file << n << '\n';
	for (int i = 0; i < n; i++) {
		file << a[i] << ' ';
	}
}

#endif //SORTING_GROUP_PROJECT_FILE_H
