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
	Direction = Up | Down | Left | Right; // 오른쪽 위

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
*/