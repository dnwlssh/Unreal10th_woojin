#include <iostream>
#include "Day0526.h"

void Day0526()
{
	// 포인터
	// - 메모리 '주소'를 저장하는 변수
	// - 각 데이터 타입에 *(아스트리크)만 붙이면 포인터 타입이 된다.
	
	// IntergerAddres는 int 타입 변수의 주소를 저장하는 변수다. 기본값으로 nullptr을 저장한다
	int* IntergerAddress = nullptr;	// 인티저 포인터 IntergerAddress 선언하고 nullptr로 초기화하기

	float* pFloat = nullptr;		// 플롯 포인터 pFloat
	char* pTestString = nullptr;	// 캐릭터 포인터 (문자열,string) pTestString

	// 포인터 연산자
	// - & : 주소 연산자 . 변수 앞에 붙이면 그 변수의 주소를 돌려준다.
	// - * : 간접 참조 연산자 . 포인터 변수 앞에 붙이면 그 포인터 변수가 가리키는 주소에 있는 실제 값을 돌려준ㄷ

	int Data = 10; 
	IntergerAddress = &Data;				// 'Data라는 변수의 주소'를 IntergerAddress에 저장해라.
	int Temp1 = *IntergerAddress;			// IntergerAddress가 가리키는 주소에 있는 실제값(Data의 값)을 Temp에 대입해라.
	int Temp2 = (*IntergerAddress) * 2;		// IntergerAddress가 가리키는 실제값을 두배시켜서 Temp2에 대입해라.

	// 상수와 포인터
	const int* ConstPointer = &Data;		//ConstPointer는 Data의 주소를 가리키는데 그 "값"을 변경하지 않겠다.
	ConstPointer = &Temp1;
	//(*ConstPointer) = 2;					// const int*에서 값을 변경하는 것은 문법 에러
	int* const ConstPointer2 = &Data;		// ConstPointer는 Data의 주소를 가리키는데 그 "주소"를 변경하지 않겠다.
	//ConstPointer2 = &Temp2;				// int * const에서 주소를 변경하는 것은 문법 에러


	// const는 자기 왼쪽에 있는 것(왼쪽에 아무것도 없으면 오른쪽에 있는 것)을 변경하지 않는다.
	//const int A = 10;	// 일반적으로 많이 사용
	//int const B = 20;	// 문법적으로느 문제 없으나 거의 사용 안함

	// '+' 연산자와 '-' 연산자
	// - 포인터 타입의 값타입의 크기만큼 증가/감소한다.
	int* pData = &Data;		// Data의 주소가 0x10이라고 가정하면
	pData = pData + 1;		// +1 한 결과는 0x14. int의 크기가 4byte라서.
	pData++;				// 0x18
	pData--;				// 0x14

	// 배열과 포인터
	int Array[5] = {1,2,3,4,5};
	int* pArray = Array;
	Array[1];				// 배열의 두번째 요소에 접근
	pArray + 1;				// 포인터를 이용해서 두번째 요소에 접근

	// range-for : 배열이나 컨테이너의 첫 요소에서 마지막 요소까지 순차적으로 처리할 때 유용
	for (int Element : Array)
	{
		printf("%d", Element);
	}
	printf("\n");

	// pArray를 이용해서 Array의 4번째 요소 출력하기
	printf("Array의 4번째 요소 : %u\n", (*pArray + 3));		// pArray + 3 : Array의 4번쨰 요소 '주소값' , (*pArray + 3) : Array의 4번째 요소의 '주소값에 있는 실제 값' 
	Day0526_PointParameter(Array, 5);

	// C++의 메모리 영역
	// - 코드 영역
	//		- 프로그램의 실행 코드가 저장되는 공간
	// - 데이터 영역
	//		- 프로그램이 시작 할 떄 부터 끝날 떄까지 유지되는 변수 
	//		- 전역 변수 , static 변수 등
	// - 스택 영역
	//		- 함수가 호출될 때마다 필요한 변수(지역변수)
	//		- 함수가 끝날 떄 마다 자동으로 정리
	//		- 크기 제한이 있다.(윈도우에서 별다른 설정이 없으면 1MB)
	//		- 빠르다.
	// - 힙 영역
	//		- 프로그램 실행 중에 필요에 따라 직접 메모리를 할당하고 사용하는 공간.
	//		- 반드시 할당을 하면 해체를 해줘야 한다.
	//		- 크기는 대략 RAM 크기와 같다.
	//		- 느리다. (상대적으로 스택에 비해)

	// 동적 할당(Dynamic Allocation)
	// - 프로그램 실행 도중(Runtime)에 메모리를 사용하기 위해 확보하는 행위
	// - 단점
	//		- 처리 속도가 느리다 (= 자주하면 안된다.)
	//		- 메모리 단편화 문제가 발생 할 수 있다.
	// - C++ 방식 
	//		- 장점 : 초기화 있음. 타입 안정성 있음. 생성자/소멸자 호출됨.
	//		- new, delete

	//*할당 하면서 '메모리 주소'를 주기 때문에 무조건 포인터 변수로 선언해야함*
	int* Alloc = new int(5);	// int 크기로 동적 할당을 받고 초기값으로 5를 설정한 다음 그 주소를 Alloc에 저장해라. 
	
	*Alloc - 20;

	delete Alloc;				// 다 썼으면 반드시 해제해야 한다. 메모리를 할당하고 해제하지 않으면 메모리 누수(Memory Leak)가 발생한다.
	Alloc = nullptr;			// 댕글링 포인터 방지를 위해 꼭 하는것이 좋다.

	Alloc = new int[10];		// int 10개짜리 배열을 만들어라
	delete[] Alloc;				// 배열을 할당 받은 것을 해제할 때는 delete[]를 써야한다. 
	Alloc = nullptr;

	int** Array2Dim = new int* [5];	//세로 5
	for (int i = 0; i < 5; i++)
	{
		Array2Dim[i] = new int[10];	//가로 10
	}
	for (int i = 0; i < 5; i++)
	{
		delete[] Array2Dim[i];
	}
	delete[] Array2Dim;
	}

//배열을 파라미터로 넘길 때는 포인터를 주로 활용한다
void Day0526_PointParameter(int* Data, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%d", *(Data + i));
	}
	printf("\n");
}

// 간단 실습
// 1. 두 변수의 값을 변경하는 함수 만들기
//		int a,b; Swap(a,b); 하면 a와 b의 값이 서로 바뀐다.

void Swap(int* a, int* b) // a의 주소,b의 주소
{
	int Temp = 0;
	Temp = *a;	// Temp의 값은 a의 주소에 있는 값.
	*a = *b;	// a의주소에 있는 값은 b의 주소에 있는 값
	*b = Temp;	// b의 주소에 있는 값은 Temp(a값)

	printf("변경 결과(A,B) -> (B,A) : (%d,%d)", *a, *b);
}

// 2. 포인터를 이용해서 배열의 최댓값 찾아보기
//		- 인덱스 사용 금지. (Array[i] 이런식의 사용 금지)
void PointerUsedMinMax(int* Data,int Size)
{
	Data =
}
// 3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
