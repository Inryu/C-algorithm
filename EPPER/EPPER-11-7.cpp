#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<double> arr){

    if(arr.size()==1){
        cout<<arr[0];
    }

    //연쇄적으로 평균 구하기
    for(int i=0;i<arr.size()-1;i++){
        double avg=(arr[i]+arr[i+1])/2.0;
        arr[i+1]=avg;
    }

    //🌟소숫점 아래 6째 자리까지 출력하기
    cout<<fixed;
    cout.precision(6);

    cout<<arr[arr.size()-1];
}

int main() {
    int n;

    cin >> n;
    vector<double> arr(n);

    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        arr[i]=num;

    }

    //오름차순 정렬해야 제일 큰 평균을 구할 수 있음
    sort(arr.begin(),arr.end());

    solution(arr);
    return 0;
}
