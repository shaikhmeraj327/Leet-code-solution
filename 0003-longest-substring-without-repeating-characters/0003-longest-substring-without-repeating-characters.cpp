class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,0);
        int left=0;
        int maxLen=0;
        int n=s.size();
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            while(left<right && freq[s[right]]>1){
                freq[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};