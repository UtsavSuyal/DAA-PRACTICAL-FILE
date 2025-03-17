#include <iostream>
#include <vector>
using namespace std;

//Question: You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time Complexity = O(m + n))

vector <int> Intersection (vector <int> & arr1, vector <int> & arr2){
	int size1 = arr1.size(), size2 = arr2.size(), i = 0, j = 0;
	vector <int> result;
	while (i < size1 && j < size2)
		if (arr1[i] == arr2[j]) {result.push_back(arr1[i]); ++j; ++i;}
		else if (arr1[i] < arr2[j]) ++i;
		else ++j;
	return result;
}

int main (){
	int n1, n2;
	cout<<"\nEnter number of elements in array 1 : "; cin>>n1;
	vector <int> arr1 (n1);
	cout<<"Enter elements of Array 1 : "; 
	for (int i = 0; i < n1; ++i) cin>>arr1[i];
	cout<<"\nEnter number of elements in array 2 : "; cin>>n2;
	vector <int> arr2(n2);
	cout<<"Enter elements of Array 2 : ";
	for (int i = 0; i < n2; ++i) cin>>arr2[i];
	vector <int> intersection = Intersection(arr1, arr2);
	cout<<"\nCommon Elements : ";
	for (const int & i : intersection) cout<<i<<", "; cout<<endl;
	return 0;
}
