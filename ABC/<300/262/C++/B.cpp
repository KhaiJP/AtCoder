#include<iostream>
#include<set>
using namespace std;
typedef pair<int,int> pr;
#define rep(i,s,t) for(int i=(s); i<(t); ++i)


int main(){
  int N, M; cin >> N >> M;
  set<pr> S;
  rep(i,0,M){
    int U, V; cin >> U >> V;
    S.insert({U-1,V-1});
    S.insert({V-1,U-1}); 
  }
  int answer = 0;
  rep(a,0,N)rep(b,a+1,N)rep(c,b+1,N){
    bool flag_ab = S.count({a,b}) == 1 || S.count({a,b}) == 1;
    bool flag_bc = S.count({b,c}) == 1 || S.count({c,b}) == 1;
    bool flag_ca = S.count({c,a}) == 1 || S.count({a,c}) == 1;
    if(flag_ab && flag_bc && flag_ca) answer += 1;
  }
  cout << answer << endl;
  return 0;
}