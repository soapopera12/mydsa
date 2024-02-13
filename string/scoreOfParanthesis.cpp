// 856. Score of Parentheses
// https://leetcode.com/problems/score-of-parentheses

class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        int i = 0;

        while(s[i] != '\0') {
            
            if(s[i] == '(') {
                // found a open bracket
                st.push(-1);
            }
            else {
                // found a close bracket
                if(st.top() == -1) {
                    // tue pop
                    st.pop();
                    st.push(1);
                }
                else {
                    int ans = 0;
                    while(st.top() != -1) {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2 * ans);
                }
            }
            i++;
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;

    }
};