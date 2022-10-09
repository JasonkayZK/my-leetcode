#include "utils/utils.h"
#include "data_structure/list.h"
#include "data_structure/tree.h"
#include "data_structure/trie.h"
#include "data_structure/segment_tree.h"
#include "data_structure/union_find.h"

class ParkingSystem {
 public:
  ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {};

  bool addCar(int carType) {
    if (carType == 1) {
      if (big > 0) {
        --big;
        return true;
      }
    } else if (carType == 2) {
      if (medium > 0) {
        --medium;
        return true;
      }
    } else if (carType == 3) {
      if (small > 0) {
        --small;
        return true;
      }
    }
    return false;
  }

 private:
  int big, medium, small;
};

int main() {

  return 0;
}
