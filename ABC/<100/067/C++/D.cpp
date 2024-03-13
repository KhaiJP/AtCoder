#include<iostream>
#include<vector>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int N;
vector<int> E[100010], V, T;

void find_path_Fennec_to_Snuke(int me, int parent){
  T.push_back(me);
  if(me == N){
    V = T;
    return ;
  }

  for(auto child : E[me])if(child != parent){
    find_path_Fennec_to_Snuke(child, me);
  }
  T.pop_back();
  return ;
}


int size_of_tree(int me, int parent){
  int total = 1;
  for(auto child : E[me])if(child != parent){
    total += size_of_tree(child, me);
  }
  return total;
}


void solve(){
  int m = V.size();
  int mid_Fennec = V[m/2-(m%2==0)], mid_Snuke = V[m/2+(m%2==1)];
  int area_Fennec = size_of_tree(mid_Fennec, mid_Snuke);
  int area_Snuke  = size_of_tree(mid_Snuke, mid_Fennec);
  cout << (area_Fennec > area_Snuke ? "Fennec" : "Snuke") << endl;
}


int main(){
  cin >> N;
  rep(i, 1, N){
    int a, b; cin >> a >> b;
    E[a].push_back(b), E[b].push_back(a);
  }

  find_path_Fennec_to_Snuke(1, 0);
  solve();

  return 0;
}