class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long prod=1;
        int temp=n;
        while(n>0){
            long long dig=n%10;
            n=n/10;
            sum+=dig;
            prod*=dig;
        }
        long long res=sum+prod;
        return temp%res==0;
    }
};