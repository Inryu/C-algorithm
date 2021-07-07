#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//상 우 하 좌
int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int N;
int map[20][20];

struct Student{
    int id; //학생 번호
    int likeFriends[4]; //좋아하는 친구들
};

struct Loc{
    int r,c;
    int likeFriendsCnt;//인접하는 좋아하는 학생칸 개수
    int Empty;//인접하는 빈 칸 개수

    Loc(int rr, int cc, int a, int b){
        r=rr;
        c=cc;
        likeFriendsCnt=a;
        Empty=b;
    }

    //정렬
    bool operator<(const Loc &b) const{
        if(likeFriendsCnt==b.likeFriendsCnt){
            if(Empty==b.Empty){
                if(r==b.r){
                    return c>b.c;
                }else return r>b.r;
            }else return Empty<b.Empty;
        }else return likeFriendsCnt<b.likeFriendsCnt;
    }
};



void placeStudent(Student student); //1. 학생 배치
int Calculate(Student student); //2. 만족도 계산

int main(){
    int score=0;
    vector<Student> students;
    cin>>N;

    //input
    for(int i=0;i<N*N;i++){
        int id, f1, f2, f3, f4;
        cin>>id>>f1>>f2>>f3>>f4;
        students.push_back({id,{f1,f2,f3,f4}});
    }

    //각 학생 마다 자리 배치
    for(int i=0;i<N*N;i++){
        placeStudent(students[i]);
    }

    //만족도 계산
    for(int i=0;i<N*N;i++){
        score+=Calculate(students[i]);
    }

    cout<<score<<"\n";
    return 0;
}

void placeStudent(Student student){

    priority_queue<Loc> pQ;

    //모든 맵을 탐색하면서, 그 위치의 맵 좌표를 우선순위 큐에 삽입하여 정해진 규칙으로 정렬.
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            //이미 학생이 배치된 경우
            if(map[r][c]!=0) continue;

            int likeFriendsCnt=0;//인접하는 좋아하는 학생칸 개수
            int Empty=0;//인접하는 빈 칸 개수

            for(int d=0;d<4;d++){
                int nr=r+dr[d];
                int nc=c+dc[d];

                if(nr<0||nc<0||nr>=N||nc>=N) continue;

                if(map[nr][nc]==0) Empty++;
                else{
                    for(int f=0;f<4;f++){
                        int friendId=student.likeFriends[f];
                        if(map[nr][nc]==friendId) {
                            likeFriendsCnt++;
                            break;
                        }
                    }
                }

            }
            pQ.push(Loc(r,c,likeFriendsCnt,Empty));
        }
    }

    //pQ에 정렬 끝남.
    int rr=pQ.top().r;
    int cc=pQ.top().c;

    map[rr][cc]=student.id;
}

int Calculate(Student student){

    int r, c;
    int cnt=0;
    //학생의 위치 찾기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==student.id){
                r=i;
                c=j;
                break;
            }
        }
    }

    for(int d=0;d<4;d++){
        int nr=r+dr[d];
        int nc=c+dc[d];

        if(nr<0||nc<0||nr>=N||nc>=N) continue;

        for(int f=0;f<4;f++){
            int friendId=student.likeFriends[f];
            if(friendId==map[nr][nc]){
                cnt++;
                break;
            }
        }
    }

    switch(cnt){
        case 0: return 0;
        case 1: return 1;
        case 2: return 10;
        case 3: return 100;
        case 4: return 1000;
    }

}

