#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class Solution {
 public:

  vector<string> subdomainVisits(vector<string> &cpdomains) {
    vector<string> res;
    unordered_map<string, int> counts;

    for (const auto &item : cpdomains) {
      auto space = item.find(' ');
      int count = stoi(item.substr(0, space));
      string domain = item.substr(space + 1);
      counts[domain] += count;
      for (int i = 0; i < domain.size(); ++i) {
        if (domain[i] == '.') {
          string subdomain = domain.substr(i + 1);
          counts[subdomain] += count;
        }
      }
    }

    for (const auto &[k, v] : counts) {
      res.emplace_back(to_string(v) + " " + k);
    }
    return res;
  }

 private:

};

int main() {

  return 0;
}
