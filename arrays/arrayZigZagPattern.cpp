// Convert array into Zig-Zag fashion
// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/0

// User function template for C++
class Solution {
  public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n) {
        // code here
        
        for(int i=0;i<n;i++){
            if(i%2 == 0 && arr[i] > arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
            if(i%2 != 0 && arr[i] < arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
};