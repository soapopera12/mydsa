// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/description/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        // // why does this not work
        // int n = s.size() > t.size() ? s.size()-1 : t.size()-1;
        // int i = 0;
        // while(i<=n){
        //     if(s[i] == t[i]){
        //         i++;
        //     }
        //     if(s[i] != t[i]){  // && s[i+1] == '#' && t[i+1] == '#'
        //         if(i+1 < s.size()-1 && i+1 < t.size()-1){
        //             if(s[i+1] == '#' && t[i+1] == '#'){
        //                 i++;
        //             }
        //         }
        //     }
        // }

        // if( i == n){
        //     return true;
        // }
        
        // return false;

         int i = s.size() - 1; // Pointer for string s
        int j = t.size() - 1; // Pointer for string t
        int skipS = 0;        // Count of backspaces encountered in s
        int skipT = 0;        // Count of backspaces encountered in t
        
        while (i >= 0 || j >= 0) {
            // Skip backspaces in string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            // Skip backspaces in string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            // Compare characters at the current positions
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            
            // If one string reaches the beginning and the other doesn't, they can't be equal
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            
            // Move to the previous character
            i--;
            j--;
        }
        
        // Both strings match after handling backspaces
        return true;

    }
};