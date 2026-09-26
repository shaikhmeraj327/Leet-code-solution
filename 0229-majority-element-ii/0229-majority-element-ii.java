class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int ele1=Integer.MAX_VALUE;
        int ele2=Integer.MAX_VALUE;
        int count1=0,count2=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]){
                count1++;
            }
            else if(ele2==nums[i]){
                count2++;
            }
            else if(count1==0){
                ele1=nums[i];
                count1++;
            }
            else if(count2==0){
                ele2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i])count1++;
            else if(ele2==nums[i])count2++;
        }
        List<Integer>ans=new ArrayList<>();
        if(count1>n/3)ans.add(ele1);
        if(count2>n/3)ans.add(ele2);
        Collections.sort(ans);
        return ans;
    }
}






// class Solution {
//     public List<Integer> majorityElement(int[] nums) {
//         int n=nums.length;
//         HashMap<Integer,Integer>map=new HashMap<>();
//         for(int i=0;i<n;i++){
//             if(map.containsKey(nums[i])){
//                 int count=map.get(nums[i]);
//                 map.put(nums[i],count+1);
//             }
//             else map.put(nums[i],1);
//         }
//         List<Integer> ans=new ArrayList<>();
//         for(Map.Entry<Integer,Integer>entry:map.entrySet()){
//             int key=entry.getKey();
//             int val=entry.getValue();
//             if(val>n/3){
//                 ans.add(key);
//             }

//         }
//         return ans;

//     }
// }