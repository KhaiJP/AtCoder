#include<iostream>
#include<atcoder/all>
using namespace std;
using UF = atcoder::dsu;

int N, M;

int main(){
  cin >> N >> M;
  UF uf(N);
  for(int _ = 0; _ < M; ++_){
    int x, y, z; cin >> x >> y >> z;
    --x, --y;
    uf.merge(x, y);
  }
  cout << uf.groups().size() << endl;
}