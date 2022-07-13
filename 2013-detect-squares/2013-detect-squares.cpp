class DetectSquares {
public:
    map<pair<int,int>, int> freq;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        freq[{x, y}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;
        for(auto it: freq){
            int nx = it.first.first, ny = it.first.second;
            if(nx != x && y != ny && abs(x - nx) == abs(y - ny)){
                int f1 = freq[{nx, ny}], f2 = freq[{nx, y}], f3 = freq[{x, ny}];
                ans += (f1 * f2 * f3);
            }
        }
        return ans;
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */