class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans=strs[0];
       for(int i=1;i<strs.size();i++){
        int j=0;
        while(j<strs[i].length()&&j<ans.length()&&ans[j]==strs[i][j]){
            j++;
        }
        ans=ans.substr(0,j);
        if(ans.empty())
            return ans;
       } 
       return ans;
        
    }
};