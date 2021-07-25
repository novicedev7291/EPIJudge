#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using std::max;

double BuyAndSellStockOnce(const vector<double>& prices) {
  double max_profit = 0.0, b_day = 0;

  for(int i = 1; i < prices.size(); i++) {
    double profit = prices[i] - prices[b_day];
    if(profit < 0.0) {
      b_day = i;
    }else {
      max_profit = max(profit, max_profit);
    }
  }

  return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
