class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int i=n-1;
        while(i>=0){
             if((num[i]-'0')%2==0)i--;
             else break;
        }
        if(i<0)return "";
        return num.substr(0,i+1);
    }
};