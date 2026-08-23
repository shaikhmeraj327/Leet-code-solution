class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        double long leftSum=0;
        double long rightSum=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?')leftSum+=4.5;
            else leftSum+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?')rightSum+=4.5;
            else rightSum+=num[i]-'0';
        }
        return leftSum!=rightSum;
    }
};