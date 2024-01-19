/*
 * Author:
 * Date:
 * Name:
 */

class Problem7 {
public:
#include <iostream>
#include <vector>
#include <unordered_map>

int minRabbits(std::vector<int>& answers) {
    std::unordered_map<int, int> countMap;

    // Count the number of rabbits for each answer
    for (int answer : answers) {
        countMap[answer]++;
    }

    int minRabbits = 0;

    // Calculate the minimum number of rabbits
    for (const auto& entry : countMap) {
        int answer = entry.first;
        int count = entry.second;
        minRabbits += (count + answer - 1) / (answer + 1) * (answer + 1);
    }

    return minRabbits;
}

int main() {
    // Sample input: answers = [1, 1, 2]
    std::vector<int> answers = {1, 1, 2};

    // Calculate the minimum number of rabbits
    int result = minRabbits(answers);

    // Print the result
    std::cout << "Minimum number of rabbits: " << result << std::endl;

    return 0;
}

};
