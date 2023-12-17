typedef pair<int, string> pis;

class Compare {
    public:
       bool operator()(pis a, pis b){
           if(a.first == b.first){
               return a.second > b.second;
           }
           else{
               return a.first < b.first;
           }
      }
};

class FoodRatings {
public:
    
    unordered_map<string, int> foodToRating;
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, priority_queue<pis, vector<pis>, Compare>> cuisineToFoodRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i < n; i++){
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            foodToRating[food] = rating;
            foodToCuisine[food] = cuisine;
            cuisineToFoodRating[cuisine].push({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodToRating[food] = newRating;
        string cuisine = foodToCuisine[food];
        cuisineToFoodRating[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto highRatedFood = cuisineToFoodRating[cuisine].top();
        
        while(foodToRating[highRatedFood.second] != highRatedFood.first){
            cuisineToFoodRating[cuisine].pop();
            highRatedFood = cuisineToFoodRating[cuisine].top();
        }
        
        return highRatedFood.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */