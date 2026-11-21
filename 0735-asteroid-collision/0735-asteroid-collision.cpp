class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            bool flag=true;
            while(!st.empty() && asteroids[i]<0 && st.top()>0){
                if(abs(st.top())<abs(asteroids[i])){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(asteroids[i])){
                    st.pop();
                    flag=false;
                    break;
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag)st.push(asteroids[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};