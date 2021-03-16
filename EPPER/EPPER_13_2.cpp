#include <iostream>
#include <vector>
using namespace std;

void solution(int n){
    vector<int> dy(n+1);


    dy[1]=1;
    dy[2]=2;

    //점화식 bottom-up 방식 이용
    for(int i=3;i<=n;i++){
        dy[i]=dy[i-1]+dy[i-2];
    }
    cout<<"계단 오르는 방법의 수 : "<<dy[n]<<"\n";

}

int main(){

    int n;
    cout<<"계단의 수를 입력하시오 : ";
    cin>>n;

    solution(n);


}

