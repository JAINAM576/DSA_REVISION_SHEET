class Solution {
public:
    bool canPlace(int i, int j, int n, vector<string>& gameBoard) {
        // up, down , left , right , rightDownCross , leftUpCross , RightUpcross
        // , leftDowncross
        vector<vector<int>> dir = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},
                   {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};

        for (auto& pair : dir) {
            int dirI = pair[0];
            int dirJ = pair[1];

            int tempI = i;
            int tempJ = j;

            while ((tempI + dirI)>=0 && (tempI + dirI) < n && (tempJ + dirJ) < n && (tempJ + dirJ)>=0) {
                if (gameBoard[tempI + dirI][tempJ + dirJ] == 'Q')
                    return false;
                tempI += dirI;
                tempJ += dirJ;
            }
        }
        return true;
    }
    void makeBoard(vector<string>& gameBoard, vector<vector<string>>& vec,
                   int n, int i) {

        if (i == n) {
            vec.push_back(gameBoard);
            return;
        }
        for (int index = 0; index < n; index++) {
            if (i == 0) {
                gameBoard[i][index] = 'Q';
                makeBoard(gameBoard, vec, n, i + 1);
            }
            else if (canPlace(i, index, n, gameBoard)) {
                gameBoard[i][index] = 'Q';
                makeBoard(gameBoard, vec, n, i + 1);
            }

            gameBoard[i][index] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        string s = "";
        for (int i = 0; i < n; i++) {
            s += '.';
        }
        vector<string> gameBoard(n, s);

        makeBoard(gameBoard, vec, n, 0);

        return vec;
    }
};