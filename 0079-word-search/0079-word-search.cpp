class Solution {
public:
   bool isPossible(vector<vector<char>>& board,string &word,int r,int c,int ind){
       if(ind>=word.size())return true;
       int m=board.size();
       int n=board[0].size();
       if((r>=m || r<0) ||(c>=n || c<0) || (board[r][c]!=word[ind]))return false;
       char temp=board[r][c];
       board[r][c]='#';

       bool check=isPossible(board,word,r+1,c,ind+1) || isPossible(board,word,r-1,c,ind+1) ||
                  isPossible(board,word,r,c+1,ind+1) || isPossible(board,word,r,c-1,ind+1);
       board[r][c]=temp;
       return check;
   }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(isPossible(board,word,i,j,0))return true;
                }
            }
        }
        return false;
    }
};