#pragma once
#include <iostream>
#include <string>

void Day0602();
void Day0602_Class();
void Day0602_virtual();
// 객체 지향
//	- 프로그램 패러다임 중 하나
//  - 객체(Object)를 만들고 객체간에 상호작용 프로그램이 돌아가게 만드는 방식
//	- 4대 특성
//		- 추상화
//			- 불필요한 세부사항을 숨기고 핵심적인 부분만 말하는 것 
//			- 중요한 개념과 기능만을 드러내는 것(상위 개념으로 묶기)
//			- 코드의 복잡성을 낮출 수 있다.
//		- 캡슐화
//			- 접근제한자를 통한 데이터의 접근 제어.
//			- 몰라도 되는 것은 안보이게 하는 것
//			- 데이터를 보호하고 안정성을 높인다. 그리고 결합도도 낮춘다.
//			- 접근 제한자를 이용해 캡슐화를 한다.
//		- 상속
//			- 부모클래스의 데이터와 기능을 물려받는 자식클래스를 만드는 것.
//			- 코드의 재사용성이 높아진다. 계층 구조가 형성된다. (위, 아래가 생긴다)
//		- 다형성
//			- 동일한 인터페이스를 동해 다양한 처리를 하는 것
//			- 가상 함수의 오버리드를 통한 다형성 구현
//

// 클래스
//	- 객체(Object)를 만들기 위한 설계도
//  - 객체가 가지게 될 상태(데이터,변수)와 동작(기능, 함수)을 하나로 묶어놓은 것
//		- 그 자체로 특정한 어떤 것을 표현할 수 있어야한다.
//	- 구성요소
//		- 생성자
//			- 구조체와 같이 객체를 생성했을 때 자동 호출되는 함수 같은 것
//			- 예) 클래스이름()
//		- 소멸자
//			- 구조체나 클래스의 객체가 해제될 때(delete가 되거나 지역변수일 때 함수 종료되는 시점) 자동으로 호출되는 함수 같은 것
//			- 목적
//				- 객체가 사용하던 자원을 깨끗하게 정리하는 역할
//				- 주로 객체가 동적할당 한 메모리를 해제하는데 사용 
//				- 그 외 기타 자원들(파일, 네트워크 연결 닫기)도 이곳에서 정리.
//			- 예) ~클래스이름()
//		- 멤버 변수 
//			- 객체의 상태나 데이터를 저장하는 변수
//			- 속성, 필드라고도 함
//		- 멤버 함수
//			- 객체가 할 수 있는 동작이나 기능을 정의한 함수
//			- 메서드(Method)라고도 함 
//		- 객체,인스턴스(Instance)
//			- 큭정 클래스를 이용해 실제 메모리에 할당된 실체
//

// 접근 제한자(Access Modifier)
//	- 특정 객체의 내부를 누구까지 볼 수 있을 것인가를 설정
//	- public, protected, private
//		- public	:  public멤버는 모두에게 공개되어 있다.
//		- protected : protected멤버는 상속된 자식(파생) 클래스까지는 볼 수 있다.(나랑 나를 상속받은 자식만 볼 수 있음)
//		- private	: private멤버는 자기 자신만 볼 수 있다.
//		-정리
//			- public	: 모두가 접근 가능
//			- protected : 나랑 내 자식클래스만 접근 가능
//			- private	: 나만 접근가능
//	
//	- **구조체는 따로 설정 안하면 public
//	- **클래스는 따로 설정 안하면 private
//

// 상속 
//	- 부모 클래스의 내용을 몰려받는 행동(자식은 부모 클래스를 확장/파생 시킨다)
//	- 특징
//		- 코드 재사용성 증가
//		- 계층구조로 객체들간의 관게를 명확히 함
//		- 부모 클래스의 포인터나 참조로 자식 클래스를 다룰 수 있다.
//

