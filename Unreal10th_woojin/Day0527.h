#pragma once

void Day0527();

int MyStrLen(const char* str);

char* MyStrCpy(char* Destination, const char* Source);

char* MyStrCat(char* Destination, const char* Source);

int MyStrCmp(const char* Str1, const char* Str2);

int MyAtoI(const char* Source);

float MyAtoF(const char* Source);

/// <summary>
/// 두 실수가 같은지 판별 하는 함수
/// </summary>
/// <param name="MyAtoF">비교할 실수 1</param>
/// <param name="TestCaseResult2">비교할 실수 2</param>/// 
/// <returns> 두 실수가 같은지 여부 (Bool)</returns>
bool ComparisonOfNumbers(float MyAtoF, const float TestCaseResult2);