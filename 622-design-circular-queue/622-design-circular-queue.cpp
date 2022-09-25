class MyCircularQueue {
public:
    vector<int> v;
    int n, front = -1, rear = -1;
    
    MyCircularQueue(int k) {
        n = k;
        for(int i = 0; i < n; i++){
            v.push_back(-1);
        }
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            if(isEmpty()){
                front++;
            }
            rear = (rear + 1) % n;
            v[rear] = value;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % n;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return v[front];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return v[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return front == ((rear + 1) % n);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */