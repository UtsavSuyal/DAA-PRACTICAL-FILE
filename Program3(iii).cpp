#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//Question: Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(nlogn)

bool containDuplicates1 (vector <int> & arr){//Using Sorting
     int size = arr.size();
     sort(arr.begin(), arr.end());
     for (int i = 0; i < size - 1; ++i)
          if (arr[i] == arr[i + 1]) return true;
     return false;
}

bool containDuplicates2 (vector <int> & arr){//Using Sorting
     unordered_set <int> hash;
     for (const int & i : arr) hash.insert(i);
     if (hash.size() == arr.size()) return false;
     return true;
}

int main (){
     int size;
     cout<<"\nEnter no. of elements : "; cin>>size; 
     cout<<"Enter elements : ";
     vector <int> arr (size);
     for (int i = 0; i < size; ++i) cin>>arr[i];
     cout<<endl<<(containDuplicates1(arr)? "YES" : "NO")<<endl;
	return 0;
}
