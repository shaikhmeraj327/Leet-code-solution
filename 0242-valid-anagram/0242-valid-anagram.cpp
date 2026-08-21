class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m!=n)return false;
        vector<int>count1(26,0);
        vector<int>count2(26,0);
        for(int i=0;i<m;i++){
            char ch1=s[i];
            char ch2=t[i];
            count1[ch1-'a']++;
            count2[ch2-'a']++;
        }
        return count1==count2;
        
    }
};