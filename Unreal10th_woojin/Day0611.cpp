#include <vector>
#include <algorithm>
#include "Day0611.h"

void Day0611::TestSTL_Algorithm()
{
	std::vector<int> Datas = { 10, 35, 55 ,22, 47 };

	// 데이터 찾기 (find() : 순서대로 찾음)
	std::vector<int>::iterator findIter = std::find(Datas.begin(), Datas.end(), 55); // begin부터 end까지 55를 탐색
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.", (*findIter));
	}
	else
	{
		printf("찾는 수가 없음.");
	}
	findIter = std::find(Datas.begin(), Datas.end(), 100);
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.", (*findIter));
	}
	else
	{
		printf("찾는 수가 없음.");
	}

	std:sort(Datas.begin(), Datas.end());
	PrintVector(Datas);
	std::binary_search(Datas.begin(), Datas.end(), 55);
	if (findIter != Datas.end())
	{
		printf("%d를 찾았다.", 55);
	}
	else
	{
		printf("찾는 수가 없음.");
	}
}

void Day0611::PrintVector(std::vector<int>& InData)
{
	printf("Data : ");
	for (int e : InData)
	{
		printf("%d : ", e);
	}
	printf("\n");
}

void Day0611::TestLambda()
{
}
