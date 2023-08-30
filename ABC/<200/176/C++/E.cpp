#include<iostream>
#include<set>
using namespace std;
using ll = int64_t;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

set<int> Rows[300010], Cols[300010];
int H, W, M, answer;

int main(){
  cin >> H >> W >> M;
  rep(i, 0, M){
    int h, w; cin >> h >> w;
    Cols[h].insert(w);
    Rows[w].insert(h);
  }

  // find the maximum numbers of bombs lay on a row/column
  int max_Rs = 0, max_Cs = 0;
  rep(r, 0, H+1) max_Cs = max(max_Cs, (int)Cols[r].size());
  rep(c, 0, W+1) max_Rs = max(max_Rs, (int)Rows[c].size());

  // collect the rows/columns that possess max_R/Cs bombs
  set<int> mrs; rep(r, 1, H+1)if(Cols[r].size() == max_Cs) mrs.insert(r);
  set<int> mcs; rep(c, 1, W+1)if(Rows[c].size() == max_Rs) mcs.insert(c);

  // if there is a pair r and c that do not share bomb, the answer is simple sum
  for(auto r : mrs)for(auto c : mcs){
    if(Cols[r].find(c) == Cols[r].end()){
      cout << max_Cs + max_Rs << endl;
      return 0;
    }
  }

  // if all the rows/columns in mr/cs share a bomb, the answer is the sum -1
  cout << max_Cs + max_Rs - 1 << endl;
  return 0;
}