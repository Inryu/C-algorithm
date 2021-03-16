#include <iostream>
using namespace std;

void solution(int num){

    int room_n;//방 번호
    int in_n; //방 안에서의 번호


    if(num%15==0){
        room_n=num/15;
        in_n=15;
    }else{
        room_n=num/15+1;
        in_n=num%15;
    }

    cout<<room_n<<" "<<in_n<<"\n";


}
int main() {
    ios_base::sync_with_stdio(false);


    int num; //번호표

    cin>>num;
    solution(num);

    return 0;
}