#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Day0527.h"

void Day0527()
{
	// 문자열
	// - 한 문장, 연속된 char.
	// - C에서는 char*, char[] 사용
	// - 항상 모든 문자열은 '\0'로 끝난다.
	const char* TestString1 = "Hello String!\n";
	const char* TestString2 = "안녕 문자열!\n";		// 인코딩이 자동으로 처리되서 한글이 보이는거다

	// wchar_t : 유니코드용 char.

	const char* TestStirng = "Hello";

	int Size = MyStrLen(TestStirng);
	printf("[%s]의 길이는 [%d]입니다.\n", TestStirng, Size);

	Size = (int)strlen(TestStirng);			// 기본 헤더 <string.h>>에 포함된 내장 함수 
	printf("[%s]의 길이는 [%d]입니다.\n", TestStirng, Size);

	//복사
	char Buffer[32] = { 0, };			// Butter 사이즈가 32인이유 : 메모리를 잡아줄 때는 2의 배수로 잡는것을 권장
	strcpy(Buffer, TestStirng);
	printf("Buffer의 내용문은 [%s]입니다.\n", Buffer);		// Buffer : Hello			// 함수 구현 : 각 글자 값을 하나씩 출력

	//덧붙이기
	strcat(Buffer, TestStirng);
	printf("Buffer의 내용문은 [%s]입니다.\n", Buffer);	// Buffer : Hello Hello		// 함수 구현 : 버퍼의 마지막을 찾아서 strcpy 한번더 실행

	//비교
	int Result = strcmp("abc", "abc");	// 같으면 0
	Result = strcmp("ab", "abc");		// 왼쪽이 작으면 -1
	Result = strcmp("abb", "abc");
	Result = strcmp("abc", "abb");		// 오른쪽이 작으면 +1
	Result = strcmp("abc", "ab");


	const char* TestStringNumber1 = "123";
	int Number = atoi(TestStringNumber1);
	printf("문자열 [%s]는 인티저 [%d]입니다.\n", TestStringNumber1, Number);

	const char* TestStringNumber2 = "12.3";
	float FloatNumber = atof(TestStringNumber2);
	printf("문자열 [%s]는 실수 [%d]입니다.\n", TestStringNumber2, Number);

	// 간단 실습 
	// 1.MyStrCpy
	// 2.MyStrCat
	// 3.MyStrCmp
	// 4.MyAtoI
	// 5.MyAtoF
	// 위 함수들 만들기. 파라메터와 리턴타입은 원본과 같이 만들기

	//테스트
	//const char* TestCasePass[] = { "123", "-342", "0", " 33", "+92", "  -11" };
	//const int TestCaseResult[] = { 123, -342, 0, 33, 92, -11 };
	//const char* TestCaseFail[] = { "45ds", "as54", " +-233", "12 35", "" };	
	//
	//int PassCount = 0;
	//int FailCount = 0;
	//int TestCount = sizeof(TestCasePass) / sizeof(TestCasePass[0]);
	//for(int i=0;i< TestCount;i++)
	//{
	//	const char* Case = TestCasePass[i];
	//	if (MyAtoI(Case) == TestCaseResult[i])
	//		PassCount++;
	//	else
	//		FailCount++;
	//	printf("[%s] = [%d] : %s\n", Case, MyAtoI(Case), MyAtoI(Case) == TestCaseResult[i] ? "Pass" : "Fail");
	//}
	//printf("PassCount : %d, FailCount : %d\n", PassCount, FailCount);
	//if (FailCount > 0)
	//{
	//	printf("ERROR!!!!!!!!!!!!!!!!!!!!\n");
	//}
	//
	//// 실패 테스트
	//PassCount = 0;
	//FailCount = 0;
	//TestCount = sizeof(TestCaseFail) / sizeof(TestCaseFail[0]);
	//for (int i = 0; i < TestCount; i++)
	//{
	//	const char* Case = TestCaseFail[i];
	//	if (MyAtoI(Case) == 0)
	//		PassCount++;
	//	else
	//		FailCount++;
	//	printf("[%s] = [%d] : %s\n", Case, MyAtoI(Case), MyAtoI(Case) == 0 ? "Pass" : "Fail");
	//}
	//printf("PassCount : %d, FailCount : %d\n", PassCount, FailCount);
	//if (FailCount > 0)
	//{
	//	printf("ERROR!!!!!!!!!!!!!!!!!!!!\n");
	//}

	const char* TestCasePass2[] = { "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54" };
	const float TestCaseResult2[] = { 123.45f, -38.556f, 0.0f, 3.14f, 0.5f, 0.7f, 12.0f, -0.54f };
	const char* TestCaseFail2[] = { "12.05.78", "45.dd", "aqw45.8", "12. 35", "" };
	int PassCount2 = 0;
	int FailCount2 = 0;
	int TestCount2 = sizeof(TestCasePass2) / sizeof(TestCasePass2[0]);

	for (int i = 0; i < TestCount2; i++)
	{
		const char* Case = TestCasePass2[i];
		float PrasedFloatVal = MyAtoF(Case);
		bool IsSame = ComparisonOfNumbers(PrasedFloatVal, TestCaseResult2[i]);
		if (IsSame)
			PassCount2++;
		else
			FailCount2++;
		printf("[%s] = [%f] : %s\n", Case, PrasedFloatVal, IsSame ? "Pass" : "Fail");
	}
	printf("PassCount : %d, FailCount : %d\n", PassCount2, FailCount2);
	if (FailCount2 > 0)
	{
		printf("ERROR!!!!!!!!!!!!!!!!!!!!\n");
	}

	// 실패 테스트
	PassCount2 = 0;
	FailCount2 = 0;
	TestCount2 = sizeof(TestCaseFail2) / sizeof(TestCaseFail2[0]);
	for (int i = 0; i < TestCount2; i++)
	{
		const char* Case = TestCaseFail2[i];
		if (MyAtoF(Case) == 0)
			PassCount2++;
		else
			FailCount2++;
		printf("[%s] = [%f] : %s\n", Case, MyAtoF(Case), MyAtoF(Case) == 0.0f ? "Pass" : "Fail");
	}
	printf("PassCount : %d, FailCount : %d\n", PassCount2, FailCount2);
	if (FailCount2 > 0)
	{
		printf("ERROR!!!!!!!!!!!!!!!!!!!!\n");
	}
}

