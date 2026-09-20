class Solution {
public:
    int m=1e9+7;
    long long power(long long a,long long b ){
        if(b==0)return 1;
        long long half=power(a,b/2);
        if(b%2==1)return a*half*half%m;
        return half*half%m;
    }

    int countGoodNumbers(long long n) {
        long long even=power(5,(n+1)/2);
        long long odd=power(4,n/2);
        return even * odd%m;
    }
};