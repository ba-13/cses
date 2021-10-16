#include <random>
#include <iostream>
#include <ctime>

int main()
{
    std::random_device rd;
    std::time_t t = std::time(0);
    std::mt19937 mtTrue(rd());
    std::mt19937 mtPseudo(t);
    std::cout << mtTrue << "\n";
    std::uniform_real_distribution<double> dist(1.0, 100.0);

    for (int i = 0; i < 16; ++i)
    {
        std::cout << (int)dist(mtTrue) << " ";
        std::cout << (int)dist(mtPseudo) << "\n";
    }
}