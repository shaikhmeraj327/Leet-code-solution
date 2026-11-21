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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0 || n==0)return 0;
        int ans=0;
        vector<int>heights(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                heights[j]=(matrix[i][j]=='1')? heights[j]+1:0;
            }
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};