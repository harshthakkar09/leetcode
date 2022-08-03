class MyCalendar {
public:
    vector<pair<int, int>> selected;
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(auto it: selected){
            if(start >= it.second){
                continue;
            }
            if(end <= it.first){
                continue;
            }
            return false;
        }
        selected.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */