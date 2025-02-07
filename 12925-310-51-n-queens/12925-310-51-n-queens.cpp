class Solution {
public:
    void PushAns(vector<vector<char>>&board,vector<vector<string>>&ans){
        vector<string>chotu;
        for(int i=0;i<board.size();i++){
            string temp = "";
            for(int j=0;j<board.size();j++){
                temp.push_back(board[i][j]);
            }
            chotu.push_back(temp);
        }
        ans.push_back(chotu);
    }
    bool isSafe(vector<vector<char>>&board,int i,int j,int &n){
        int row = i; int col=j;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        row =i; col=j;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row =i; col=j;
        while(row<n&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void Solve(vector<vector<char>>&board,int&n,vector<vector<string>>&ans,int i,int j){
        if(j>=n){
            PushAns(board,ans);
            return;
        }
        for(int row =0;row<n;row++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                Solve(board,n,ans,i,j+1);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        Solve(board,n,ans,0,0);
        return ans;
    }
};