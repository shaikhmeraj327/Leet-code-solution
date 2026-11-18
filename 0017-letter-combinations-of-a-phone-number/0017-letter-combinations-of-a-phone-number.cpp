class Solution {
public:
    void solve(string &digits,string map[],int ind,string &output,vector<string>&ans){
        if(ind>=digits.size()){
            ans.push_back(output);
            return;
        }
        int dig=digits[ind]-'0';
        string val=map[dig];
        if(val.empty())solve(digits,map,ind+1,output,ans);
        for(int i=0;i<val.size();i++){
            output.push_back(val[i]);
            solve(digits,map,ind+1,output,ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int ind=0;
        string output="";
        vector<string>ans;
        solve(digits,map,ind,output,ans);
        return ans;
    }
};