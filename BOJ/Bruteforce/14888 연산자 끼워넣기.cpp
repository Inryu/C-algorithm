#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> numbers;
int op[4];
int minVal=2147000000, maxVal=-2147000000;

void dfs(int level, int sum){
    if(level==N){
        minVal=min(minVal,sum);
        maxVal=max(maxVal,sum);
        return;
    }

    //4개 부호 모두 가지뻗기
    //+
    if(op[0]>0){
        op[0]--;
        dfs(level+1,sum+numbers[level]);
        op[0]++;
    }
    //-
    if(op[1]>0){
        op[1]--;
        dfs(level+1,sum-numbers[level]);
        op[1]++;
    }
    //*
    if(op[2]>0){
        op[2]--;
        dfs(level+1,sum*numbers[level]);
        op[2]++;
    }
    // /
    if(op[3]>0){
        op[3]--;
        dfs(level+1,sum/numbers[level]);
        op[3]++;
    }
}

int main(){

    cin>>N;
    for(int i=0;i<N;i++){
        int val;
        cin>>val;
        numbers.push_back(val);
    }
    for(int i=0;i<4;i++){
        cin>>op[i];
    }
    dfs(1,numbers[0]); // 처음 숫자는 무조건 들어가고, 1레벨부터 4개 부호 전부 가지를 뻗어봄.
    cout<<maxVal<<"\n"<<minVal<<"\n";
}
