#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Order{
    int time;
    char color;
    Order(int t, int c) {
        time = t;
        color = c;
    }
    bool operator <(const Order &b)const{
        if(time==b.time) return color>b.color; //시간이 같으면 상민이가 먼저 시작
        return time>b.time; //최소힙
    }
};

int main(){
    int A, B, N;
    cin>>A>>B>>N;

    priority_queue <Order> pq;

    //만약에 상민이한테 1,2번 주문이 들어온다하자.
    //1번 주문을 포장하고 있는 중에 2번 주문이 들어오면, 1번이 끝나지 않으면 바로 시작(t)할 수 없으므로
    //1번 주문이 끝나는 시점을 기억하고 있다가 그때부터 시작해야 한다.
    int bEnd=-1;
    int rEnd=-1;
    for(int i=0;i<N;i++){
        int t,n;char c;
        cin>>t>>c>>n;

        if(c=='B'){
            if(bEnd>t) t=bEnd; // 아직 앞 주문이 끝나지 않은 상태라면
            for(int j=0;j<n;j++){
                pq.push(Order((t+A*j),'B')); //(✨포장 시작 시간, 색깔)
            }
            bEnd=(t+A*n); //현재 주문이 끝나는 시간 업데이트

        }else if(c=='R') {
            if(rEnd>t) t=rEnd; // 아직 앞 주문이 끝나지 않은 상태라면

            for (int j = 0; j <n; j++) {
                pq.push(Order((t+B*j), 'R')); //(✨포장 시작 시간, 색깔)
            }
            rEnd=(t+B*n); //현재 주문이 끝나는 시간 업데이트
        }
    }

    vector<int> sangmin;
    vector<int> jisu;

    int idx=1;
    while(!pq.empty()){

        //cout<<"["<<idx<<"] time : "<<pq.top().time<<" color : "<<pq.top().color<<"\n";

        char color=pq.top().color;
        pq.pop();
        if(color=='B'){
            sangmin.push_back(idx);
        }else{
            jisu.push_back(idx);
        }
        idx++;
    }
    cout<<sangmin.size()<<"\n";
    for(int i=0;i<sangmin.size();i++){
        cout<<sangmin[i]<<" ";
    }

    cout<<"\n"<<jisu.size()<<"\n";
    for(int i=0;i<jisu.size();i++){
        cout<<jisu[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

