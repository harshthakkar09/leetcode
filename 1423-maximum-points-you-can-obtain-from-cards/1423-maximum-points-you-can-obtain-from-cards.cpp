class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int sum=0,windowSum=0,n=cards.size(),windowSize=n-k,minSum=INT_MAX;
        for(int i=0;i<n;i++){
            if(i<windowSize){
                windowSum+=cards[i];
            }
            sum+=cards[i];
        }
        minSum=min(minSum,windowSum);
        for(int i=windowSize;i<n;i++){
            windowSum+=cards[i];
            windowSum-=cards[i-windowSize];
            minSum=min(windowSum,minSum);
        }
        if(minSum==INT_MAX){
            return sum;
        }
        return (sum-minSum);
    }
};