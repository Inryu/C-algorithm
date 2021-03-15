#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);

    int n,m; // 동전의 종류 개수, 거슬러줄 금액

    cin>>n;
    vector<int> coin(n);

    for(int i=0;i<n;i++) cin>>coin[i];
    cin>>m;

    //🌟dy[j] : j원을 거슬러주는 데 사용된 동전의 최소 개수
    vector<int> dy(m+1,1000); //최대 값으로 초기화

    dy[0]=0; //직관적으로

    //코인 종류 하나씩 넣어보면서 dy배열 초기화
    for(int i=1;i<n;i++){
        for(int j=coin[i];j<=m;j++){
            // coin[i]를 사용하지 않거나, 사용하거나!
            dy[j]=min(dy[j],dy[j-coin[i]]+1);
        }
    }

    cout<<dy[m];

    return 0;


}