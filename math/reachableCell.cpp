// 2849. Determine if a Cell Is Reachable at a Given Time
// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/

class Solution {
public:

    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // bfs question
        // starting from sx and sy reach fx and fy decrementing t
        // greid is infinite so make sure that you return when t is below 0

        int xdist = abs(sx-fx);
        int ydist = abs(sy-fy);

        if(xdist == 0 && ydist == 0) {
            return t != 1;
        }

        return xdist <= t && ydist <= t;

    }
};