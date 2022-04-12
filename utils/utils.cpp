//
// Created by JasonkayZK on 2022/3/26.
//

#include "utils.h"

int nine_dirs[9][2] = {{0,  0},
                       {1,  0},
                       {-1, 0},
                       {0,  1},
                       {0,  -1},
                       {-1, -1},
                       {-1, 1},
                       {1,  -1},
                       {1,  1}};

int four_dirs[4][2] = {{0,  -1},
                       {0,  1},
                       {-1, 0},
                       {1,  0}};

bool is_valid_pos(const int x, const int y, const int m, const int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}


void print_vec(const vector<int> &arr) {
    std::for_each(arr.begin(), arr.end(), [](const auto &i) { std::cout << i << " "; });
    cout << "\n";
}

vector<string> split(const string &s, const char delimiter) {
    vector<string> tokens;
    string token;
    istringstream token_stream(s);
    while (getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
