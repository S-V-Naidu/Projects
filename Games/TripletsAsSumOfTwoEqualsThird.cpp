// C++ implementation to count the 
// triplets such that the sum of the 
// two numbers is equal to third number 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find the count of the  
// triplets such that sum of two  
// numbers is equal to the third number  
int countTriplets(int arr[], int n){ 
    int freq[100] = {0}; 
      
    // Loop to count the frequency 
    for (int i=0; i < n; i++){ 
        freq[arr[i]]++; 
    } 
    int count = 0; 
      
    // Loop to count for triplets 
    for(int i = 0;i < n; i++){ 
        for(int j = i+1; j < n; j++){ 
            if(freq[arr[i] + arr[j]]){ 
                count++; 
            } 
        } 
    } 
    return count; 
} 
  
// Driver Code 
int main() 
{ 
    int n = 4; 
    int arr[] = {4, 1, 5, 3, 2}; 
      
    // Function Call 
    cout << countTriplets(arr, n); 
    return 0; 
} 
