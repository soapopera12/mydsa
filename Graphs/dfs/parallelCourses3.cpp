// 2050. Parallel Courses III
// https://leetcode.com/problems/parallel-courses-iii/description/


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        // adjacency list prepare karo
        vector<vector<int>> adj(n);

        for(auto i:relations){      // will auto work
            int prev = i[0] - 1;
            int next = i[1] - 1;
            adj[prev].push_back(next);
        }

        // ek vector banao jo course ka mini completion time compute karega
        vector<int> memo(n,-1);

        // lambda function jo course ka required time calculate karega in the form of dfs
        // function<char(int)> convertFunction; <char -> return type, int is input type
        // <int(int, int)> - multiple input parameters
        function<int (int)> calculateTime = [&](int course) {   // applying dfs here

            if(memo[course] != -1){
                return memo[course];
            }

            if(adj[course].empty()){
                memo[course] = time[course];
                return memo[course];
            }

            int maxPrerequisiteTime = 0; // iss course ke liye kitne preReq lagenge

            for(int preReq: adj[course]) {
                maxPrerequisiteTime = max(maxPrerequisiteTime,calculateTime(preReq));
            }

            memo[course] = maxPrerequisiteTime + time[course];  // max time for that course
            return memo[course];

        };

        // for loop jo overall min time calculate karega
        int overAllMinTime = 0;

        for(int course=0;course<n;course++){
            overAllMinTime = max(overAllMinTime,calculateTime(course));
        }

        return overAllMinTime;

    }
};