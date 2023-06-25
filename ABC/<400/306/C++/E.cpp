#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

multiset<int> biggers, smallers;
int N, K, Q, A[500010];
ll S;

void init();
void update(int old, int new_);
void _balance();

int main(){
  cin >> N >> K >> Q;
  init();
  rep(i, 0, Q){
    int X, Y; cin >> X >> Y; --X;
    int old = A[X], new_ = Y;
    A[X] = Y;
    update(old, new_);
    
    cout << S << endl;
  }
  return 0;
}



void init(){
  rep(i, 0, K) biggers.insert(0);
  rep(i, K, N) smallers.insert(0);
}

void update(int old, int new_){
  auto itr_old = biggers.find(old);
  if(itr_old != biggers.end()){
    biggers.erase(itr_old);
    biggers.insert(new_);
    S += new_ - old;
  }

  else{
    auto itr_old_ = smallers.find(old);
    smallers.erase(itr_old_);
    smallers.insert(new_);
  }
  if(N == K) return ; 
  _balance();
}

void _balance(){
  int minBigger = *biggers.begin();
  auto itr_maxSmaller = smallers.end(); --itr_maxSmaller;
  int maxSmaller = *itr_maxSmaller;

  if(minBigger < maxSmaller){
    biggers.erase(biggers.begin());
    biggers.insert(maxSmaller);

    smallers.erase(itr_maxSmaller);
    smallers.insert(minBigger);
    
    S += maxSmaller - minBigger;
  }
}