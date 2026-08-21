class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i==n-1)ans+=map[s[i]];
            else if(map[s[i+1]]>map[s[i]]){
                ans+=map[s[i+1]]-map[s[i]];
                i++;
            }
            else ans+=map[s[i]];
        }
        return ans;
    }
};