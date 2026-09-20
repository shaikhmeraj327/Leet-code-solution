class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        long long ans=0;
        while(i<n){
            if(s[i]==' ')i++;
            else break;
        }
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+')i++;
        while(i<n && s[i]>='0' && s[i]<='9'){
            if(s[i]==0){
                i++;
                continue;
            }
            else{
                int dig=s[i]-'0';
                ans=ans*10+dig;
            }
            if(ans>INT_MAX && sign==1)return INT_MAX;
            if(ans>INT_MAX && sign<0)return INT_MIN;
            i++;
        }
        if(sign>0)return ans;
        return sign*ans;
    }
};