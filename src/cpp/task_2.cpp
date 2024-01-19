/*
 * Author:
 * Date:
 * Name:
 */

class Problem2 {
public:
#include <iostream>
#include <vector>

enum State {
    q0, q1, q2, q3, HALT
};

void unaryAddition(std::vector<int>& tape) {
    State currentState = q0;
    int head = 0;

    while (currentState != HALT) {
        switch (currentState) {
            case q0:
                // Move to the first '0'
                while (head < tape.size() && tape[head] != 0) {
                    head++;
                }
                currentState = q1;
                break;

            case q1:
                // Addition loop
                while (head < tape.size() && tape[head] == 0) {
                    tape[head] = 1;
                    head--;
                    while (head >= 0 && tape[head] != 0) {
                        head--;
                    }
                    head++;
                }
                currentState = (head < tape.size() && tape[head] == 0) ? q1 : q2;
                break;

            case q2:
                // Handle separator
                tape[head] = 1;
                head++;
                currentState = q3;
                break;

            case q3:
                // Shift to the right
                while (head < tape.size() && tape[head] != 0) {
                    head++;
                }
                currentState = (head < tape.size()) ? q1 : HALT;
                break;
        }
    }
}

int main() {
    std::vector<int> tape = {1, 1, 1, 0, 1, 1, 1, 1};

    unaryAddition(tape);

    std::cout << "Result: ";
    for (int bit : tape) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    return 0;
}

};
