// 99퍼까지 간 후에 fail: n=1일 때의 처리를 따로 해줘야 했다.

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int n;

void discard() {
    dq.pop_front();
}

void totheback() {
  int x = dq.front();
  dq.pop_front();
  dq.push_back(x);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> n;

  for (int i = n; i>0; i--){
      dq.push_front(i);
    }
  
  if(n != 1){
    for (int j=n-2; j>0; j--){
      discard(); //버리는 건 n-1번해야한다. 
      totheback(); 
    }
    discard();
  }
  cout << dq.front();
}

