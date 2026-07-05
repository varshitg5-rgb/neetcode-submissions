class Solution {
public:
    bool check(int i,int j,vector<vector<char>>& board,string & word,int idx,vector<vector<bool>> &visited){
        if(idx==word.length()-1) return true;

        int n = board.size();
        int m = board[0].size();
        if(i+1<n && visited[i+1][j]==false && board[i+1][j]==word[idx+1]){
            visited[i+1][j] = true;
            if(check(i+1,j,board,word,idx+1,visited)) return true;
            visited[i+1][j] = false;
        }
        if(i-1>=0 && visited[i-1][j]==false && board[i-1][j]==word[idx+1]){
            visited[i-1][j] = true;
            if(check(i-1,j,board,word,idx+1,visited)) return true;
            visited[i-1][j] = false;

        }
        if(j+1<m && visited[i][j+1]==false && board[i][j+1]==word[idx+1]){
            visited[i][j+1] = true;
            if(check(i,j+1,board,word,idx+1,visited)) return true;
            visited[i][j+1] = false;

        }
        if(j-1>=0 && visited[i][j-1]==false && board[i][j-1]==word[idx+1]){
            visited[i][j-1] = true;
            if(check(i,j-1,board,word,idx+1,visited)) return true;
            visited[i][j-1] = false;

        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    int idx = 0;
                    visited[i][j] = true;
                    if(check(i,j,board,word,idx,visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
