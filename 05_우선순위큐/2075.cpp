#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> small_heap;

    int num;

    for (int i = 0; i < n * n; i++) {
        cin >> num;

        small_heap.push(num);

        // 힙 크기가 n보다 커지면 제일 작은 값 제거
        if (small_heap.size() > n) {
            small_heap.pop();
        }
    }

    cout << small_heap.top() << "\n";

    return 0;
}