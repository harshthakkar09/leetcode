class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.size(), i = 0, j = n - 1;
        
        while(i < j && s[i] == s[j]){
            // cout<<"i: "<<i<<" "<<s[i]<<" j: "<<j<<" "<<s[j]<<"\n";
            
            while(i + 1 < j && s[i + 1] == s[i] && i < j){
                i++;
                // cout<<"i: "<<i<<"\n";
            }
            
            while(j - 1 > i && s[j - 1] == s[j] && i < j){
                j--;
                // cout<<"j: "<<j<<"\n";
            }
            
            i++;
            j--;
            
        }
        
        if(i > j){
            return 0; 
        }
        
        return (j - i + 1);
    }
};