#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//Question: Given an array of non-negative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.

int twoSum(vector<int> &arr, int target){
	int size = arr.size(), count = 0;
	unordered_set <int> hash;
	for (int i = 0; i < size; ++i){
		int toFind1 = target + arr[i], toFind2 = arr[i] - target;
		if (hash.find(toFind1) != hash.end()) ++count;
		if (target != 0) if (hash.find(toFind2) != hash.end()) ++count;
		hash.insert(arr[i]);
	}
	return count;
}

int main(){
	int size, target;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
     cout<<"Enter the value of key : "; cin>>target;
     int result = twoSum(arr, target);
     cout<<"\nCount : "<<result<<endl;
	return 0;
}
