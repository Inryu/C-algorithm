#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25


struct SHARK
{
	int x;
	int y;
	int Dir;
	bool Live;
	vector<int> Priority[5];
};

struct MAP_INFO
{
	vector<int> V; //해당 좌표에 존재하는 상어들의 번호
	int Smell_Time; //냄새가 없어지는 시간
	int Smell_Host; //냄새를 뿌린 상어
};



int N, M, K;
MAP_INFO MAP[MAX][MAX];
SHARK Shark[410];

int dx[] = { 0, -1, 1, 0, 0 }; //인덱스 1부터 쓸 것임, (위,아래,왼,오) 
int dy[] = { 0, 0, 0, -1, 1 };

void Input()
{
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a; cin >> a;

			//상어면
			if (a != 0)
			{
				MAP[i][j].V.push_back(a);
				Shark[a].x = i; //1~M번의, M마리의 상어
				Shark[a].y = j;
			}
			MAP[i][j].Smell_Time = 0; //아직 냄새 안 뿌렸으니깐
			MAP[i][j].Smell_Host = 0;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int Dir; cin >> Dir;
		Shark[i].Dir = Dir;
		Shark[i].Live = true;
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int Arr[4];
			cin >> Arr[0] >> Arr[1] >> Arr[2] >> Arr[3];
			for (int k = 0; k < 4; k++)
			{
				Shark[i].Priority[j].push_back(Arr[k]);
			}
		}
	}
}


bool Check()
{
	for (int i = 2; i <= M; i++)
	{
		if (Shark[i].Live == true) return false;
	}
	return true;
}


//1) 현재 자신의 위치에 냄새 뿌리기
void Setting_Smell(int Time) //Time : 현재 시간
{
	for (int i = 1; i <= M; i++)
	{
		if (Shark[i].Live == false) continue;

		int x = Shark[i].x;
		int y = Shark[i].y;
		MAP[x][y].Smell_Time = Time + K; //현재시간 + K
		MAP[x][y].Smell_Host = i;
	}
}

//2) 상어들 움직여주기

/*
각각을 진행방향의 우선순위에 맞게 생각해줌!
1. 상하좌우에 비어있는 칸이 있는지
2. 없으면
*/

void Move_Shark(int Time)
{

	//기존에 상어에 대한 정보가 저장되어 있는 좌표들을 지워줌.
	for (int i = 1; i <= M; i++)
	{
		if (Shark[i].Live == false) continue;
		int x = Shark[i].x;
		int y = Shark[i].y;
		MAP[x][y].V.clear();
	}


	//상어 이동
	for (int i = 1; i <= M; i++)
	{
		if (Shark[i].Live == false) continue;

		int x = Shark[i].x;
		int y = Shark[i].y;
		int Dir = Shark[i].Dir;

		int Self_x, Self_y, Self_Dir;
		Self_x = Self_y = Self_Dir = -1;
		bool Flag = false;

		//현재 방향에서 우선순위대로
		for (int j = 0; j < Shark[i].Priority[Dir].size(); j++)
		{
			int nDir = Shark[i].Priority[Dir][j];
			int nx = x + dx[nDir]; //인덱스를 그대로 넣어줬음
			int ny = y + dy[nDir];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{

				//갈 수 있는 칸이 있는 경우
				if (MAP[nx][ny].Smell_Time <= Time)
				{
					Flag = true;
					MAP[nx][ny].V.push_back(i);
					Shark[i].x = nx;
					Shark[i].y = ny;
					Shark[i].Dir = nDir;
					break;
				}
				else // 4방향 다 막힌 경우, 내 냄새가 있는 칸을 구해놓고 저장
				{
					if (MAP[nx][ny].Smell_Host == i)
					{
						if (Self_x == -1)
						{
							Self_x = nx;
							Self_y = ny;
							Self_Dir = nDir;
						}
					}
				}
			}
		}

		//4방향 모두에 없을 때 내 냄새가 있는 좌표로
		if (Flag == false)
		{

			MAP[Self_x][Self_y].V.push_back(i);
			Shark[i].x = Self_x;
			Shark[i].y = Self_y;
			Shark[i].Dir = Self_Dir;
		}
	}
}


	//3. 상어 죽이기
	// 한 좌표에 2마리 이상 있을 때
void Killing_Shark()
	{
		for (int i = 1; i <= M; i++)
		{
			if (Shark[i].Live == false) continue;

			int x = Shark[i].x;
			int y = Shark[i].y;

			//2마리 이상 있으면
			if (MAP[x][y].V.size() >= 2)
			{
				sort(MAP[x][y].V.begin(), MAP[x][y].V.end()); //오름차순 정렬
				int Live_Num = MAP[x][y].V[0]; //제일 작은 얘 빼고 다 죽임
				
				for (int j = 1; j < MAP[x][y].V.size(); j++)
				{
					int Shark_Num = MAP[x][y].V[j];
					Shark[Shark_Num].Live = false;  //죽음
				}

				//벡터 비우고 다시 하나만 넣기
				MAP[x][y].V.clear();
				MAP[x][y].V.push_back(Live_Num);
				MAP[x][y].Smell_Host = Live_Num;
			}
		}
}

void Solution()
{
	for (int Time = 0; Time < 1001; Time++)
	{
		if (Check() == true) //한 마리만 남으면!
		{
			cout << Time << endl;
			return;
		}

		//1) 현재 자신의 위치에 냄새 뿌리기
		Setting_Smell(Time);

		//2) 상어들을 움직여주기
		Move_Shark(Time);

		//3) 상어 죽이기
		Killing_Shark();
	}
	cout << -1 << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}


