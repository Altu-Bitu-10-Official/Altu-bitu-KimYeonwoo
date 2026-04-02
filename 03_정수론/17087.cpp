//즉, 동생과 수빈이와의 거리를 같게 만들 수 있는 최소 거리를 구하라는 거다.
//N은 반복문으로 쓰인다.
//우선 S와 A들의 차이들을 구한 다음, 벡터에 저장한다. 
//그 차이들의 최대공약수를 구하자.
//여러 개의 최대공약수는 어떻게 구하면 되지..? -> a와 b의 최대공약수인 d를 구하고, c와 d의 최대공약수를 구하면?

#include <iostream>
#include <vector>

using namespace std;

int getGcdRecur(int a, int b){ //a가 큼
  if (b == 0) {
    return a;
  }
  return getGcdRecur(b, a%b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vector<int> arr;

  int N,S;
  cin >> N >> S;

  for (int i=0; i<N; i++){     // 언니와 동생들의 차이를 arr에 배열로 저장함
    int A;
    cin >> A;
    int d = abs(S - A);       //절댓값 처리 꼭 하기!
    arr.push_back(d);         //arr[i] = d; 로 작성함: 빈 배열에 접근하게됨 -> 런타임에러 outofbound의 원인
  }

  for (int j = 0; j<N-1; j++){ //최대공약수를 구하는 반복문. 차이(동생의 수)가 3개이면 2번 실행됨  
    int n1 = arr[0];   //차이1
    int n2 = arr[1];   //차이2

    int m = getGcdRecur(max(n1,n2), min(n1,n2)); //return된 a의 값을 다시 이 배열에 넣어야 한다.
    arr.push_back(m);

    arr.erase(arr.begin());
    arr.erase(arr.begin());
  }

  cout << arr[0];

}