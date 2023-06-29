#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// rate[i] : the rate of infant i,  belonging[i] : current belonging of infant i
int rate[200010], belonging[200010];
int N, Q;
// set of highest rate of each non-empty kindergarten
multiset<int> S;
// garten[j] : set of {rate[i], i}
multiset<pair<int, int>> garten[200010];

template<typename T>
T get_max(multiset<T> &s){
  auto itr = s.end();
  --itr;
  return *itr;
}

template<typename T>
bool erase_once(multiset<T> &s, T target){
  auto itr = s.find(target);
  if(itr == s.end()) return false;
  s.erase(itr);
  return true;
}

int main(){
  cin >> N >> Q;
  rep(i, 1, N+1){
    cin >> rate[i] >> belonging[i];
    garten[belonging[i]].insert({rate[i], i});
  }

  rep(i, 0, 200010)if(!garten[i].empty()){
    int max_rate = get_max(garten[i]).first;
    S.insert(max_rate);
  }

  while(Q--){
    int C, D; cin >> C >> D;

    // get info of infant C
    int current = belonging[C];
    int rate_C = rate[C];

    // erase C from the garten C belongs
    garten[current].erase({rate_C, C});
    if(!garten[current].empty()){
      int max_garten = get_max(garten[current]).first;
      if(rate_C > max_garten){
        erase_once(S, rate_C);
        S.insert(max_garten);
      }
    }else erase_once(S, rate_C);

    // move C to garten[D]
    if(garten[D].empty()) S.insert(rate_C);
    else{
      int max_garten_D = get_max(garten[D]).first;
      if(max_garten_D < rate_C){
        erase_once(S, max_garten_D);
        S.insert(rate_C);
      }
    }
    garten[D].insert({rate_C, C});
    belonging[C] = D;

    cout << *S.begin() << endl;
  }
  return 0;
}