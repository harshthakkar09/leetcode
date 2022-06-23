class Solution {
public:
    
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int n=courses.size(),ans=0,time=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            if(courses[i][0]+time<=courses[i][1]){
                pq.push(courses[i][0]);
                ans++;
                time+=courses[i][0];
            }
            else{
                if(!pq.empty()){
                    int t=pq.top();
                    if(t>courses[i][0]){
                        time-=t;
                        time+=courses[i][0];
                        pq.pop();
                        pq.push(courses[i][0]);
                    }
                }
            }
        }
        return ans;
    }
};