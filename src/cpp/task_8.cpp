/*
 * Author:
 * Date:
 * Name:
 */

class Problem8 {
public:
#include <iostream>
#include <vector>

bool canPartition(const std::vector<int>& nums) {
    int sum = 0;

    for (int num : nums) {
        sum += num;
    }

    // If the sum is odd, it's not possible to partition into two equal subsets
    if (sum % 2 != 0) {
        return false;
    }

    int targetSum = sum / 2;
    int n = nums.size();

    // dp[i][j] will be true if there is a subset of elements in the first i numbers
    // such that their sum is equal to j
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    // Base case: an empty subset can always achieve a sum of 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Build the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    // Sample input: nums = [1, 5, 11, 5]
    std::vector<int> nums = {1, 5, 11, 5};

    // Check if it's possible to partition the array into two equal sum subsets
    bool result = canPartition(nums);

    // Print the result
    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

};
