#include<iostream>
using namespace std;

int N, M, leader=200010, maximum, cnt[200010];

int main(){
  cin >> N >> M;
  for(int i = 0; i < M; ++i){
    int a; cin >> a;
    ++cnt[a];
    if(cnt[a] > maximum){
      leader = a;
      maximum = cnt[a];
    }else if(cnt[a] == maximum){
      leader = min(leader, a);
    }
    cout << leader << endl;
  }
  return 0;
}