// 입력을 공백을 기준으로 두 수를 어떻게 나누면 될까. 입력을 문자열에서 int로 바꾸는게 필요할까

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  stack<char> s;
  string n1, n2;
  int carry = 0;

  cin >> n1 >> n2;

  int i = n1.size() - 1;
  int j = n2.size() - 1;

  while (i >= 0 || j >= 0 || carry) {
    int sum = carry;

    if (i >= 0) {
      sum += n1[i--] - '0';
    }
    if (j >= 0) {
      sum += n2[j--] - '0';
    }
    s.push((sum % 10) + '0');
    carry = sum / 10;
  }

  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}