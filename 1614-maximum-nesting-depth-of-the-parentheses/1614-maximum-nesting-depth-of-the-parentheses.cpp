class Solution {
public:
    int maxDepth(string s) {
        int maxCount=0;
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
                maxCount=max(maxCount,count);
            }
            else if(s[i]==')')count--;
        }
        return maxCount;
    }
};