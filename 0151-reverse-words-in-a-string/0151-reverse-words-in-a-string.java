class Solution {
    public String reverseWords(String s) {
        int  n=s.length();
        if(n==0)return s;
        StringBuilder sb=new StringBuilder(s);
        sb.reverse();
        StringBuilder ans=new StringBuilder();
        for(int i=0;i<n;i++){
            StringBuilder word=new StringBuilder();
            while(i<n && sb.charAt(i)!=' '){
                word.append(sb.charAt(i));
                i++;
            }
            if(!word.isEmpty()){
                word.reverse();
                ans.append(' ');
                ans.append(word);
            }
        }
        if(ans.length()==0)return "";
        // String res=ans.toString();
        // if(res.length()==0 ||res.length()==1 )return "";
        return ans.substring(1);
    }
}