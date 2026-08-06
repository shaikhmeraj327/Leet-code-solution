class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        int ans=n;
        
        while(true){
            int prod=1;
            ans=num;
            while(num>0){
                prod=prod*(num%10);
                num=num/10;
            }
            if(prod%t==0){
                return ans;
            }
            num=ans+1;
        }
        return ans;
    }
};