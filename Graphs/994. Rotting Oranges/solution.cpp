class Solution {
public:
    bool checkIfFresh(vector<vector<int>>& grid, int i, int j, int n, int m,
                      char direction) {
        int dir_i;
        int dir_j;
        // upward direction
        if (direction == 'u') {
            dir_i = i - 1;
            dir_j = j;
            if (dir_i >= 0 && grid[dir_i][dir_j] == 1) {
                return true;
            }
            return false;
        }
        if (direction == 'l') {
            dir_i = i;
            dir_j = j - 1;
            if (dir_j >= 0 && grid[dir_i][dir_j] == 1) {
                return true;
            }
            return false;
        }
        if (direction == 'r') {
            dir_i = i;
            dir_j = j + 1;
            if (dir_j < m && grid[dir_i][dir_j] == 1) {
                return true;
            }
            return false;
        }
        dir_i = i + 1;
        dir_j = j;
        if (dir_i < n && grid[dir_i][dir_j] == 1) {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vec(n, vector<int>(m, -1));
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vec[i][j] = 1;
                }
            }
        }
        q.push({-1, -1});
        bool check = false;

        while (!q.empty()) {
            if (q.front().first == -1) {
                if (check)
                    time++;
                check = false;
                q.pop();
                continue;
            }
            pair<int, int> top = q.front();
            q.pop();
            int temp = 0;
            if (!q.empty() && q.front().first == -1) {
                temp = 1;
            }
            int i = top.first;
            int j = top.second;
            if (grid[i][j] == 2) {
                if (checkIfFresh(grid, i, j, n, m, 'u') &&
                    vec[i - 1][j] == -1) {
                    vec[i - 1][j] = 1;
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                    check = true;
                }
                if (checkIfFresh(grid, i, j, n, m, 'l') &&
                    vec[i][j - 1] == -1) {
                    vec[i][j - 1] = 1;
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                    check = true;
                }
                if (checkIfFresh(grid, i, j, n, m, 'r') &&
                    vec[i][j + 1] == -1) {
                    vec[i][j + 1] = 1;
                    grid[i][j + 1] = 2;

                    q.push({i, j + 1});

                    check = true;
                }
                if (checkIfFresh(grid, i, j, n, m, 'd') &&
                    vec[i + 1][j] == -1) {
                    vec[i + 1][j] = 1;
                    grid[i + 1][j] = 2;

                    q.push({i + 1, j});
                    check = true;
                }
                if (temp)
                    q.push({-1, -1});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};