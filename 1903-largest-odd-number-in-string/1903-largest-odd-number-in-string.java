class Solution {
    public String largestOddNumber(String num) {
        StringBuilder sb=new StringBuilder(num);
        int n=sb.length();
        int i=n-1;
        while(i>=0){
            if((sb.charAt(i)-'0')%2==1){
                return sb.substring(0,i+1);
            }
            i--;
        }
        return "";
    }
}