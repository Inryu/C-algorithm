#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    int n, m, w, v;

    cin >> n >> m;
    vector<int> dy(m + 1, 0); //무게제한 m의 인덱스까지 받아야

    for (int i = 0; i < n; i++) {
        cin >> w >> v;

        for (int j = w; j <= m; j++) {
            dy[j] = max(dy[j], dy[j - w] + v); //max(기존 값 , w를 담았다고 칠 때)
        }
    }

    cout<<dy[m];
    return 0;
}