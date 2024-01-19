/*
 * Author:
 * Date:
 * Name:
 */

class Problem10 {
public:
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

std::vector<char> generateVariables(int numVariables) {
    std::vector<char> variables;
    for (int i = 0; i < numVariables; ++i) {
        variables.push_back('A' + i);
    }
    return variables;
}

std::string generateRandom3SATFormula(int numVariables, int numClauses) {
    std::vector<char> variables = generateVariables(numVariables);
    std::string formula;

    srand(time(nullptr));

    for (int i = 0; i < numClauses; ++i) {
        std::unordered_set<char> clauseVariables;

        while (clauseVariables.size() < 3) {
            char randomVariable = variables[rand() % numVariables];
            bool negateVariable = rand() % 2 == 0;

            if (negateVariable) {
                clauseVariables.insert('~' + randomVariable);
            } else {
                clauseVariables.insert(randomVariable);
            }
        }

        formula += '(';
        for (char variable : clauseVariables) {
            formula += variable;
            formula += '|';
        }
        formula.pop_back(); // Remove the last '|'
        formula += ") & ";
    }

    formula.pop_back(); // Remove the last '&'

    return formula;
}

int main() {
    // Sample input: Variables: 3, Clauses: 2
    int numVariables = 3;
    int numClauses = 2;

    // Generate a random 3-SAT formula
    std::string random3SATFormula = generateRandom3SATFormula(numVariables, numClauses);

    // Print the generated formula
    std::cout << random3SATFormula << std::endl;

    return 0;
}

};
