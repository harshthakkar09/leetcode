class FoodRatings {
public:
    
    map<string, set<pair<int, string>>> cuisine_items;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            cuisine_items[cuisine].insert({-rating, food});
            food_cuisine[food] = cuisine;
            food_rating[food] = -rating;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int rating = food_rating[food];
        cuisine_items[cuisine].erase({rating, food});
        cuisine_items[cuisine].insert({-newRating, food});
        food_rating[food] = -newRating;
    }
    
    string highestRated(string cuisine) {
        pair<int, string> selected_food = *(cuisine_items[cuisine].begin());
        return selected_food.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */