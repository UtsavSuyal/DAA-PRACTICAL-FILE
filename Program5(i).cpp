#include <iostream>
#include <vector>
using namespace std;

//Question: Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)

char maxOccurrences(vector<char> &arr){
	vector<int> hash(26, 0);
	for (const char &i : arr)
		if (i >= 'a' && i <= 'z') ++hash[i - 'a'];
	int max = -1, count = 0;
	vector<int> result;
	for (int i = 0; i < 26; ++i)
		if (count < hash[i]){max = i; count = hash[i];}
	for (int i = 1; i < 26; ++i) hash[i] += hash[i - 1];
	int i = 0, j = 0;
	while (i < 26 && j < arr.size())
		if (j < hash[i]) arr[j++] = 'a' + i;
		else ++i;
	if (count == 1 || count == 0){
		cout<<"No duplicates present...";
		return '\0';
	}
	return 'a' + max;
}

int main(){
	int n;
	cout<<"\nEnter the number of elements : "; cin>>n;
	vector <char> arr(n);
	cout<<"Enter elements : ";
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cout<<"\nMax Occurrence Character : ";
	char maxOccur = maxOccurrences(arr);
	cout<<maxOccur;
	cout<<"\nSorted Array : ";
	for (int i = 0; i < n; ++i) cout << arr[i] << " "; cout<<endl;
	return 0;
}
