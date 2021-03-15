#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//// ❌ 문제당 한 번만 풀 수 있으므로 이렇겐 안 됨!!!
//int main(){
//    ios_base::sync_with_stdio(false);
//
//    int n,m; //문제 개수,제한 시간
//    int s,t; //각 문제의 점수, 푸는데 걸리는 시간
//    cin>>n>>m;
//
//    //dy[j] : j시간동안 풀 수 있는 최대 점수
//    vector<int> dy(m+1,0);
//
//
//    //각 문제들!
//    for(int i=0;i<n;i++){
//        cin>>s>>t; //점수, 푸는데 걸리는 시간
//
//        for(int j=t;j<=m;j++){
//            //풀지 않거나, 풀거나
//            dy[j]=min(dy[j],dy[j-t]+s);
//        }
//    }
//
//    cout<<dy[m];
//    return 0;
//}

int main(){
    ios_base::sync_with_stdio(false);
    int n,m; //문제 종류, 제한 시간
    int ps,pt; //문제 점수, 문제 시간;

    cin>>n>>m;
    vector<int> dy(m+1);; //🌟1차원 배열로 구현하기!

    for(int i=0;i<n;i++){ //문제 유형 한 행씩 읽으면서
        cin>>ps>>pt;

        //🌟거꾸로 돌기!! 제한시간 부터 pt까지!!!!
        for(int j=m;j>=pt;j--) {
            //max( 풀 거나, 안 풀거나)
            dy[j] = max(dy[j], dy[j - pt] + ps);
        }
    }
    cout<<dy[m];
    return 0;
}
