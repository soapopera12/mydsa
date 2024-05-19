// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:

    // store mapping of the number and alphabets
    unordered_map<char, string> mp;

    void dfs(string& digits, int index, vector<string>& combinations, string& temp) {

        if(index == digits.length()) {
            combinations.push_back(temp);
            return;
        }

        for(auto ch:mp[digits[index]]) {
            temp.push_back(ch);
            dfs(digits, index+1, combinations, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> combinations;
        string temp = "";

        if(digits.size() == 0) {
            if(temp == "") {
                return combinations;
            }
            combinations.push_back(temp);
            return combinations;
        }
        
        dfs(digits, 0, combinations, temp);      

        return combinations;

    }
};