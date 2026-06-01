#pragma once

struct Map //맵은
{
	const int MazeHeight;
	const int MazeWidth;
};

enum MazeTile
{
	MazePath = 0,
	MazeWall = 1,
	MazeStart = 2,
	MazeEnd = 3,
};

enum MoveDirection
{
	DirNone = 0,
	DirUp = 1 << 0,
	DirDown = 1 << 1,
	DirLeft = 1 << 2,
	DirRight = 1 << 3,
};

//맵 파일을 불러오고 파싱하는 함수
void CallOutMapData();

//게임 시작 함수
void Weekend0523_Dungeon();

/// <summary>
/// 시작 위치 찾는 함수
/// </summary>
/// <param name="OutX">시작 X 위치(출력용)</param>
/// <param name="OutY">시작 Y 위치(출력용)</param>
void FindStart(int& OutX, int& OutY);

/// <summary>
/// 미로를 출력하는 함수 
/// </summary>
/// <param name="PlayerX">플레이어의 현재 위치(X)</param>
/// <param name="PlayerY">플레이어의 현재 위치(Y)</param>
void PrintMaze(int PlayerX, int PlayerY);

/// <summary>
/// 플레이어가 도착점에 도착했는지 확인하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 위치(X)</param>
/// <param name="PlayerY">플레이어의 현재 위치(Y)</param>
/// <returns> true 면 도착점에 있고 false면 도착점에 없다</returns>
//bool IsGoal(int PlayerX, int PlayerY) { return Maze[PlayerY][PlayerY] == MazeEnd; } 인라인 함수 참고
bool IsGoal(int PlayerX, int PlayerY);

/// <summary>
/// 이동 할 수 있는 방향을 출력하고 그 결과를 비트 플래그로 반환하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 위치(X)</param>
/// <param name="PlayerY">플레이어의 현재 위치(Y)</param>
/// <returns>이동 가능한 방향이 저장된 비트 플래그</returns>
int PrintAvailableMoves(int PlayerX, int PlayerY);

/// <summary>
/// 해당 위치가 벽인지 아닌지 확인하는 함수
/// </summary>
/// <param name="X">확인할 X 위치</param>
/// <param name="Y">확인할 Y 위치</param>
/// <returns> true면 벽 , false면 벽이 아닌 이동 가능한 지역</returns>
bool IsWall(int X, int Y);

/// <summary>
/// 이동 방향을 입력 받고 해당 방향을 리턴하는 함수
/// </summary>
/// <param name="PlayerX">플레이어의 현재 위치(X)</param>
/// <param name="PlayerY">플레이어의 현재 위치(Y)</param>
/// <returns>입력 받은 방향</returns>
MoveDirection GetMoveInput(int PlayerX, int PlayerY);

/// <summary>
/// 0.0f ~ 1.0f 사이를 리턴하는 함수
/// </summary>
/// <returns>0.0f ~ 1.0f 사이의 랜덤 값</returns>
float GetRandom();

/// <summary>
/// Min ~ Max 사이의 랜덤한 값을 리턴하는 함수
/// </summary>
/// <param name="Min">랜덤의 최소값(포함)</param>
/// <param name="Max">랜덤의 최대값(포함)</param>
/// <returns>Min ~ Max 사이의 랜덤한 값</returns>
int GetRandomRange(int Min, int Max);

/// <summary>
/// 랜덤 인카운터(전투) 발생여부 체크하는 함수
/// </summary>
/// <returns>true면 전투 발생, false면 전투 발생 X</returns>
bool RandomIncounter();

/// <summary>
/// 전투 처리 함수
/// </summary>
/// <param name="PlayerHealth"></param>
/// <returns></returns>
bool Battle(int& PlayerHealth);


//자리수 분리해서 합치기(입력은 정수형으로 제한)
int GetSum(int Number);

//자리수 분리해서 합치기(입력은 제한 없음)
int GetSum(char* NumberString);

MazeTile GetMazeData(int X, int Y);


