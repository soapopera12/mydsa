// 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution {
public:
    void solve(int l,int r,int &ans,vector<int> & arr){

        if(l<r){
            //check value of ans
            if(ans > arr.size()){
                ans = -1;
            }
        }

        int mid = l + (r-l)/2;

        if(mid-1 >= 0 && mid+1 < arr.size() && arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
            ans = mid;
            return;
        }

        if(mid-1 >= 0 && arr[mid] > arr[mid-1]){
            l = mid + 1;
            solve(l,r,ans,arr);
        }

        if(mid+1 < arr.size() && arr[mid] > arr[mid+1]){
            r = mid - 1;
            solve(l,r,ans,arr);
        }
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        // int n = arr.size()+1;
        // // check first 3 elements
        // solve(0,arr.size()-1,n,arr);        
        // return n;
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end-start)/2;
        while(start<end){
            if(arr[mid] < arr[mid+1]){
                start = mid + 1;
            }
            else{
                end = mid;          // insane solution copied though 
            }
            mid = start + (end - start)/2;
        }
        return start;

    }
};