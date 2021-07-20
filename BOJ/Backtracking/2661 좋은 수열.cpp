#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[81]; //정답 배열


// 1부터 ~idx까지 좋은 배열인지 체크
bool valid(int idx){

    int cnt=0;
    for(int i=2;i<=idx/2;i++){ //비교할 문자 길이.
        for(int j=1;j<=idx-i;j++){ //비교 시작할 앞 문자 인덱스
            cnt=0;
            for(int k=j; k<i+j; k++){
                if(i+k > idx) continue;
                if(arr[k] == arr[k+i]) cnt++;
            }
            if(cnt == i) return 0;
        }
    }

    return 1;

}

void dfs(int idx){
    if(idx>N){ //종료 조건
        for(int i=1;i<=N;i++) cout<<arr[i];
        exit(0); //제일 처음 나온 것만 출력하고 끝!
    }
    //1->2->3 순서대로 넣어보면서, 좋은 수열인지 판단!
    for(int i=1;i<=3;i++){
        if(arr[idx-1]==i) continue; //바로 이전꺼와 같은 걸 넣을 수 없음!
        arr[idx]=i;
        if(valid(idx)) dfs(idx+1);
    }
}


int main(){
    cin>>N;
    dfs(1);
}
