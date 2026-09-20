class Solution {
    public
    long m=1000000007;
    public long power(long a,long b){
        if(b==0)return 1;
        long half=power(a,b/2);
        if(b%2==0)return half*half%m;
        return a*half*half%m;
    }
    public int countGoodNumbers(long n) {
        long even=power(5,(n+1)/2);
        long prime=power(4,n/2);
        return (int)(even*prime%m);
    }
}