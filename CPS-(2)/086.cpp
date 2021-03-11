#include<stdio.h>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

vector <pair<int,int>> home;
vector <pair<int,int>> pizza;
vector<int> ch;

int n,m,minval=2147000000;

void DFS(int s, int L){
    //s는 pizza 인덱스 조합
    if(L==m){
        int sum=0;
        for(int i=0;i<home.size();i++){ //각 집에서 피자배달거리 구하기
            int x1=home[i].first;
            int y1=home[i].second;

            int minhome=2146000;
            for(int j=0;j<m;j++){ //조합으로 선택된 피자가게
                int x2=pizza[ch[j]].first;
                int y2=pizza[ch[j]].second;

                int dis=abs(x1-x2)+abs(y1-y2);

                if(dis<minhome) minhome=dis; // 최소거리!
            }
            sum+=minhome; //sum에 누적
        }

        if(sum<minval) minval=sum; //어떤 조합이 제일 최소냐

    }else{
        for(int i=s;i<pizza.size();i++){
            ch[L]=i; //ch 배열에는 , pizza 벡터의 인덱스로 조합이 담긴다.
            DFS(i+1,L+1);
        }
    }
}

int main(){

    int i,j,num;
    scanf("%d %d",&n,&m);

    //m크기로 0으로 초기화
    ch.assign(m,0);

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&num);
            if(num==1){ //집
                home.push_back(make_pair(i,j)); //(x좌표,y좌표)
            }else if(num==2) { //피자집
                pizza.push_back(make_pair(i, j)); //(x좌표,y좌표)
            }
        }
    }
    DFS(0,0);// 조합 구하기

    printf("%d\n",minval);
}

