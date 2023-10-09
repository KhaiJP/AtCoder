#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

ll N, X, M, answer;
bool visited[100010];

template <typename T>
void separate_head_and_tail(T a, vector<T> &V, vector<T> &head, vector<T> &tail){
  bool ishead = false;
  rep(i, 0, V.size()){
    if(!ishead) ishead = V[i] == a;

    if(ishead) head.push_back(V[i]);
    else tail.push_back(V[i]);
  }
}

template <typename T>
T summation(vector<T> &v){
  T s = 0;
  for(T a : v) s += a;
  return s;
}

int main(){
  cin >> N >> X >> M;
  vector<ll> v;
  ll A = X;
  while(true){
    if(visited[A]) break;
    visited[A] = true;
    v.push_back(A);
    A = A*A % M;
  }

  vector<ll> head, tail;
  separate_head_and_tail(A, v, head, tail);
  ll head_size = head.size(), tail_size = tail.size();

  if(N <= tail_size){
    rep(i, 0, N) answer += tail[i];
    cout << answer << endl;
    return 0;
  }

  ll tail_sum = summation(tail), head_sum = summation(head);

  answer += tail_sum;
  N -= tail_size;
  
  answer += (N/head_size) * head_sum;
  N %= head_size;
  
  rep(i, 0, N) answer += head[i];
  cout << answer << endl;
  return 0;
}