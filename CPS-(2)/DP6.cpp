#include <iostream>
#include <vector>
using namespace std;

struct Brick{
    int s; //넓이
    int h; //높이
    int w; //무게

    Brick(int a,int b,int c){
        s=a;
        h=b;
        w=c;
    }

    //넓이 기준으로 내림차순
    bool operator<(const Brick &b) const{
        return s>b.s;
    }

};

int main(){
    ios_base::sync_with_stdio(false);

    int n,a,b,c,max_h=0,res=0;

    cin>>n;
    vector<Brick> Bricks;
    vector<int> dy(n,0); // dy[i] : i벽돌이 제일 꼭대기에 있다고 가정할 때, 탑의 최대 높이

    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        Bricks.push_back(Brick(a,b,c));
    }

    sort(Bricks.begin(), Bricks.end()); //밑면의 넓이 기준으로 정렬(내림차순)

    dy[0]=Bricks[0].h; //0번이 꼭대기에 있으면 밑에는 둘 수 있는 게 아무 것도 없으니깐 자기높이가 최대
    res=dy[0]; //dy 배열 값중 최대 값을 찾아 저장할 것

    //dynamic~~✨
    for(int i=1;i<=n;i++){
        max_h=0;
        // i번째 벽돌이 가장 위에 있다고 가정
        for(int j=i=1;j>=0;j--){

            //그 때에 i 앞에 벽돌을을 살핌
            if(Bricks[j].w>Bricks[i].w&&dy[j]>max_h) { //나보다 앞에 벽돌이 무거워야 됨
                    //+ 그 중 가장 큰 높이를 가진 것
                    max_h=dy[j];
            }
        }
        dy[i]=max_h+Bricks[i].h;
        if(dy[i]>res) res=dy[i]; //전체 중 최대값 찾기 (dy배열의 최대값)
    }

    cout<<res;
    return 0;

}
