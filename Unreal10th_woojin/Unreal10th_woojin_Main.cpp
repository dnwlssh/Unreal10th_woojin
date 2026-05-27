


#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0527.h"

using namespace std;

int main()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화


	
	Day0527();

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

}