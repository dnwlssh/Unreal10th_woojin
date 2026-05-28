#pragma once

void Day0528();
void Day0528_String();
void Day0528_FileIO();
void Day0528_Structure();
void FindCharacter(const std::string& Str, const char Target);

void Test(int i = 0);

struct Enemy	// 적은
{
	std::string Name;	// 이름을 가지고
	float Health;		// 체력을 가지고
	float AttackPower;	// 공격력을 가지고
	int Reward;			// 보상을 가진다.
};

struct EnemyOrc
{
	std::string Name = "Orc";	// 멤버 직접 초기화
	float Health = 150.0f;		
	float AttackPower = 10.0f;	
	int Reward = 50;	

	//EnemyOrc()	//생성자(기본 / 생성자가 하나도없으면 CPP가 컴파일 할 때 자동으로 만들어줌)
	//{

	//}
	EnemyOrc() = default; // 기본 생성자를 사용한다는 의미
	//EnemyOrc(EnemyOrc& Other)
	//{
	//	Name = Other.Name;
	//	Health = Other.Health;
	//	AttackPower = Other.AttackPower;
	//	Reward = Other.Reward;
	//}
	EnemyOrc(float Modifier = 1.0f)
	{
		// 체력은 모디파이어의 10배
		Health *= (Modifier * 10.0f);
		// 공격력은 모디파이어의 5배
		AttackPower *= (Modifier * 5.0f);
		// 리워드는 모디파이어의 3배
		Reward *= (Modifier * 3.0f);
	}

	EnemyOrc(std::string DefaultName)
	{
		Name = DefaultName; // 4. 생성자 내부 대입
	}
	EnemyOrc(std::string _Name, float _Health, float _AttckPower , int _Reward)
		: Name(_Name), Health(_Health), AttackPower(_AttckPower), Reward(_Reward)		//생성자 초기화 리스트
	{
	}
};

void TestStruct(Enemy Target);

void PrintEnemyData(Enemy& Target);	// 참조에 의한 호출(Call by reference)
void PrintEnemyData(Enemy* Target);	// 주소에 의한 호출(Call by Address)
void PrintEnemyData(EnemyOrc* Target);

void PrintEnemyData(EnemyOrc* Target);

