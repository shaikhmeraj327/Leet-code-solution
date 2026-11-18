class Solution {
public:
    void solve(int n,int ind,int open,int close,string &output,vector<string>&ans){
        if(ind>=2*n){
           ans.push_back(output);
           return;
        }
        if(open<n){
            output.push_back('(');
            solve(n,ind+1,open+1,close,output,ans);
            output.pop_back();
        }
        if(close<open){
            output.push_back(')');
            solve(n,ind+1,open,close+1,output,ans);
            output.pop_back();
        }  
    }

    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string output="";
        vector<string>ans;
        solve(n,0,open,close,output,ans);;
        return ans;
    }
};