


#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0522.h"
#include "Weekend_Practice0523.h"
#include "Day0526.h"

using namespace std;

int main()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

	int a = 30, b = 20;
	Swap(&a, &b);
}