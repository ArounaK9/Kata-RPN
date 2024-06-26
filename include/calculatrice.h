#ifndef CALCULATRICERPN_H
#define CALCULATRICERPN_H

#include <string>

class CalculatriceRPN {
public:
    double evaluer(const std::string& expression);

private:
    bool estNombre(const std::string& s);
};

#endif 
