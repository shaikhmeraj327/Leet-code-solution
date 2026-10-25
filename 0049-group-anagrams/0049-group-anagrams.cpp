class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>freq;
        for(string str:strs){
            string key=str;
            sort(key.begin(),key.end());
            freq[key].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto p:freq)ans.push_back(p.second);
        return ans;
        
    }
};






// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n=strs.size();
//         vector<vector<int>>freq;
//         for(int i=0;i<n;i++){
//             string word=strs[i];
//             vector<int>output(26,0);
//             for(int j=0;j<word.size();j++){
//                 output[word[j]-'a']++;
//             }
//             freq.push_back(output);
//         }
//         vector<bool>visited(n,false);
//         vector<vector<string>>ans;
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 visited[i]=true;
//             vector<string>words;
//             words.push_back(strs[i]);
//                for(int j=0;j<n;j++){
                  
//                   if(!visited[j] && freq[i]==freq[j]){
//                     visited[j]=true;
                    
//                     if(i!=j)words.push_back(strs[j]);
//                   }
//                }
//                if(words.size()>0)ans.push_back(words);
//             }

//         }
//         return ans;
        
//     }
// };