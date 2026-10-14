class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)return "";
        int totalNine=sum/9;
        int rem=sum%9;
        int count=0;
        string ans="";
        // while(count<num){
        //     if(totalNine>0){
        //         ans.push_back('9');
        //         totalNine--;
        //     }
        //     else if(rem>0){
        //         ans.push_back('0'+rem);
        //         rem=0;
        //     }
        //     else ans.push_back('0');
        //     count++;
        // }
        ans.append(totalNine,'9');
        if(rem>0)ans.push_back('0'+rem);
        ans.append(num-ans.size(),'0');
        return ans;
    }
};