class Solution {
    public String removeOuterParentheses(String s) {
        int count=0;
        int n=s.length();
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='('){
                if(count>0)sb.append('(');
                count++;
                
            }
            else{
                count--;
                if(count>0)sb.append(')');
            }
        }
        return sb.toString();
    }
}