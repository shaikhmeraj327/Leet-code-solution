class Solution {
public:
    int maxArea(vector<int>& height) {
         int left=0;
         int n=height.size();
         int right=n-1;
         int maxi=0;
         while(left<right){
             maxi=max(maxi,((right-left)*min(height[left],height[right])));
             if(height[left]>height[right])right--;
             else left++;
         }  
         return maxi;
    }
};