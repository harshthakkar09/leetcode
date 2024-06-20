class Solution {
public:
    
    bool check(int mid, vector<int>& arr, int n, int m){
        int pre = arr[0], count = 1;
        for(int i = 1; i < n; i++){
            if((arr[i] - pre) >= mid){
                // cout<<"arr[i] "<<arr[i]<<" pre "<<pre<<"\n";
                pre = arr[i];
                count++;
            }
        }
        // cout<<"count "<<count<<"\n";
        return (count >= m);
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size(), left = 0, right = position[n - 1] - position[0], ans;
        while(left <= right){
            // cout<<"left: "<<left<<" right "<<right<<"\n";
            int mid = (left + right) / 2;
            if(check(mid, position, n, m)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};