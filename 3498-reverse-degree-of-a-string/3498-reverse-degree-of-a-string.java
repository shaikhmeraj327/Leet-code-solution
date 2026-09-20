class Solution {
    public int reverseDegree(String s) {
        int n=s.length();
        int sum=0;
        int pos=1;
        for(int i=0;i<n;i++){
            int num=26-(s.charAt(i)-'a');
            sum+=(num*pos);
            pos++;
        }
        return sum;
    }
}