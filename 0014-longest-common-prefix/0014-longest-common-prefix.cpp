class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            int j=0;
            while(j<ans.size() && j<strs[i].size() && strs[i][j]==ans[j])j++;
            if(j==0)return "";
            // ans=ans.substr(0,j); Time o(n.M)
            ans.resize(j);
        }
        return ans;
    }
};