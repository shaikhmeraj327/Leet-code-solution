class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end())return 0;
        if(st.find(beginWord)!=st.end())st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int ans=0;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            string word=temp.first;
            int step=temp.second;
            if(word==endWord)return step;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(original==ch)continue;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                    word[i]=original;
                }
            }
        }
        return ans;
    }
};