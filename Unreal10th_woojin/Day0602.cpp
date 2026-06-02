#include "Day0602.h"

void Animal::Move()		// Animal 클래스의 멤버 함수인 Move
{
	// 움직이기
	printf("\n이동합니다.\n");
	printf("에너지가 %d만큼 감소합니다.\n", MoveEnergyCost);
	Energy -= MoveEnergyCost;
}

void Animal::Chrip()	
{
	// 소리지르기
	printf("\n으르렁하고 소리를 냅니다.\n");
}

void Animal::Eat()		
{
	// 먹기
	printf("\n먹습니다.\n");
	printf("에너지를 %d만큼 회복합니다.\n",EatEnergyCost);
	Energy += EatEnergyCost;
}

void Animal::Sleep()	
{
	//자기
	printf("쿨쿨 잡니다.\n에너지가 완전히 회복됩니다.\n나이가 한살 증가합니다.\n");
	Age += 1;
	Energy = MaxEnergy;
}

void Animal::ViewMyInformation()
{
	printf("\n-----------------------------------------------------\n");
	printf("이름 : %s\n", Name.c_str());
	printf("나이 : %d살\n", Age);
	printf("현재 에너지 : %d\n", Energy);
	printf("-----------------------------------------------------\n");
}

void Day0602()
{
	//Day0602_Class();
	Day0602_virtual();
}

void Day0602_Class()
{
	Animal* MyAnimal = new Animal();
	MyAnimal->ViewMyInformation();
	MyAnimal->Move();
	MyAnimal->Chrip();
	MyAnimal->ViewMyInformation();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->Move();
	MyAnimal->ViewMyInformation();
	MyAnimal->Eat();
	MyAnimal->ViewMyInformation();
	delete MyAnimal;
	MyAnimal = nullptr;

	Eagle* MyEagle = new Eagle("독수리");
	MyEagle->ViewMyInformation();
	MyEagle->Fly();
	MyEagle->ViewMyInformation();

	Animal* pEagle = MyEagle;	// Animal이 Eagle의 부모이기 때문에 저장 가능하다.
	// pEagle는 Animal*이기 때문에 Eagle만의 멤버에 접근은 안된다.(하려면 캐스팅해야 한다.)
	// (Eagle*)pEagle;		// C 스타일의 캐스팅. 위험한 방식
	// int* a;
	// Eagle* Test = (Eagle*)a; // 문법적으로 가능
	// dynamic_cast C++ 스타일의 캐스팅. 안전하지만 느리다.

	delete MyEagle;
	MyEagle = nullptr;

	//pEagle->ViewMyInformation(); // pEagle는 댕글링 포인터다.(이미 유효하지 않은 주소)

	// 간단 실습
	// Animal의 자식 클래스 5개 이상 만들기 .
	// 각 자식 클래스는 자신만의 기능이 있어야 한다.

	Wolf* MyWolf = new Wolf("늑대");
	MyWolf->ViewMyInformation();
	MyWolf->Howling();

	delete MyWolf;
	MyWolf = nullptr;

	Horse* MyHorse = new Horse("말");
	MyHorse->ViewMyInformation();
	MyHorse->Run();
	MyHorse->ViewMyInformation();

	delete MyHorse;
	MyHorse = nullptr;

	Crocodile* MyCorocodile = new Crocodile("악어");
	MyCorocodile->ViewMyInformation();
	MyCorocodile->Diving();

	delete MyCorocodile;
	MyCorocodile = nullptr;

	Chameleon* MyChameleon = new Chameleon("카멜레온");
	MyChameleon->ViewMyInformation();
	MyChameleon->Camouflage();

	delete MyChameleon;
	MyChameleon = nullptr;
}

void Day0602_virtual()
{
	Animal* Zoo[3] = { nullptr, };
	Zoo[0] = new Eagle("독수리");
	Zoo[1] = new Wolf("늑대");
	Zoo[2] = new Horse("말");

	for (Animal* anim : Zoo)
	{
		anim->ViewMyInformation();
		anim->Chrip();
	}

	for (int i = 0; i < 3; i++)
	{
		delete Zoo[i];		// 소멸자가 있다면 Animal의 소멸자가 
		Zoo[i] = nullptr;
	}
}

void Eagle::Fly()
{
	printf("\n하늘을 납니다.\n에너지가 %d만큼 감소합니다.\n", FlyEnergeCost);
	Energy -= FlyEnergeCost;
}

void Wolf::Move()
{
	printf("\n늑대가 재빠르게 이동합니다.\n");
}

void Wolf::Howling()
{
	printf("\n하울링합니다.....\n");
}

void Horse::Run()
{
	printf("\n달립니다.....\n에너지가 %d만큼 감소합니다.\n", RunEnergeCost);
	Energy -= RunEnergeCost;
}

void Crocodile::Move()
{
	printf("\n악어가 재빠르게 이동합니다.\n");
}

void Crocodile::Diving()
{
	printf("\n잠수합니다.....\n");
}

void Chameleon::Camouflage()
{
	printf("\n위장합니다.....\n");
}

void Eagle::Chrip()
{
	printf("\n끼룩.....\n");
}

void Horse::Chrip()
{
	printf("\n히히힝.....\n");
}