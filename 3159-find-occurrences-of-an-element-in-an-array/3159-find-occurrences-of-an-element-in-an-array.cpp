class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,int>freq;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num==x){
                count++;
                freq[count]=i;
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int f=queries[i];
            if(freq.find(f)!=freq.end()){
                ans.push_back(freq[f]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};