


#include <iostream>
using namespace std;

void TempConversion()
{
    //  온도변환기
    //  - 섭씨 온도를 정수로 입력받아 화씨 온도로 변환하여 출력하는 프로그램
    //  - 공식 : 화씨 = 섭씨 * 9 / 5 +32

    int Cel = 0;
    int Fah = 0;
    printf("섭씨 온도를 입력하세요 : ");
    cin >> Cel;

    Fah = Cel * 9 / 5 + 32;
    printf("화씨 온도 : %d\n", Fah);
}

void TimeCalculator()
{
    //  시간변환기
    //  -초를 입력 받아 시,분,초 출력하기

    int Sec, Min, Hour = 0;
    int InputSec = 0;

    printf("변환하고자 하는 전체 초를 입력하세요 : ");
    cin >> InputSec;

    Hour = InputSec / 3600;
    Min = (InputSec % 3600) / 60;
    Sec = (InputSec % 3600) % 60;

    printf("입력하신 시간은 %d시간 %d분 %d초 입니다.\n", Hour, Min, Sec);
}

void Coin()
{
    int Price;

    printf("금액을 입력하십시오 : ");
    cin >> Price;

    int Coin500, Coin100, Coin50, Coin10;

    Coin500 = Price / 500;  //500원의 개수
    Coin100 = (Price - (Coin500 * 500)) / 100;  //100원의 개수
    Coin50  = (Price - (Coin500 * 500) - (Coin100 * 100)) / 50;  //50원의 개수
    Coin10 = (Price - (Coin500 * 500) - (Coin100 * 100) - (Coin50 * 50)) / 10;  //10원의 개수

    printf("입력한 금액에 필요한 각 동전의 개수\n");
    printf("500원 : %d개 , 100원 : %d개 , 50원 : %d개 , 10원 : %d개 \n", Coin500,Coin100,Coin50,Coin10);

}

void Digits()
{
    int Num;
    int Hun, Dec, One;
    printf("세자리 숫자를 입력하세요 : ");
    cin >> Num; 
    Hun = Num / 100;
    Dec = (Num - (Hun * 100)) / 10;
    One = Num - (Hun * 100) - (Dec * 10);
    printf("입력한 수의 100의 자리 : %d , 10의 자리 : %d , 1의 자리 : %d \n",Hun,Dec,One);
    printf("각 자리 수의 합 : %d\n", Hun + Dec + One);
}

void FileIndex()
{
    int Mega, Killo, Byte;

    printf("파일 크기를 입력하세요.(MB단위) : ");
    cin >> Mega;

    Killo = 1024 * Mega;
    Byte = 1024 * 1024 * Mega;
    
    printf("%d MB = %d KB = %d Byte\n", Mega,Killo,Byte);

}

void WeNeedTiles()
{
    int Length, Width;  //가로, 세로
    int TileSize = 30;
 
    printf("방의 가로 , 세로 길이 입력 : ");
    cin >> Length >> Width;

    //int LengthCount = (Width + (TileSize - 1)) / TileSize;
    //int WidthCount = (Length + (TileSize - 1)) / TileSize;

    int LengthCount = (Length - 1) / 30 + 1;
    int WidthCount = (Width - 1) / 30 + 1;



    printf("필요한 타일의 개수 : %d개\n",LengthCount * WidthCount);
   
}

int main()
{
    //TempConversion();
    //TimeCalculator();
    //Coin();
    //Digits();
    //FileIndex();
    WeNeedTiles();
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
