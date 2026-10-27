class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>map;
        int n=paragraph.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            string word="";
            while(i<n && isalpha(paragraph[i])){
                word+=tolower(paragraph[i]);
                i++;
            }
            if(!word.empty()){
                map[word]++;
            }

        }
        string ans="";
        unordered_set<string>st(banned.begin(),banned.end());
        for(auto p:map){
            if(st.find(p.first)==st.end()){
                if(maxi<p.second){
                    ans=p.first;
                    maxi=p.second;
                }
            }
        }
        
       
        return ans;
    }
};





