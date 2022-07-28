#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

 private:

};

class Codec {
 public:

  void serialize_helper(const TreeNode *root, vector<string> &list) {
    if (root == nullptr) return;

    list.push_back(to_string(root->val));
    serialize_helper(root->left, list);
    serialize_helper(root->right, list);
  }

  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (root == nullptr) {
      return "";
    }

    vector<string> list;
    serialize_helper(root, list);
    return std::accumulate(list.begin(), list.end(), std::string{}, [](
        const std::string &a,
        const std::string &b) -> std::string {
      return a + (a.length() > 0 ? "," : "") + b;
    });
  }

  TreeNode *deserialize_helper(const vector<string> &list, int l, int r) {
    if (l > r) return nullptr;

    int j = l + 1, t = std::stoi(list[l]);
    auto *res = new TreeNode(t);
    while (j <= r && std::stoi(list[j]) <= t) j++;
    res->left = deserialize_helper(list, l + 1, j - 1);
    res->right = deserialize_helper(list, j, r);
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string &data) {
    if (data.empty()) return nullptr;

    vector<string> list = split(data, ',');
    return deserialize_helper(list, 0, int(list.size() - 1));
  }

 private:

  vector<string> split(const string &s, const char delimiter) {
    vector<string> tokens;
    string token;
    istringstream token_stream(s);
    while (getline(token_stream, token, delimiter)) {
      tokens.push_back(token);
    }
    return tokens;
  }
};

int main() {

  return 0;
}
