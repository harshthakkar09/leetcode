typedef long long ll;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> freq(n, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> busy;
        
        for(int i = 0; i < n; i++){
            free.push(i);
        }
        
        sort(meetings.begin(), meetings.end());
        
        for(auto meeting : meetings){
            int start = meeting[0], end = meeting[1];
            
            // cout<<"start: "<<start<<" end: "<<end<<"\n";
            
            while(!busy.empty() && busy.top().first <= start){
                int index = busy.top().second;
                busy.pop();
                // cout<<"index: "<<index<<"\n";
                free.push(index);
            }
            
            if(!free.empty()){
                int freeInd = free.top();
                free.pop();
                freq[freeInd]++;
                // cout<<"increased for freeInd: "<<freeInd<<"\n";
                // cout<<"print freq: "<<freq[freeInd]<<"\n";
                busy.push({end, freeInd});
            }
            else{
                pair<ll, int> allocated = busy.top();
                busy.pop();
                freq[allocated.second]++;
                // cout<<"increased for allocated.second: "<<allocated.second<<"\n";
                // cout<<"print freq: "<<freq[allocated.second]<<"\n";
                ll newEnd = allocated.first;
                newEnd += (end - start);
                // cout<<"pushing for newEnd: "<<newEnd<<"\n";
                busy.push({newEnd, allocated.second});
            }
        }
        
        int ans, max = 0;
        for(int i = 0; i < n; i++){
            if(freq[i] > max){
                max = freq[i];
                ans = i;
            }
        }
        
        return ans;
    }
};