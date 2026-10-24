class Solution {
public:
   static bool comp(string &a,string &b){
     int i=a.find(' ');
     int j=b.find(' ');
     string content1=a.substr(i+1);
     string content2=b.substr(j+1);
     if(content1!=content2)return content1<content2;
     return a.substr(0,i)<b.substr(0,j);
   }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>letter;
        vector<string>digit;
        for(string st:logs){
            int space_ind=st.find(' ');
            space_ind++;
            if(isalpha(st[space_ind])){
                letter.push_back(st);
            }
            else digit.push_back(st);
        }
        sort(letter.begin(),letter.end(),comp);
        for(string st:digit)letter.push_back(st);
        return letter;
    }
};