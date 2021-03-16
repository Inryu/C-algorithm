#include <iostream>
#include <string>
using namespace std;

int solution(string str){
    char f=str.front();

    if(f=='1') cout<<"1";

    int cnt=0;

    //마지막 문자 전과 마지막 문자까지 비교
    for(int i=0;i<str.size()-1;i++){
        //바로 다음 문자와 같으면
        if(str[i]==str[i+1])
            cnt++; //카운트 증가

            //다르면 출력
        else{
            cout<<(char)('A'+cnt);
            cnt=0;//카운트 초기화
        }
    }

    //마지막
    cout<<(char)('A'+cnt);

    return 0;
}

int main() {
    string str;
    cin>>str;

    solution(str);
}