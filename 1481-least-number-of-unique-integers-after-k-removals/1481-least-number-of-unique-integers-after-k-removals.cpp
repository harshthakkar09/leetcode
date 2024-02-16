class Solution {
public:
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.second < b.second){
            return true;
        }
        else if(a.second > b.second){
            return false;
        }
        else{
            return a.first < b.first;
        }
    }
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> fre;
        for(auto num : arr){
            fre[num]++;
        }
        vector<pair<int, int>> v;
        for(auto it : fre){
            v.push_back({it.first, it.second});
        }
        sort(v.begin(), v.end(), cmp);
        // for(auto it : v){
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        int count = 0, n = v.size(), removed = 0;
        while((k > 0) && (removed < n)){
            // cout<<"k: "<<k<<" removed: "<<removed<<"\n";
            k -= v[removed].second;
            removed++;
            // cout<<"removed: "<<removed<<" k: "<<k<<"\n";
            if(k < 0){
                removed--;
            }
        }
        // cout<<"n: "<<n<<" removed: "<<removed<<"\n";
        return (n - removed);
    }
};