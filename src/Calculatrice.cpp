#include "CalculatriceRPN.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

double CalculatriceRPN::evaluer(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<double> pile;
    std::string token;

    while (iss >> token) {
        if (estNombre(token)) {
            pile.push(std::stod(token));
        } else if (token == "+") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a + b);
        } else if (token == "-") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a - b);
        } else if (token == "*") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a * b);
        } else if (token == "/") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(a / b);
        } else if (token == "SQRT") {
            double a = pile.top(); pile.pop();
            pile.push(std::sqrt(a));
        } else if (token == "MAX") {
            double b = pile.top(); pile.pop();
            double a = pile.top(); pile.pop();
            pile.push(std::max(a, b));
        } else {
            throw std::runtime_error("Token inconnu : " + token);
        }
    }

    return pile.top();
}

bool CalculatriceRPN::estNombre(const std::string& s) {
    return !s.empty() && (std::isdigit(s[0]) || (s[0] == '-' && s.size() > 1));
}
