#include "Day0605.h"
#include <stdint.h>
#include <type_traits>

void Day0605::Interface()
{
	IFlyable* List[2];

	// 간단 실습
	// - Day0602에 있는 동물들에게 인터페이스 추가하기
	// - 수영할 수 있다
	// - 날 수 있다
	// - 전투 할 수 있다.


}


void Day0605::EnumClass()
{
	enum Color{ Red,Green,Blue };
	//enum TrafficLight { Red, Yellow, Green };	// 재정의가 되어서 컴파일 에러 
	enum Fruit{ Apple,Orange,Banna };

	Color MyColor = Red;
	Fruit MyFruit = Apple;
	if (MyColor == MyFruit)
	{
		// 색상과 과일이 같다. 논리적으로 말이 안되지만 문법적으로는 가능.
	}


	enum class Color2 {Red,Green,Blue};
	enum class Fruit2 {Apple,Orenge,Banna};

	Color2 MyColor2 = Color2::Red;
	Fruit2 MyFruit2 = Fruit2::Apple;

	//if (MyColor2 == MyFruit2)
	//{
	//		문법적으로 불가능
	//}

	// int로 변경하려면 명시적 캐스팅 필요
	int ColorNumber = static_cast<int>(Color::Green); //(int)(Color2::Green)

	enum class AnimalType : int8_t		// 사이즈를 지정할 수 있다.
	{
		Eagle,
		Tiger,
		Whale
	};

	int Size = sizeof(AnimalType::Eagle);

	using RealType = std::underlying_type_t<AnimalType>; // AnimalType의 실제 타입 받아오기

	int i = 0;

	// 헤더에서 연산자 오버로딩
	Direction Dir = Direction::Up | Direction::Down; // 타입이 Direction이라 연산하고 싶으면 연산자 오버로딩을 해줘야 한다.
}