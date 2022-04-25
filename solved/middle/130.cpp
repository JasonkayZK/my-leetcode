#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    int four_dirs[4][2] = {{0,  -1},
                           {0,  1},
                           {-1, 0},
                           {1,  0}};

    bool is_valid_pos(const int x, const int y, const int m, const int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:

    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        int m = int(board.size()), n = int(board[0].size());

        queue<pair<int, int>> q;

        // mark first raw and last raw
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.emplace(i, 0);
                board[i][0] = 'A';
            }
            if (board[i][n - 1] == 'O') {
                q.emplace(i, n - 1);
                board[i][n - 1] = 'A';
            }
        }

        // mark first col and last col(skip dumplicate)
        for (int i = 1; i < n - 1; ++i) {
            if (board[0][i] == 'O') {
                q.emplace(0, i);
                board[0][i] = 'A';
            }
            if (board[m - 1][i] == 'O') {
                q.emplace(m - 1, i);
                board[m - 1][i] = 'A';
            }
        }

        // mark inner
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (const auto &item: four_dirs) {
                int cur_x = x + item[0], cur_y = y + item[1];
                if (is_valid_pos(cur_x, cur_y, m, n) && board[cur_x][cur_y] == 'O') {
                    q.emplace(cur_x, cur_y);
                    board[cur_x][cur_y] = 'A';
                }
            }
        }

        // traverse and remark all
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

};

int main() {

    return 0;
}
