//
// Created by 신인류 on 2021/07/01.
//

#include <iostream>
using namespace std;
#define MAX 50

// ←, ↓, →, ↑
// 달팽이 배열 만들기 방향벡터
int dr[] = { 0,1,0,-1 };
int dc[] = { -1,0,1,0 };

//  ↑, ↓, ←, →  = 1,2,3,4
// 공격 방향벡터
int dr2[] = { 0, -1, 1, 0, 0 };
int dc2[] = { 0, 0, 0, -1, 1 };

int N; //map크기
int m; //블리자드 시전 횟수
int map[MAX][MAX]; //input map

int indexMap[MAX][MAX]; // 달팽이 모양으로 인덱스를 갖는 맵
int indexArray[MAX*MAX]; // indexMap에 넣어줄 index. (indexArray[i]=i)
int indexValue[MAX * MAX]; // indexMap을 1차원 배열로 볼 때 값 저장 (input 배열의 실제 값)
int ivSize; //indexValue 배열 크기.

int Count[4]; //폭발한 구슬 count


// 달팽이 모양 인덱스 맵 만들어주고, input 1차원으로 펴서 indexValue에 넣어주기
void makeIndexMap(int indexMap[MAX][MAX], int indexArray[])
{
    int r, c, dir, index, size;

    dir = index = size = 0; //초기화 // 처음 방향 인덱스는 0으로, 왼쪽 방향
    r = c = N / 2 + 1; // 시작점 (상어가 있는 위치)

    indexMap[r][c] = indexArray[index++];

    // 총 2*N-1회 방향 바꿈
    for (int i = 0; i < 2 * N - 1; i++)
    {
        // 방향 2번 바꿀 때 마다 1칸씩 늘어나므로
        if (i % 2 == 0) size++;

        // 현 방향으로 사이즈만큼 인덱스를 채워줘야 함!
        for (int s = 0; s < size; s++)
        {
            int nr, nc;

            //행과 열에 방향벡터 더해주기.
            nr = r + dr[dir];
            nc = c + dc[dir];

            // 달팽이 배열에 달팽이 모양으로 인덱스 넣어주기
            indexMap[nr][nc] = indexArray[index];

            //indexValue에는 input 배열의 실제 값을 1차원 배열로 넣어준다.
            indexValue[index++] = map[nr][nc];

            // 이동.
            r = nr;
            c = nc;
        }

        // 방향 전환
        dir++;

        // 마지막 방향까지 갔으면 초기화
        if (dir == 4) dir = 0;
    }
}

void move(int indexValue[]){
    int temp=ivSize;

    ivSize=1;

    //indexValue를 1부터 끝까지 보면서, 0이 아닌 값만 넣어주기.
    for(int i=1;i<temp;i++){
        if(indexValue[i]!=0) indexValue[ivSize++]=indexValue[i];
    }

    //남은 칸은 0으로
    for(int i=ivSize;i<N*N;i++){
        indexValue[i]=0;
    }

}

// 구슬 폭발
int explode(int indexValue[])
{
    int flag=0; //폭발이 발생하는지 아닌지 flag //폭발 발생하면 1
    int count=1; //같은 구슬 개수 (최초 1개)
    int start=1, temp;

    temp = ivSize;
    ivSize = 1;

    //indexValue를 끝까지 본다.
    for (int i = 1; i < temp; i++)
    {
        //연속으로 같으면 count 증가
        if (indexValue[i] == indexValue[i + 1]) count++;

            //앞뒤 구슬이 다른 경우
        else
        {
            // count < 4
            // start부터 start+count까지를 다시 indexValue에 복사
            if (count < 4)
                for (int k = start; k < start + count; k++) indexValue[ivSize++] = indexValue[k];

                // 4개 이상 연속하는 구슬이 있으면
            else
            {
                flag = 1;
                Count[indexValue[i]] += count; //폭발한 구슬 개수 누적
            }

            // 초기화
            count = 1;
            start = i + 1;
        }
    }

    //남은 칸은 0으로
    for (int i = ivSize; i < N * N; i++) indexValue[i] = 0;

    return flag;
}

int main(){
    cin>>N>>m;

    //map
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<N*N;i++){
        indexArray[i]=i;
    }

    makeIndexMap(indexMap,indexArray);

    // 시뮬레이션
    for(int i=0;i<m;i++){

        int d,s; // 마법의 방향, 거리
        int sr, sc; // 상어의 위치

        cin>>d>>s;

        sr=sc=N/2+1;

        /* 1. 구슬 파괴 */
        for (int j = 1; j <= s; j++)
        {
            int nr, nc, index;

            nr = sr + dr2[d] * j;
            nc = sc + dc2[d] * j;

            map[nr][nc] = 0; //파괴해서 0이 됨

            index = indexMap[nr][nc];
            indexValue[index] = 0; //indexValue에서도 0으로 만들어 줘야 함.
        }

        /*2. 구슬 이동 */
        ivSize=N*N;
        move(indexValue);

        /*3. 구슬 폭발*/
        while(true){
            int flag = explode(indexValue);

            // 폭발이 발생하지 않은 경우 빠져나옴
            if (flag == 0) break;

            // 폭발 후엔 구슬 이동
            move(indexValue);
        }

        /*4. 구슬 변경*/
        int newArr[MAX * MAX] = { 0 };
        int newIdx=1; //newArr의 인덱스
        int count=1;

        for (int j = 1; j < ivSize; j++)
        {
            // 같은 거 개수 세기
            if (indexValue[j] == indexValue[j + 1]) count++;

                //다르면 newArr에 넣어주기
            else
            {
                newArr[newIdx++] = count; // A : 개수
                newArr[newIdx++] = indexValue[j]; // B : 구슬 번호
                count = 1; // 초기화
            }

            // N*N보다 구슬이 큰 경우는 버림.
            if (newIdx == N * N) break;
        }

        // newArr를 indexValue에 복사.
        for (int j = 1; j < newIdx; j++) indexValue[j] = newArr[j];

        // 남은 부분은 0으로 초기화
        for (int j = newIdx; j < N * N; j++) indexValue[j] = 0;

        makeIndexMap(map, indexValue); // map을 indexValue로 바꿔줌
    }


    cout<<1 * Count[1] + 2 * Count[2] + 3 * Count[3];

    return 0;
}