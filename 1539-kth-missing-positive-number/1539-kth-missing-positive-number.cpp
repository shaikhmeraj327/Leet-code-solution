class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=1;
        int index=0;
        int n=arr.size();
        while(index<n && k>0){
            if(arr[index]==count)index++;
            else{
                k--;
                if(k==0)return count;
            }
            count++;
        }
        while(k>1){
            count++;
            k--;
        }
        return count;
    }
};