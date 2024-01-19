/*
 * Author:
 * Date:
 * Name:
 */

class Problem5 {
#include <iostream>
#include <vector>

bool hasZeroSumTriplet(const std::vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    // Sample input: -5 -17 7 -4 3 -2 4
    std::vector<int> nums = {-5, -17, 7, -4, 3, -2, 4};

    // Check if the set contains a distinct triplet whose sum is zero
    bool result = hasZeroSumTriplet(nums);

    // Print the result
    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

};
