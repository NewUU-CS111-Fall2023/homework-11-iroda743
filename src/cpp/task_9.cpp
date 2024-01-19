/*
 * Author:
 * Date:
 * Name:
 */

class Problem9 {
public:
#include <iostream>
#include <vector>
#include <unordered_map>

// Define a structure to represent a clause in CNF
struct Clause {
    char variable;
    bool isNegated;
};

// Define a structure to represent the CNF formula
struct CNFFormula {
    std::vector<std::vector<Clause>> clauses;
};

// Function to check if a given assignment satisfies the CNF formula
bool isSatisfied(const CNFFormula& formula, const std::unordered_map<char, bool>& assignment) {
    for (const auto& clauseGroup : formula.clauses) {
        bool clauseSatisfied = false;
        for (const auto& clause : clauseGroup) {
            char variable = clause.variable;
            bool isNegated = clause.isNegated;

            // Check if the variable is in the assignment
            if (assignment.find(variable) != assignment.end()) {
                bool variableValue = assignment.at(variable);
                if (isNegated) {
                    variableValue = !variableValue;
                }
                clauseSatisfied = clauseSatisfied || variableValue;
            } else {
                // Variable not in the assignment, consider it as False
                clauseSatisfied = clauseSatisfied || (isNegated ? true : false);
            }
        }

        // If no clause in the group is satisfied, the whole group is not satisfied
        if (!clauseSatisfied) {
            return false;
        }
    }

    // All clause groups are satisfied
    return true;
}

int main() {
    // Sample input: Formula: (A | ~B) & (~A | B | C), Assignment: A=T, B=F, C=T
    CNFFormula formula = {{{{'A', false}, {'B', true}}, {{'A', true}, {'B', false}, {'C', true}}}};
    std::unordered_map<char, bool> assignment = {{'A', true}, {'B', false}, {'C', true}};

    // Check if the assignment satisfies the formula
    bool satisfied = isSatisfied(formula, assignment);

    // Print the result
    if (satisfied) {
        std::cout << "Satisfied" << std::endl;
    } else {
        std::cout << "Not Satisfied" << std::endl;
    }

    return 0;
}

};
