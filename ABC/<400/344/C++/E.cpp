#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N, Q, inf = 1e9+1;

struct DubLinkedList{
  unordered_map<int, int> prevs;
  unordered_map<int, int> nexts;
  DubLinkedList(vector<int> V){
    vector<int> v(V.size()+2);
    v[0] = -inf, v[v.size()-1] = inf;
    rep(i, 1, v.size()-1) v[i] = V[i-1];
    rep(i, 0, v.size()-1){
      nexts[v[i]] = v[i+1];
      prevs[v[i+1]] = v[i];
    }
  }


  bool insert_back(int base, int item){
    if(prevs.count(base) == 0) return false;
    int nxt = nexts[base];
    nexts[base] = item;
    nexts[item] = nxt;
    prevs[nxt]  = item;
    prevs[item] = base;

    return true;
  }


  bool insert_front(int base, int item){
    if(prevs.count(base) == 0) return false;
    int pre = prevs[base];
    nexts[pre]  = item;
    nexts[item] = base;
    prevs[base] = item;
    prevs[item] = pre;
    return true;
  }


  bool erase(int base){
    if(prevs.count(base) == 0) return false;
    int pre = prevs[base];
    int nxt = nexts[base];

    prevs[nxt] = pre;
    nexts[pre] = nxt;

    prevs.erase(base);
    nexts.erase(base);
    return true;
  }
  

  void show_forward(){
    int idx = -inf;
    while(nexts[idx] != inf){
      idx = nexts[idx];
      cout << idx << '\n';
    }
  }


  void show_backward(){
    int idx = inf;
    while(prevs[idx] != -inf){
      idx = prevs[idx];
      cout << idx << '\n';
    }
  }
};


int main(){
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];

  DubLinkedList bdl(A);

  cin >> Q;
  while(Q--){
    int e, x; cin >> e >> x;
    if(e == 1){
      int y; cin >> y;
      bdl.insert_back(x, y);
    }
    if(e == 2){
      bdl.erase(x);
    }
  }
  bdl.show_forward();
  return 0;
}