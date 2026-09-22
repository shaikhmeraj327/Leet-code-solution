class Solution {
public:
    void solve(string &digits,string map[],string &output,vector<string>&ans,int ind){
        if(ind>=digits.size()){
            ans.push_back(output);
            return;
        }
        int num=digits[ind]-'0';
        string str=map[num];
        if(str.empty())solve(digits,map,output,ans,ind+1);
        for(int i=0;i<str.size();i++){
            output.push_back(str[i]);
            solve(digits,map,output,ans,ind+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output="";
        vector<string>ans;
        solve(digits,map,output,ans,0);
        return ans;
    }
};