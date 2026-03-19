#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Sum(const string& s) {
    int sum = 0;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }
    return sum;
}

bool cmp(const string& a, const string& b) {

    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    int sumA = Sum(a);
    int sumB = Sum(b);
    if (sumA != sumB) {
        return sumA < sumB;
    }
    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> serials(n);
    for (int i = 0; i < n; i++) {
        cin >> serials[i];
    }

    sort(serials.begin(), serials.end(), cmp);

    for (const string& s : serials) {
        cout << s << '\n';
    }

    return 0;
}