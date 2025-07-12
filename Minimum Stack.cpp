// class MinStack {
//     stack<long> st;
//     long min=0;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.empty()){
//             st.push(0);
//             min=val;
//         }
//         else{
//             st.push(val-min);
//             if(min>val){
//                 min=val;
//             }
//         }
//     }
    
//     void pop() {
//         long pop=st.top();
//         st.pop();
//         if(pop<0){
//             min-=pop;
//         }
//     }
    
//     int top() {
//         if(st.top()>=0)
//         return st.top()+min;
//         return min;
//     }
    
//     int getMin() {
//         return min;
//     }
// };

class MinStack {
    stack<int> st,min;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.empty() || min.top()>=val){
            min.push(val);
        }
        else{
            min.push(min.top());
        }
    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
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