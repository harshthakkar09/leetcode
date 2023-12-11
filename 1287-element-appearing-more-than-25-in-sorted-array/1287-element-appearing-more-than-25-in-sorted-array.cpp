class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), target = n / 4;
        vector<int> ind = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        for(auto i : ind){
            int left = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), i) - arr.begin() - 1;
            if(right - left + 1 > target){
                return i;
            }
        }
        return -1;
    }
};