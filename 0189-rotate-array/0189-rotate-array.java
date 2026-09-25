class Solution {
    public void reverse(int[] nums,int i,int j){
        while(i<j){
            // swap(nums[i],nums[j]);
            int temp=nums[j];
            nums[j]=nums[i];
            nums[i]=temp;
            i++;
            j--;
        }
    }

    public void rotate(int[] nums, int k) {
        int n=nums.length;
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
}





// class Solution {
//     public void rotate(int[] nums, int k) {
//         int n=nums.length;
//         int [] ans=new int[n];
//         for(int i=0;i<n;i++){
//             ans[(i+k)%n]=nums[i];
//         }
//         for(int i=0;i<n;i++){
//             nums[i]=ans[i];
//         }
//     }
// }