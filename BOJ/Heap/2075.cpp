#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 우선순위 큐(최소힙)에 가장 슨 수부터 N번재 큰 수까지 총 N개의 숫자가 들어있음
// 가장 큰 수부터 N번째 큰 수까지를 최소 힙에 넣어
// top에 있는 것이 N번째 큰 수!@


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,val;

    priority_queue<int,vector<int>, greater<>> pq; //최소 힙
    cin>>N;

    int size=N*N;
    while(size--) {
        cin >> val;
        if (pq.size() < N) pq.push(val);
        else if (pq.top() < val) { //사이즈가 꽉 찼는데 제일 작은 수가 input보다 작으면 치워!
            pq.pop();
            pq.push(val);
        }
    }
    cout<<pq.top()<<"\n";
    return 0;
}