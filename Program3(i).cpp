#include <bits/stdc++.h>
using namespace std;

//Question: Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.

pair <int, int> insertionSort1(vector <int> & arr){
	int size = arr.size(), shifts = 0, comparisons = 0;
	if (size <= 1) return {0, 0};
	for (int i = 1; i < size; ++i){
		int pivot = arr[i], j = i - 1;
		for (; j >= 0; --j){
			++comparisons;
			if (arr[j] <= pivot) break;
			arr[j + 1] = arr[j];
			++shifts;
		}
		if (j < 0) ++comparisons; //Account for the last failed comparison (j == -1)
    		arr[j + 1] = pivot;
	}
	return {shifts, comparisons};
}

pair <int, int> insertionSort2(vector <int> & arr){
	int size = arr.size();
	int shifts = 0, comparisons = 0;
	if (size <= 1) return {0, 0};
	for (int i = 1; i < size; ++i){
		int pivot = arr[i], j = i - 1;
		while (j >= 0 && arr[j] > pivot){
			arr[j + 1] = arr[j];
			++shifts; --j;
		}
		comparisons += i - j;
		arr[j + 1] = pivot;
	}
	return {shifts, comparisons};
}

int main(){
	int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	pair<int, int> values = insertionSort1(arr);
	cout << "\nSorted Array : ";
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << "\nNo. of shifts : " << values.first;
	cout << "\nNo. of comparisons : " << values.second << endl;
	return 0;
}
