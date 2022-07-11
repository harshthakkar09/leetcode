class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pass, int cap) {
        sort(bus.begin(), bus.end());
        sort(pass.begin(), pass.end());
        int pass_cap = pass.size(), pass_cur = 0, ans = 1, bus_num = bus.size(), pre = -1;
        for(int i = 0; i < bus_num; i++){
            int cur_cap = 0;
            int dep = bus[i];
            while(cur_cap < cap && pass_cur < pass_cap && pass[pass_cur] <= dep){
                if(pass[pass_cur] - 1 != pre){
                    ans = pass[pass_cur] - 1;
                }
                pre = pass[pass_cur];
                cur_cap ++ ;
                pass_cur ++;
            }
            if(cur_cap < cap && dep != pre){
                ans = dep;
            }
        }
        return ans;
    }
};