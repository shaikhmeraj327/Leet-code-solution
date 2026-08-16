class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
       int m=a.size();
        int n=b.size();
        if(m>n)return findMedianSortedArrays(b,a);
        int low=0,high=m;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=(m+n+1)/2-mid1;
            int x1=(mid1==0)?INT_MIN :a[mid1-1];
            int x2=(mid2==0)?INT_MIN :b[mid2-1];
            int x3=(mid1==m)?INT_MAX :a[mid1];
            int x4=(mid2==n)?INT_MAX :b[mid2];
            if(x1<=x4 && x2<=x3){
                if((m+n)%2==1)return max(x1,x2);
                else return (max(x1,x2)+min(x3,x4))/2.0;
            }
            else if(x1>x4)high=mid1-1;
            else low=mid1+1;
        }
        return -1; 
    }
};