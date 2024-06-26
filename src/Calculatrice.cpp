#include "calculatrice.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

double Calculatrice::contate(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<double> pile;
    std::string score;

    while (iss >> score) {
        if (estNombre(score)) {
            pile.push(std::stod(score));
        } else if (score == "+") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a + b);
        } else if (score == "-") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a - b);
        } else if (score == "*") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a * b);
        } else if (score == "/") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a / b);
        } else if (score == "SQRT") {
            double a = pile.top(); pile.pop();
            pile.push(std::sqrt(a));
        } else if (score == "MAX") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(std::max(a, b));
        } else {
            throw std::runtime_error("score inconnu : " + score);
        }
    }

    return pile.top();
}

bool Calculatrice::estNombre(const std::string& s) {
    return !s.empty() && (std::isdigit(s[0]) || (s[0] == '-' && s.size() > 1));
}
