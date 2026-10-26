class Solution {
public:
    string decodeString(string s) {
        stack<string>stringStack;
        stack<int>countStack;
        int count=0;
        string currString="";
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            // case 1 number
            if(isdigit(ch)){
                count=count*10+(ch-'0');
            }
            // open bracket
            else if(ch=='['){
                countStack.push(count);
                stringStack.push(currString);
                count=0;
                currString="";
            }
            // close brack means we need to make string
            else if(ch==']'){
                int repeatNo=countStack.top();
                countStack.pop();
                string repeatSt="";
                while(repeatNo>0){
                    repeatSt+=currString;
                    repeatNo--;
                }
                repeatSt=stringStack.top()+repeatSt;
                stringStack.pop();
                currString=repeatSt;
            }
            else currString+=ch;

        }
        return currString;
    }
};