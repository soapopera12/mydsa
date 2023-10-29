// Sort an array of 0s, 1s and 2s
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/0
 

class Solution
{
    public:
    void sort012(int a[], int n)
    {
         int low = 0;           // Pointer to the beginning of the sorted array (0s)
    int high = n - 1;      // Pointer to the end of the sorted array (2s)
    int mid = 0;           // Pointer to the current element
    
    while (mid <= high)
    {
        switch (a[mid])
        {
            case 0:
                // Swap the current element with the element at the low pointer
                swap(a[low], a[mid]);
                low++;
                mid++;
                break;
            case 1:
                // Move to the next element
                mid++;
                break;
            case 2:
                // Swap the current element with the element at the high pointer
                swap(a[mid], a[high]);
                high--;
                break;
        }
    }
    }
    
};