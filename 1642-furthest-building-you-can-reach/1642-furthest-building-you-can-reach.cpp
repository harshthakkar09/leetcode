class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int> pq;
        int i=0;
        for(;i<n-1;i++){
            int d=heights[i+1]-heights[i];
            if(d>0){
                if(bricks>=d){
                    bricks-=d;
                    pq.push(d);
                }
                else if(ladders>0){       
                    if(pq.size()){
                        int t=pq.top();
                        if(t>d){
                            bricks+=t;
                            pq.pop();
                            pq.push(d);
                            bricks-=d;
                        }   
                    }
                    ladders--; 
                }
                else{
                    break;
                }
            }
        }
        return i;
    }
};