// Kth smallest element
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    public:

    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        // build heap
        sort (arr,arr+(r+1));
        k=arr[k-1];
        return k;
    }
};