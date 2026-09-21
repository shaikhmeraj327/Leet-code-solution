class Solution {
public:
    void solve(int n,int open,int close,string &output,vector<string>&ans,int ind){
        if(ind>=2*n){
            ans.push_back(output);
            return;
        }
        if(open<n){
            output.push_back('(');
            solve(n,open+1,close,output,ans,ind+1);
            output.pop_back();
        }
        if(close<open){
            output.push_back(')');
            solve(n,open,close+1,output,ans,ind+1);
            output.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string output="";
        vector<string>ans;
        solve(n,open,close,output,ans,0);
        return ans;
    }
};