// 557. Reverse Words in a String III
// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:

    string reverseWords(string s) {
        int start = 0;
        for(int i=0; i<s.size();i++){
            if(s[i] == ' '){
                // reverse
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        reverse(s.begin() + start, s.end());        
        return s;
    }
};