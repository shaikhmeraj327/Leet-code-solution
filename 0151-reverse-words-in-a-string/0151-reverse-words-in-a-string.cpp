class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        if(n==0)return ans;
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!=' '){
                word.push_back(s[i++]);
            }
            if(!word.empty()){
                reverse(word.begin(),word.end());
                ans+=' '+word;
            }
        }
        return ans.substr(1);
    }
};