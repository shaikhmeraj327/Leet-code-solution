class Solution {
    public int[] searchRange(int[] nums, int target) {
       int first=-1;
       int second=-1;
       int s=0;
       int n=nums.length;
       int e=n-1;
       while(s<=e){
          int mid=s+(e-s)/2;
          if(nums[mid]==target){
             first=mid;
             e=mid-1;
          }
          else if(nums[mid]>target){
            e=mid-1;
          }
          else s=mid+1;
       } 
       s=0;
       e=n-1;
       while(s<=e){
          int mid=s+(e-s)/2;
          if(nums[mid]==target){
             second=mid;
             s=mid+1;
          }
          else if(nums[mid]>target){
            e=mid-1;
          }
          else s=mid+1;
       }
       int[] ans=new int[2];
    //    if(first==-1 || last==-1){
          ans[0]=first;
          ans[1]=second;
          return ans;
    //    }

    }
}