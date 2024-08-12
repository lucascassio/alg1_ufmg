#include "bits/stdc++.h"

using namespace std;

const int64_t INF = 0x3f3f3f3f;
const int64_t LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int64_t> decisao;

struct secao {
  int64_t bonificacao;
  int64_t tTravessia;
};

struct manobra {
  int64_t pontuacao;
  int64_t tManobra;
};

vector<secao> secoes;
vector<manobra> manobras;

int64_t countSetBits(int64_t n) {
    int64_t count = 0;
    while(n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void combinacoes(vector<vector<int64_t>>& tabela, int64_t N, int64_t K) {
  for(int64_t i = 0; i < (1 << K); i++) {
    tabela[i][0] = 0;
    for(int64_t mask = 1; mask < (1 << K); mask++) {
      for(int64_t k = 0; k < K; k++) {
        if(mask & (1 << k)) {
          if((i & (1 << k)) && (mask & (1 << k))) {
            tabela[i][mask] += (manobras[k].pontuacao / 2) * countSetBits(mask);
          } else if ((i & (1 << k)) != (mask & (1 << k))) {
            tabela[i][mask] += manobras[k].pontuacao * countSetBits(mask);
          }      
        }
      }
    }
  }
}

bool tempo(int64_t mask, int64_t secao, int64_t K) {
  int64_t tempoSecao = secoes[secao].tTravessia;
  bool possivel = true;
  for(int64_t k = 0; k < K; k++) {
    if(mask & (1 << k)) {
      if(manobras[k].tManobra <= tempoSecao) {
        tempoSecao -= manobras[k].tManobra;
      } else if(manobras[k].tManobra > tempoSecao) {
        possivel = false;
        break;
      }
    }
  }

  return possivel;
}

int64_t dp(vector<vector<int64_t>>& tabela, vector<vector<int64_t>>& memo, vector<int64_t>& decisao, int64_t N, int64_t K, int64_t secao, int64_t manobra) {
    if(secao == N) {
        return 0;
    }

    if(memo[secao][manobra] != -LINF) {
        return memo[secao][manobra];
    }

    int64_t maxValue = 0;
    int64_t mask = 0;
    for(int64_t i = 0; i < (1 << K); i++) {
        if(tempo(i, secao, K)) {
            int64_t atualValue = tabela[manobra][i] * secoes[secao].bonificacao;
            atualValue += dp(tabela, memo, decisao, N, K, secao + 1, i);
            if(atualValue > maxValue) {
              maxValue = atualValue;
              mask = i;
            }
        }
    }
    memo[secao][manobra] = maxValue;
    decisao[secao] = mask;
    return maxValue;
}

int main() {
  int64_t N, K; cin >> N >> K;
  manobras.resize(K);
  secoes.resize(N);
  decisao.resize(N);
  
  for(int64_t i = 0; i < N; i++) {
    cin >> secoes[i].bonificacao;
    cin >> secoes[i].tTravessia;
  }

  for(int64_t j = 0; j < K; j++) {
    cin >> manobras[j].pontuacao;
    cin >> manobras[j].tManobra;
  }

  int64_t dim = pow(2, K);

  vector<vector<int64_t>> tabela(dim, vector<int64_t>(dim, 0));
  vector<vector<int64_t>> memo(N, vector<int64_t>(1 << K, -LINF));

  combinacoes(tabela, N, K);
  cout << dp(tabela, memo, decisao, N, K, 0, 0) << endl;
  for(int64_t i = 0; i < N; i++) {
    cout << countSetBits(decisao[i]) << " ";
    for(int64_t k = 0; k < K; k++) {
      if(decisao[i] & (1 << k)) {
        cout << k + 1 << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
