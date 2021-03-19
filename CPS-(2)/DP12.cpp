#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//기
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, a, b, c;
    cin>>n>>m; //n개의 도시(노드), m개의 도로(엣지)

    //각 노드에서 노드로 가야하므로 n+1 * n+1 (1번~n번 까지의 인덱스 번호)
    vector<vector<int> > dis(n+1, vector<int>(n+1, 5000)); //맥스로 초기화

    for(int i=1; i<=n; i++) dis[i][i]=0; // 자기자신으로 가는 것은 0

    //인접행렬 초기화
    for(int i=1; i<=m; i++){
        cin>>a>>b>>c;
        dis[a][b]=c;
    }

    //k : 거치는 노드 (1~5)
    for(int k=1; k<=n; k++){

        // 2차원 배열 모두 살피면서
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){

                // k를 거치는 게 더 작으면 업데이트
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    //출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j]==5000){
                cout<<"M ";
            }
            else cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}