


#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0522.h"
#include "Weekend_Practice0523.h"

using namespace std;

int main()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

	//Day0522_Array_Example1();
	//Day0522_Array_Example2();
	//Day0522_Array_Example3();
	//Day0522_ArrayParameter();
	//Day0522_Shuffle();
	//Day0522_MainPractice1();
	//Day0522_MainPractice3();
	//Day0522_MainPractice4();
	Weekend0523_Dungeon();

}