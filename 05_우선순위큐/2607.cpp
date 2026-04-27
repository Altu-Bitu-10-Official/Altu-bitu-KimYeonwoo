#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string first_word;
    cin >> first_word;

    int first_count[26] = {0};

    for (int i = 0; i < first_word.length(); i++) {
        first_count[first_word[i] - 'A']++;
    }

    int answer = 0;

    for (int i = 0; i < n - 1; i++) {
        string word;
        cin >> word;

        int word_count[26] = {0};

        for (int j = 0; j < word.length(); j++) {
            word_count[word[j] - 'A']++;
        }

        int plus_cnt = 0;
        int minus_cnt = 0;

        for (int j = 0; j < 26; j++) {
            int diff = word_count[j] - first_count[j];

            if (diff > 0) {
                plus_cnt += diff;
            } else if (diff < 0) {
                minus_cnt += -diff;
            }
        }

        // 완전히 같음
        if (plus_cnt == 0 && minus_cnt == 0) {
            answer++;
        }
        // 하나 추가 or 하나 삭제
        else if (plus_cnt == 1 && minus_cnt == 0) {
            answer++;
        }
        else if (plus_cnt == 0 && minus_cnt == 1) {
            answer++;
        }
        // 하나 바꾸기
        else if (plus_cnt == 1 && minus_cnt == 1) {
            answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}