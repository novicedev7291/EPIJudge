#include "test_framework/generic_test.h"

bool IsPalindromeNumber(int x) {
  if(x < 0) return false;

  const int n = static_cast<int>(floor(std::log10(x))) + 1;
  int ms_mask = static_cast<int>(std::pow(10, n-1));

  while(x) {
    int lsd = x % 10;
    int msd = x / ms_mask;
    if(lsd != msd) return false;

    x %= ms_mask;
    x /= 10;
    ms_mask /= 100;
  }
  return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "is_number_palindromic.cc",
                         "is_number_palindromic.tsv", &IsPalindromeNumber,
                         DefaultComparator{}, param_names);
}
