#include "LinkedList.h"
#include <stdio.h>
#include "Weekend_Practice0605_BattleShip_Solution.h"

LinkedList::~LinkedList()
{
	// 동적 할당이 된 노드를 모두 제거한다.
	Clear();
}

void LinkedList::Add(int InData)                                                                                                                                                         
{
	// InData가 들어간 노드를 만든다.
	// 맨 마지막으로 이동해서 맨 마지막 노드의 Next를 새 노드로 지정한다. 
	// 헤드가 없는 경우, Tail과 Size에 대한 처리 필요

	// 1. InData를 가진 새 노드를 힙 메모리에 동적 할당
	ListNode* Node = new ListNode(InData);

	// 2. 리스트가 완전히 비어있는 경우 (Head가 nullptr인 경우)
	if (Head == nullptr)
	{
		Head = Node; // 새 노드가 첫 번째 노드가 됨
		Tail = Node; // 새 노드가 동시에 마지막 노드가 됨
	}
	// 3. 리스트에 이미 노드가 존재하는 경우
	else
	{
		Tail->Next = Node; // 기존 마지막 노드의 Next가 새 노드를 가리키도록 연결
		Tail = Node;       // 이제 새 노드가 가장 마지막이 되었으므로 Tail을 새 노드로 갱신
	}

	// 4. 전체 노드 개수(Size) 1 증가
	Size++;

	delete Node;
	Node = nullptr;
}
void LinkedList::InsertAt(int InData, int InPosition)
{
	// InData가 들어간 노드를 만든다.
	// 포지션까지 Head에서 시작해서 Next를 계속 타고 이동한다.
	// 포지션 위치에 있는 노드의 앞 노드의 Next 주소를 새로 만든 노드로 설정
	// 포지션 위치에 있는 노드의 Next 주소에 새로 만든 노드의 주소를 저장
	
	// InPositiondl이 Size보다 크거나 같을 때. InPosition이 0 일 때

	if (InPosition > Size)
	{
		InPosition = Size;
	}
	if (InPosition = Size)
	{
		Add(InData);	// 어차피 마지막에 추가할거면 Tail을 활용하는게 빠르다.
		return;
	}
	ListNode* Node = new ListNode(InData);
	if (InPosition == 0)
	{
		Node->Next = Head;
		Head = Node;
	}
	else
	{
		ListNode* PreNode = Head;
		ListNode* Current = Head;
		for (int i = 0; i < InPosition; i++)
		{
			PreNode = Current;
			Current = Current->Next;
		}
		PreNode->Next = PreNode;	// 포지션 위치에 있는 노드의 앞 노드의 Next 주소를 새로 만든 노드로 설정
		Current->Next = Current;	// 새 노드의 다음 주소를 포지션 위치에 있는 노드의 주소로 설정
	}
	Size++;

	delete Node;
	Node = nullptr;
}

void LinkedList::Remove(int InData)
{
	// 맨 앞과 뒤 일때 처리, 없는 경우에 대한 처리
	if (Head == nullptr)
	{
		return;
	}
	// InData를 가진 노드가 있는지 Head부터 찾는다.
	ListNode* NodeToDelete = nullptr;
	ListNode* PreNode = nullptr;

	if (Head->Data == InData)
	{
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head == nullptr)
		{
			Tail = nullptr;
		}
		else
		{
			PreNode = Head;
			while (PreNode->Next != nullptr && PreNode->Next->Data != InData)
			{
				// 찾는 데이터를 가진 노드의 앞노드 찾기
				PreNode = PreNode->Next;
			}

			if (PreNode->Next != nullptr)
			{
				// 찾은 노드의 앞에 있는 노드의 Next를 찾은 노드의 Next의 저장된 주소로 변경한다.
				NodeToDelete = PreNode->Next;
				PreNode->Next = NodeToDelete->Next;
				if (NodeToDelete == Tail)
				{
					Tail == PreNode;
				}
			}
		}
	}

	if (NodeToDelete != nullptr)
	{
		// 찾은 노드를 delete
		delete NodeToDelete;
		NodeToDelete = nullptr;
		Size--;
	}
	else
	{
		printf("오류 : %d 값을 가진 노드가 없습니다.\n", InData);
	}
	
}

void LinkedList::RemoveAt(int InPosition)
{
	if (InPosition >= Size)
	{
		printf("오류\n");
		return;
	}
	ListNode* NodeToDelete = nullptr;
	if (InPosition == 0)
	{
		// 특수처리
		NodeToDelete = Head;
		Head = Head->Next;
		if (Head == nullptr)
		{
			Tail = nullptr;
		}
	}
	else
	{
		// 위치 찾기 
		// 찾은 노드 앞 노드의 Next를 찾은 노드의 Next로 변경
		// 찾은 노드 변경	
		ListNode* PreNode = Head;
		int TargetIndex = InPosition - 1;	// 지울 노드의 앞쪽노드(PreNode)까지 가기 위해서
		for (int i = 0; i < TargetIndex; i++)
		{
			PreNode = PreNode->Next;
		}
		NodeToDelete = PreNode->Next;
		PreNode->Next = NodeToDelete->Next;
		if (NodeToDelete == Tail)
		{
			PreNode->Next = nullptr;
			Tail = PreNode;
		}
	}
	delete NodeToDelete;
	NodeToDelete = nullptr;
	Size--;
}
ListNode* LinkedList::Search(int InData) const
{
	// InData와 같은 값을 가지는 노드 찾기
	ListNode* Current = Head;
	while (Current != nullptr)
	{
		if (Current->Data == InData)
		{
			break;
		}
		Current = Current->Next;
	}
	return nullptr;
}





void LinkedList::Clear()
{
	// Head가 빌때 까지
	// 동적 할당이 된 노드를 모두 제거한다.
	while (Head)
	{
		RemoveAt(0);
	}
}



void LinkedList::PrintList() const
{
	// 리스트 Head부터 Tail까지 출력하는 함수
	if (Head == nullptr && Size == 0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}

	printf("리스트(크기:%d) : ", Size);
	ListNode* Current = Head;
	while (Current != nullptr)
	{
		printf("%d -> ", Current->Data);
		Current = Current->Next;
	}
	printf("nullptr\n");
}
