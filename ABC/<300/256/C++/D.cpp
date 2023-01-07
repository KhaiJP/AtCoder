#include<iostream>
#include<vector>

using namespace std;
typedef pair<int,int> pr;
#define rep(i,s,t) for(int i = (s); i < (t); ++i)

int main(){
  int N; cin >> N;
  const int M = 2*100000;
  vector<int> imos(M+1, 0);
  rep(i,0,N){
    int L, R; cin >>  L >> R;
    imos[L]++; imos[R]--;
  }
  rep(i,0,M+1) imos[i] += imos[i-1];
  vector<pr> answer;
  int index = 0;
  while(index <= M){
    if(imos[index] == 0)index += 1;
    else{
      int l = index;
      while(index<M && imos[index+1]!=0){
        index++;
      }
      int r = ++index;
      answer.push_back({l,r});
    }
  }
  for(auto p : answer) cout << p.first << ' ' << p.second << '\n';
  cout << endl;
  return 0;
}