/*
 * Author:
 * Date:
 * Name:
 */

class Problem11 {
public:
#include <iostream>
#include <vector>

bool isSatisfiable(const std::vector<std::vector<int>>& cnf_formula, std::vector<int>& assignment, int index) {
    int numClauses = cnf_formula.size();
    int numVariables = assignment.size();

    // Check if the current assignment satisfies all clauses
    auto checkClauses = [&]() {
        for (const auto& clause : cnf_formula) {
            bool clauseSatisfied = false;
            for (int literal : clause) {
                if ((literal > 0 && assignment[abs(literal)] == 1) || (literal < 0 && assignment[abs(literal)] == 0)) {
                    clauseSatisfied = true;
                    break;
                }
            }
            if (!clauseSatisfied) {
                return false;
            }
        }
        return true;
    };

    // Base case: check if the current assignment satisfies all clauses
    if (index == numVariables) {
        return checkClauses();
    }

    // Try assigning true to the current variable
    assignment[index + 1] = 1;
    if (isSatisfiable(cnf_formula, assignment, index + 1)) {
        return true;
    }

    // Try assigning false to the current variable
    assignment[index + 1] = 0;
    if (isSatisfiable(cnf_formula, assignment, index + 1)) {
        return true;
    }

    return false;
}

bool solveSAT(const std::vector<std::vector<int>>& cnf_formula) {
    int numVariables = 0;

    // Find the maximum variable in the formula
    for (const auto& clause : cnf_formula) {
        for (int literal : clause) {
            numVariables = std::max(numVariables, abs(literal));
        }
    }

    // Initialize assignment vector with 0s
    std::vector<int> assignment(numVariables + 1, 0);

    // Check if the CNF formula is satisfiable
    return isSatisfiable(cnf_formula, assignment, 0);
}

int main() {
    // Sample input: cnf_formula = [[1, 2, -3], [-1, -2, 3], [2, -3]]
    std::vector<std::vector<int>> cnf_formula = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};

    // Check if the CNF formula is satisfiable
    bool result = solveSAT(cnf_formula);

    // Print the result
    if (result) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}

};
