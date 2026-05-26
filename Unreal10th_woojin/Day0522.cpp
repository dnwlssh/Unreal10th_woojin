#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0522.h"

using namespace std;

//void Day0522_Array()
//{
//	unsigned int Seed = (unsigned int)time(0);
//	Seed = 0;		// 테스트용으로 임시로 설정
//	srand(Seed);	// 시드값 초기화
//
//	// 배열
//	// 같은 종류의 데이터타입을 한번에 여러개 저장할 때 사용.
//	// 같은 데이터 타입을 가진 요소들이 연속적으로 저장되어 있는 데이터 구조를 가진다.
//	// 장점 : 빠르게 각 요소에 접근이 가능하다(랜덤 엑세스 성능이 매우 뛰어나다)
//	// 단점 : 크기가 고정이다. 삽입/삭제가 힘들다.
//
//	int Num1 = 0, Num2 = 0, Num3 = 0;	// 이전까지 데이터 3개 저장하는 방식
//	int Numbers[3];			// 배열을 이용해서 데이터 3개 저장하는 방식
//	Numbers[0] = 10;		// 배열의 각 요소에 접근하는 방식
//	Numbers[1] = 20;
//	Numbers[2] = 50;
//
//	Numbers[1] = Numbers[0];	// Numbers의 첫번째 요소를 두번째 요소에 대입하기
//
//	// Numbers[3] = 100;		// 범위를 벗어나서 접근하는 것은 안됨!!!
//
//	int Array1[5] = { 1, 4, 76, 32, 6 };	// 순서대로 데이터 초기화
//	int Array2[5] = { 32, 6 };				// 32, 6들어가고 나머지는 0
//
//	int ArraySize = sizeof(Array1);
//	printf("ArraySize : %d Byte\n", ArraySize);
//	int ArrayCount = ArraySize / sizeof(int);
//	printf("ArrayCount : %d 개\n", ArrayCount);
//
//	// 2차원 배열
//	int Array3[4][3];	// int 3개짜리 배열이 4개있다.
//	int Array4[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };	// int Array4[12];와 메모리상 구조는 똑같다.
//
//	// 간단 실습
//	
//	
//	int ArrayAverage[11]; // {0,1,2,3,4,5,6,7,8,9,10}
//
//	for (int i = 1; i < 11; i++)
//	{
//		ArrayAverage[i] += ArrayAverage[i];
//	}
//
//	
//}
//
//void Day0522_Array_Example1()
//{
//	// 1. 배열 만들고 초기화 하고 전부 출력해보기(1차원과 2차원 모두)
//
//	int Array1[5] = { 1,2,3,4,5 };
//	int Array1Size = sizeof(Array1) / sizeof(Array1[0]);
//	printf("Array1 = [");
//	for (int i = 0; i < Array1Size; i++)
//	{
//		printf("%d ", Array1[i]);
//	}
//	printf("]");
//
//	int Array2[5] = { 0, };
//
//	printf("Array2 = [");
//	for (int i = 0; i < Array1Size; i++)
//	{
//		printf("%d ", Array2[i]);
//	}
//	printf("]");
//
//
//	int Array3[3][4] = {
//		{1,2,3,4},
//		{ 5,6,7,8 },
//		{ 9,10,11,12 }
//	};
//
//	printf("Array3 = [ \n");
//	for (int i = 0; i <3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%3d ", Array3[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void Day0522_Array_Example2()
//{
//	// 2. 배열 내부값을 모두 더하고 평균 구해보기
//	const int Size = 5;
//	int Array[Size] = { 1,2,3,4,5 };
//	int Sum = 0;
//	for (int i = 0; i < Size; i++)
//	{
//		printf("%d",Array[i]);
//		Sum += Array[i];
//	}
//	float Average = Sum / Size;
//	printf("}\n");
//	printf("Sum = %d , Average = %.1f", Sum, Average);
//}
//
//void Day0522_Array_Example3()
//{
//	// 3. 배열의 값 중 최대값과 최소값 구해보기
//	int Max = INT32_MIN;
//	int Min = INT32_MAX;
//
//	int Array[5] = {0,-55,99,10,53};
//	for (int i = 0; i < 5; i++)
//	{
//		if (Max < Array[i])
//		{
//			Max = Array[i];
//		}
//		if (Min > Array[i])
//		{
//			Min = Array[i];
//		}
//	}
//	printf("Max =%d Min = %d", Max, Min);
//}
//
//void Day0522_Casting()
//{
//	// 캐스팅
//	// 값의 데이터 타입을 다른 타입으로 변경하는것
//	
//	// C 스타일
//	// - 강제 변환(가능 유/무를 따지지 않는다 , 사용하기 위험함)
//	int Integer = 10;
//	float RealNumber = (float)Integer;		//Integer에 있는 값을 float타입으로 임시 변경한 후 RealNumber에 저장
//
//	bool Boolean = (bool)Integer;
//	Boolean = (bool)0;
//
//	int i = 0;
//
//	// C++ 스타일
//	// 1. static_cast *주로 사용*
//	//		- C 스타일 cast와 매우 유사
//	//		- 문법적으로 암시적 변환이 허용 될 때만 캐스팅을 한다.
//	RealNumber = static_cast<float>(Integer);
//	//
//	// 2. dynamic_cast
//	//		- 상속을 배워야 의미가 있음. 다운캐스팅을 할 때 사용.
//	//		- 캐스팅 할 수 있으면 nulldl 아닌 값. 할 수 없으면 null을 반환한다.
//	//		- RTTI(RunTime Type INformation)를 관리
//	//		- *변환 속도가 매우 늦다* (일반적인 게임에서 남용하면 안된다)
//	//	캐스팅된 결과를 받을 변수 = dynamic_cast<캐스팅 할 타입>(변수);
//	// 
//	// 3. const_cast
//	//		- const나 volatile 속성을 제거하거나 추가할 때 사용.
//	//		- 상수를 정해놓고 그 상수를 임시로 변환하고 싶을 때
//	//		- 사용되지 않는 것을 권장(레거시(옛날에 만들어진 코드) 처리용)
//	// 4. reinterpret_cast
//	//		- C 스타일 캐스트의 위험성을 그대로 가져온 것.
//	//		- 원래 타입의 구조를 무시하고 새 타입으로 강제적으로 해석하게 하는 cast
//	//		- 포인터 타입간 변환이나 유니온 변환 같은 경우 사용
//}

