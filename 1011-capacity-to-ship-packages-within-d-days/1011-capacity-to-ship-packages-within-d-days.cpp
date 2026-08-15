class Solution {
public:
    bool isPossible(vector<int>& weights,int mid,int days){
        int n=weights.size();
        int day=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(mid<weights[i])return false;
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }
            else{
                day++;
                if(day>days)return false;
                sum=weights[i];
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=0;
        int high=0;
        for(int w:weights)high+=w;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return  ans;
    }
};