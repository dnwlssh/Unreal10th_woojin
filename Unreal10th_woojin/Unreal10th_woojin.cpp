#include <iostream>

int main()
{
    printf("나이를 입력하세요.\n"); 
    int Age = 0;// 변수 초기화
    printf("당신의 나이 : ");
    std::cin >> Age;
    printf("제 나이는 [%d]살 입니다.", Age);

    printf("안녕하세요 Git Branch 컨플리트 발생을 위한 테스트\n");

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


    /* 언리얼 코딩 표준 */
    //https://dev.epicgames.com/documentation/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine?lang=ko
}