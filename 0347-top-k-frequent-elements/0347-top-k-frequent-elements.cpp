class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto p:freq){
            int f=p.second;
            int num=p.first;
            if(k>0)pq.push({f,num});
            else{
                if(pq.top().first<f){
                    pq.pop();
                    pq.push({f,num});
                }
            }
            k--;
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};