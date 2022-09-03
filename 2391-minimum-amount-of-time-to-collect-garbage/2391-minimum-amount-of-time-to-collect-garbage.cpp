class Solution {
public:
    
    void count(int& garbage, int& paper, int& meal,string& s){
        for(auto c: s){
            if(c == 'G'){
                garbage++;
            }
            else if(c == 'P'){
                paper++;
            }
            else{
                meal++;
            }
        }
    }
    
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(), lastGarbage = -1, lastPaper = -1, lastMeal = -1, ans = 0;
        vector<int> garbageCnt(n, 0);
        vector<int> paperCnt(n, 0);
        vector<int> mealCnt(n, 0);
        for(int i = 0; i < n; i++){
            int gar = 0, paper = 0, meal = 0;
            count(gar, paper, meal, garbage[i]);
            if(gar > 0){
                lastGarbage = i;
            }
            if(paper > 0){
                lastPaper = i;
            }
            if(meal > 0){
                lastMeal = i;
            }
            garbageCnt[i] = gar;
            paperCnt[i] = paper;
            mealCnt[i] = meal;
        }
        for(int i = 0; i < min(n, lastGarbage); i++){
            ans += garbageCnt[i];
            ans += travel[i];
        }
        if(lastGarbage >=  0){
            ans += garbageCnt[lastGarbage];    
        }
        for(int i = 0; i < min(n, lastPaper); i++){
            ans += paperCnt[i];
            ans += travel[i];
        }
        if(lastPaper >=  0){
            ans += paperCnt[lastPaper];    
        }
        for(int i = 0; i < min(n, lastMeal); i++){
            ans += mealCnt[i];
            ans += travel[i];
        }
        if(lastMeal >= 0){
            ans += mealCnt[lastMeal];    
        }
        return ans;
    }
};