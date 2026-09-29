class Solution {
    public int numberOfSubstrings(String s) {
        int[] freq=new int[3];
        int dist=0;
        int count=0;
        int left=0;
        int n=s.length();
        for(int right=0;right<n;right++){
            if(freq[s.charAt(right)-'a']==0)dist++;
            freq[s.charAt(right)-'a']++;
            while(left<=right && dist==3){
                freq[s.charAt(left)-'a']--;
                if(freq[s.charAt(left)-'a']==0)dist--;
                left++;
                count+=n-right;
            }
        }
        return count;
    }
}