#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); //입출력 속도 향상 (동기화 해제)

    //어떤 알파벳이 가장 많이 있는지
    map<string,int> ch;

    //접근하기 위한 반복자 필요
    map<string,int>::iterator it;


    //단어 읽기
    char a[1000];
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >>a;
        ch[a]++; //단어(string)가 key가 됨.
    }

    int max=0;
    string res;

    //map의 처음 위치,마지막 위치
    for(it=ch.begin();it!=ch.end();it++){ //오름차순 정렬로 접근
        if(it->second>max){
            max=it->second;
            res=it->first;
        }
    }
    cout<<res<<" : "<<max<<"\n";

}
