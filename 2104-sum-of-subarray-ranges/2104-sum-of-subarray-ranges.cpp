using namespace std;
#include<bits/stdc++.h>

class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int n=arr.size();
        vector<int>nSi(n,n);
        vector<int>pSi(n,-1);
        vector<int>nLi(n,n);
        vector<int>pLi(n,-1);
        stack<int>st;
        // next larger element
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>=arr[st.top()])st.pop();
            if(!st.empty())nLi[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        // previous largest element index
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()])st.pop();
            if(!st.empty())pLi[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        // next smallest element index.
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
            if(!st.empty())nSi[i]=st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        // previous smallest element index
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()])st.pop();
            if(!st.empty())pSi[i]=st.top();
            st.push(i);
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long l1=i-pSi[i];
            long long r1=nSi[i]-i;
            long long mini=1LL*l1*r1*arr[i];
            long long l2=i-pLi[i];
            long long r2=nLi[i]-i;
            long long maxi=1LL*l2*r2*arr[i];
            sum+=maxi-mini; 
        }
        return sum;
    }
};









