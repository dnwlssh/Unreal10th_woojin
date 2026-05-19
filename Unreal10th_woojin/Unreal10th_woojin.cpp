


#include <iostream>
using namespace std;

void MaxMin()
{
	int Num1, Num2, Num3;
	int MaxNum =0 , MinNum = 0;
	 printf("세개의 정수를 입력 : ");
	 cin >> Num1 >> Num2 >> Num3;

	 if (Num1==Num2==Num3) // 세 수가 같을 때
	 {
		 MaxNum = Num1;
		 MinNum = Num1;
	 }

	 if ((Num1 == Num2) || (Num2 == Num3) || (Num3 == Num1)) //세 수중 두개가 같을 때
	 {
		 if (Num1 == Num2) // 1,2가 같을 때
		 {
			 if (Num1 > Num3)
			 {
				 MaxNum = Num1;
				 MinNum = Num3;
			 }
			 else
			 {
				 MaxNum = Num3;
				 MinNum = Num1;
			 }
		 }
		 else if (Num2 == Num3) // 2,3이 같을 때
		 {
			 if (Num2 > Num1)
			 {
				 MaxNum = Num2;
				 MinNum = Num1;
			 }
			 else
			 {
				 MaxNum = Num1;
				 MinNum = Num2;
			 }
		 }
		 else if (Num1 == Num3) // 1,3이 같을 때
		 {
			 if (Num1 > Num2)
			 {
				 MaxNum = Num1;
				 MinNum = Num2;
			 }
			 else
			 {
				 MaxNum = Num2;
				 MaxNum = Num1;
			 }
		 }
	 }

	 if ((Num1 > Num2) && (Num1 > Num3)) // Num1이 제일 클때
	 {
		 MaxNum = Num1;

		 if (Num2 > Num3)
		 {
			 MinNum = Num3;
		 }
		 else
		 {
			 MinNum = Num2;
		 }
	 }
	 else if ((Num2 > Num3) && (Num2 > Num1)) // Num2이 제일 클 때
	 {
		 MaxNum = Num2;

		 if (Num1 > Num3)
		 {
			 MinNum = Num3;
		 }
		 else
		 {
			 MinNum = Num1;
		 }
	 }
	 else if ((Num3 > Num1) && (Num3 > Num2)) // Num3가 제일 클 때
	 {
		 MaxNum = Num3;
		 
		 if (Num1 > Num2)
		 {
			 MinNum = Num2;
		 }
		 else
		 {
			 MinNum = Num1;
		 }
	 }
	 
	 printf("입력한 수중 가장 큰 수는 [%d]. 가장 작은 수는 [%d]\n", MaxNum, MinNum);
}

void CanWeMakeTriangle()
{
	int line1, line2, line3;
	printf("세 선분의 길이 입력 : ");
	cin >> line1 >> line2 >> line3;

	if ((line1 < line2 + line3) && (line2 < line1 + line3) && (line3 < line1 + line2))
	{
		printf("삼각형 가능\n");
	}
	else
	{
		printf("삼각형 불가능\n");
	}
}

void MiniCalculator()
{
	int Num1, Num2;
	char Operator;
	float Sol;
	printf("식 입력 :");
	cin >> Num1 >> Operator >> Num2;

	switch (Operator)
	{
	case '+':
		Sol = Num1 + Num2;
		printf("%d %c %d = %d\n", Num1, Operator, Num2, (int)Sol);
		break;
	case '-':
		Sol = Num1 - Num2;
		printf("%d %c %d = %d\n", Num1, Operator, Num2, (int)Sol);
		break;
	case '*':
		Sol = Num1 * Num2;
		printf("%d %c %d = %d\n", Num1, Operator, Num2, (int)Sol);
		break;
	case '/':
		if (Num2 == 0)
		{
			printf("0으로 나눌 수 없습니다!\n");
			break;
		}
		Sol = Num1 / Num2;
		printf("%d %c %d = %.2f\n", Num1, Operator, Num2, Sol);
		break;
	default:
		printf("+,-,*,/ 만 사용할 수 있습니다.\n");
	}
	

}
void LeapYear()
{
	int Year;
	printf("연도 입력 :");
	cin >> Year;

	//연도가 4로 나누어 떨어지면 윤년이다.
	//하지만 100으로 나누어 떨어지면 평년이다.
	//그럼에도 400으로 나누어 떨어지면 윤년이다.
	// 
	//4의 배수이면서, 100으로 나누어 떨어지지 않고 ,400으로 나누어 떨어지는 수


	if (((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0))
	{
		printf("%d년은 윤년이다.\n",Year);
	}
	else
	{
		printf("%d은 평년이다.\n", Year);
	}
}

int main()
{
	//MaxMin();
	//CanWeMakeTriangle();
	//MiniCalculator();
	//LeapYear();
}
