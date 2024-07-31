class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """
        # products need to be lexicographically sorted -> O(n^2)
        products.sort()
        # search using binary search and find the first element that matches lexicographically       
        prefix = ''
        ans = []
        i=0
        
        # for string the operators will also check lexicographically
        def custom_bisect_left(sorted_list, element, lo=0, hi=None):
            if hi is None:
                hi = len(sorted_list)
            
            while lo < hi:
                mid = (lo + hi) // 2
                if sorted_list[mid] < element:
                    lo = mid + 1
                else:
                    hi = mid
            return lo

        for c in searchWord:
            prefix += c
            # gives me the index of the first smallest lexicpgrapic number
            i = custom_bisect_left(products, prefix, i)
            ans.append([w for w in products[i:i+3] if w.startswith(prefix)])        
       
        return ans  