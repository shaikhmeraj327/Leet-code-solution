class Solution {
    public int majorityElement(int[] nums) {
        double ele=1e9;
        int n=nums.length;
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
                count++;
            }
            else if(ele!=nums[i]){
                count--;
            }
            else count++;
        }
        return (int)ele;
    }
}





// class Solution {
//     public int majorityElement(int[] nums) {
//         int n=nums.length;;
//         HashMap<Integer,Integer>map1=new HashMap<>();
//         for(int i=0;i<n;i++){
//             if(map1.containsKey(nums[i])){
//                 int count=map1.get(nums[i]);
//                 count++;
//                 map1.put(nums[i],count);
//             }
//             else map1.put(nums[i],1);
//         }
//         for(Map.Entry<Integer,Integer>entry:map1.entrySet()){
//             int key=entry.getKey();
//             int val=entry.getValue();
//             if(val>n/2)return key;
//         }
//          return -1;
//     }
// }