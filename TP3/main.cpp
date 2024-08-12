#include <bits/stdc++.h>

using namespace std;

const int64_t INF = 0x3f3f3f3f;
const int64_t LINF = 0x3f3f3f3f3f3f3f3fll;

struct secao {
  int64_t bonificacao;
  int64_t tTravessia;
};

struct manobra {
  int64_t pontuacao;
  int64_t tManobra;
};

struct sequencia {
  int64_t pontuacao;
  int64_t seq;
  
  sequencia(int64_t p = -LINF, int64_t s = 0) : pontuacao(p), seq(s) {}
};

vector<secao> secoes;
vector<manobra> manobras;

int64_t contaBits(int64_t n) {
    int64_t count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

void combinacoes(vector<vector<int64_t>>& tabela, int64_t K) {
  for (int64_t i = 0; i < (1 << K); i++) {
    for (int64_t mask = 0; mask < (1 << K); mask++) {
      tabela[i][mask] = 0;
      for (int64_t k = 0; k < K; k++) {
        if (mask & (1 << k)) {
          if ((i & (1 << k)) && (mask & (1 << k))) {
            tabela[i][mask] += (manobras[k].pontuacao / 2) * contaBits(mask);
          } else if ((i & (1 << k)) != (mask & (1 << k))) {
            tabela[i][mask] += manobras[k].pontuacao * contaBits(mask);
          }      
        }
      }
    }
  }
}

bool tempo(int64_t mask, int64_t secao, int64_t K) {
  int64_t tempoSecao = secoes[secao].tTravessia;
  for (int64_t k = 0; k < K; k++) {
    if (mask & (1 << k)) {
      if (manobras[k].tManobra <= tempoSecao) {
        tempoSecao -= manobras[k].tManobra;
      } else {
        return false;
      }
    }
  }
  return true;
}

int64_t dp(vector<vector<int64_t>>& tabela, vector<vector<sequencia>>& memo, int64_t N, int64_t K, int64_t secao, int64_t manobra) {
    if (secao == N) {
        return 0;
    }

    if (memo[secao][manobra].pontuacao != -LINF) {
        return memo[secao][manobra].pontuacao;
    }

    int64_t maxValue = 0;
    for (int64_t i = 0; i < (1 << K); i++) {
        if (tempo(i, secao, K)) {
            int64_t atualValue = tabela[manobra][i] * secoes[secao].bonificacao;
            atualValue += dp(tabela, memo, N, K, secao + 1, i);
            if (atualValue > maxValue) {
                maxValue = atualValue;
                memo[secao][manobra].seq = i;
            }
        }
    }
    memo[secao][manobra].pontuacao = maxValue;

    return maxValue;
}

void seqManobras(vector<vector<sequencia>>& memo, int64_t N, int64_t K, int64_t secao, int64_t manobra) {
  if(secao == N) {
    return;
  }

  int64_t mask = memo[secao][manobra].seq;
  cout << contaBits(mask) << " ";
  
  for(int k = 0; k < K; k++) {
    if(mask & (1 << k)) {
      cout << k + 1 << " ";
    }
  } 
  cout << endl;

  seqManobras(memo, N, K, secao + 1, mask);
}

int main() {
  int64_t N, K;
  cin >> N >> K;

  manobras.resize(K);
  secoes.resize(N);

  for (int64_t i = 0; i < N; i++) {
    cin >> secoes[i].bonificacao >> secoes[i].tTravessia;
  }

  for (int64_t j = 0; j < K; j++) {
    cin >> manobras[j].pontuacao >> manobras[j].tManobra;
  }

  int64_t dim = pow(2, K);

  vector<vector<int64_t>> tabela(dim, vector<int64_t>(dim, 0));
  vector<vector<sequencia>> memo(N, vector<sequencia>(dim));

  combinacoes(tabela, K);
  cout << dp(tabela, memo, N, K, 0, 0) << endl;

  seqManobras(memo, N, K, 0, 0); 

  return 0;
}
