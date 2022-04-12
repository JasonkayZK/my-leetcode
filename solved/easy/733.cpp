#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
private:

    int four_dir[4][2] = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0}
    };

    bool isValidPos(const int x, const int y, const int m, const int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int m = int(image.size());
        if (m <= 0) return {{}};
        int n = int(image[0].size());
        if (n <= 0) return {{}};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int init_color = image[sr][sc];
        queue<pair<int, int>> q;
        q.emplace(make_pair(sr, sc));
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            // update cur node
            image[cur.first][cur.second] = newColor;
            visited[cur.first][cur.second] = true;

            // add new node
            for (const auto &new_pair: four_dir) {
                int next_x = cur.first + new_pair[0], next_y = cur.second + new_pair[1];
                if (isValidPos(next_x, next_y, m, n) && !visited[next_x][next_y] &&
                    image[next_x][next_y] == init_color) {
                    q.emplace(make_pair(next_x, next_y));
                }
            }
        }

        return image;
    }
};

int main() {

    vector<vector<int>> l = {{1, 1, 1},
                             {1, 1, 0},
                             {1, 0, 1}};
    Solution().floodFill(l, 1, 1, 2);

    return 0;
}
