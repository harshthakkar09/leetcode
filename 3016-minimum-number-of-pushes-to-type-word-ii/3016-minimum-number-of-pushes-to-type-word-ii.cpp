class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto c : word){
            freq[c - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for(char c = 'a'; c <= 'z'; c++){
            if(freq[c - 'a'] > 0){
                pq.push({freq[c - 'a'], c});
            }
        }
        int ans = 0, count = 0, push = 1;
        while(!pq.empty()){
            auto freq = pq.top();
            pq.pop();
            int fre = freq.first;
            count++;
            if(count > 8){
                count = 1;
                push++;
            }
            ans += (fre * push);
        }
        return ans;
    }
};