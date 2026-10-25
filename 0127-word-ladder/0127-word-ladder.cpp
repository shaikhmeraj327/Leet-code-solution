class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(beginWord==endWord)return 1;
        if(st.find(beginWord)!=st.end())st.erase(beginWord);
        if(st.find(endWord)==st.end())return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            string word=temp.first;
            int step=temp.second;
            if(word==endWord)return step;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    if(word[i]==ch)continue;
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }

        }
        return 0;
    }
};