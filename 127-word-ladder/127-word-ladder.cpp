class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string> words;
        for(auto w:word){
            words.insert(w);
        }
        if(words.find(end)==words.end()){
            return 0;
        }
        int ans=1;
        queue<string> q;
        q.push(begin);
        while(!q.empty()){
            int len=q.size();
            while(len--){
                string cur=q.front();
                q.pop();
                int n=cur.size();
                for(int i=0;i<n;i++){
                    string temp=cur;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(temp==cur){
                            continue;
                        }
                        if(temp==end){
                            return ans+1;
                        }
                        if(words.find(temp)!=words.end()){
                            cout<<"going to push "<<temp<<"\n";
                            q.push(temp);
                            words.erase(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};