#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Question: Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

int firstOccurrence(vector<int> &arr, int target){
	int i = 0, j = arr.size() - 1, ans = -1;
	while (i <= j){
		int mid = i + (j - i)/2;
		if (arr[mid] >= target) {ans = mid; j = mid - 1;}
		else i = mid + 1;
	}
	return (arr[ans] == target)? ans : -1;
}
int lastOccurence(vector<int> &arr, int target){
	int i = 0, j = arr.size() - 1, ans = -1;
	while (i <= j){
		int mid = i + (j - i)/2;
		if (arr[mid] <= target) {ans = mid; i = mid + 1;}
		else j = mid - 1;
	}
	return (arr[ans] == target)? ans : -1;
}

int main (){
     int size, target;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
     cout<<"Enter element to search : "; cin>>target;
     //sort(arr.begin(), arr.end()); //If array is not already sorted use sort for binary search
	int firstIndex = firstOccurrence(arr, target);
	if (firstIndex == -1) cout<<"\nKey Not Found"<<endl;
     else cout<<endl<<arr[firstIndex]<<" - "<<(lastOccurence(arr, target) - firstIndex) + 1<<endl;
     return 0;
}
