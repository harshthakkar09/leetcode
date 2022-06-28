class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(),s.end());
        int n=s.size();
        int cnt=1;
        char pre;
        unordered_set<int> us;
        int ans=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
               cnt++;
            }
            else{
                if(us.find(cnt)==us.end()){
                    us.insert(cnt);
                }
                else{
                    int ocnt=cnt;
                    while((cnt>0) && (us.find(cnt)!=us.end())){
                        cnt--;
                    }
                        us.insert(cnt);
                        ans+=(ocnt-cnt);
                }
                cnt=1;
            }
        }
         int ocnt=cnt;
        while((cnt>0) && (us.find(cnt)!=us.end())){
                        cnt--;
                    }
                        us.insert(cnt);
                        ans+=(ocnt-cnt);
        return ans;
    }
};