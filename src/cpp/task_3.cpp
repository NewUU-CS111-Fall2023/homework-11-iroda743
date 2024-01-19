/*
 * Author:
 * Date:
 * Name:
 */

class Problem3 {
#include <iostream>
#include <vector>

enum State {
    q0, q1, q2, q3, q4, q5, q6, HALT
};

void compareNumbers(std::vector<char>& tape) {
    State currentState = q0;
    int head = 0;

    while (currentState != HALT) {
        switch (currentState) {
            case q0:
                while (head < tape.size() && tape[head] != 'c') {
                    head++;
                }
                currentState = q1;
                break;

            case q1:
                while (head < tape.size() && tape[head] != '0') {
                    head++;
                }
                currentState = q2;
                break;

            case q2:
                // Move right to find the start of the second number
                while (head < tape.size() && tape[head] != '1') {
                    head++;
                }
                currentState = q3;
                break;

            case q3:
                while (head < tape.size() && tape[head] != '0') {
                    head++;
                }
                currentState = q4;
                break;

            case q4:
                if (head < tape.size() && tape[head] == '1') {
                    currentState = HALT;
                    std::cout << "11" << std::endl;
                } else if (head < tape.size() && tape[head] == '0') {
                    currentState = HALT;
                    std::cout << "1" << std::endl;
                } else {
                    // Both numbers are equal
                    currentState = q5;
                }
                break;

            case q5:
                while (head < tape.size() && tape[head] != 'c') {
                    head++;
                }
                currentState = q6;
                break;

            case q6:
                while (head < tape.size()) {
                    head++;
                }
                std::cout << "11" << std::endl;
                currentState = HALT;
                break;
        }
    }
}

int main() {
    std::vector<char> tape = {'0', '1', '1', '1', 'c', '1', '1', '1', '1', '0'};
    
    compareNumbers(tape);

    return 0;
}

};
