class Solution {
    public boolean rotateString(String s, String goal) {
        int n=s.length();
        int m=goal.length();
        if(m!=n)return false;
        s=s+s;
        // for(int i=0;i<n;i++){
            // if(s.substr(i,m+i).equalsto(goal))return true;
            if(s.contains(goal))return true;
        // }
        return false;
    }
}