import java.util.*;
class Solution {
    public int myAtoi(String s) {
        int n=s.length();
        long ans=0;
        int sign=1;
        int i=0;
        while(i<n){
            if(s.charAt(i)==' ')i++;
            else break;
        }
        if(i<n && s.charAt(i)=='-'){
            sign=-1;
            i++;
        }
        else if(i<n && s.charAt(i)=='+')i++;

        while(i<n && s.charAt(i)>='0' && s.charAt(i)<='9'){
            if(s.charAt(i)=='0' && ans==0){
                i++;
                continue;
            }
            else{
                int dig=s.charAt(i)-'0';
                ans=ans*10+dig;
            }
            if(ans>Integer.MAX_VALUE && sign>0)return Integer.MAX_VALUE;
            if(ans>Integer.MAX_VALUE && sign<0)return Integer.MIN_VALUE;
            i++;
        }
        if(sign>0)return (int)ans;
        return (int)ans*(-1);
    }
}