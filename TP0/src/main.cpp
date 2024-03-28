#include <iostream>
#include <vector>
#include <chrono> // Para medir o tempo
#include <numeric> // Para cálculos estatísticos
#include <cmath>   // Para cálculo do desvio padrão
#include "../include/ord.hpp"
#include "../include/random.hpp"

// Função para calcular a média de um vetor de números
double calculateMean(const std::vector<double>& data) {
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return sum / data.size();
}

// Função para calcular o desvio padrão de um vetor de números
double calculateStdDev(const std::vector<double>& data, double mean) {
    double sum = 0.0;
    for (double x : data) {
        sum += (x - mean) * (x - mean);
    }
    return std::sqrt(sum / data.size());
}

int main() {
    const int num_sets = 1;
    const int set_size = 1000000;

    std::vector<std::vector<int>> sets;
    for (int i = 0; i < num_sets; ++i) {
        sets = generateSets();
    }

    Ord ord;

    std::vector<double> execution_times_ins;
    std::vector<double> execution_times_ins_itr;
    std::vector<double> execution_times_quick;
    std::vector<double> execution_times_quick_itr;

    for (int i = 0; i < num_sets; ++i) {
        auto start_ins = std::chrono::steady_clock::now(); // Marca o tempo de início da ordenação
        ord.quickSortIns(sets[i], 0, set_size - 1); // Ordena o conjunto atual
        auto end_ins = std::chrono::steady_clock::now(); // Marca o tempo de término da ordenação
        std::chrono::duration<double> elapsed_seconds_ins = end_ins - start_ins; // Calcula a diferença de tempo
        execution_times_ins.push_back(elapsed_seconds_ins.count());

        auto start_ins_itr = std::chrono::steady_clock::now();
        ord.quickSortInsItr(sets[i], 0, set_size - 1);
        auto end_ins_itr = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds_ins_itr = end_ins_itr - start_ins_itr;
        execution_times_ins_itr.push_back(elapsed_seconds_ins_itr.count());

        auto start_quick = std::chrono::steady_clock::now();
        ord.quickSort(sets[i], 0, set_size - 1);
        auto end_quick = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds_quick = end_quick - start_quick;
        execution_times_quick.push_back(elapsed_seconds_quick.count());

        auto start_quick_itr = std::chrono::steady_clock::now();
        ord.quickSortItr(sets[i], 0, set_size - 1);
        auto end_quick_itr = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds_quick_itr = end_quick_itr - start_quick_itr;
        execution_times_quick_itr.push_back(elapsed_seconds_quick_itr.count());
    }

    // Calcula a média e o desvio padrão para cada algoritmo de ordenação em milissegundos
    double mean_ins_ms = calculateMean(execution_times_ins) * 1000;
    double std_dev_ins_ms = calculateStdDev(execution_times_ins, mean_ins_ms / 1000) * 1000;

    double mean_ins_itr_ms = calculateMean(execution_times_ins_itr) * 1000;
    double std_dev_ins_itr_ms = calculateStdDev(execution_times_ins_itr, mean_ins_itr_ms / 1000) * 1000;

    double mean_quick_ms = calculateMean(execution_times_quick) * 1000;
    double std_dev_quick_ms = calculateStdDev(execution_times_quick, mean_quick_ms / 1000) * 1000;

    double mean_quick_itr_ms = calculateMean(execution_times_quick_itr) * 1000;
    double std_dev_quick_itr_ms = calculateStdDev(execution_times_quick_itr, mean_quick_itr_ms / 1000) * 1000;

    // Imprime os resultados em milissegundos
    std::cout << "Média e desvio padrão dos tempos de execução (em milissegundos):" << std::endl;
    std::cout << "QuickSort: Média = " << mean_quick_ms << " milissegundos, Desvio Padrão = " << std_dev_quick_ms << " milissegundos" << std::endl;
    std::cout << "QuickSortItr: Média = " << mean_quick_itr_ms << " milissegundos, Desvio Padrão = " << std_dev_quick_itr_ms << " milissegundos" << std::endl;
    std::cout << "QuickSortIns: Média = " << mean_ins_ms << " milissegundos, Desvio Padrão = " << std_dev_ins_ms << " milissegundos" << std::endl;
    std::cout << "QuickSortInsItr: Média = " << mean_ins_itr_ms << " milissegundos, Desvio Padrão = " << std_dev_ins_itr_ms << " milissegundos" << std::endl;

    return 0;
}
