class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        int ind=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(n%ind==0){
                sum+=nums[i]*nums[i];
            }
            ind++;
        }
        return sum;
    }
};