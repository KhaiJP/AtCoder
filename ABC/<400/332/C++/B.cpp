#include<iostream>
using namespace std;
int K, G, M, g, m;

int main(){
  cin >> K >> G >> M;
  while(K--){
    if(g == G){
      g = 0;
    }else if(m == 0){
      m = M;
    }else{
      if(G - g >= m){
        g += m;
        m = 0;
      }else{
        m -= G-g;
        g = G;
      }
    }
  }

  cout << g << ' ' << m << endl;
  return 0;
}