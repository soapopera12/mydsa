// Binary Search
// https://practice.geeksforgeeks.org/problems/binary-search-1587115620/0

// User function template for C++

class Solution {
  public:
 
    int solve(int arr[],int n ,int k){
        //base case 
        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;
        
        while(start<=end){
            if(arr[mid]==k){
                return mid;
            }
            else if(mid<k){
                start = mid+1;
            }
            else{
                end=mid-1;
            }
            mid=(start+end)/2;
        }
        
        return -1;
    }
    
    int binarysearch(int arr[], int n, int k) {
        // code here
          int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == k)
                return mid;
            if (arr[mid] < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};