class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        set.insert(nums.begin(),nums.end());
        int n=nums.size();
        int maxCount=0;
        for(int ele:set){
            // int ele=nums[i];
            int count=1;
            if(set.find(ele-1)==set.end()){
                while(set.find(ele+1)!=set.end()){
                    ele++;
                    count++;
                }
            }
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};