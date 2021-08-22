#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 30
int map[MAX][MAX];
bool visited[MAX][MAX];

// ➡️↘️⬇️↗️
int dr[4]={0,1,1,-1};
int dc[4]={1,1,0,1};

// ➡️ ️
bool search1(int color, int r, int c, int cnt){
    while(true){
        if(c+1>19) break;
        if(map[r][++c]==color) cnt++;
        else break;
    }
   return cnt == 5;
}

// ↘️ ️
bool search2(int color, int r, int c, int cnt){
    while(true){
        if(c+1>19||r+1>19) break;
        if(map[++r][++c]==color) cnt++;
        else break;
    }
    return cnt == 5;
}

//  ⬇️
bool search3(int color, int r, int c, int cnt){
    while(true){
        if(r+1>19) break;
        if(map[++r][c]==color) cnt++;
        else break;
    }
    return cnt == 5;
}

// ↗️
bool search4(int color, int r, int c, int cnt){
    while(true){
        if(c+1>19||r-1<1) break;
        if(map[--r][++c]==color) cnt++;
        else break;
    }
    return cnt == 5;
}


int main(){
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            if(!map[i][j]) continue;

            //1. ➡️
            if(map[i][j-1]!=map[i][j]&&search1(map[i][j],i,j,1)){
                cout<<map[i][j]<<"\n"<<i<<" "<<j<<"\n";
                return 0;
            }

            //2. ↘️
            if(map[i-1][j-1]!=map[i][j]&&search2(map[i][j],i,j,1)){
                cout<<map[i][j]<<"\n"<<i<<" "<<j<<"\n";
                return 0;
            }

            //3. ⬇️
            if(map[i-1][j]!=map[i][j]&&search3(map[i][j],i,j,1)){
                cout<<map[i][j]<<"\n"<<i<<" "<<j<<"\n";
                return 0;
            }

            //4. ↗️
            if(map[i+1][j-1]!=map[i][j]&&search4(map[i][j],i,j,1)){
                cout<<map[i][j]<<"\n"<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }

    cout<<0<<"\n";
    return 0;
}