int MyStrLen(const char* str)
{
	// \0는 제외한 길이를 리턴
	int Length = 0;
	while (*(str + Length) != '\0') // '\0'이 나올 때 까지 Length 카운트
	{
		Length++;
	}
	return Length;
}

//복사
char* MyStrCpy(char* Destination, const char* Source)
{
	// 표준 버전
	// char* Result = Destination;		//시작 주소
	// while ((*Destination++ = *Source++) != \'0') {}
	// return Result;

	// 표준 버전 해설 
	// while ((*Destination++ = *Source++) != \'0')
	//	1. *Destination++ = *Source++ : Source 의 char 값을 Destination에 담는다.
	//  2. *Destination++ , *Source++ 로 다음 글자로 이동
	//  3. Destination의 현재 값을 나타내는 캐릭터가 \0인지 아닌지 확인
	//
	printf("MyStrCpy : ");
	// Source : 복사 할 원본 문자열
	// Destination : 붙여넣기 할 자리
	//각 글자 값을 하나씩 출력
	int Index = 0;
	while (*(Destination + Index) != *(Source + Index))
	{
		//Destination의 첫 요소 값에 Source의 첫 요소값을 대입
		*(Destination + Index) = *(Source + Index);
		Index++;
	}
	return Destination;
}

char* MyStrCat(char* Destination, const char* Source)
{
	printf("MyStrCat : ");
	// 표준 해설
	//char* Result = Destination;
	//while(*Destination)
	//{
	//	 Destination++;				// Destination의 마지막 까지 이동
	//}
	//
	//while ((*Destination++ = *Source++) != '\0') {}		//strcpy 한번더
 	//
	//return Result;
	
	
	char* Result = Destination;		// Result 는 Destination 문자열을 저장하는 포인터 변수
	int index = 0;
	while (*(Destination + index) != '\0')	//Destination의 요소 값이 '\0'이 나올 떄 까지 요소 확인
	{
		index++;
	}
	while ((*(Destination + index) = *(Source + index - 5)) != '\0')			// '\0' 이후부터 다시 Source를 입력해줘야함 
	{
		index++;
	}
	return Result;
}

