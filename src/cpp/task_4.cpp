/*
 * Author:
 * Date:
 * Name:
 */

class Problem4 {
#include <iostream>
#include <vector>

enum State {
    q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, HALT
};

void multiplyNumbers(std::vector<char>& tape) {
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
                if (head < tape.size() && tape[head] == 'c') {
                    tape[head] = 'C';
                    head++;
                    currentState = q2;
                }
                break;

            case q2:
                while (head < tape.size() && tape[head] != '0') {
                    head++;
                }
                currentState = q3;
                break;

            case q3:
                while (head < tape.size()) {
                    head++;
                }
                currentState = HALT;
                break;
        }
    }
}

int main() {
    std::vector<char> tape = {'0', '1', '1', '1', 'c', '1', '1', '1', '0'};

    multiplyNumbers(tape);

    for (char symbol : tape) {
        if (symbol != '0') {
            std::cout << symbol << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}

};
