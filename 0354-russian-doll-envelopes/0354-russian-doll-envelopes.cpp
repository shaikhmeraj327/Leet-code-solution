class Solution {
public:
   bool static compare(vector<int>&a,vector<int>&b){
     if(a[0]==b[0])
       return a[1]>b[1]; 
    else return a[0]<b[0];
   }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int>ans;
        for(int i=0;i<envelopes.size();i++){
            if(ans.empty() || ans.back()<envelopes[i][1]){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int ind=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[ind]=envelopes[i][1];

            }
        }
        return ans.size();
    }
};