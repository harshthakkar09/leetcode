class NumberContainers {
public:
    map<int, set<int>> number_to_indices; 
    unordered_map<int, int> index_to_number;
    
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(index_to_number.find(index) == index_to_number.end()){
            index_to_number[index] = number;
            number_to_indices[number].insert(index);
        }
        else{
            int pre_number = index_to_number[index];
            number_to_indices[pre_number].erase(index);
            number_to_indices[number].insert(index);
            index_to_number[index] = number;
        }
    }
    
    int find(int number) {
        if(number_to_indices[number].size() != 0){
            return *(number_to_indices[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */