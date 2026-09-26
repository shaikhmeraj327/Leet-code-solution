class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int count=0;
        int n=nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           if(sum==k)count++;
           int rem=sum-k;
           if(map.containsKey(rem)){
              count+=map.get(rem);
           } 
           if(map.containsKey(sum)){
              int val=map.get(sum);
              map.put(sum,val+1);
           }
           else map.put(sum,1);
        }
        return count;
    }
}




// class Solution {
//     public int subarraySum(int[] nums, int k) {
//         int count=0;
//         int m=nums.length;
//         for(int i=0;i<m;i++){
//             int sum=0;
//             for(int j=i;j<m;j++){
//                 sum+=nums[j];
//                 if(sum==k)count++;
//             }
//         }
//         return count;
//     }
// }