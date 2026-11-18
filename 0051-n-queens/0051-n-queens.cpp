class Solution {
public:
    bool isPossible(vector<string>&board,int row,int col){
        int n=board.size();
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q')return false;
        }
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q')return false;
        }
        // checking right dig
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        // checking left diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0 ;i--,j--) if(board[i][j]=='Q')return false;
        return true;
    }

    void solve(int n,int row,vector<string>&board,vector<vector<string>>&ans){
        if(row>=n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isPossible(board,row,j)){
                board[row][j]='Q';
                solve(n,row+1,board,ans);
                board[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        int row=0;
        solve(n,row,board,ans);
        return ans;
    }
};