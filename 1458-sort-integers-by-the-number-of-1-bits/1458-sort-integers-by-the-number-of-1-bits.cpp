class Solution {
public:

    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.first != b.first){
            return a.first < b.first;
        }
        else{
            return a.second < b.second;
        }
    }

    int countSetBits(int num){
        int count = 0;
        for(int i = 0; i <= 31; i++){
            if((num & (1 << i)) != 0){
                count++;
            }
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v;
        for(auto num : arr){
            int setBits = countSetBits(num);
            v.push_back(make_pair(setBits, num));
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(auto it : v){
            ans.push_back(it.second);
        }
        return ans;
    }
};