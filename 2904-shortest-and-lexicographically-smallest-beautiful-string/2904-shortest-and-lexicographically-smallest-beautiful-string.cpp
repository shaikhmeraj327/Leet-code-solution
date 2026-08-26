class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int n=s.size();
        int left=0;
        int minLen=INT_MAX;
        int count=0;
        for(int right=0;right<n;right++){
            if(s[right]=='1')count++;
            while(left<=right && count>=k){
                if(count==k){
                    int len=right-left+1;
                    string temp=s.substr(left,len);
                    if(minLen>=len){
                        if(minLen>len){
                            ans=temp;
                        }
                        else{
                            if(ans.empty())ans=temp;
                            else if(temp<ans)ans=temp;
                        }
                        minLen=len;
                    }
                }
                if(s[left]=='1')count--;
                left++;
            }
        }
        return ans;
    }
};