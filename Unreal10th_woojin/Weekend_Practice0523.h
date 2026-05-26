#pragma once

enum MazeTile
{
	MazePath = 0,
	MazeWall = 1,
	MazeStart = 2,
	MazeEnd = 3,
};

enum MoveDirection
{
	DirNone		= 0,
	DirUp		= 1 << 0,
	DirDown		= 1 << 1,
	DirLeft		= 1 << 2,
	DirRight	= 1 << 3,
};

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

