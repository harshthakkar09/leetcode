class Solution {
public:
    
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxes, int truck) {
        int n=boxes.size(),ans=0,i=0;
        sort(boxes.begin(),boxes.end(),cmp);
        while(i<n && truck){
            int selected=min(truck,boxes[i][0]);
            ans+=(selected*boxes[i][1]);
            truck-=selected;
            i++;
        }
        return ans;
    }
};