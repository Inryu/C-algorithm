#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][21],dy[21][21];

//#8 알리바와 40인의 도둑 (Bottom-up)
int main(){
    ios_base::sync_with_stdio(false);

    int n,cnt=0;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    dy[0][0]=arr[0][0]; //직관적으로 초기화
    //dy[i][j] : 출발점 (0,0)에서 (i,j)까지 가는 데 드는 최소 비용

    //0행, 0열은(가장자리) 경로가 1가지 이므로 초기화
    for(int i=1;i<n;i++){
        dy[0][i]=dy[0][i-1]+arr[0][i];
        dy[i][0]=dy[i-1][0]+arr[i][0];
    }

    //~~✨dynamic
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            //위에서 오거나 왼쪽에서 옴
            dy[i][j]=min(dy[i][j-1],dy[i-1][j])+arr[i][j];
        }
    }

    cout<<dy[n-1][n-1];

}