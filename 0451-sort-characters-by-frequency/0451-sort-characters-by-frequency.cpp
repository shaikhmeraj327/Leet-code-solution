class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(256,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<256;i++){
            if(freq[i]>0)pq.push({freq[i],char(i)});
        }
        string ans;
        while(!pq.empty()){
            ans.append(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};