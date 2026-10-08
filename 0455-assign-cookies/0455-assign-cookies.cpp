class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;int j=0;
        while(i<m && j<n){
            if(s[j]>=g[i]){
                i++;
                j++;
                count++;
            }
            else j++;
        }
        return count;
    }
};