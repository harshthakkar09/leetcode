class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(sx - fx), diffy = abs(sy - fy);
        if(diffx == 0 && diffy == 0){
            return t != 1;
        }
        return min(diffx, diffy) + abs(diffx - diffy) <= t;
    }
};