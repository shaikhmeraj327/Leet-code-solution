class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        long long ans=0;
        int i=0;
        while(i<n){
            if(s[i]==' ')i++;
            else break;
        }
        int sign=1;
        if(i<n && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s[i]=='+')i++;
        while(i<n && s[i]>='0' && s[i]<='9'){
            if(s[i]=='0' && ans==0){
                i++;
                continue;
            }
            ans=ans*10+(s[i]-'0');
            if(ans>INT_MAX && sign>0)return INT_MAX;
            if(ans>INT_MAX && sign<0)return INT_MIN;
            i++;
        }
     
        if(sign<0)return -1*ans;
        return ans;
    }
};