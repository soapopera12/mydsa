// k largest elements
// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

//User function template for C++
#include<queue>
class Solution{
public:	
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        // Your Code Here
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if(left < n && arr[largest] < arr[left]){
          largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        int mid = n/2;
        for(int i=mid;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        //code here
        for(int i = n-1;i>=0;i--){    
            swap(arr[i],arr[0]);    
            heapify(arr,i,0);       // highest element ko last mai daal diya to -1 therefore i
        }
    }
    
    
    
    
	vector<int> kLargest(int arr[], int n, int k) {
	    
	   // vector<int> klarge(k,0);  
	    
	   // //build heap // O(n)
	   // buildHeap(arr,n);
	    
	   // //heapsort // O(n)
	   // heapSort(arr,n);
	    
	   // int z = 0;
	   // for(int i=n-1;i>n-k-1;i--){
	   //     klarge[z] = arr[i];
	   //     z++;
	   // }
	    
	   // return klarge;
	   
	    priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
	   
	   
	}

};