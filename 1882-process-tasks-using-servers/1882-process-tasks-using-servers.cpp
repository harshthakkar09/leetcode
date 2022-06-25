typedef pair<int,int> pii;
class Solution {
public:

    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        int n=s.size(),m=t.size(),time=0;
        priority_queue<pii,vector<pii>,greater<pii>> free;
        priority_queue<pii,vector<pii>,greater<pii>> taken;
        vector<int> ans(m);
        for(int i=0;i<n;i++){
            free.push({s[i],i});
        }
        for(int i=0;i<m;i++){
            if(time<i){
                time=i;
            }
            while(!taken.empty() && taken.top().first<=i){
                free.push({s[taken.top().second],taken.top().second});
                taken.pop();
            }
            if(free.empty()){
                time=taken.top().first;
                while(!taken.empty() && taken.top().first<=time){
                    free.push({s[taken.top().second],taken.top().second});
                    taken.pop();
                }
            }
            auto res=free.top();
            ans[i]=res.second;
            taken.push({time+t[i],res.second});
            free.pop();
        }
        return ans;
    }
};

