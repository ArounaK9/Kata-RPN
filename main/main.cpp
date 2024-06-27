#include <iostream>
#include <vector>
#include <string>
#include "../include/calculatrice.h"


int main() {
    Calculatrice calculatrice;
    std::vector<std::string> expressions = {
        "20 5 /",
        "4 2 + 3 -",
        "3 5 8 * 7 + *",

    };
    
    for (const auto& exp : expressions) {
        try {
            double resultat = calculatrice.contate(exp);
            std::cout << exp << " => " << resultat << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de l'évaluation de l'expression '" << exp << "': " << e.what() << std::endl;
        }
    }

    return 0;
}
