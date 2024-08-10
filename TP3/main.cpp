#include "bits/stdc++.h"

using namespace std;

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<long long>> decisao;

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
  for(int i = 0; i < (1 << K); i++) {
    tabela[i][0] = 0;
      for(int mask = 1; mask < (1 << K); mask++) {
        for(int k = 0; k < K; k++) {
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

bool tempo(long long mask, long long secao, long long K) {
  long long tempoSecao = secoes[secao].tTravessia;
  bool possivel = true;
  for(int k = 0; k < K; k++) {
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

long long dp(vector<vector<long long>>& tabela, vector<vector<long long>>& memo, long long N, long long K, long long secao, long long manobra) {
    if(secao == N) {
        return 0;
    }

    if(memo[secao][manobra] != -LINF) {
        return memo[secao][manobra];
    }

    long long maxValue = 0;
    for(int i = 0; i < (1 << K); i++) {
        if(tempo(i, secao, K)) {
            long long atualValue = tabela[manobra][i] * secoes[secao].bonificacao;
            atualValue += dp(tabela, memo, N, K, secao + 1, i);
            maxValue = max(atualValue, maxValue);
            memo[secao][i] = manobra;
            memo[secao][manobra] = maxValue;
        }
    }
    return maxValue;
}

int main() {
  int N, K; cin >> N >> K;
  manobras.resize(K);
  secoes.resize(N);
  decisao.resize(N, vector<long long>(1 << K));
  
  for(int i = 0; i < N; i++) {
    cin >> secoes[i].bonificacao;
    cin >> secoes[i].tTravessia;
  }

  for(int j = 0; j < K; j++) {
    cin >> manobras[j].pontuacao;
    cin >> manobras[j].tManobra;
  }

  long long dim = pow(2, K);

  vector<vector<long long>> tabela(dim, vector<long long>(dim, 0));
  vector<vector<long long>> memo(N, vector<long long>(1 << K, -LINF));

  combinacoes(tabela, N, K);
  cout << dp(tabela, memo, N, K, 0, 0) << endl;
  return 0;
}
