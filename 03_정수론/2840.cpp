//아하 바퀴가 시계방향으로 돌아가면 화살표의 글자의 현현은 시계반대방향으로 나타나는 거구나!!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, K;
    cin >> N >> K;

    vector<char> ans(N, '?');   // 배열 초기화
    int arr = 0;                // 현재 화살표가 가리키는 위치

    for (int j = 0; j < K; j++) {
        int s;
        char ch;
        cin >> s >> ch;

        // 바퀴를 시계방향으로 s칸 돌렸으므로
        // 화살표가 가리키는 위치는 반대로 이동한 것처럼 처리
        arr = (arr - s % N + N) % N;

        // 이미 적혀 있는 글자와 다르면 모순
        if (ans[arr] != '?' && ans[arr] != ch) {
            cout << "!";
            return 0;
        }

        // 같은 알파벳이 다른 칸에 이미 있으면 모순
        for (int i = 0; i < N; i++) {
            if (i != arr && ans[i] == ch) {
                cout << "!";
                return 0;
            }
        }

        ans[arr] = ch;
    }

    // 마지막 회전에서 화살표가 가리키는 문자부터 시계방향 출력
    for (int i = 0; i < N; i++) {
        cout << ans[(arr + i) % N];
    }

    return 0;
}




