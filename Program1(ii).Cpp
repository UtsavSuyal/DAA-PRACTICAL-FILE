#include <iostream>
 #include <vector>
 using namespace std;
 
 //Question: Given an array of non-negative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).
 
 int linearSearch (vector <int> & arr, int target){
      int size = arr.size();
      for (int i = 0; i < size; ++i)
           if (arr[i] == target) {cout<<"Present "; return (i + 1);}
      cout<<"Not Present ";
      return size;
 }
 
 int main (){
      int size, target;
      cout<<"\nEnter no. of elements : "; cin>>size; 
      cout<<"Enter elements : ";
      vector <int> arr (size);
      for (int i = 0; i < size; ++i) cin>>arr[i];
      cout<<"Enter element to search : "; cin>>target;
      cout<<endl<<linearSearch(arr, target)<<endl;
      return 0;
 }
