


#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Weekend_Practice0523.h"

using namespace std;

int main()
{
	unsigned int Seed = (unsigned int)time(0);
	Seed = 0;		// 테스트용으로 임시로 설정
	srand(Seed);	// 시드값 초기화

	//int Array[5] = {315, 5995,2112,2,325};
	//PointerUsedMinMax(Array,5);
	/*int Array[7] = {1,2,3,4,5,6,7};
	Day0526_Practice_ReverseArray(Array, 7);
	for (int i = 0; i < 7; i++)
	{
		printf("%d", Array[i]);
	}*/
	Weekend0523_Dungeon();

}