#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include "ArrayList.cpp"

using namespace std;
using namespace std::chrono;

void executarBenchmark(int qtd, const vector<int>& dados) {
    ArrayList minhaLista(10);
    
    // Teste de Inserção
    auto start = high_resolution_clock::now();
    for(int n : dados) minhaLista.add(n);
    auto end = high_resolution_clock::now();
    auto tempoAdd = duration_cast<microseconds>(end - start).count();

    // Teste de Busca (buscando o último elemento inserido)
    start = high_resolution_clock::now();
    minhaLista.find(dados.back());
    end = high_resolution_clock::now();
    auto tempoFind = duration_cast<microseconds>(end - start).count();

    // Teste de Remoção
    start = high_resolution_clock::now();
    minhaLista.remove();
    end = high_resolution_clock::now();
    auto tempoRem = duration_cast<microseconds>(end - start).count();

    cout << qtd << " elementos -> Add: " << tempoAdd << "us | Find: " << tempoFind << "us | Rem: " << tempoRem << "us" << endl;
}

int main() {
    ifstream arquivo("entrada.txt");
    string linha;
    
    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) { // Lê "X Entradas"
            int qtd = stoi(linha.substr(0, linha.find(" ")));
            vector<int> numeros;
            int num;
            for(int i = 0; i < qtd; i++) {
                arquivo >> num;
                numeros.push_back(num);
            }
            getline(arquivo, linha); // Limpa o buffer
            executarBenchmark(qtd, numeros);
        }
        arquivo.close();
    }
    return 0;
}
