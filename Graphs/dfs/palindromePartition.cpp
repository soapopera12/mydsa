// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:

    bool isPalindrome(string s, int index, int last) {

        while(index <= last) {
            if(s[index] != s[last]) {
                return false;
            }
            index++;
            last--;
        }
        return true;
    }

    void palindromePartition(int index,  vector<string>& ds, vector<vector<string>>& output, string s) {

        if(index == s.length()) {       // If index reaches end push all possible palindrom strings to outputs
            output.push_back(ds);
            return;
        }

        for(int i=index; i<s.length(); i++) {
            // check if palindrome
            if(isPalindrome(s, index, i)) {
                // if it is a palindrom we push that substring into ds and continue for the rest of the part
                ds.push_back(s.substr(index,i-index+1)); // substr(position,length)
                palindromePartition(i+1, ds, output, s);
                ds.pop_back();  // why do this? -- at the end remove all the added partitioned strings
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> output;
        vector<string> ds;

        palindromePartition(0,ds,output,s);

        return output;
    }
};