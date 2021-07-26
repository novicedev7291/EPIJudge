#include <vector>
#include <deque>

#include "test_framework/generic_test.h"
using std::vector;
using std::deque;

#define ll long long

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  vector<int> primes;

  deque<bool> possiblePrimes(n+1, true);

  for(ll i = 2; i < n + 1; i++) {
    if(possiblePrimes[i]) {
      primes.push_back(i);

      for(ll j = i * i;  j <= n; j += i) possiblePrimes[j] = false;
    }
  } 

  return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
