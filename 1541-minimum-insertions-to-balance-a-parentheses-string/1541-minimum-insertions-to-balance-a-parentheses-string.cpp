class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int count=0;
        int res=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                count++;
            }
            else{
                if(count>0)count--;
                else res++;
                if(i+1<n && s[i+1]==')')i+=2;
                else {
                    res++;
                    i++;
                }
            }
        }
        return res+count*2;
    }
};