import java.util.*;
class Solution {
   public List<Integer> solve(int row){
       List<Integer>ans=new ArrayList<>();
       int temp=1;
       ans.add(temp);
       for(int col=1;col<row;col++){
           temp=temp*(row-col)/col;
           ans.add(temp);
       }
       return ans;
   }

    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>>ans=new ArrayList<>();
        for(int row=1;row<=numRows;row++){
            ans.add(solve(row));
        }
        return ans;
    }
}