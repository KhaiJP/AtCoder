#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int A, B, C, D, E, F, answer;
pair<int, int> max_density;

void update(int water, int suger){
  int solution = water + suger;
  int max_solution = max_density.first, max_suger = max_density.second;
  if(suger * max_solution > max_suger * solution){
    max_density = {solution, suger};
  }
}

int main(){
  cin >> A >> B >> C >> D >> E >> F;
  A *= 100, B *= 100;
  if(min(A, B) > F){
    cout << A << ' ' << 0 << endl;
    return 0;
  }
  max_density.first = A;
  
  rep(na, 0, 31)rep(nb, 0, 31){
    int water = na * A + nb * B;
    if(water > F) break;
    int max_suger = min(F-water, (water/100) * E);
    int suger = 0;
    rep(nc, 0, 3001){
      int suger_C = nc * C;
      if(suger_C > max_suger) break;
      int rest_for_D = max_suger - suger_C;
      int suger_D = (rest_for_D/D) * D;
      suger = max(suger, suger_C + suger_D);
    }
    update(water, suger);
  }

  cout << max_density.first << ' ' << max_density.second << endl;
  return 0;
}