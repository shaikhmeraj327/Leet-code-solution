class Solution {
    public void nextPermutation(int[] nums) {
        int n=nums.length;
        if(n==1)return;
        int j=n-2;
        while(j>=0 && nums[j]>=nums[j+1])j--;
        if(j==-1){
            int s=0,e=n-1;
            while(s<e){
                int temp=nums[s];
                nums[s]=nums[e];
                nums[e]=temp;
                s++;
                e--;
            }
            return;
        }

        // case when j>=0;
        int i=n-1;
        while(i>j && nums[j]>=nums[i])i--;
        int temp1=nums[i];
        nums[i]=nums[j];
        nums[j]=temp1;
        int s=j+1;
        int e=n-1;
        while(s<e){
            int temp=nums[s];
            nums[s]=nums[e];
            nums[e]=temp;
            s++;
            e--;
       }


    }
}