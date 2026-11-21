class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nSi(n,n);
        vector<int>pSi(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()])st.pop();
            if(!st.empty())nSi[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i])st.pop();
            if(!st.empty())pSi[i]=st.top();
            st.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int val=heights[i]*(nSi[i]-pSi[i]-1);
            maxi=max(maxi,val);
        }
        return maxi;
    }
};