int MyStrCmp(const char* Str1, const char* Str2)
{
	int Result = 0;
	 //Str1의 값이 \0이 아니고, Str1과 Str2가 같을 때
	 while (*Str1 && (*Str1 == *Str2))
	 {
	 	 Str1++;		// 다음 글자로 이동
	 	 Str2++;		// 
	 }
	 if ((*((const unsigned char*)Str1) - *((const unsigned char*)Str2)) > 0)
	 {
		 Result = 1;
	 }
	 else if ((*((const unsigned char*)Str1) - *((const unsigned char*)Str2)) < 0)
	 {
		 Result = -1;
	 }
	 else
	 {
		 Result = 0;
	 }
	 //아스키 코드값 비교. 같으면 0, Str1이 작으면 음수 , Str2가 작으면 양수
	 return Result;


	//비교를 멈추는 조건 : 두 요소 값이 모두 '\0'이 아닐 때와 두 요소 값이 같지 않을 때
	// 두 요소 값이 모두 '\0'이 아닐때 = 두 요소값이 다를 때

	//while ((*Str1 == *Str2) && *Str1)	// 두 요소값이 다르면 스탑
	//{
	//	Str1++;
	//	Str2++;
	//}
	//return *((const unsigned char*)Str1) - *((const unsigned char*)Str2);
}

int MyAtoI(const char* Source)
{
	//	- 성공 : "123", "-342", "0", " 33", "+92", "  -11"
	//  - 실패. 무조건 0반환 : "45ds", "as54", " +-233", "12 35", ""

	// 공백 제거
	while (*Source == ' ' || *Source == '\t' || *Source == '\n' || *Source == '\r')
	{
		Source++;
	}

	// 부호처리
	int Sign = 1;
	if (*Source == '-')
	{
		Sign = -1;
		Source++;
	}
	else if (*Source == '+')
	{
		Source++;
	}

	// 문자를 숫자로 바꾸기
	int Result = 0;
	while (*Source >= '0' && *Source <= '9')
	{
		Result = Result * 10 + (*Source - '0');	// 숫자 누적하기
		Source++;
	}

	// 숫자가 아닌 것이 나왔을 때 처리
	if (*Source != '\0')
	{
		Result = 0;
	}

	return Result * Sign;
}

float MyAtoF(const char* Source)
{
	//	- 성공 : "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54"
	//	- 실패. 무조건 0반환 : "12.05.78", "45.dd", "aqw45.8", "12. 35", ""

	// 공백 제거
	while (*Source == ' ' || *Source == '\t' || *Source == '\n' || *Source == '\r')
	{
		Source++;
	}

	// 부호 처리
	int Sign = 1;
	if (*Source == '-')
	{
		Sign = -1;
		Source++;
	}
	else if (*Source == '+')
	{
		Source++;
	}

	// 문자를 숫자로 바꾸기
	float Result = 0;
	while (*Source >= '0' && *Source <= '9')
	{
		Result = Result * 10.0f + (*Source - '0');	// 숫자 누적하기
		Source++;
	}

	// 소수점(.) 처리
	if (*Source == '.')
	{
		Source++;

		float Fraction = 1.0f;
		// 문자를 숫자로 바꾸기
		while (*Source >= '0' && *Source <= '9')
		{
			//123.45
			Result = Result * 10.0f + (*Source - '0');	// 숫자 누적하기
			Source++;
			Fraction *= 0.1f;	// 소수점 아래로 얼마나 내려갈지 누적
		}
		Result *= Fraction;		// 소수점 적용
	}

	// 숫자가 아닌 것이 나왔을 때 처리
	if (*Source != '\0')
	{
		Result = 0;
	}

	return Result * Sign;
}

bool ComparisonOfNumbers(float MyAtoF, const float TestCaseResult2)
{
	float Absolute = MyAtoF - TestCaseResult2;
	float ThreashHold = 0.0001f;
	if (-ThreashHold < Absolute && Absolute < ThreashHold) // 0과 0.1 사이의 양수 이거나 0과 -0.1 사이의 음수 일 때
	{
		return true;
	}
	return false;
	
}


/*
		0 ~ 0.1	
-0.1 ~ 0
       0
-0.5 < Absolute <  0.5
*/
