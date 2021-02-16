#include <iostream>
using namespace std;

int main(){
    //파일 입출력으로 해볼려면?
    freopen("input.txt","rt",stdin); //cin이 읽을 때마다 지정 파일에서 읽어줌

    int n,i,min=2147000000,max=-2147000000,age ;
    //min은 int중 가장 큰 수로, max는 가장 작은 수로 초기화

    cin>>n;
    for(i=0;i<n;i++){
        cin>>age;
        if(age<min) min=age;
        else if(age>max) max=age;
    }

    cout<<max-min;
    return 0;

}