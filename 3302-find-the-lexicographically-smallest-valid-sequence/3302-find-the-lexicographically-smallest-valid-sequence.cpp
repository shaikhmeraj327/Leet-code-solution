class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int>matchingEle(n,0);
        int count=0;
        int i=n-1;
        int j=m-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                count++;
                matchingEle[i]=count;
                i--;
                j--;
            }
            else {
                matchingEle[i]=count;
                i--;
                
            }
        }
        while(i>=0)matchingEle[i--]=count;
        vector<int>res;
        i=0;
        j=0;
        bool canChange=true;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                res.push_back(i);
                i++;
                j++;
            }
            else if(canChange &&i+1<n && matchingEle[i+1]>=m-j-1){
                canChange=false;
                res.push_back(i);
                i++;j++;
            }
            else i++;
        }
        if(j==m)return res;
        return {};

    }
};