class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m)return false;
        vector<int>count1(26,0),count2(26,0);
        for(int i=0;i<n;i++){
            count1[s[i]-'a']++;
            count2[t[i]-'a']++;
        }
        return count1==count2;
    }
};