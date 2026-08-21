class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string ans="";
        priority_queue<pair<int,char>>pq;
        vector<int>freq(128,0);
        for(int i=0;i<n;i++){
            char ch=s[i];
            freq[ch]++;
        }
        for(int i=0;i<128;i++){
            int f=freq[i];
            if(f>0){
                char ch=(char)i;
                pq.push({f,ch});
            }
        }
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            char ch=temp.second;
            int f=temp.first;
            ans.append(f,ch);
        }
        return ans;
    }
};