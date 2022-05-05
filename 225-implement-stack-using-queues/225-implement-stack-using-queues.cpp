class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            int f=q1.front();
            q1.pop();
            q2.push(f);
        }
        while(!q2.empty()){
            int f=q2.front();
            q2.pop();
            q1.push(f);
        }
        int val=q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        while(q1.size()>1){
            int f=q1.front();
            q1.pop();
            q2.push(f);
        }
        while(!q2.empty()){
            int f=q2.front();
            q2.pop();
            q1.push(f);
        }
        int val=q1.front();
        q1.pop();
        q1.push(val);
        return val;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */