#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int answer[100010], p[100010], index, N;

void run_length(string S){
  int l = 0;
  char current = 'R';
  rep(i, 0, N){
    if(S[i] == current) ++l;
    else{
      p[index] = l;
      l = 1;
      current = S[i];
      ++index;
    }
  }
  p[index] = l;
  ++index;
}

int main(){
  string S; cin >> S;
  N = S.size();
  run_length(S);
   
  int j = 0;
  rep(i, 0, index){
    // checking Ls
    if(i & 1){
      answer[j-1] += p[i]/2;
      answer[j]   += (p[i]+1)/2;
    }
    // checking Rs
    else{
      answer[j+p[i]]   += p[i]/2;
      answer[j+p[i]-1] += (p[i]+1)/2;
    }
    j += p[i];
  }

  rep(i, 0, N) cout << answer[i] << ' '; cout << endl;
  return 0;
}