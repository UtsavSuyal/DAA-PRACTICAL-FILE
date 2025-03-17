#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Question: Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

vector <int> twoSum (vector <int> & arr, int sum, int size){
	unordered_map <int, int> hash;
	for (int i = 0; i < size; ++i){
		int toFind = sum - arr[i];
		if (hash.find(toFind) != hash.end()) return {hash[toFind] + 1, i + 1};
		hash[arr[i]] = i;
	}
	return {-1, -1, -1};
}
vector <int> threeSum (vector <int> & arr){
	int size = arr.size();
	if (size < 3) return {-1, -1, -1};
	vector <int> result;
	for (int i = 2; i < size; ++i){
		result = twoSum(arr, arr[i], i);
		result.push_back(i + 1);
		if (result[0] != -1 && result[1] != -1) return result;
	}
	return {-1, -1, -1};
}

int main(){
	int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
     vector <int> result = threeSum(arr);
	if (result[0] == -1 && result[1] == -1 && result[2] == -1) cout<<"\nNo Sequence found"<<endl;
	else cout<<endl<<result[0]<<", "<<result[1]<<", "<<result[2]<<endl;
	return 0;
}
