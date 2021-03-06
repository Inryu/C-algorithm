
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Loc{
    int x,y,z;

    //🌟구조체 생성자
    Loc(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }

    // 연산자 오버로딩 / 비교연산자 "<"
    //상수 함수 -> 멤버변수 바꾸지 못하게
    bool operator <(const Loc &b) const{ //구조체를 주소로 받음 //const로 원본 바꾸지 못하게
        return x<b.x; //호출한 객체 < 매개변수 객체
        //앞에꺼가 작은 오름차순으로 정렬해라.ㅏ x를 기준으로!!
    }
};

int main(){
    vector <Loc> XY;
    XY.push_back(Loc(2,3,5));
    XY.push_back(Loc(3,6,7));
    XY.push_back(Loc(2,3,1));
    XY.push_back(Loc(5,2,3));
    XY.push_back(Loc(3,1,6));

    sort(XY.begin(),XY.end());

    for(auto pos : XY) cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;

}