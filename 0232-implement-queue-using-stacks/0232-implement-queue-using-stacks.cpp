class MyQueue {
public:
    
    stack<int> inp, oup;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(!oup.empty()){
            int val = oup.top();
            oup.pop();
            return val;
        }
        else{
            while(!inp.empty()){
                int val = inp.top();
                inp.pop();
                oup.push(val);
            }
            int val = oup.top();
            oup.pop();
            return val;
        }
    }
    
    int peek() {
        if(!oup.empty()){
            return oup.top();
        }
        else{
            while(!inp.empty()){
                int val = inp.top();
                inp.pop();
                oup.push(val);
            }
            return oup.top();
        }
    }
    
    bool empty() {
        return inp.empty() && oup.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */