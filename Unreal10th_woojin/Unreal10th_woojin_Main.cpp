


#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0528.h"
#include "Weekend_Practice0523.h"
#include "Day0529.h"
#include "Day0529_Pratice.h"
#include "Weekend_Practice0529_2.h"
#include "Day0602.h"

#include "Actor.h"
#include "Utils.h"
#include "MazeCommon.h"
#include "Player.h"
#include "Enemy.h"

#include "Day0605.h"
#include "LinkedList.h"

#include "DArray.h"
#include "Weekend_Practice0605_BattleShip.h"

#include "Weekend_Practice0605_BattleShip_Solution.h"


using namespace std;

int main()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화


	
	//Day0529();

	//const char* TestStirng = "Hello";
	//char Buffer[32] = { 0, };
	//MyStrCpy(Buffer, TestStirng);
	//printf("Buffer의 내용문은 [%s]입니다.\n", Buffer);
	//MyStrCat(Buffer, TestStirng);
	//printf("Buffer의 내용문은 [%s]입니다.\n", Buffer);
	//
	//int Result = MyStrCmp("abc", "abc");	// 같으면 0
	//printf("abc 와 abc 비교값 : [%d]\n", Result);
	//Result = MyStrCmp("ab", "abc");		// 왼쪽이 작으면 -1
	//printf("ab 와 abc 비교값 : [%d]\n", Result);
	//Result = MyStrCmp("abb", "abc");
	//printf("abb 와 abc 비교값 : [%d]\n", Result);
	//Result = MyStrCmp("abc", "abb");		// 오른쪽이 작으면 +1
	//printf("abc 와 abb 비교값 : [%d]\n", Result);
	//Result = MyStrCmp("abc", "ab");
	//printf("abc 와 ab 비교값 : [%d]\n", Result);
	//Weekend0523_Dungeon();
	//Day0529_Pratice();
	//Homework02_Run();
	//Day0602();

	//Day0605();
	//Day0605 day0605;
	//day0605.TestList();

	BattleShipGame game;
	game.play();
}