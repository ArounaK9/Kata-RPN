#include <gtest/gtest.h>
#include "../src/Calculatrice.cpp"  // Inclure le fichier source à tester

// Test de la classe Calculatrice
TEST(CalculatriceTest, Addition) {
    Calculatrice calc;
    EXPECT_DOUBLE_EQ(calc.contate("3 4 +"), 7.0);
}

TEST(CalculatriceTest, Subtraction) {
    Calculatrice calc;
    EXPECT_DOUBLE_EQ(calc.contate("10 4 -"), 6.0);
}

// Ajoutez d'autres tests selon les fonctionnalités que vous souhaitez tester

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
