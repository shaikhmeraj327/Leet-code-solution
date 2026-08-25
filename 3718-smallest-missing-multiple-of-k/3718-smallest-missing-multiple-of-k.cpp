class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>set(nums.begin(),nums.end());
        int num=k;
        while(true){
            if(!set.contains(k))return k;
            else k+=num;
        }
        return -1;
    }
};