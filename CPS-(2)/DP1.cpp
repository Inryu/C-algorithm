#include <iostream>
using namespace std;


//🌟bottom up (점화식)
int dy[50];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    //직관적으로 알 수 있는 것
    dy[1]=1;
    dy[2]=2;

    for(int i=3;i<=n;i++){
        dy[i]=dy[i-2]+dy[i-1]; //점화식
    }

    cout<<dy[n];
}
