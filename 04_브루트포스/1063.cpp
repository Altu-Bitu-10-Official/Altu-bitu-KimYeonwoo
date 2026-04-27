//N은 50보다 작거나 같은 자연수이고, 움직이는 정보는 위에 쓰여 있는 8가지 중 하나이다.
/*
A1 A2 5   킹의 위치, 돌의 위치, 움직이는 횟수 N, 둘째 줄부터 N개의 줄에는 킹이 어떻게 움직여야 하는지 주어진다. 
B
L
LB
RB
LT
*/   /* 첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치를 출력한다.
A1
A2*/

// 우선 움직임을 구현하는 반복문을 하나씩 8개 만든다. R L B T RT LT RB LB
// N만큼의 반복문을 수행해서 각 이름에 맞는 움직임을 수행하도록 한다.
// 움직일때마다 킹은 자신의 위치를 갱신한다.
// 킹의 위치 중 알파벳 갱신은 배열의 인덱스를 이용하여 갱신한다.
// 자신의 위치와 돌의 위치가 일치하면 돌도 그전의 킹과 똑같은 움직임으로 움직이게 된다. (즉, 킹이 먼저 움직이고, 업힌다음에 돌의 움직임을 후로 구현)

#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<char> al = {'A','B','C','D','E','F','G','H'};

  string cmd;
  char Ka, Sa;
  int Kn, Sn, N;

  cin >> Ka >> Kn >> Sa >> Sn >> N;

  // 알파벳들 배열내 위치로 맵핑
  for (int n = 1; n<=al.size(); n++) { //8로 다시 바꿔서 써보자. 시간 차이가 많이 날까?
    if(Ka == al[n]){
      int KA = n;
    }
    if(Sa == al[n]){
      int SA = n;
    }
  }

  for (int i = 0; i<N; i++){
    getline(cin, cmd);
    if(cmd == "R"){

    }
    if(cmd == "L"){

    }
    if(cmd == "B"){

    }
    if(cmd == "T"){

    }
    if(cmd == "RT"){
   
    }
    if(cmd == "LT"){
  
    }
    if(cmd == "RB"){
   
    }
    if(cmd == "LB"){
  
    }
    //한 움직임이 끝난 뒤에 돌의 위치와 겹치는지 확인
  }

}

