class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int n=s.size();
        int rightClose=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else {
                if(count>0)count--;
                else rightClose++;
            }
        }
        return rightClose+count;
    }
};