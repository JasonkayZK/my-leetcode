#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"

class Solution {
 private:

 public:

  vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr) {
      return {};
    }

    vector<vector<int>> ans;
    queue < Node * > q;
    q.push(root);

    while (!q.empty()) {
      int cnt = q.size();
      vector<int> level;
      for (int i = 0; i < cnt; ++i) {
        Node *cur = q.front();
        q.pop();
        level.push_back(cur->val);
        for (Node *child : cur->children) {
          q.push(child);
        }
      }
      ans.push_back(move(level));
    }

    return ans;
  }

};

int main() {

  return 0;
}
