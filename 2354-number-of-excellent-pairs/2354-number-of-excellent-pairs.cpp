typedef long long ll;
class Solution {
public:
    
    int countBits(int num, ll &ans, int &k){
        int count = 0;
        while(num > 0){
            if((num % 2) == 1){
                count++;
            }
            num /= 2;
        }
        if((count * 2) >= k){
            ans++;
        }
        return count;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> nums_set;
        for(auto num: nums){
            nums_set.insert(num);
        }
        vector<int> v;
        for(auto it: nums_set){
            v.push_back(it);
        }
        vector<int> set_bits;
        ll ans = 0;
        for(auto it: v){
            int num_of_set_bit = countBits(it, ans, k);
            set_bits.push_back(num_of_set_bit);
        }
        sort(set_bits.begin(), set_bits.end());
        int left = 0, right = set_bits.size() - 1;
        while(left <= right){
            if(set_bits[left] + set_bits[right] >= k){
                ans += (right - left) * 2;
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};