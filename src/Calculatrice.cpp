#include "../include/calculatrice.h"
#include <string>
#include <cctype>
#include <stack>
#include <stdexcept> 
#include <cmath>

double Calculatrice::contate(const std::string& expression) {
    std::stack<double> pile;
    std::string score;
    
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        
        if (std::isdigit(c) || c == '.') {
            score += c;
        } else {
            if (!score.empty()) {
                pile.push(std::stod(score));
                score.clear();
            }
            
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == 'S' || c == 'M') {
                if (pile.size() < 2) {
                    throw std::runtime_error("Pas assez d'opérandes sur la pile");
                }

                double b = pile.top();
                pile.pop();
                double a = pile.top();
                pile.pop();
                
                switch (c) {
                    case '+':
                        pile.push(a + b);
                        break;
                    case '-':
                        pile.push(a - b);
                        break;
                    case '*':
                        pile.push(a * b);
                        break;
                    case '/':
                        if (b == 0) {
                            throw std::runtime_error("Division par zéro");
                        }
                        pile.push(a / b);
                        break;
                    case 'S': // Suppose that 'S' stands for "SQRT"
                        pile.push(std::sqrt(b));
                        break;
                    case 'M': // Suppose that 'M' stands for "MAX"
                        pile.push(std::max(a, b));
                        break;
                    default:
                        throw std::runtime_error(std::string("Opérateur inconnu : ") + c);
                }
            }
        }
    }

    if (!score.empty()) {
        pile.push(std::stod(score));
    }

    if (pile.size() != 1) {
        throw std::runtime_error("Expression invalide");
    }

    return pile.top();
}

bool Calculatrice::estNombre(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!std::isdigit(c) && c != '.') return false;
    }
    return true;
}
