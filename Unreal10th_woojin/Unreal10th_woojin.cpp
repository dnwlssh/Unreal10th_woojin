


#include <iostream>
using namespace std;

//간단 실습
// // 1. 원의 반지름 입력 받고 넓이 구하기
// 2. 3개의 값을 입력 받고 평균값 구하기
// 3. 정가와 할인율을 입력 받고 할인된 가격 구하기

void CircleArea()
{
	float radius;
	float PI;
	PI = 3.141592;
	printf("반지름 입력 : ");
	cin >> radius;
	printf("원의 넓이 : %.2f\n", PI * radius * radius);
}

void Average()
{
	float Num1, Num2, Num3;
	float Ave;	//왠만하면 변수를 선언해주는게 좋다.
	printf("각 값 입력 :");
	cin >> Num1 >> Num2 >> Num3;
	Ave = (Num1 + Num2 + Num3) / 3.0;
	printf("세 값의 평균 : %.2f\n", Ave);
}

void DiscountRate()
{
	float Price,Discount;
	printf("정가와 할인율 입력 : ");
	cin >> Price >> Discount;
	printf("할인된 가격 : %.0f원\n", Price - (Price * (Discount / 100)));
}

void NumberPlay()
{
	int Num;
	printf("숫자 입력 :");
	cin >> Num;
	if (Num > 0)
	{
		printf("입력하신 숫자 [%d]는 양수입니다.\n",Num);
	}
	else if (Num == 0)
	{
		printf("입력하신 숫자 [%d]는 '0' 입니다.\n", Num);
	}
	else
	{
		printf("입력하신 숫자 [%d]는 음수입니다.\n", Num);
	}
}

void NumberPlay2()
{
	int Num;
	printf("숫자 입력 :");
	cin >> Num;
	if (Num%2 == 0)
	{
		printf("입력하신 숫자 [%d]는 짝수입니다.\n", Num);
	}
	else
	{
		printf("입력하신 숫자 [%d]는 홀수입니다.\n", Num);
	}
}

void NumberPlay3()
{
	int Num1,Num2 ;
	printf("숫자 입력 :");
	cin >> Num1>>Num2;
	if (Num1 > Num2)
	{
		printf("더 큰 수는 [%d].\n", Num1);
	}
	else if (Num1 < Num2)
	{
		printf("더 큰 수는 [%d].\n", Num2);
	}
	else
	{
		printf("두 수가 같습습니다.\n");
	}
}

void AndOrNot1()
{
	int Age, Height;
	printf("나이와 키 입력 :");
	cin >> Age >> Height;
	if ((Age > 6) && (Height > 120))
	{
		printf("탑승 가능\n");
	}
	else
	{
		printf("탑승 불가능\n");
	}
}

void AndOrNot2()
{
	int Score;
	printf("점수 입력 :");
	cin >> Score;
	if (Score >= 90)
	{
		printf("A\n");
	}
	else if ((Score < 90) && (Score >= 80))
	{
		printf("B\n");
	}
	else if ((Score < 80) && (Score >= 70))
	{
		printf("C\n");
	}
	else if ((Score < 70) && (Score >= 60))
	{
		printf("D\n");
	}
	else
	{
		printf("F\n");
	}
}

void AndOrNot3()
{
	int Sub1, Sub2, Sub3;
	float SubAvg;
	printf("각 과목 점수 입력 :");
	cin >> Sub1 >> Sub2 >> Sub3;

	SubAvg = (Sub1 + Sub2 + Sub3) / 3.0;

	if (SubAvg >= 60)
	{
		if ((Sub1 < 40) || (Sub2 < 40) || (Sub3 < 40))
		{
			printf("불합격\n");
		}
		else
		{
			printf("합격\n");
		}
		
	}
	else
	{
		printf("불합격\n");
	}
	
}

int main()
{
	// 조건문 간단 실습
	// 1. 숫자를 입력 받아 양수인지 음수인지 0 인지 판단하는 코드
	// 2. 숫자를 입력 받아 홀수인지 짝수인지 판단하는 코드
	// 3. 두 수를 입력 받아 더 큰 수를 출력하는 코드 . 같을경우 같다고 출력.

	// 논리연산자 간단 실습
	// 1. 나이와 키를 입력 받아, 6세 이상 , 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력하기
	// 2. 점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기
	// 3. 세 과목의 점수를 입력 받아, 세 과목의 평균점이 60점 이상이면 "합격", 아니면 "불합격"을 출력하는 프로그램을 작성하기
	//		한 과목이라도 40점 미만이면 불합격 출력하기

	AndOrNot3();
}
