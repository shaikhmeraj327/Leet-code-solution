class Solution {
public:
   
   int mergeRP(vector<int>& nums,int s,int e,int mid){
       int  j=mid+1;
       vector<int>temp;
       int count=0;
       for(int i=s;i<=mid;i++ ){
        while(j<=e &&((long long)nums[i])>2LL*nums[j]){
            j++;
          
        }
        count+=j-(mid+1);
       }
        int i=s;
        j=mid+1;
       while(i<=mid && j<=e){
         if(nums[i]<=nums[j])
            temp.push_back(nums[i++]);
         else{
            temp.push_back(nums[j++]);
         }
       }
       while(i<=mid)
         temp.push_back(nums[i++]);
       while(j<=e)
         temp.push_back(nums[j++]);
       for(int ind=0;ind<temp.size();ind++){
          nums[ind+s]=temp[ind];
       }
       return count;
   }

   int mergesortRP(vector<int>& nums,int s,int e){
      if(s>=e)
       return 0;
      int mid=s+(e-s)/2;
      int count=mergesortRP(nums,s,mid);
      count+=mergesortRP(nums,mid+1,e);
      count+=mergeRP(nums,s,e,mid);
      return count;
   }

    
    int reversePairs(vector<int>& nums) {
        int e=nums.size()-1;
        return mergesortRP(nums,0,e);
    }
};





// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//     int n=nums.size();
//     int count=0;
//     for(int i = 0; i < n-1; i++) {
//      long long x = nums[i];
//      for(int j = i + 1; j < n; j++) {
//         long long y = 2 * nums[j];
//         if(x > y)
//             count++;
//      }
//     }
//     return count;
  
//     }
// };