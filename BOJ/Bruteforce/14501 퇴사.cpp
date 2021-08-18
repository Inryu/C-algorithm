#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> days(16);
int maxVal=-1;

//현재 day에 상담을 할 것이냐 말 것이냐.
void dfs(int day, int sum){
    if(day>N){
        maxVal=max(sum,maxVal);
        return;
    }

    //1. 포함
    if(day+days[day].first<=N+1) {
        dfs(day + days[day].first, sum + days[day].second);
    }

    //2. 포함X -> 다음날을 따져봄
    dfs(day+1,sum);
}

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int t, p;
        cin >> t >> p;
        days[i] = {t, p};
    }


    dfs(1, 0);
    cout<<maxVal<<"\n";

}