class Solution {
public:
    bool solve(vector<char>&temp,char op){
        if(op=='!')return temp[0]=='t'?false:true;
        if(op=='&'){
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='f')return false;
            }
            return true;
        }
        if(op=='|'){
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='t')return true;
            }
            return false;
        }
        return false;
    }


    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char>st;
        bool res = (expression[0] == 't');  
        for(int i=0;i<n;i++){
            char ch=expression[i];
            if(ch=='(' || ch=='t'|| ch=='f'|| ch=='!' ||ch=='&' ||ch=='|')st.push(ch);
            else if(ch==')') {
                vector<char>temp;
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                res=solve(temp,op);
                if(res)st.push('t');
                else st.push('f');
            }
        }
        return res;
    }
};





// class Solution {
// public:
//     bool solve(vector<char>&temp,char op){
//         if (op == '!') {
//             // temp[0] is the value inside !(...)
//             return temp[0] == 't' ? false : true;
//         }
//         if(op=='|'){
//             for(int i=0;i<temp.size();i++){
//                 if(temp[i]=='t')return true;
//             }
//             return false;
//         }
//         else if(op=='&'){
//             for(int i=0;i<temp.size();i++){
//                 if(temp[i]=='f')return false;
//             }
//             return true;
//         }
//         return false;
//     }
//     bool parseBoolExpr(string expression) {
//         stack<char>st;
//         bool res = (expression[0] == 't'); 
//         int n=expression.size();
//         for(int i=0;i<n;i++){
//             char ch=expression[i];
//             if(ch=='(' || ch=='!' || ch=='&' || ch=='|' || ch=='t'|| ch=='f')st.push(ch);
//             else if(ch==')'){
//                 vector<char>temp;
//                 while(st.top()!='('){
//                     temp.push_back(st.top());
//                     st.pop();
//                 }
//                 st.pop();
//                 char op=st.top();
//                 st.pop();
//                 // if(op=='!' && res=='f')res=true;
//                 // else if(op=='!' && res=='t')res=false;
//                  res= solve(temp,op);
//                 if(res==false)st.push('f');
//                 else st.push('t');
//             }
//         }
//         return res;
//     }
// };