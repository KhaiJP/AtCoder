#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)
#define fore(a, v) for(auto a : v)

ll A[20][20];
vector<pair<ll, ll>> V;
bool used[20];
int N;

ll dfs(){
  if(V.size() == N){
    ll ret = 0;
    fore(p, V) ret ^= A[p.first][p.second];
    return ret;
  }

  int l;
  rep(i, 1, 2*N+1)if(!used[i]){
    l = i;
    break;
  }used[l] = true;

  ll ret = 0;
  rep(i, l+1, 2*N+1)if(!used[i]){
    V.push_back({l, i});
    used[i] = true;
    ret = max(ret, dfs());
    V.pop_back();
    used[i] = false;
  }used[l] = false;
  
  return ret;
}

int main(){
  cin >> N;
  rep(i, 1, 2*N)rep(j, i+1, 2*N+1) cin >> A[i][j];

  cout << dfs() << endl;
  return 0;
}


// TLE algorithm
// #include<algorithm>
// #include<set>
// ll A[20][20], V[20], B[10];
// int group[20];

// int main(){
//   int N; cin >> N;
//   rep(i, 0, 2*N-1)rep(j, i+1, 2*N) cin >> A[i][j];
  
//   rep(i, 0, N)rep(j, 0, 2) V[2*i+j] = i;
  
//   ll answer = 0;

//   do{
//     vector<int> group[N];
//     rep(k, 0, 2*N) group[V[k]].push_back(k);
//     rep(k, 0, N) B[k] = A[group[k][0]][group[k][1]];

//     ll tmpans = 0;
//     rep(i, 0, N) tmpans = tmpans ^ B[i];
//     answer = max( answer, tmpans );
//   }while(next_permutation(V, V+2*N));
  
//   cout << answer << endl;
//   return 0;
// }