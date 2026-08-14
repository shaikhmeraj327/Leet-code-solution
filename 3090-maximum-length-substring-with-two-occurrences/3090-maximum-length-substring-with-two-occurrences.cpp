class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int left=0;int maxLen=0;
        int mxFeq=0;
        vector<int>freq(26,0);
        for(int right=0;right<n;right++){
            freq[s[right]-'a']++;
            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};