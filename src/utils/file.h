#ifndef SORTING_GROUP_PROJECT_FILE_H
#define SORTING_GROUP_PROJECT_FILE_H

#include <fstream>

using namespace std;

bool fileExist(const char *fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		return false;
	}
	file.close();
	return true;
}

int* readFile(const char *fileName, int &n) {
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
vector<int> readFile2Vector(const char *fileName, int &n) {
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

void writeFile(const char *fileName, int *a, int n) {
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
