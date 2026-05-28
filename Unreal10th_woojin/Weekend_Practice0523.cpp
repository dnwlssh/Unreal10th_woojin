#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include "Weekend_Practice0523.h"

using namespace std;

int MazeHeight ; //10
int MazeWidth;  //20
const int InvalidPosition = -1; //플레이어 위치 값

const char* ShapePlayer = "P";
const char* ShapeWall = "#";
const char* ShapePath = ".";
const char* ShapeStart = "S";
const char* ShapeEnd = "E";

const float BattleRate = 0.1f;
const int InitHealth = 100;
int PlayerHealth = InitHealth;

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

int* Maze = nullptr;


void Weekend0523_Dungeon()
{
	//Maze = new int[MazeHeight * MazeWidth]
	//	{
	//		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	//		1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,
	//		1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1,
	//		1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,
	//		1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,
	//		1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,
	//		1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,
	//		1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1,
	//		1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,
	//		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	//	};

	// 맵 데이터 파일에서 불러오기


	int PlayerX = InvalidPosition;
	int PlayerY = InvalidPosition;

	CallOutMapData();
	FindStart(PlayerX, PlayerY); //시작 위치 찾기

	if (PlayerX != InvalidPosition && PlayerY != InvalidPosition)
	{
		//시작 위치를 잘 찾은 정상적인 경우
		printf("\n\n=== 텍스트 미로 탈출 게임 ===\n\n");

		while (true)
		{
		printf("진행을 위해 아무키나 눌러주세요 : ");
		int Temp = getchar();

		system("cls"); // 화면 깨끗이 지우기

		//화면 출력
		PrintMaze(PlayerX, PlayerY);

		//출구에 도달했는지 확인
		if (IsGoal(PlayerX,PlayerY))
		{
			printf("미로를 탈출했습니다.\n\n");
			break;
		}
		
		
		//입력 처리
		MoveDirection Direction = GetMoveInput(PlayerX, PlayerY);
		switch (Direction)
		{
		case DirUp:
			PlayerY--;
			break;
		case DirDown:
			PlayerY++;
			break;
		case DirLeft:
			PlayerX--;
			break;
		case DirRight:
			PlayerX++;
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

void CallOutMapData()
{
	const string MapOfMaze = ".\\Data\\MapData.txt";
	ifstream InputFile(MapOfMaze);
	if (InputFile.is_open())			// 파일이 열렸을 떄
	{
		std::string FileTexts(								//파일에 있는 데이터 가져오기
			(std::istreambuf_iterator<char>(InputFile)),
			std::istreambuf_iterator<char>()
		);

		// 저장된 맵데이터 찾고 파싱
		// 20 , 10 각 변수에 저장하기
		int FindFirstComma = FileTexts.find(',');  //FindFirstComma는  첫번째 콤마 가 나온 인덱스가 저장되어 있다. Size는 2
		int FindFirstEnter = FileTexts.find('\n');
		
		int ParsedMazeWidth = stoi(FileTexts.substr(0, FindFirstComma)); // 20 저장
		int ParsedpMazeHeight = stoi(FileTexts.substr(FindFirstComma + 1, FindFirstEnter - FindFirstComma)); //10 /인덱스 3부터 5 - 3만큼(2)

		MazeHeight = ParsedpMazeHeight; //10
		MazeWidth = ParsedMazeWidth; //20

		// 맵 저장 하기
		int MainIndex = 0;
		Maze = new int[MazeWidth * MazeHeight]; // 저장한 가로 세로 바탕으로 1차원 배열 형태 생성
		//이제 각 배열의 값마다 남은 문자열들을 넣어줘야 한다.
		for (int i = 0; i < FileTexts.length(); i++)
		{
			if (MainIndex >= MazeWidth * MazeHeight)
			{
				break;
			}
//			const char* CheckMazeIndex = FileTexts.substr(FindFirstEnter + 1 + i, 1).c_str();
			if ((*(FileTexts.substr(FindFirstEnter + 1 + i, 1).c_str()) == ',') || (*(FileTexts.substr(FindFirstEnter + 1 + i, 1).c_str()) == '\n'))
			{
				continue;
			}
			else
			{
				// 첫 엔터 이후 첫 인덱스의 값 하나를 잘라서 인티저로 만든 값 대입
				Maze[MainIndex] = stoi(FileTexts.substr(FindFirstEnter + 1 + i, 1).c_str());
				MainIndex++;
			}
		}
		InputFile.close();	//작업을 마치면 파일을 무조건 닫아줘야 한다.
	}
	else
	{
		// 파일이 없거나 다른 이유로 열리지 않았다.
		printf("파일을 열 수 없습니다.\n");
	}
}

void FindStart(int& OutX, int& OutY)
{
	//이중 for를 통해서 미로 전체 순회
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			if (GetMazeData(x,y) == MazeStart)	// 플레이어 시작점을 찾았으면
			{
				OutX = x;
				OutY = y;
				return;
			}
		}
	}
	OutX = InvalidPosition; // 여기는 잘못된 곳이라고 의도를 명확히 써놓는 의미
	OutY = InvalidPosition;
}

void PrintMaze(int PlayerX, int PlayerY)
{
	for (int y = 0; y < MazeHeight; y++)
	{
		for (int x = 0; x < MazeWidth; x++)
		{
			//현재 위치에 맞는 모양 찍엊주기
			if (PlayerX == x && PlayerY == y)
			{
				printf(ShapePlayer);	//pritf("P"); 와 같음
			}
			else if (GetMazeData(x,y) == MazeWall)
			{
				printf(ShapeWall);
			}
			else if (GetMazeData(x, y) == MazePath)
			{
				printf(ShapePath);
			}
			else if (GetMazeData(x, y) == MazeStart)
			{
				printf(ShapeStart);
			}
			else if (GetMazeData(x, y) == MazeEnd)
			{
				printf(ShapeEnd);
			}
		}
		printf("\n"); //줄바꿈 추가
	}
}

bool IsGoal(int PlayerX, int PlayerY)
{
	return GetMazeData(PlayerX, PlayerY) == MazeEnd;
}

int PrintAvailableMoves(int PlayerX, int PlayerY)
{
	int Flags = DirNone; // ????(Flags) || 0000  = 0

	//w(↑) s(↓) a(←) d(→)
	if (!IsWall(PlayerX, PlayerY - 1))
	{
		printf("w(↑) ");
		Flags |= DirUp; 
	}
	if (!IsWall(PlayerX, PlayerY + 1))
	{
		printf("s(↓) ");
		Flags |= DirDown;
	}
	if (!IsWall(PlayerX - 1, PlayerY))
	{
		printf("a(←) ");
		Flags |= DirLeft;
	}
	if (!IsWall(PlayerX + 1, PlayerY ))
	{
		printf("d(→) ");
		Flags |= DirRight;
	}
	printf("\n");
	return Flags;
}

bool IsWall(int X, int Y)
{
	return (X < 0 || X >= MazeWidth || Y < 0 || Y >= MazeHeight || GetMazeData(X, Y) == MazeWall);
}

MoveDirection GetMoveInput(int PlayerX, int PlayerY)
{
	printf("이동할 방향을 선택하세요 (w:위, s:아래, a:왼쪽, d:오른쪽) :\n");
	int AvailableFalgs = PrintAvailableMoves(PlayerX, PlayerY);

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

MazeTile GetMazeData(int X, int Y)
{
	return (MazeTile)Maze[X + MazeWidth * Y];
}
