class MinStack {
public:
    stack<int>st,minst;
  
    MinStack() {
        
    }
    
    void push(int value) {
        if(minst.empty()){
            minst.push(value);
        }
        else  if(value<=minst.top()){
            minst.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(st.empty())return;
        int top=st.top();
        st.pop();
        if(minst.top()>=top){
            minst.pop();
        }
    }
    
    int top() {
        if(st.empty())return -1;
        return st.top();
    }
    
    int getMin() {
        if(minst.empty())return -1;
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */