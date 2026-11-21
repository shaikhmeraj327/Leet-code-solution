class StockSpanner {
public:
    stack<pair<int,int>>st;// price and its index

    StockSpanner() {
        
    }
    
    int next(int price) {
        int spane=1;
        while(!st.empty() && price>=st.top().first){
             spane=spane+st.top().second;
             st.pop();
        }
        st.push({price,spane});
        return spane;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */