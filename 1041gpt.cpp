#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    int dice[6];
    int sum = 0;
    
    // 입력 처리
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    // 1면 (가장 작은 면) 찾기
    int min1 = *min_element(dice, dice + 6);

    // 2면 (인접한 두 면 중 가장 작은 면) 찾기
    int min2 = 51;  // 51로 초기화 (50보다 크니까)
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if ((i != j) && (i + j != 5)) {  // 반대면 제외
                min2 = min(min2, dice[i] + dice[j]);
            }
        }
    }

    // 3면 (인접한 세 면 중 가장 작은 면) 찾기
    int min3 = 51;  // 51로 초기화
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                if ((i + j != 5) && (i + k != 5) && (j + k != 5)) {
                    min3 = min(min3, dice[i] + dice[j] + dice[k]);
                }
            }
        }
    }

    // n == 1 일 때
    if (n == 1) {
        int max1 = *max_element(dice, dice + 6);
        sum = accumulate(dice, dice + 6, 0);
        cout << sum - max1 << endl;
        return 0;
    }

    // n == 2 일 때
    if (n == 2) {
        cout << 4 * (min2 + min3) << endl;
        return 0;
    }

    // n >= 3 일 때
    if (n >= 3) {
        cout << 4 * (min3 + 2 * n * min2 + (n - 2) * (n - 2) * (n - 2) * min1) << endl;
    }

    return 0;
}
