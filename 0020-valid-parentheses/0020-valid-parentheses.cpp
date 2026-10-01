class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0)
         return false;
        stack<char>st;
        for(int i=0;i<s.size();i++){

            char ch=s[i];
            if(ch=='(' || ch =='[' || ch=='{'){
                st.push(ch);
            }
            else if(!st.empty()){
                char peek=st.top();
                if((ch==')' && peek=='(') || (ch==']' && peek=='[') || (ch=='}' && peek=='{')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
            
        }
        if(st.empty())
             return true;
            return false;
        
    }
};