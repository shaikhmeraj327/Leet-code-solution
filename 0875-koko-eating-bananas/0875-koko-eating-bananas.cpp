class Solution {
public:
    bool isPossible(vector<int>& piles,int mid,int h){
        int totalHour=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            int a=piles[i]/mid;
            int b=piles[i]%mid;
            totalHour+=a;
            if(b>0)totalHour++;
            if(totalHour>h)return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};