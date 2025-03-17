#include <iostream>
#include <vector>
using namespace std;

//Question: Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array.

pair <int, int> merge(vector<int> &arr, int start, int pivot, int end){
	int comparisons = 0, inversions = 0;
	vector<int> temp(end - start + 1);
	for (int i = 0; i < end - start + 1; ++i) temp[i] = arr[start + i];
	int i = 0, j = pivot - start + 1, k = start;
	while (i <= pivot - start && j <= end - start){
		++comparisons; 
		if (temp[i] <= temp[j]) arr[k++] = temp[i++];
		else {arr[k++] = temp[j++]; inversions += pivot - start - i + 1;}
	}
	while (i <= pivot - start) arr[k++] = temp[i++];
	while (j <= end - start) arr[k++] = temp[j++];
	return {inversions, comparisons};
}
pair <int, int> mergeSort(vector<int> &arr, int start, int end){
	if (start >= end) return {0, 0};
	int comparisons = 0, inversions = 0;
	int mid = start + (end - start) / 2;
	pair <int, int> result;
	result = mergeSort(arr, start, mid); comparisons += result.second; inversions += result.first;
	result = mergeSort(arr, mid + 1, end); comparisons += result.second; inversions += result.first;
	result = merge(arr, start, mid, end); comparisons += result.second; inversions += result.first;
	return {inversions, comparisons};
}

int main (){
	int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	pair <int, int> values = mergeSort(arr, 0, arr.size() - 1);
	cout << "\nSorted Array : ";
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << "\nNo. of inversions : " << values.first;
	cout << "\nNo. of comparisons : " << values.second << endl;
	return 0;
}
