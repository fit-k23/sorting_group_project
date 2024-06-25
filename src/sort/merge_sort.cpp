#include <iostream>
#include <vector>
#include "../utils/result.h"
void Run_mergeSort(Result &r,int *a,int left,int right){
	if (++r.cmps && left==right) return;
	if (++r.cmps && (right-left==1)){
		if (++r.cmps && (a[left]>a[right])) swap(a[left],a[right]);
		return;
	}
	int mid=(left+right)/2;
	Run_mergeSort(a,left,mid);
	Run_mergeSort(a,mid+1,right);
	
	// combine the array's parts to merge array in ascending order
	vector<int> c(right-left+1);
	int i=left, j=mid+1, index=0;
	while (++r.cmps && (i<=mid && j<=right)){
		if (++r.cmps && a[i]<a[j]){
			c[index++]=a[i];
			++i;
		}
		else {
			c[index++]=a[j];
			++j;
		}
	}
	while (++r.cmps && i<=mid) c[index++] = a[i++];
	while (++r.cmps && j<=right) c[index++] = a[j++];
	for (int i=left;++r.cmps && i<=right; ++i)
		a[i]=c[i-left];
	
}
Result mergeSort(int *a, int n) {
	Result r;
	auto start = chrono::high_resolution_clock::now();
	Run_mergeSort(r,a,0,n-1);
	chrono::duration<double, std::milli> duration = chrono::high_resolution_clock::now() - start;
	r.time = duration.count();
	return r;
}
