#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);

    int n,res=0;
    cin>>n;
    vector<int> arr(n+1), dy(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }


    //dy[i] : arr[i]가 내가 만드는 증가수열의 마지막 원소일 때, 그 중 가장 긴 수열의 길이
    dy[1]=1;

    //dynamic
    for(int i=2;i<=n;i++){
        int max=0;

        //앞에 원소들을 차례로 살피면서
        for(int j=i-1;j>=1;j--){

            //앞에 값이 더 작으면 (해당 원소를 arr[i]바로 앞에 두고 중가수열을 만들 수 있으면)
            if(arr[j]<arr[i]&&dy[j]>max){ //그리고 앞에 원소들 중, 해당 원소를 가장 마지막 원소로하는 증가수열의 최대 길이값!!
                max=dy[j];
            }
        }
        dy[i]=max+1; //자기 바로 앞에 해당 원소를 둔 거니까

        if(dy[i]>res) res=dy[i]; //이건 전체에서 만들 수 있는 최대 길이 바로바로 구해주기
    }

    cout<<res;
}