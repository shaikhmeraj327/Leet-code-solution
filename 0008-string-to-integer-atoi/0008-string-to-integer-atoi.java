class Solution {
    public int myAtoi(String s) {
        int n=s.length();
        long ans=0;
        if(n==0)return 0;
        int i=0;
        while(i<n && s.charAt(i)==' '){
            i++;
        }
        int sign=1;
        if(i<n && s.charAt(i)=='-'){
            sign=-1;
            i++;
        }
        else if(i<n &&  s.charAt(i)=='+')i++;
        while(i<n && s.charAt(i)>='0' && s.charAt(i)<='9'){
            if(ans==0 && s.charAt(i)=='0'){
                i++;
                continue;
            }
            else{
                ans=ans*10+s.charAt(i)-'0';
            }
            if(ans>Integer.MAX_VALUE && sign==1)return Integer.MAX_VALUE;
            if(ans>Integer.MAX_VALUE && sign==-1)return Integer.MIN_VALUE;
            i++;
        }
        if(sign==-1)return -(int)ans;
        return (int) ans;
        
    }
}