/*
void Day0522_Reference()
{
	// 참조
	// - 변수의 별명
	// - *참조 대상을 재설정하는 것이 불가능하다*.(선언할 때 참조할 변수를 지정해줘야 한다.)
	// - *참조를 변경하면 참조하고 있더 원본 변수도 함께 수정된다.
	
	int Num = 10;
	int Target = Num;
	Target = 15;
	
	Day0522_Test_Reference1(Num);
	Num = Day0522_Test_Reference2(Num);

	int& NumRef = Num;		//int& 별명 = 본명;
	int i;
	// int& Ref;	//참조할 변수 지정없이 사용하는건 안된다.
	NumRef = 100;	//참조하고 있는 변수인 Num이 100이 된다.

	int Num1 = 0 ,Num2 = 0 , Num3 = 0;
	//Day0522_Test_Reference3(Num1, Num2, Num3);
}
*/

void Day0522_Test_Reference1(int Data)
{
	Data += 10;
}

int Day0522_Test_Reference2(int Data)
{
	return Data += 10;
}

void Day0522_Test_Reference3(int OutData1, int OutData2, int OutData3)	//함수의 파라메터를 참조형식으로 받은 모습 
{
	OutData1 = 10;
	OutData2 = 20;
	OutData3 = 30;
}

void Day0522_ArrayParameter()
{
	const int Length = 5;
	int Array[Length] = { 10, 50, 30, 20 ,40 };

	//포인터(*)와 배열은 근본적으로 같다.
	Test_ArrayParameter(Array, Length);
}
void Test_ArrayParameter(int *Array, int Length)
{
	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("\n");
}

