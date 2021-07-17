#include "test_framework/generic_test.h"

unsigned long long add(unsigned long long a, unsigned long long b) {
  while(b) {
    unsigned long long carry = a & b;
    a ^= b;
    b = carry << 1;
  }
  return 0;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
  unsigned long long result = 0;

  while(x) {
    if( x & 1 ) {
      result = add(result, y);
    }
    x >>= 1, y <<=1;
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
