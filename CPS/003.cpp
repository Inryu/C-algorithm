#include <iostream>
using namespace std;

//진약수의 합
int main(){

    //1은 무조건 진약수이므로 먼저 출력하고 이후 +num 의 패턴으로 출력
    int n,i,sum=1; //sum 처음엔 1 안더해줬으니깐
    
    cin>>n;
    cout<<"1"; //모든 수의 진약수!

    for(i=2;i<n;i++){
        if(n%i==0){ //i는 n의 약수인 것
            cout<<" + "<<i;
            sum+=i;
        }
    }

    cout<<" = "<<sum;


    return 0;

}