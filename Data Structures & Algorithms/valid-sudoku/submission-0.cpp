class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> u;
            for(int j=0;j<9;j++){
                if(board[i][j]-'0'>=1 && board[i][j]-'0'<=9){
                    if(u.find(board[i][j])!=u.end()) return false;
                    u.insert(board[i][j]);
                }
            }
        }

        for(int i=0;i<9;i++){
            unordered_set<char> u;
            for(int j=0;j<9;j++){
                if(board[j][i]-'0'>=1 && board[j][i]-'0'<=9){
                    if(u.find(board[j][i])!=u.end()) return false;
                    u.insert(board[j][i]);
                }
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }

        return true;
    }
};
