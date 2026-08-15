class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int mid,int m,int k){
        int total=0;
        int n=bloomDay.size();
        int adj=0;
        for(int i=0;i<n;i++){
            // if(mid<bloomDay[i])return false;
            if(bloomDay[i]<=mid){
                adj++;
                if(adj==k){
                    total++;
                    if(total==m)return true;
                    adj=0;
                }
            }
            else adj=0;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(1LL*m*k>n)return -1;
        int low=0;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};