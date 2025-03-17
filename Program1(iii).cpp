#include <iostream>
 #include <vector>
 #include <cmath>
 using namespace std;
 
 //Question: Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): Jump Search
 
 int jumpSearchLinearVariation(vector<int>& arr, int target) {
      int size = arr.size(), j = 0, prev = 0, noOfComparisons = 0;
      if (size == 0) {cout << "Not Present "; return noOfComparisons;}
      while (j < size && arr[j] <= target) {
           ++noOfComparisons;
           prev = j; j += sqrt(size);
           if (prev >= size) break;
      } j = min(j, size - 1);
      for (int i = prev; i <= j; i++)
           if (arr[i] == target) {cout << "Present "; return noOfComparisons;}
           else if (arr[i] > target) break;
      cout<<"Not Present ";
      return noOfComparisons;
 }
 
 int main (){
      int size, target;
      cout<<"\nEnter no. of elements : "; cin>>size; 
      cout<<"Enter elements : ";
      vector <int> arr (size);
      for (int i = 0; i < size; ++i) cin>>arr[i];
      cout<<"Enter element to search : "; cin>>target;
      //sort(arr.begin(), arr.end()); //If array is not already sorted use sort for binary search
      cout<<endl<<jumpSearchLinearVariation(arr, target)<<endl;
      return 0;
 }
