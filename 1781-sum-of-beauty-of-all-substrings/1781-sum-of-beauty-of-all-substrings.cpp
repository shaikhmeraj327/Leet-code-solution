class Solution {
public:
    int beautySum(string s) {
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int maxFreq=0;
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                maxFreq=max(maxFreq,freq[s[j]-'a']);
                int minFreq=n;
                for(int k=0;k<26;k++){
                    if(freq[k]>0)minFreq=min(minFreq,freq[k]);
                }
                count+=maxFreq-minFreq;
            }
        }
        return count;
    }
};