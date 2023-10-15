class MinStack {
public:
    int arr[30001][2];
    int tp;
    int mini;
    MinStack() {
        tp = -1;
        mini = INT_MAX;
        
    }
    
    void push(int val) {
        tp++;
        if(tp!=0)mini = min(arr[tp-1][1],val);
        else mini = val;
        //arr.push_back({val,mini});
        arr[tp][0] = val;
        arr[tp][1]= mini;
       
    }
    
    void pop() {
        tp--;
    }
    
    int top() {
        return arr[tp][0];
    }
    
    int getMin() {
        return arr[tp][1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */