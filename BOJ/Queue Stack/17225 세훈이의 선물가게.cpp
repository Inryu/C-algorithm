#include <iostream>
#include <algorithm>
#include <stack>
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
        if(time==b.time) return color>b.color;
        if(color!=b.color) return time<b.time;
    }
};

int main(){
    int A, B, N;
    cin>>A>>B>>N;

     vector<Order> st;

    //만약에 상민이한테 1,2번 주문이 들어온다하자.
    //1번 주문을 포장하고 있는 중에 2번 주문이 들어오면, 1번이 끝나지 않으면 바로 시작(t)할 수 없으므로
    //1번 주문이 끝나는 시점을 기억하고 있다가 그때부터 시작해야 한다.
    int bEnd=-1;
    int rEnd=-1;
    for(int i=0;i<N;i++){
        int t,n;
        char c;
        cin>>t>>c>>n;

        if(c=='B'){
            if(bEnd>t) t=bEnd; // 아직 앞 주문이 끝나지 않은 상태라면
            for(int j=1;j<=n;j++){
                st.push_back(Order((t+A*j),'B')); //(포장 끝나는 시간, 색깔)
            }
            bEnd=(t+A*n);

        }else if(c=='R') {
            if(rEnd>t) t=rEnd; // 아직 앞 주문이 끝나지 않은 상태라면
            for (int j = 1; j <= n; j++) {
                st.push_back(Order((t + B * j), 'R')); //(포장 끝나는 시간, 색깔)
            }
            rEnd=(t+B*n);
        }
    }

    sort(st.begin(), st.end());

    vector<int> sangmin;
    vector<int> jisu;

    for(int i=0;i<st.size();i++){
        if(st[i].color=='B'){
            sangmin.push_back(i+1);
        }else{
            jisu.push_back(i+1);
        }
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

