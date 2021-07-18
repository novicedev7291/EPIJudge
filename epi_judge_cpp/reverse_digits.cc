#include "test_framework/generic_test.h"
long long Reverse(int x) {
  long long ans = 0;

  while(x) {
    ans = ans * 10 + x % 10;
    x /= 10;
  }
  return ans;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_digits.cc", "reverse_digits.tsv",
                         &Reverse, DefaultComparator{}, param_names);
}
