#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Day0521_Practice_1.h"

void Pratice_1()
{
    int State = None;
    //플레이어의 상태를 대기로 설정
    State = StateAdd(State, Standby);
    ShowMeTheState(State);

    //점프 상태 추가
    State = StateAdd(State, Jump);
    ShowMeTheState(State);

    //공격 상태 추가
    State = StateAdd(State, Attack);
    ShowMeTheState(State);

    //대기 상태 해제
    State = StateSub(State, Standby);
    ShowMeTheState(State);

    //무적 상태 추가
    State = StateAdd(State, Invincable);
    ShowMeTheState(State);

    //무적 상태 토글 (XOR)
    State = StateToggle(State, Invincable);
    ShowMeTheState(State);
}

//플레이어의 상태를 추가하는 함수
int StateAdd(int SetState,int InputState)
{
    SetState |= InputState;
    return SetState;
}

//플레이어의 상태를 해제 하는 함수
int StateSub(int SetState, int InputState)
{
    SetState = SetState & (~InputState);
    return SetState;
}

//플레이어의 상태를 토글 하는 함수
int StateToggle(int SetState, int InputState)
{
    SetState ^= InputState;
    return SetState;
}

//현재 상태를 출력하는 함수
void ShowMeTheState(int SetState)
{
   printf("\n현재 상태\n");
   printf("대기 : [%c], 점프 : [%c], 공격 : [%c], 무적 : [%c]",
       (SetState & Standby) ? 'O' : 'X',
       (SetState & Jump) ? 'O' : 'X',
       (SetState & Attack) ? 'O' : 'X',
       (SetState & Invincable) ? 'O' : 'X');
}
