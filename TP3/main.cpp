#include "bits/stdc++.h"

using namespace std;

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

struct secao {
  long long bonificacao;
  long long tTravessia;
};

struct manobra {
  long long pontuacao;
  long long tManobra;
};

vector<secao> secoes;
vector<manobra> manobras;

long long countSetBits(long long n){
    long long count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void combinacoes(vector<vector<long long>>& tabela, long long N, long long K) {
  for(int i = 0; i < N; i++) {
    tabela[i][0] = 0;
    for(int mask = 1; mask < (1 << K); mask++) {
      long long aux = secoes[i].tTravessia;
      for(int k = 0; k < K; k++) {
        if(mask & (1 << k)) {

          if(manobras[k].tManobra <= aux) {
            tabela[i][mask] += manobras[k].pontuacao * secoes[i].bonificacao;
            aux -= manobras[k].tManobra;
          } else if(manobras[k].tManobra > aux) {
            tabela[i][mask] = -LINF;
          }

          if(k == K - 1) {
            if(tabela[i][mask] != -LINF) {
              tabela[i][mask] *= countSetBits(mask);
            }
            aux = secoes[i].tTravessia;
          }

        } 
      }
    }
  }
} 

int main() {
  int N, K; cin >> N >> K;
  manobras.resize(K);
  secoes.resize(N);
  
  for(int i = 0; i < N; i++) {
    cin >> secoes[i].bonificacao;
    cin >> secoes[i].tTravessia;
  }

  for(int j = 0; j < K; j++) {
    cin >> manobras[j].pontuacao;
    cin >> manobras[j].tManobra;
  }

  long long tabelaY = pow(2, K);

  vector<vector<long long>> tabela(N, vector<long long>(tabelaY, 0));
  
  combinacoes(tabela, N, K);
  for(int i = 0; i < tabela.size(); i++) {
    for(int j = 0; j < tabela[i].size(); j++) {
      cout << tabela[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
