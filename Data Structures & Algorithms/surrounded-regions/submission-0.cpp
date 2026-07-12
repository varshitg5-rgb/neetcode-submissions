class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0] = 'B';
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                board[i][m-1] = 'B';
            }
        }

        for(int i=1;i<m-1;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                board[0][i] = 'B';
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                board[n-1][i] = 'B';
            }
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if(x-1>=0 && board[x-1][y]=='O'){
                q.push({x-1,y});
                board[x-1][y] ='B';
            }
             if(y-1>=0 && board[x][y-1]=='O'){
                q.push({x,y-1});
                board[x][y-1] ='B';
            }
             if(x+1<n && board[x+1][y]=='O'){
                q.push({x+1,y});
                board[x+1][y] ='B';
            }
             if(y+1<m && board[x][y+1]=='O'){
                q.push({x,y+1});
                board[x][y+1] ='B';
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';

                else if(board[i][j]=='B') board[i][j] = 'O';
            }
        }
        return;
    }
};
