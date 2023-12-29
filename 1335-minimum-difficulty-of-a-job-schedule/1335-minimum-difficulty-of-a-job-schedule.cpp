int dp[301][1001][11];
class Solution {
public:
    
    int helper(int ind, int preJob, int left, vector<int>& job, int n){
        // cout<<"ind: "<<ind<<" preJob: "<<preJob<<" left: "<<left<<"\n";
        
        if(left < 0){
            return INT_MAX / 2;
        }
        
        if(ind == n){
            if(left == 0){
                return preJob;
            }
            else{
                return INT_MAX / 2;
            }
        }
        
        if(dp[ind][preJob][left] != -1){
            return dp[ind][preJob][left];
        }
        
        int keepJob = helper(ind + 1, max(job[ind], preJob), left, job, n);
        int newJob = preJob + helper(ind + 1, job[ind], left - 1, job, n);
        // cout<<"keepJob: "<<keepJob<<" newJob: "<<newJob<<"\n";
        
        // cout<<"returning"<<"\n";
        // cout<<"ind: "<<ind<<" preJob: "<<preJob<<" left: "<<left<<"\n";
        int ans =  min(keepJob, newJob);
        // cout<<"ans: "<<ans<<"\n";
        return dp[ind][preJob][left] = ans;
    }
    
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(d > n){
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        return helper(1, job[0], d - 1, job, n);
    }
};