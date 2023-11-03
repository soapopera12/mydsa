// 1441. Build an Array With Stack Operations
// https://leetcode.com/problems/build-an-array-with-stack-operations/description/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int streamNum = 0;
        stack <int> st;
        st.push(streamNum);
        vector<string> ans;
        string push = "Push";
        string pop = "Pop";
        
        

        for(int i=0;i<target.size();i++) {
            
            while(streamNum <= n){
                streamNum++;
                st.push(streamNum);
                ans.push_back(push);

                if(st.top() == target[i]) {
                    break;
                }

                st.pop();
                ans.push_back(pop);
            }

        }

        return ans;
    }
};