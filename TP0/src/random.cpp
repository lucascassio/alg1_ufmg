#include "../include/random.hpp"
#include <random>

using namespace std;

std::vector<int> generateUniqueNumbers(int numNumbers) {
    std::vector<int> numbers(numNumbers);
    std::iota(numbers.begin(), numbers.end(), 1); // Preenche o vetor com números sequenciais de 1 a numNumbers
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g); // Embaralha os números no vetor
    return numbers;
}

std::vector<std::vector<int> > generateSets() {
    std::vector<std::vector<int> > sets(50);
    for (int i = 0; i < 50; ++i) {
        sets[i] = generateUniqueNumbers(100000);
    }
    return sets;
}
