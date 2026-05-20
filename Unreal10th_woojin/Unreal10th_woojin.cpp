


#include <iostream>
using namespace std;

void NumCheck()
{
	int Num;
	printf("숫자 입력 : ");
	cin >> Num;

	if (Num & 1 == 1)
	{
		printf("%d는 홀수입니다.\n",Num);
	}
	else
	{
		printf("%d는 짝수입니다.\n",Num);
	}
}

void MakeEnum()
{
	enum Wepons
	{
		Sword = 1,
		Mace = 1 << 1,
		Halberd = 1 << 2,
		Crossbow = 1 << 3,
		Warhammer = 1 << 4,
		Lance
	};
	const int NumOfWepons = 5;
	int CharactorArmStaus = Sword | Mace | Halberd ;
	int Weponchoose;

	printf("무기를 선택하세요 \n1.Sword\n2.Mace\n3.Helberd\n4.Crossbow\n5.Warhammer\n6.Lance  : \n");
	printf("무기선택 : ");  cin >> Weponchoose;

	/*switch (Weponchoose)
	{
	case 1:
		if ((CharactorArmStaus & Sword) != 0)
		{
			printf("검을 사용할 수 있습니다.\n");
		}
		else
		{
			printf("검을 사용할 수 없습니다.\n");
		}
		break;
	case 2:
		if ((CharactorArmStaus & Mace) != 0)
		{
			printf("메이스를 사용할 수 있습니다.\n");
		}
		else
		{
			printf("메이스를 사용할 수 없습니다.\n");
		}
		break;*/
	
	//무기 추가/삭제
	/*printf("플레이어가 사용 가능한 무기는 다음과 같습니다.\n");
	for (int i = 0; i < 6; i++)
	{
		if (CharactorArmStaus & (1 << i) != 0)
		{

		}
	}*/
}

void Loop1()
{
	int Sol = 0;
	int Num = 0;
	while (true)
	{
		printf("숫자 입력 : ");
		cin >> Num;
		if (Num == 0)
		{
			break;
		}
		Sol += Num;
	}

	/*do
	{
		printf("숫자 입력 : ");
		cin >> Num;
		Sol += Num;
	} while (Num == 0);*/

	printf("지금까지 입력 한 숫자의 합 : %d\n", Sol);
}

void Loop2()
{
	int MulNum;
	printf("숫자 입력 : ");
	cin >> MulNum;

	for (int i = 1; i < 10; i++)
	{
		printf("%d X %d = %d\n", MulNum, i , MulNum * i);
	}

}

void Loop3()
{
	int Num;
	printf("숫자 입력 :");
	cin >> Num;

	printf("1부터 %d 사이에 존재하는 홀수는\n",Num);
	for (int i = 0; i <= Num; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d\n",i);
		}
	}
}

void Loop4()
{
	printf("1~100 중 7의 배수는\n");
	for (int i = 1; i < 101; i++)
	{
		if (i % 7 == 0)
		{
			printf("%d\n", i);
		}
	}
}

void Loop5()
{
	int Num = 0, Sol = 1;
	printf("숫자 입력 : ");
	cin >> Num;
	for (int i = 1; i <= Num ; i++)
	{
		Sol *= i;
	}
	printf("%d! = %d\n",Num,Sol);
}

void Loop6()
{
	int floor=0;
	printf("피라미드 바닥 갯수 : ");
	cin >> floor;

	for (int i = 0; i < floor; i++)
	{
		for (int j = 0; j < floor - 1 - i; j++)
		{
			printf(" ");
		}

		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	// 간단 실습
	// 1. 0을 입력 받을 때 까지 입력 받은 숫자의 합을 출력
	//		-while과 do while 둘다 사용
	// 2. 입력 받은 수의 구구단 출력하기
	// 3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기
	// 4. 1 ~ 100 중에 7의 배수만 출력하기
	// 5. 팩토리얼 계산하기
	// 6. *으로 피라미드 모양의 삼각형 찍기
	Loop6();
}

	
	