void Day0522_Shuffle()
{
	const int DataSize = 100;
	int Data[DataSize] = { 0, };

	for (int i = 0; i < DataSize; i++)
	{
		Data[i] = i;
	}
	Test_ArrayParameter(Data, DataSize);
	FisherYatesShuffle(Data, DataSize);
	Test_ArrayParameter(Data, DataSize);

}

void FisherYatesShuffle(int* Array, int Length) //Rand의 편향문제를 해결하는 알고리즘
{
	// 1. 배열의 마지막 요소에서 첫번째 요소로 진행
	// 2. 인덱스가 가리키는 요소와 0 ~ 인덱스 까지의 요소 중 임의의 요소를 선택
	// 3. 인덱스가 가리키느 요소와 임의로 선택된 요소를 교환
	// 4. 인덱스는 1감소

	for (int i = Length - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}
}

//간단 실습
// 1. 배열의 값들을 전부 출력해주는함수 만들기
// 2. 배열을 파라메터로 받는 함수를 만들어 구현하기
//		- 배열 내부값을 모두 더하고 평균 구해보기
//		- 배열의 값 중 최대값과 최솟값 구해보기
// 3. 피셔에이츠 알고리즘 완성 하기

void AarryTest1()
{
	const int Index = 10; 
	int TestArray[Index] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//ArrayTest1_Funtion(TestArray, Index);
	ArrayTest2_Average(TestArray, Index);

}

void ArrayTest1_Funtion(int* Array,int Index)
{
	for (int i = 0; i < Index ; i++)
	{
		printf("%d ",Array[i]);
	}
	printf("\n");
}

void ArrayTest2_Average(int* Array, int Index)
{
	int Sum = 0;
	float Avg = 0;
	for (int i = 0; i < Index; i++)
	{
		//배열 값들의 합계 구하기
		Sum += Array[i];
	}
	Avg = Sum / (float)Index;
	printf("평균 : %.1f ", Avg);
}

void Day0522_MainPractice1()
{
	const int DiceIndex =  6;			//주사위 최대 사이즈
	const int RollDiceTime = 1000000;	// 주사위 굴리는 횟수

	int Rolldice; // 랜덤 주사위 값 저장

	int CountNum1 = 0, CountNum2 = 0, CountNum3 = 0, CountNum4 = 0, CountNum5 = 0, CountNum6 = 0;

	int CountingDice[6] = {0,};

	for (int i = 0; i < RollDiceTime; i++)
	{
		Rolldice = (rand() % DiceIndex) + 1;

		//CountingDice[i] = Rolldice;

		switch (Rolldice)
		{
		case 1:
			CountNum1++;
			break;
		case 2:
			CountNum2++;
			break;
		case 3:
			CountNum3++;
			break;
		case 4:
			CountNum4++;
			break;
		case 5:
			CountNum5++;
			break;
		case 6:
			CountNum6++;
			break;
		default:
			break;
		}
	}
	printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d\n",CountNum1, CountNum2, CountNum3, CountNum4, CountNum5, CountNum6);
}

void Day0522_MainPractice2()
{
	const int IndexSize = 10;

	int Array_1[IndexSize] = {1,2,3,4,5,6,7,8,9,10};

	Day0522_MainPractice2_Function(Array_1, IndexSize);
}

