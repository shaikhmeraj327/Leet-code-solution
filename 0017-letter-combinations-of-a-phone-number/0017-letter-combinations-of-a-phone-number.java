class Solution {
    public void solve(String digits,String[] map,StringBuilder output,List<String>ans,int ind){
        if(ind>=digits.length()){
            ans.add(output.toString());
            return;
        }
        int num=digits.charAt(ind)-'0';
        if(map[num].isEmpty())solve(digits,map,output,ans,ind+1);
        String str=map[num];
        for(int i=0;i<str.length();i++){
            output.append(str.charAt(i));
            solve(digits,map,output,ans,ind+1);
            output.deleteCharAt(output.length()-1);
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String>ans=new ArrayList<>();
        StringBuilder output=new StringBuilder();
        String[] map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,map,output,ans,0);
        return ans;
    }
}