#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Question: Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element. (Time Complexity = O(nlog n))

vector<int> twoSum(vector<int> &arr, int target){
	int size = arr.size();
	unordered_map <int, int> hash;
	for (int i = 0; i < size; ++i){
		int toFind = target - arr[i];
		if (hash.find(toFind) != hash.end()) return {hash[toFind], i};
		hash[arr[i]] = i;
	}
	return {-1, -1};
}

vector<int> twoSum(vector<int> &arr, int target){
	int i = 0, j = arr.size() - 1;
	sort(arr.begin(), arr.end());
	while (i < j)
		if (arr[i] + arr[j] > target) --j;
		else if (arr[i] + arr[j] < target) ++i;
		else return {arr[i], arr[j]};
	return {-1, -1};
}

int main(){
	int size, target;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
	cout<<"Enter the key : "; cin>>target;
     vector <int> result = twoSum(arr, target);
	if (result[0] == -1 && result[1] == -1) cout<<"\nNo Sequence found"<<endl;
	else cout<<endl<<result[0]<<", "<<result[1]<<endl;
	return 0;
}
