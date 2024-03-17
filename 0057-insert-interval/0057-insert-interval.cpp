class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        stack<pair<int, int>> st;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            // cout<<"i: "<<i<<" start "<<start<<" end "<<end<<"\n";
            if(st.empty()){
                // cout<<"pushing start "<<start<<" end  "<<end<<"\n";
                st.push({start, end});
            }
            else{
                if(st.top().second >= start){
                    pair<int, int> t = st.top();
                    st.pop();
                    // cout<<"pushing t.first "<<t.first<<" end "<<end<<"\n";
                    st.push({t.first, max(t.second, end)});
                }
                else{
                    // cout<<"pushing start "<<start<<" end "<<end<<"\n";
                    st.push({start, end});
                }
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()){
            pair<int, int> t = st.top();
            st.pop();
            ans.push_back({t.first, t.second});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};