// 가상함수
//	- virtual 키워드 사용
//	- 함수를 선언할 떄 가상함수로 만들 멤버 함수 앞에서 붙인다.
//	- 가상함수가 있는 클래스를 상속받은 자식클래스는 해당 함수를 overide(덮어쓰기) 할 수 있다. 
//	- *부모 클래스에게 상속을 받았는데 소멸자를 만들었다면 부모 클래스와 자식클래스 모두 '무조건' virtual을 붙여야 한다.* 
//	- 언리얼은 다중상속을 막아놓음
//

class Animal
{
	// 멤버 변수	
protected:
	const int MaxEnergy = 100;
	const int MoveEnergyCost = 5; // 동물이 이동시 소비하는 에너지
	const int EatEnergyCost = 10; // 동물이 먹으면 회복하는 에너지 

protected:
	std::string Name = "동물";	// 동물의 이름
	int Age = 0;				// 동물의 나이
	int Energy = MaxEnergy;		// 동물의 에너지

	
public:
	Animal() = default;
	//{
	//	// 생성자
	//}
	Animal(const std::string& InName)
		:Name(InName)
	{ }

	virtual ~Animal() = default;
	//{
	//	// 소멸자 // 소멸자는 무조건 public이어야만 한다. 근데 잘 안씀
	//}
	
	//멤버 함수
	virtual void Move();	// 움직이기(가상함수)
	virtual void Chrip();	// 소리내기(가상함수)
	void Eat();		// 먹기
	void Sleep();	// 잠자기
	void ViewMyInformation(); // 내 정보 보이기

public:
	// getter/setter --> *다른 클래스에 내부 데이터를 넘겨야 할 때* / 캡슐화에 도움이 된다. / 코드의 의도를 쉽게 알게함
	//int GetAge() const; // getter의 기본형, 여기서 const는 함수 내에서 다른 멤버 변수를 수정하지 않겠다라는 의미
	inline int GetAge() const { return Age; } // 보통은 inline으로 이렇게 씀 , Getter와 setter는 프로그래머의 이도에 따라 사용처를 한정 할 수 있어 좋다.
	inline void SetAge(int InAge) { Age = InAge; }
};

// 간단 실습
// - 동물 클래스 만들어보기
//		- 움직이면 에너지를 소비한다.
//		- 소리를 지를 수 있다. 
//		- 먹을 수 있다.(먹으면 에너지가 증가한다)
//		- 잠을 잘 수 있다.(잠을 자면 나이가 증가하고 에너지가 완벽 회복)
//		- 자신의 정보를 출력할 수 있다.

// 독수리
class Eagle : public Animal
{
public:
	Eagle()
		:Animal(), aAA(8)
	{
		aAA = 8;
	}
	Eagle(const std::string& InName)
		:Animal(InName)
	{ }

	virtual ~Eagle() = default;

	void Fly();
	virtual void Chrip() override; // 가상함수 덮어 쓰기
private:
	const int FlyEnergeCost = 10;
	int aAA = 9;
};

// 늑대
class Wolf : public Animal
{
public:
	Wolf()
		:Animal()
	{ }
	Wolf(const std::string& InName)
		:Animal(InName)
	{ }

	virtual ~Wolf() = default;

	void Move() override;
	void Howling();
};

// 하울링 인터페이스(0605 수업참조)
class IHowling
{
public:
	virtual void Howling() = 0;
	virtual ~IHowling() = default;
};

// 말
class Horse : public Animal
{
public:
	Horse()
	{ }
	Horse(const std::string& InName)
		:Animal(InName)
	{ }

	virtual ~Horse() = default;

	void Run();
	void Chrip() override; // 가상 함수 덮어쓰기
private:
	const int RunEnergeCost = 10;
};

// 악어
class Crocodile : public Animal
{
public:
	Crocodile()
	{ }
	Crocodile(const std::string& InName)
		:Animal(InName)
	{ }

	virtual ~Crocodile() = default;

	void Move() override;
	void Diving();
};

class IDiving
{
public:
	virtual void Diving() = 0;
	virtual ~IDiving() = default;
};

// 카멜레온
class Chameleon : public Animal
{
public:
	Chameleon()
	{ }
	Chameleon(const std::string& InName)
		:Animal(InName)
	{ }

	void Camouflage();
};

// 간단 실습
// Move함수를 가상함수로 만들어 처리하기

