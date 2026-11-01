class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==0 || n==1)return {0};
        int num=n/2;
        num=-num;
        vector<int>ans;
        if(n%2==0){
            for(int i=0;i<n;i++){
                if(num==0){
                    ans.push_back(num+1);
                    num++;
                }
                else ans.push_back(num);
                num++;
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(num);
                num++;
            }
        }
        return ans;      
    }
};