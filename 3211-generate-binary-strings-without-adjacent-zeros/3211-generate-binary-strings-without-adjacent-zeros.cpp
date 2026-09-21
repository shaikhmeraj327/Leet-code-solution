class Solution {
public:
    void solve(int n,string &output,vector<string>&ans,int ind){
        if(ind>=n){
            ans.push_back(output);
            return;
        }
        if(output.empty() || output.back()!='0'){
            output.push_back('0');
            solve(n,output,ans,ind+1);
            output.pop_back();
        }
        output.push_back('1');
        solve(n,output,ans,ind+1);
        output.pop_back();

    }

    vector<string> validStrings(int n) {
        string output="";
        vector<string>ans;
        solve(n,output,ans,0);
        return ans;
    }
};