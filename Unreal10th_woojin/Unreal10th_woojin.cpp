


#include <iostream>

int main() 
{
    int Number = 10;    //대입 연산자로 Number에 10으로 선언했다.
    printf("Number : %d\n", Number);
    printf("Number : %5d\n", Number);   // %5d : Number를 정수 5자리로 출력
    Number = 20;        //대입 연산자로 Number 값을 20을 넣었다.
    printf("Number : %d\n", Number);
    Number = 5 + 10;    //산술 연산자 + 를 이용해서 5와 10을 더하고 그 결과를 Number에 대입한다.
    printf("Number : %d\n", Number);
    Number = 7 % 3;     //산술 연산자 &를 이용해서 7을 3으로 나눈 나머지를 구하고(1) 그 결과를 Number에 대입한다.
    printf("Number : %d\n", Number);
    
    int Temp1 = 7;

    Number += Temp1;    //Number와 Temp1의 값을 더하고 그 결과를 Number에 덮어쓴다. (Number = 8)
    printf("Number : %d\n", Number);
    Number *= Temp1;    //Number와 Temp1의 값을 곱하고 그 결과를 Number에 덮어쓴다. (Number = 56)
    printf("Number : %d\n", Number);

    Number--;   //(Number = 55)
    Number--;   //(Number = 54)
    Number--;   //(Number = 53)
    printf("Number : %d\n", Number);

    //  간단 실습
    //  - 두 수를 입력받아 스왑하기
    //  - 두 수를 입력받아 합을 출력하기
    //  - 사각형의 가로, 세로를 입력받아 넓이를 출력하기
    //  - 두 수를 입력받아 나머지를 출력하기(% 연산자를 사용한 것과 안한것 모두)

    int Num1 = 0; 
    int Num2 = 0;
    
    //  - 두 수를 입력받아 스왑하기
    printf("첫번째 수를 입력하세요. : ");
    std::cin >> Num1;
    printf("두번째 수를 입력하세요. : ");
    std::cin >> Num2;

    printf("- 두 수를 입력 받아 스왑하기\n");
    int Num3 = 0;
    Num3 = Num1;
    Num1 = Num2;
    Num2 = Num3;
    printf("스왑한 두 값의 결과 Num1 = %d, Num2 = %d\n",Num1 , Num2);

    //  - 두수를 입력받아 합을 출력하기
    printf("첫번째 수를 입력하세요. : ");
    std::cin >> Num1;
    printf("두번째 수를 입력하세요. : ");
    std::cin >> Num2;

    printf("두 수를 입력 받아 합을 출력하기\n");
    printf("입력받은 두 수의 합 %d\n", Num1 + Num2);

    //  -사각형의 가로, 세로를 입력받아 넓이를 출력하기
    printf("사각형의 가로의 길이를 입력하세요. : ");
    std::cin >> Num1;
    printf("사각형의 세로의 길이를 입력하세요. : ");
    std::cin >> Num2;

    printf("사각형의 넓이는 %d 입니다.\n", Num1 * Num2);

    //  - 두 수를 입력받아 나머지를 출력하기(% 연산자를 사용한 것과 안한것 모두)
    printf("첫번째 수를 입력하세요. : ");
    std::cin >> Num1;
    printf("두번째 수를 입력하세요. : ");
    std::cin >> Num2;

    printf("두 수를 입력 받아 나머지를 출력하기\n");
    printf("첫번째 입력한 수를 두번째 입력한 수로 나눈 나머지의 값(%연산자를 사용하여) : %d\n", Num1 % Num2);

    int Remain = 0;
    Remain = Num1 / Num2;
    printf("첫번째 입력한 수를 두번째 입력한 수로 나눈 나머지의 값(%연산자를 사용하지 않고) : %d\n",Num1 - (Num2 * Remain));
}

    // 변수(Variable)
    // - 변하는 숫자
    // - 컴퓨터에 값을 기억시키기 위해 만들고 사용한다.
    // - ex) 데이터타입 변수명; int age;
    // - 메모리의 일정 공간을 확보하고 이름을 붙여 사용하는 것.

    // Int(Integer,정수)
    // - 정수형 타입
    // - 정수는 소수점이 없는 숫자
    // - 일반적으로 32bit이 크기를 가진다.

    // 네이밍 규약
    // - 중요.
    // - 알아보기 쉽고 규칙은 간결해야한다.(길이가 길어지더라도 알아보기 좋은 것이 권장된다.)
    // - 수업중에는 언리얼 코딩 규약을 따를 것(파스칼 케이스 기반 + 약간의 변형)
    // - *문법적 금지 사항*
    //      - 예약어(컴파일러가 미리 사용하려고 잡아놓은 이름)
    //      - 대부분의 특수문자(언더바(_)는 가능. 하지만 되도록이면 지양하자.)
    //      - 띄어쓰기
    // - *비권장*
    //      - 영어가 아닌 문자.
    //      - 알파벳은 같지만, 대소문자가 다른 두 변수

    // 연산자(Operator)
    //  - 산술연산자
    //      +,-,*,/,%
    //      사칙연산 같이 숫자끼리 더하거나 빼거나 하는 것들(%는 나머지 연산 ex) 5%3 --> 2)
    //  - 대입연산자
    //      =
    //      = 오른쪽에 있는 값을, = 왼쪽에 있는 변수에 넣어라
    //      ex) int i = 20; // i라는 변수에 20이라는 값을 넣어라
    //  - 복합 대입 연산자
    //      줄여 쓰기용. 대입연산자와 다른 연산자를 합쳐서 복합적으로 사용하는 연산자.
    //      int a, int b;  
    //      a = a + b;      a += b;     // 둘다 같은 코드
    //  -증감 연산자 
    //      줄여 쓰기용. 정수에 1을 더하거나 뺄 때 사용하는 연산자.
    //      a = a + 1;      a++; 
    //      b = b - 1;      b--; //둘다 같은 코드


    /* 언리얼 코딩 표준 */
    //https://dev.epicgames.com/documentation/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine?lang=ko
