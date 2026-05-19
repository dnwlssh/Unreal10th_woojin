/*
	//이진수
	// - 0과 1로만 표현되는 숫자
	//	-ex) int i = 8 ;	// 메모리 : 0000 0000 0000 0000 0000 0000 0000 1000

	//float(부동소수점)
	//	- 32bit
	//	- 소수점이 있는 숫자를 저장한다.
	//	- 구조적으로 오차가 있는 데이터 타입. 같다는 비교를 조심해서 해야한다.
	//	- 숫자 뒤에 f를 붙여야 한다.

	//double(부동소수점)
	//	- 64bit

	float RealNumber = 0.0f;		// 0.0f는 float 타입
	//RealNumber = 0.1;				// 0.1은 double 타입	-> 암시적 변환이 일어나 float으로 저장됨 -> 오류 경고 발생
	RealNumber = (float)0.1;		// 명시적 변환, Casting

	printf("%.2f\n", RealNumber);

	RealNumber = 0.1f + 0.5f;
	printf("%.2f\n", RealNumber);	// 소수점 아래 둘째자리까지 출력
	RealNumber -= 0.2f;
	printf("%8.2f\n", RealNumber);	//소수점 포함 전체 8자리, 소수점 아래 둘째자리까지 출력
	printf("float 타입의 사이즈는 [%d]byte입니다.\n", (int)sizeof(float));

	//bool(불리언 타입)
	//	- 1Byte(8bit)
	//	- true,false 두개만 저장하는 데이터 타입
	//	- 프로그램의 각종 분기를 결정할 때 사용
	//	- 변수명 앞에 'b' 혹은 'is'를 붙임 (b -> Be)

	bool bTest = false;
	bTest = true;
	printf("bool 타입의 사이즈는 [%d]byte입니다.\n",(int)sizeof(bool));

	//char(캐릭터 타입)
	// - 글자 하나를 저장하는 데이터 타입
	// - 8bit짜리 정수형 데이터타입

	char testCharactor = 'a';
	testCharactor = 'b';
	testCharactor = 'B';
	printf("char textCharactor = %c\n", testCharactor);

	// 문자열
	// - char*, std::string
	string TestString = "Hello World!\n";

	// 부호없음 정수형(32bit, 숫자 범위 약 0 ~ 42억)
	// unsigned
	unsigned int TestInteger = 0;

	// 64bit 정수형
	long long TestInteger64 = 0;
	unsigned long long TestInteger64_2 = 0;	//부호 없는 long long

	//유니코드 캐릭터형
	// wcahr_t
	// 글자 하나 저장
	// 암시적 변환 X
	// * 문자열끼리는 서로 비교하지 않는 것이 좋다.
	wchar_t UnicodeChar = L'가';

	int Size = 100;
	printf("한 변이 %d인 정사각형의 넓이는 %d입니다.\n",Size , Size * Size);

	Size = 50000;
	printf("한 변이 %d인 정사각형의 넓이는 %u입니다.\n", Size, (unsigned int)Size * (unsigned int)Size);

	//const(상수)
	//	-절대 변하지 않는 숫자
	// - 코드의 안정성과 가독성을 높여준다.
	//
	const int TestConst = 10;

	//간단 실습
	// 1. 원의 반지름 입력 받고 넓이 구하기
	// 2. 3개의 값을 입력 받고 평균값 구하기
	// 3. 정가와 할인율을 입력 받고 할인된 가격 구하기

	//비교연산자(이항연산자)
	// - 두 변수를 비교하는 연산자(크다,작다,같다 등을 계산)
	bool bTest = false;
	bTest = 10 > 5;		//true		> 왼쪽 항목이 오른쪽 항목보다 큰지 확인하는 비교연산자
	bTest = 10 < 5;		//false
	bTest = 10 >= 5;	//true
	bTest = 10 >= 10;	//true
	bTest = 10 > 10;	//false
	bTest = 10 == 10;	//true		 == 양변의 값이 같은지 확인하는 비교연산자

	bTest = 0.1f + 0.2f == 0.3f;	//이런식의 비교는 절대로 하면 안된다.(메모리상 float의 수치값이 실제와 다를 수 있으므로)

	// 조건문
	// - 특정 조건에 따라 다른 동작을 하게 만드는 문(statement)

	// if
	// - () 사이의 조건식이 ture면 다음 {} 사이의 코드를 실행한다.
	int a = 10;
	int b = 20;
	if (a > b)
	{
		printf("a가 b보다 큽니다.\n");
	}

	// if else
	// - () 사이의 조건식이 ture면 If 아래 {} 사이의 코드를 실행하고, false면 else 아래 {} 사이의 코드를 실행한다.
	if (a > b)
	{
		printf("a[%d]가 b[%d]보다 큽니다.\n",a,b);
	}
	else
	{
		printf("a[%d]가 b[%d]보다 작습니다.\n", a, b);
	}

	//else if
	// - if를 중첩하기
	if (a < (b * 2))
	{

	}
	else if (a > b)
	{

	}
	else if (a > (b / 2))
	{

	}
	else

	// switch
	// - 값이 여러가지 중 하나일 때 각각의 경우에 따라 다르게 처리할 때 사용
	// - if, elsf if 와 크게 성능차이는 없으나 케이스 별로 관리하기 좋기 때문에, 코드 가독성 좋음

	a = 1;
	switch (a)
	{
	case 1:
		printf("a는 1입니다.\n");
		break;
	case 10:
		printf("a는 10입니다.\n");
		break;
	default:
		printf("a는 %d입니다.\n",a);
		break;
	}

	// 삼항연산자
	int x = (a > 10) ? 1 : 0;	// ? 앞의 조건식이 참이면 ? 와 : 사이에 있는 값, 거짓이면 : 뒤에 있는 값

	// 논리연산자
	// - 참 아니면 거짓이 나오는 연산
	// - bool을 다루는 연산자.

	// &&
	//	- And
	//	- && 연산자 좌우의 값이 모두 ture일때만 ture를 반환, 아니면 false를 반환
	//	- bool bTest = true && true;	// 이 경우에만 bTest는 true를 반환한다.

	// ||
	//	- OR
	//	- || 연산자 좌우의 값 중 하나라도 true일때 true를 반환, 둘 다 false일 때만 false를 반환한다.
	//	- bool bTest = false || false;	// 이 경우에만 bTest는 false를 반환한다.

	// !
	//	- NOT
	//	- ture는 false로 만들고 false는 true로 만든다.
	//	- bool bTest = true; bTest = !bTest;	//bTest는 false를 반환한다.

	int point = 78;
	if ((point < 90) && (point > 80))
	{
		printf("B학점입니다.\n");
	}

	*/