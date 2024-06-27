#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <string>

class Calculatrice {
public:
    double contate(const std::string& expression);
    bool estNombre(const std::string& s);
};

#endif // CALCULATRICE_H
