#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) {
            return 0;
        }

        size_t totalCount = nums.size();
        int acceptedIndex = 0;
        int acceptedMaxValue = nums[0];

        for (int i = 1; i < totalCount; ++i) {
            int currentValue = nums[i];

            if (currentValue > acceptedMaxValue) {
                acceptedIndex++;
                acceptedMaxValue = currentValue;

                if (acceptedIndex != i) {
                    nums[acceptedIndex] = currentValue;
                }
            }
        }

        return acceptedIndex + 1;
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int profit = 0;
        int buyPrice = prices[0];
        int sellPrice = prices[0];

        for (vector<int>::iterator it = prices.begin(); it != prices.end(); ++it) {
            int currentPrice = *it;

            if (currentPrice >= sellPrice) {
                sellPrice = currentPrice;
            }else {
                profit += sellPrice - buyPrice;
                buyPrice = sellPrice = currentPrice;
            }
        }

        if (sellPrice > buyPrice) {
            profit += sellPrice - buyPrice;
        }

        return profit;
    }
};