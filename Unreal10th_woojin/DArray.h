#pragma once
class DArray
{
	//std::vector 비슷하게 만들기
	//	- 인티저 저장
	//	- Reserve(Capacity 설정), PushBack(뒤에 추가하기), PopBack(뒤에 제거하기), Print(내용 출력하기)
	//	- Reallocation(PushBack으로 Capacity가 넘칠 때 처리하는 함수)
public:
	int& operator[](size_t Index)
	{
		return Data[Index];
	}


private:
	int* Data;
};

