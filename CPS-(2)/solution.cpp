#include <string>
#include <vector>

using namespace std;

//전역 변수는 못 쓰는 건가..?!

int cnt=0;

void DFS(vector<int> numbers, int target, int L,int sum){

    if(L==numbers.size()){
        if(sum==target) cnt++;
    }else{
        DFS(numbers,target,L+1,sum+numbers[L]);
        DFS(numbers,target,L+1,sum-numbers[L]);
    }

}

int main() {

    vector <int> numbers(5,1);
    int target=3;

    DFS(numbers,target,0,0);

    printf("%d",cnt);

}

