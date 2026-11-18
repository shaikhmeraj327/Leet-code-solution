class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string &s,int ind,vector<string>&output,vector<vector<string>>&ans){
        if(ind>=s.size()){
            if(!output.empty())ans.push_back(output);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                output.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,output,ans);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>output;
        vector<vector<string>>ans;
        int ind=0;
        solve(s,ind,output,ans);
        return ans;
    }
};