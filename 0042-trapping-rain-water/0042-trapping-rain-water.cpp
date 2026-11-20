class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lM(n);
        vector<int>rM(n);
        int maxi=height[n-1];
        for(int i=n-1;i>=0;i--){
            maxi=max(height[i],maxi);
            rM[i]=maxi;
        }
        maxi=height[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            lM[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(lM[i],rM[i])-height[i];
        }
        return ans;
    }
};