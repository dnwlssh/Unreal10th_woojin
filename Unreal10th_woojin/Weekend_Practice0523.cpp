#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Weekend_Practice0523.h"

using namespace std;

const int MazeHeight = 10;
const int MazeWidth = 20;
const int InvalidPosition = -1; //플레이어 위치 값


const char* ShapePlayer = "P";
const char* ShapeWall = "#";
const char* ShapePath = ".";
const char* ShapeStart = "S";
const char* ShapeEnd = "E";

const float BattleRate = 0.1f;
const int InitHealth = 100;


// 미로 배열 정의
//int Maze[MazeHeight][MazeWidth] =
//{
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
//	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
//	{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
//	{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
//	{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};
int Size = MazeHeight * MazeWidth;
int* Maze = new int[Size]
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Y = 0
		1, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, // Y = 1
		1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, // Y = 2
		1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, // Y = 3
		1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, // Y = 4
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, // Y = 5
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, // Y = 6
		1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 3, 1, // Y = 7
		1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, // Y = 8
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  // Y = 9
	};


void Weekend0523_Dungeon()
{	
	int Player = InvalidPosition;
	int PlayerHealth = InitHealth;

	FindStart(Player); //시작 위치 찾기

	if (Player != InvalidPosition)
	{
		//시작 위치를 잘 찾은 정상적인 경우
		printf("\n\n=== 텍스트 미로 탈출 게임 ===\n\n");

		while (true)
		{
		printf("진행을 위해 아무키나 눌러주세요 : ");
		int Temp = getchar();

		system("cls"); // 화면 깨끗이 지우기

		//화면 출력
		PrintMaze(Player);

		//출구에 도달했는지 확인
		if (IsGoal(Player))
		{
			printf("미로를 탈출했습니다.\n\n");
			break;
		}
		
		
		//입력 처리
		MoveDirection Direction = GetMoveInput(Player);
		switch (Direction)
		{
		case DirUp:
			for (int i = 0; i < 20; i++)
			{
				Player--;
			}
			break;
		case DirDown:
			for (int i = 0; i < 20; i++)
			{
				Player++;
			}
			break;
		case DirLeft:
			Player--;
			break;
		case DirRight:
			Player++;
			break;
		case DirNone:
		default:
			printf("Error!!!\n");
			break;
		}
		
		//랜덤 인카운터 처리
		if (RandomIncounter())
		{
			//전투 시작
			if (Battle(PlayerHealth))
			{
				printf("당신은 승리 했습니다.\n");
			}
			else
			{
				printf("당신은 패배 했습니다.\n");
				break;
			}
		}
		}
	}
	else
	{
		//시작 위치를 찾이 못한 비정상적인 경우
		printf("ERROR!! 맵의 시작 위치를 찾을 수 없습니다!\n");
	}

	delete[] Maze;
	Maze = nullptr;
}

int FindStart(int& Player)
{
	for (int i = 0; i < Size; i++)
	{
		if (Maze[i] == MazeStart)
		{
			Player = Maze[i];
			return Player;
		}
	}
	Player = InvalidPosition; // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
}

void PrintMaze(int Player)
{
	for (int i = 0; i < Size; i++)
	{
		if (Maze[i] == Player)
		{
			printf(ShapePlayer);    //printf("P ");와 같음                
		}
		else if (Maze[i] == MazeWall)
		{
			printf(ShapeWall);
		}
		else if (Maze[i] == MazePath)
		{
			printf(ShapePath);
		}
		else if (Maze[i] == MazeStart)
		{
			printf(ShapeStart);
		}
		else if (Maze[i] == MazeEnd)
		{
			printf(ShapeEnd);
		}
		if ((i % 20 == 0))
		{
		printf("\n"); //줄바꿈 추가
		}
	}
}

bool IsGoal(int Player)
{
	return Maze[Player] == MazeEnd;
}

int PrintAvailableMoves(int Player)
{
	int Flags = DirNone; // ????(Flags) || 0000  = 0

	//w(↑) s(↓) a(←) d(→)
	if (!IsWall(Player))
	{
		printf("w(↑) ");
		Flags |= DirUp; 
	}
	if (!IsWall(Player))
	{
		printf("s(↓) ");
		Flags |= DirDown;
	}
	if (!IsWall(Player))
	{
		printf("a(←) ");
		Flags |= DirLeft;
	}
	if (!IsWall(Player))
	{
		printf("d(→) ");
		Flags |= DirRight;
	}
	printf("\n");
	return Flags;
}

bool IsWall(int X)
{
	return (X + 1 || X -1 || X + 20 || X-20 == MazeWall);
}

MoveDirection GetMoveInput(int Player)
{
	printf("\n이동할 방향을 선택하세요 (w:위, s:아래, a:왼쪽, d:오른쪽) :\n");
	int AvailableFalgs = PrintAvailableMoves(Player);

	MoveDirection Result = DirNone;
	char Input = 0;
	while (true)
	{
		printf("방향 입력 : ");
		cin >> Input;

		if ((Input == 'w' || Input == 'W') && AvailableFalgs & DirUp)
		{
			Result = DirUp;
			break;
		}
		if ((Input == 's' || Input == 'S') && AvailableFalgs & DirDown)
		{
			Result = DirDown;
			break;
		}
		if ((Input == 'a' || Input == 'A') && AvailableFalgs & DirLeft)
		{
			Result = DirLeft;
			break;
		}
		if ((Input == 'd' || Input == 'D') && AvailableFalgs & DirRight)
		{
			Result = DirRight;
			break;
		}
		printf("잘못 된 입력 입니다.\n");
	}
	return Result;
}

float GetRandom()
{
	return rand() / (float)RAND_MAX;	// 0.0f ~ 1.0f
}

int GetRandomRange(int Min, int Max)
{
	return Min + rand()% (Max - Min + 1);
}

bool RandomIncounter()
{
	return GetRandom() < BattleRate; // BattleRate보다 랜덤값이 적으면 전투 발생
}

bool Battle(int& PlayerHealth)
{
	const float CriticalRate = 0.1f;
	const int PlayerMinAttackPower = 5;
	const int PlayerMaxAttackPower = 15;
	const int EnemyMinAttackPower = 1;
	const int EnemyMaxAttackPower = 5;

	int EnemyHealth = 20;


	printf("고블린이 나타났다!! 전투 시작!\n");
	int Turn = 1;
	while (PlayerHealth > 0 && EnemyHealth > 0)
	{
		//전투 턴 진행
		printf("----------- 턴 %d ------------\n ",Turn);
		printf("| Player : %3d	Enemy : %3d |\n", PlayerHealth, EnemyHealth);
		printf("-----------------------------\n ");
		int Damage = GetRandomRange(PlayerMinAttackPower, PlayerMaxAttackPower);
		printf("당신의 공격 : %d의 데미지를 주었다!\n",Damage);
		EnemyHealth -= Damage;
		if (EnemyHealth > 0)
		{
			Damage = GetRandomRange(EnemyMinAttackPower, EnemyMaxAttackPower);
			printf("적의 공격 : %d의 데미지를 주었다!\n", Damage);
			PlayerHealth -= Damage;
		}
		Turn++;
	}

	return PlayerHealth > 0;	//플레이어의 체력이 남은 채  while이 끝났으면 플레이어가 이긴것
}

int GetSum(int Number)
{
	int Sum = 0;
	while (Number > 0)
	{
		int A = Number % 10;	// 1/10로 나눈 나머지는 따로 저장하기
		Number / 10;			// 계속 1/10로 나누기
	}
	return Sum;
}


