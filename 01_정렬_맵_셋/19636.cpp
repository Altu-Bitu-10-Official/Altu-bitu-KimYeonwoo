#include <iostream>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
	  cin.tie(NULL);

    // 데시의 다이어트 전 체중 W0, 다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량 I0, 기초 대사량 변화 역치 T
    int W0, I0, T;

    //  데시의 다이어트 기간 D, 다이어트 기간 일일 에너지 섭취량 I, 다이어트 기간 일일 활동 대사량 A
    int D, I, A;

    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;

    // 기초대사량 변화 고려 X
    int w1 = W0;
    bool dead = false;
    int diff = I - (I0 + A);

    for (int day = 0; day < D; day++) {
      
        w1 += diff;
        if (w1 <= 0) {
            dead = true;
            break;
        }
    }
    
    if (dead) {
        cout << "Danger Diet" << '\n';
    } 
    else {
        cout << w1 << ' ' << I0 << '\n';
    }

    // 기초대사량 변화 고려 O
    int w2 = W0;
    int m = I0;
    dead = false;

    for (int day = 0; day < D; day++) {
        int diff = I - (m + A);

        // 체중
        w2 += diff;
        if (w2 <= 0) {
            dead = true;
            break;
        }

        // 기초대사량 
        if (abs(diff) > T) {
            if (diff >= 0) m += diff / 2;
            else m += (diff - 1) / 2;  

            if (m <= 0) {
                dead = true;
                break;
            }
        }
    }

    if (dead) {
        cout << "Danger Diet" << '\n';
    } 
    else {
        cout << w2 << ' ' << m << ' ';
        
        if (I0 > m) {
          cout << "YOYO" << '\n';
        }

        else cout << "NO" << '\n';
    }

    return 0;
}