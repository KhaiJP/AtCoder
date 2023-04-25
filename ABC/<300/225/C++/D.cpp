#include<iostream>
#include<stack>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

pair<int, int> head_tail[100010];

int main(){
  int N, Q; cin >> N >> Q;

  rep(_, 0, Q){
    int e; cin >> e;
    
    if(e == 1){
      int x, y; cin >> x >> y;
      head_tail[x].second = y;
      head_tail[y].first = x;
    }

    if(e == 2){
      int x, y; cin >> x >> y;
      head_tail[x].second = 0;
      head_tail[y].first  = 0;
    }

    if(e == 3){
      int x; cin >> x;
      while(head_tail[x].second) x = head_tail[x].second;

      stack<int> st; st.push(x);
      while(head_tail[x].first) st.push(x = head_tail[x].first);

      cout << st.size() << ' ';
      while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
      }
      cout << endl;
    }
  }

  return 0;
}