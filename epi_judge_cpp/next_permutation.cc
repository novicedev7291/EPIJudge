#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using std::is_sorted_until;
using std::upper_bound;
using std::swap;
using std::reverse;

vector<int> NextPermutation(vector<int> perm) {

  vector<int>::reverse_iterator inversion_point = is_sorted_until(perm.rbegin(), perm.rend());
  if(inversion_point == perm.rend()) {
    return {};
  }

  vector<int>::reverse_iterator swap_point = upper_bound(perm.rbegin(), inversion_point, *inversion_point);
  swap(*inversion_point, *swap_point);

  reverse(perm.rbegin(), inversion_point);
  return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
