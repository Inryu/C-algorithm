#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2147000000
int N;
string target;
vector<pair<int, string>> books;
int res[20]; //전공책이 쓰인 개수

int minVal=MAX;
bool visited[21][51];

void dfs(int targetIdx){
    if(targetIdx==target.size()){
        int sum=0;
        for(int i=0;i<N;i++){
            if(res[i]>0) sum+=books[i].first;
        }
        minVal=min(minVal,sum);
        return;
    }

    for(int i=0;i<books.size();i++){
        for(int j=0;j<books[i].second.size();j++){
            if(books[i].second.at(j)!=target.at(targetIdx)||visited[i][j]) continue;

            visited[i][j]=true;
            res[i]++;
            dfs(targetIdx+1);
            visited[i][j]=false;
            res[i]--;
        }
    }
}
int main() {

    cin >> target;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int var;
        string str;
        cin >> var >> str;
        books.push_back({var, str});
    }

    dfs(0);

    if(minVal==MAX) cout<<-1<<"\n";
    else cout<<minVal<<"\n";
}