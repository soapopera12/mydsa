// 886. Possible Bipartition
// https://leetcode.com/problems/possible-bipartition/
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // given a graph with many nodes 
        // find the number of colours required to color each vertex
        // where no two adjacent nodes should have same colour

        enum COLOR_CONSTANT{    // so that we dont have to do string check
            GREEN = -1,         // -1
            NOT_COLORDED,       // 0
            BLUE                // 1
        };

        // quick response
        if(n == 1 || dislikes.size() == 0){
            return true;
        }

        unordered_map<int,vector<int>> dislikeTable;
        unordered_map<int,int> colorTable;

         for( const auto& relation : dislikes ){
            
            int p1 = relation[0], p2 = relation[1];
            
            dislikeTable[p1].emplace_back( p2 );
            dislikeTable[p2].emplace_back( p1 );
            
        }

        std::function< bool( int, int ) > helper; // lambda function
        helper = [&](int personID, int color)->bool{

             colorTable[personID] = color;

            for(const int& theOther:dislikeTable[personID]){
                if(colorTable[theOther] == color){
                    return false;   //for opponent colour
                }
                if(colorTable[theOther] == NOT_COLORDED && (!helper(theOther,-color))){
                    return false;
                }
            }
            return true;
        };




        for(int personID=1;personID<=n;personID++){
            if(colorTable[personID] == NOT_COLORDED && !helper(personID,BLUE)){
                return false;
            }
        }
        return true;

    }
};