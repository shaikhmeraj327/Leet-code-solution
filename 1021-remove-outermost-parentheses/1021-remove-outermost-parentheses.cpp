class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(count>0)ans.push_back('(');
                count++;
            }
            else{
                count--;
                if(count>0)ans.push_back(')');
            }
        }
        return ans;
        
    }
};