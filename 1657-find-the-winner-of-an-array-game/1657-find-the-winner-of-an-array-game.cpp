class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(n <= k){
            int maxNum = INT_MIN;
            for(auto num : arr){
                maxNum = max(maxNum, num);
            }
            return maxNum;
        }
        else{
            unordered_map<int, int> freq;
            deque<int> dq;
            for(auto num : arr){
                dq.push_back(num);
            }
            while(true){
                int first = dq.front();
                dq.pop_front();
                int second = dq.front();
                dq.pop_front();
                // cout<<"first: "<<first<<" second: "<<second<<"\n";
                int maxVal = max(first, second);
                int minVal = max(first, second);
                freq[maxVal]++;
                if(freq[maxVal] == k){
                    return maxVal;
                }
                dq.push_front(maxVal);
                dq.push_back(minVal);
            }
        }
    }
};