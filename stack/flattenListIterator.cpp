// 341. Flatten Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/description/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
// private:
//     vector<int> res;        // stores the nested list
//     int indx = 0;           // store index

// public:
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         flattenList(nestedList);
//     }

//     void flattenList(vector<NestedInteger> &nestedList){

//         for(auto x: nestedList){
//             if(x.isInteger()){
//                 res.push_back(x.getInteger());      // this is a function in the NestedIterator class
//             }
//             else{
//                 flattenList(x.getList());  
//             }
//         }

//     }
    
//     int next() {
//         return res[indx++];
//     }
    
//     bool hasNext() {
//         return indx<res.size();
//     }


    // push nestedList items onto a stack in reverse order
    // before getting the next integer we make sure that the tos is an integer
    // other if it is a list we pop it and push all the int onto the stack again
    // Noice
private:
    stack<NestedInteger> stk;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1;i>=0;i--){      // an iterator for nestedList
            stk.push(nestedList[i]);        // pushing every element onto the stack
        }
    }    
    
    int next() {
        int ans = stk.top().getInteger();
        stk.pop();
        return ans;
    }
    
    bool hasNext() {
        while(!stk.empty()){
            NestedInteger curr = stk.top();
            if(curr.isInteger()){
                return true;
            }
            stk.pop();
            vector<NestedInteger>& elements = curr.getList();
            for(int i=elements.size()-1;i>=0;i--){
                stk.push(elements[i]);
            }
        }
        return false;
    }
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */