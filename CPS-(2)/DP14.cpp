#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n,m,a,b,score;
    cin>>n>>m;
    vector<vector<int>>graph(n+1, vector<int>(n+1)); //노드 개수 인접 행렬
    vector<int> degree(n+1); //🌟진입차수 저장
    queue<int> Q; //노드번호 넣을 것

    //간선 개수만큼, 입력받아서 인접행렬 만들고 degree배열까지 업데이트!
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a][b]=1;
        degree[b]++; //b로 들어오는 진입차수
    }

    //진입차수 0인 것 다 큐에 넣기
    for(int i=1;i<=n;i++){
        if(degree[i]==0) Q.push(i);
    }


    while(!Q.empty()){
        int tmp=Q.front();
        Q.pop();
        cout<<tmp<<" ";

        //tmp가 만들고 있는 진입차수 전부 제거
        for(int i=1;i<=n;i++){
            if(graph[tmp][i]==1){
                degree[i]--;

                if(degree[i]==0){
                    Q.push(i);
                }
            }
        }
    }

}



