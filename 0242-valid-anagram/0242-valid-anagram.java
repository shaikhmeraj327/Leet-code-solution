class Solution {
    public boolean isAnagram(String s, String t) {
        int[] count1=new int[26];
        int[] count2=new int[26];
        int m=s.length();
        int n=t.length();
        if(m!=n)return false;
        for(int i=0;i<n;i++){
            count1[s.charAt(i)-'a']++;
            count2[t.charAt(i)-'a']++;
        }
        // if(count1==count2)return true;
        // if(count1.equals(count2))return true;
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i])return false;
        }
        // return false;
        return true;
    }
}