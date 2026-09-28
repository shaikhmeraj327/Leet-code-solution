class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n=strs.length;
        String s=strs[0];
        for(int i=1;i<n;i++){
            int j=0;
            while(j<s.length() && j<strs[i].length() && s.charAt(j)==strs[i].charAt(j))j++;
            if(j==0)return "";
            s=s.substring(0,j);
        }
        return s;
    }
}