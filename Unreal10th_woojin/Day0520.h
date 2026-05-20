/*
	// 비트연산자
	// - 비트를 계산하는 연산자.
	// - 비트 플래그를 사용하기 위해 필요하다.
	
	// 비트 And
	// - &
	// - 양변에 있는 데이터의 , 각 자리수 비트가 둘다 1이어야만 1이다.
	// - 특정 비트에 세팅된 값을 확인하기 위해 사용한다.
	int DataA = 6;
	int DataB = 7;
	printf("DataA & DataB = %d\n", DataA & DataB);

	// 비트 Or
	// - |
	// - 양 변에 있는 데이터의, 각 자리수 비트가 하나라도 1이면 1이다.
	// - 특정 비트에 플래그를 세팅할 떄 사용한다.
	printf("DataA & DataB = %d\n", DataA | DataB);

	//비트 Not
	// - ~
	// - 비트 값이 반전된다
	unsigned int DataC = 6;
	printf("_DataC = %d\n",~DataC);

	//비트 XOR
	// - ^
	// - 양변에 있는 데이터의 각 자리수 비트가 다르면 1, 같으면 0
	// - 특정 비트를 토글할 떄 사용(모두 0으로 채우고 토글할 비트만 1로 세팅한 후 XOR을 하면 된다.)
	printf("Bit Toggle : %d\n", DataA ^ 1);		
	printf("Bit Toggle : %d\n", (DataA ^ 1) ^ 1);

	// 비트 쉬프트
	// - 왼쪽 쉬프트 << , 오른쪽 쉬프트 >>
	printf("Bit Left Shift : %d", DataA << 1);	// 곱하기 2 (비트가 왼쪽으로 한칸씩 밀리므로)
	printf("Bit Left Shift : %d", DataA >> 1);	// 나누기 2 (비트가 오른쪽으로 한칸씩 밀리므로)
	// 1 << 4; // 5번째 비트 세팅

	// enum
	// - 상수의 집합
	enum WeekDays 
	{	// 별도의 설정이 없으면 첫번째 enum 값은 0이고 1씩 증가
		Mon,
		Tue,
		Wed,
		Thu,
		Fri,
		Sat = 10,		// 따로 설정하면 그 값부터 다시 1씩 증가
		Sun
	};
	
	int EnumTest1 = Mon;

	enum BitFlagTest // 비트 플래그용 마스크 설정하는 기본 방식
	{
		Up		= 1 << 0,
		Down,	= 1 << 1,
		Left,	= 1 << 2,
		Right	= 1 << 3,
	};

	int Direction = Up | Right; // 오른쪽 위
	Direction = Up | Down | Left | Right;

	switch (Direction)
	{
	case Up:
		break;
	case Down:
		break;
	case Left:
		break;
	case Right:
		break;
	default:
		break;
	}

	// 간단 실습
	// 1. 비트 연산을 활용해서 홀짝을 판별하기. (입력데이터는 무조건 양수이다.)
	// 2. 캐릭터가 사용가능한 무기 enum만들기. 데이터 설정해서 특정 무기를 사용할 수 있는지 없는지 확인하는 코드 만들기
	// 3. 캐릭터가 사용 가능한 무기를 추가 삭제하기

	// 반복문
	// - 특정 코드 블록을 조건에 따라 여러번 반복해서 실행 할 수 있게 해주는 문(Statement)

	// for
	// - 반복 횟수가 명확할 때 사용하기 좋다.
	for (int i = 0; i < 5; i++) // for(변수초기화 ; 종료조건 ; 증감부)
	{
		printf("Hello for\n : %d", i);
	}

	// while
	// - 반복 횟수가 명확하지 않고 조건에 따라 반복해야 할 때 사용하기 좋다.
	int j = 0;
	while (j < 5)	//while(true) -> 무한 루프(종료 조건 반드시 있어야함)
	{
		printf("Hello while : %d", j);
		j++;
	}

	// do - while
	// - while과 비슷한데 최소 한번은 실행해야 할 떄 사용하기 좋다.
	j = 0;
	do
	{
		printf("Hello while : %d", j);
		j++;
	} while (j < 5);

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
	}
}
*/
/*
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
*/

// 랜덤
//srand(time(0));
//
//int RandNumber = 0; // 랜덤의 시드값을 현재 시간으로 설정하기(프로그램 실행할 때 한번만 하면 된다.)
//int TestCount = 10000000;
//int Num1 = 0, Num2 = 0, Num3 = 0, Num4 = 0, Num5 = 0, Num6 = 0;
//
//for (int i = 0; i < TestCount; i++)
//{
//	RandNumber = rand() % 6 + 1;
//	//printf("Random : %d\n", RandNumber);
//	switch (RandNumber)
//	{
//	case 1:
//		Num1++;
//		break;
//	case 2:
//		Num2++;
//		break;
//	case 3:
//		Num3++;
//		break;
//	case 4:
//		Num4++;
//		break;
//	case 5:
//		Num5++;
//		break;
//	case 6:
//		Num6++;
//		break;
//	default:
//		printf("ERROR!!\n");
//	}
//}
//printf("1:%d\n2:%d\n3:%d\n4:%d\n5:%d\n6:%d\n", Num1, Num2, Num3, Num4, Num5, Num6);

//간단 실습
// 1. 가위 바위 보 게임 만들기
//		- 3선승제
//		- enum 활용
// 2. 하이 로우
//		- 컴퓨터가 1~100사이의 임의의 숫자를 선택하고 사용자가 맞출때 까지 입력을 받아 "더 높게", "더 낮게" 등의 힌트를 제공
//		- 5번 안에 맞춰야 함