void Day0522_MainPractice2_Function(int* Array, int Index)
{
	printf("현재 배열의 각 값 = [");
	for (int i = 0; i < Index; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");

	// 반복문을 통해서 
	// 0번방 의 값 = 9번방의 값
	// 1번방 의 값 = 8번방의 값 
	// ...
	// 9번방의 값 = 0번방의 값

	for (int i = 0; i < Index ; i++)
	{
		Array[i] = Index - i;
	}

	printf("뒤집은 배열의 각 값 = [");
	for (int i = 0; i < Index; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}

void Day0522_MainPractice3()
{
	const int LottoIndex = 45;
	int LottoNum[LottoIndex];
	const int WinningNumIndex = 6;

	for (int i = 0; i < LottoIndex; i++)
	{
		LottoNum[i] = i + 1;
	}

	Day0522_MainPractice3_Funtion(LottoNum, LottoIndex);	// 1~45 을 무작위로 섞기

	printf("당첨 번호 : [");
	for (int i = 0; i < WinningNumIndex; i++)
	{
		printf("%d ", LottoNum[i]);
	}
	printf("]");
}

void Day0522_MainPractice3_Funtion(int* Array, int Index)		//배열을 무작위로 섞기
{
	for (int i = Index - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);

		int Temp = Array[i];
		Array[i] = Array[j];
		Array[j] = Temp;
	}


}


/*이동 입력 처리
w(W): 위, s(S): 아래, a(A): 왼쪽, d(D): 오른쪽	
대소문자 구분 없이 처리
플레이어가 출구에 도착하면 종료		//4(플레이어)가 와야 하는 위치와 3(도착점)이 존재하는 위치가 같으면 종료.
플레이어는 ‘P ‘로 표시
게임 화면은 다음과 같은 양식을 따른다.
w(↑) s(↓) a(←) d(→)는 이동 가능한 방향만 출력한다.*/


void Day0522_MainPractice4()
{
	const int MazeRows = 10;
	const int MazeCols = 20;
	// 미로 배열 정의
	int Maze[MazeRows][MazeCols] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
		{1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
		{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int StartX = 1, StartY = 1;		//
	const int StartPosition = 2;	//시작 위치 '값'
	Maze[StartY][StartX] = StartPosition;		//시작 위치 설정

	const int EndPosition = 3;		//종료 위치 '값'
	Maze[7][18] = EndPosition;		// 종료 위치 설정

	int PlayerX = 0, PlayerY = 0; //플레이어의 좌표값	 //wasd 입력이 들어오면 얘네 둘이 변해야함
	PlayerX = StartX, PlayerY = StartY;	//시작 위치와 플레이어 위치 일치화
	int PlayerPosition = 4; //플레이어 위치 '값' //플레이어 시작 위치 설정


	char PlayerMoveInput; //플레이어가 입력하는 방향

	// StartPosition = PlayerPosition;

	//이동 방향 정의
	enum MoveDirection
	{
		Up,
		Down,
		Right,
		Left
	};

	while (PlayerPosition != EndPosition)
	{

		printf("\n=== 텍스트 미로 탈출 게임 ===\n\n");
		//게임 시작시 시작점을 플레이어 위치로 표시 (플레이어 이동시 다시 시작지점으로 바뀌어야한다)

		//맵 구현
		for (int i = 0; i < MazeRows; i++)
		{
			for (int j = 0; j < MazeCols; j++)
			{
				if ((i == PlayerX) && (j == PlayerY)) // 맵을 그리는 X,Y의 각 좌표가 플레이어의 좌표값과 같다면
				{	// 해당 좌표 값에 P를 표시한다
					if (Maze[PlayerX][PlayerY] == EndPosition)
					{
						PlayerPosition = PlayerPosition - 1;
						printf(" P ");
						Maze[i][j] = Maze[i][j];
					}
					else
					{
						printf(" P ");
						Maze[i][j] = Maze[i][j];
						//if (((Maze[i + 1][j]) || (Maze[i - 1][j]) || (Maze[i][j + 1]) || (Maze[i][j - 1])) == (2))
					}
				}
				else
				{
					switch (Maze[i][j])
					{
					case 0:
						printf(" · ");
						break;
					case 1:
						printf(" # ");
						break;
					case 2:
						printf(" S ");
						break;
					case 3:
						printf(" E ");
						break;
					default:
						break;
					}
				}
			}
			printf("\n");
		}
		printf("\n이동 할 수 있는 방향을 선택하세요. (w: 위, s: 아래, a: 왼쪽, d: 오른쪽): \n");
		//이동가능한 방향 출력
		printf("방향 입력 : ");
		std::cin >> PlayerMoveInput;
		switch (PlayerMoveInput)
		{
		case 'W':
		case 'w':
			PlayerX--;
			break;
		case 'S':
		case 's':
			PlayerX++;
			break;

		case 'A':
		case 'a':
			PlayerY--;
			break;
		case 'D':
		case 'd':
			PlayerY++;
			break;
		default:
			break;
		}
	}
}

void Day0522_MainPractice4_Function(int PlayerX, int PlayerY)
{

}




