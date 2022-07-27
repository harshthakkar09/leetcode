class Solution {
public:
    
    bool checkThreeOfKind(vector<int>& ranks){
        unordered_map<int,int> fre;
        for(auto rank: ranks){
            fre[rank]++;
        }
        for(auto it: fre){
            if(it.second >= 3){
                return true;
            }
        }
        return false;
    }
    
    bool checkPair(vector<int>& ranks){
        unordered_map<int,int> fre;
        for(auto rank: ranks){
            fre[rank]++;
        }
        for(auto it: fre){
            if(it.second == 2){
                return true;
            }
        }
        return false;
    }
    
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4]){
            return "Flush";
        }
        else if(checkThreeOfKind(ranks)){
            return "Three of a Kind";
        }
        else if(checkPair(ranks)){
            return "Pair";
        }
        else{
            return "High Card";
        }
    }
};