class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int>freq;
        for(char ch:t)freq[ch]++;
        int count=t.size();
        int start=0;
        int maxWind=1e9;
        int left=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            if(freq[ch]>0)count--;
            freq[ch]--;
            while(count==0 && left<=right){
                freq[s[left]]++;
                int cw=right-left+1;
                if(maxWind>cw){
                    maxWind=cw;
                    start=left;
                }
                if(freq[s[left]]>0)count++;
                left++;
            }
        }
        if(maxWind==1e9)return "";
        return s.substr(start,maxWind);
    }
};