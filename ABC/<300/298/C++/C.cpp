#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

multiset<int> box_to_cards[200010];
set<int> card_to_boxes[200010];

int main(){
  int N, Q; cin >> N >> Q;

  rep(i, 0, Q){
    int e; cin >> e;
    if(e == 1){
      int card, box; cin >> card >> box;
      box_to_cards[box].insert(card);
      card_to_boxes[card].insert(box);
    }

    if(e == 2){
      int box; cin >> box;
      for(auto card : box_to_cards[box]) cout << card << ' ';
      cout << '\n';
    }
    
    if(e == 3){
      int card; cin >> card;
      for(auto box : card_to_boxes[card]) cout << box << ' ';
      cout << '\n';
    }
  }

  cout << endl;
  return 0;
}