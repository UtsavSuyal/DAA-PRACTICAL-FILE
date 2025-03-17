#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Question: Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.

pair <int, int> selectionSort1 (vector <int> & arr){
     int size = arr.size(), swaps = 0, comparisons = 0;
     for (int i = 0; i < size - 1; ++i){
          int minIndex = i;
          for (int j = i + 1; j < size; ++j)
               if (arr[minIndex] > arr[j]) minIndex = j;
          comparisons += size - i - 1; ++swaps;
          swap(arr[minIndex], arr[i]);
     }
     return {swaps, comparisons};
}

pair <int, int> selectionSort2 (vector <int> & arr){
     int size = arr.size();
     for (int i = 0; i < size - 1; ++i){
          int minIndex = i;
          for (int j = i + 1; j < size; ++j)
               if (arr[minIndex] > arr[j]) minIndex = j;
          swap(arr[minIndex], arr[i]);
     }
     return {size - 1, (size * (size - 1))/2};
}

int main(){
     int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	pair<int, int> values = selectionSort2(arr);
	cout << "\nSorted Array : ";
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << "\nNo. of swaps : " << values.first;
	cout << "\nNo. of comparisons : " << values.second << endl;
	return 0;
}
