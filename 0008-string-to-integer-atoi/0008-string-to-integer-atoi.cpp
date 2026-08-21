class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long long ans=0;
        int i=0;
        while(i<n && s[i]==' ')i++;
        int sign=1;
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+')i++;
        while(i<n && s[i]>='0' && s[i]<='9'){
            if(s[i]=='0')continue;
            int dig=s[i]-'0';
            ans=ans*10+dig;
            if(sign>0 && ans>INT_MAX)return INT_MAX;
            if(sign<0 && sign*ans<INT_MIN)return INT_MIN;
            i++;
        }
        if(sign>0)return ans;
        return ans*sign;
    }
};