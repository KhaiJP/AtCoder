#include<iostream>
#include<vector>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(ll i = (s); i < (t); ++i)

vector<ll> hist;
bool visited[200010];
ll answer, origin_index, N, K, A[200010], tail_sum, head_sum, period;

ll find_loop_origin(ll x){
  rep(i, 0, hist.size())if(hist[i] == x){
    return i;
  }
}

template <typename T>
void separate_head_and_tail(T a, vector<T> &V, vector<T> &head, vector<T> &tail){
  bool ishead = false;
  rep(i, 0, V.size()){
    if(!ishead) ishead = V[i] == a;

    if(ishead) head.push_back(A[V[i]]);
    else       tail.push_back(A[V[i]]);
  }
  for(auto a : head) head_sum += a;
  for(auto a : tail) tail_sum += a;
}

int main(){
  cin >> N >> K;
  rep(i, 0, N) cin >> A[i];

  // finding the point the loop begins -> origin_index
  hist.push_back(0);
  visited[0] = true;
  while(1){
    ll h = hist.back();
    h = (h + A[h]) % N;
    if(visited[h]){
      origin_index = find_loop_origin(h);
      break;
    }
    visited[h] = true;
    hist.push_back(h);
  }
  
  // divide hist into 2; non-looped part -> tail, and looped part -> head
  vector<ll> head, tail;
  separate_head_and_tail(hist[origin_index], hist, head, tail);
  ll hsize = head.size(), tsize = tail.size();

  if(K <= tsize){
    rep(i, 0, K) answer += tail[i];
    cout << answer << endl;
    return 0;
  }
  
  K -= tail.size();
  answer += tail_sum + (K / hsize) * head_sum;
  rep(i, 0, K%hsize) answer += head[i];
  cout << answer << endl;
  return 0;
}