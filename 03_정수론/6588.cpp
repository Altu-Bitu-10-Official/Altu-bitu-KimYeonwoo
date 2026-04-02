#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 소수 판별 
    vector<bool> isPrime(MAX + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    // 에라토스테네스의 체
    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int n;
    
    while (cin >> n) {
        if (n == 0) break;
        bool found = false;

        // a를 작은 소수부터 탐색하면 b-a가 가장 큰 경우를 먼저 찾게 됨
        for (int a = 3; a <= n/2; a += 2) {
            if (isPrime[a] && isPrime[n - a]) {
                cout << n << " = " << a << " + " << (n - a) << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}