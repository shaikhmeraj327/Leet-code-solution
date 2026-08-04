class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=i+1;
        while(j<n){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i++],nums[j++]);
            }
            else if(nums[i]==0 && nums[j]==0)j++;
            else{
                i++;
                j++;
            }
        }
    }
};




// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
        
//         int n=nums.size();
        
//         int index=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]!=0)nums[index++]=nums[i];
//         }
//         while(index<n)nums[index++]=0;
//     }
// };