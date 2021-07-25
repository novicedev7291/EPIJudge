#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
using std::numeric_limits;
using std::min;
using std::max;

double BuyAndSellStockTwice(const vector<double>& prices) {
  double max_total_profit = 0.0;
  
  double min_price_so_far = numeric_limits<double>::max();
  vector<double> profits(prices.size(), 0.0);

  for(int i = 0; i < prices.size(); i++) {
    min_price_so_far = min(min_price_so_far, prices[i]);
    max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
    profits[i] = max_total_profit;
  }

  double max_price_so_far = numeric_limits<double>::min();
  for(int i = prices.size() - 1; i >=0 ; i--) {
    max_price_so_far = max(max_price_so_far, prices[i]);
    max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + profits[i]);
  }

  return max_total_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
