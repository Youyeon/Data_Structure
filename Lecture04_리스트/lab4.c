/* 실습 4. 단순 연결리스트와 순차 탐색 알고리즘
문제 정의: n 개의 정수 데이터가 임의의 순서로 주어질 때, 이를 1차원 배열에 임시로 저장한 후 단순 연결리스트 뒤쪽에 차례로 삽입한다.
또한, 주어지는 키(key) 값이 있는 노드를 순차 탐색에 의해 찾아 연결리스트에서 제거한 후, 이 리스트를 처음부터 다시 방문하여 각 노드의 데이터를 차례로 출력한다. (키가 없는 경우는 '키가 없음'을 출력함)
입력 첫줄: 데이터의 개수 n
입력 둘째줄: n 개의 정수 데이터값들
입력 나머지줄: 제거될 키값들
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int data;
    struct ListNode* link;
} ListNode;
void create_list(ListNode**, int*, int);
void append_node(ListNode**, ListNode*); //리스트에 노드 추가
void remove_node(ListNode**, ListNode*); //리스트에 노드 삭제
ListNode* create_node(int); //노드 생성
ListNode* find_node(ListNode**, int); //노드 탐색
ListNode* previous_node(ListNode**, int); //이전 노드 탐색

int main(void) {
    int n,key;
    scanf("%d", &n);
    int* nums=(int*)malloc(sizeof(int)*n);
    ListNode *head=(ListNode*)malloc(sizeof(ListNode)); //head 노드
	if (head == NULL) {
		printf("메모리 할당 실패");
		exit(0);
	}
    head->data=0;
    head->link=NULL;
    for (int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    create_list(&head, nums,n);
    printf("n = %d\n",n);
    printf("List = ");
    /*데이터 출력*/
	ListNode *p = head;
	p = p->link;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n\n");
	for (int i = 0; i < 3; i++) { //노드 3번 삭제
		scanf("\n%d", &key);
		ListNode* key_node = find_node(&head,key); //data값으로 key를 갖는 노드 탐색
		if (key_node == NULL) { //key가 없는 경우
			printf("Key = %d \"키가 없음\"\n",key);
			printf("List = ");
			/*데이터 출력*/
			p = head;
			p = p->link;
			while (p != NULL) {
				printf("%d ", p->data);
				p = p->link;
			}
			printf("\n\n");
		}
		else {
			remove_node(&head, previous_node(&head,key), key_node); //key 노드 삭제
			printf("Key = %d\n", key);
			printf("List = ");
			/*데이터 출력*/
			p = head;
			p = p->link;
			while (p != NULL) {
				printf("%d ", p->data);
				p = p->link;
			}
			printf("\n\n");
		}
	}
}

void create_list(ListNode** head, int* nums, int n) {
    for (int i = 0; i < n; i++)
		append_node(head, create_node(nums[i])); //리스트에 노드 추가
}

void append_node (ListNode** phead, ListNode* node) {
    ListNode* head = *phead;
    if (head==NULL)
        *phead=node;
    else {
        while(head->link!=NULL)
            head=head->link;
        head->link=node;
    }
}

void remove_node(ListNode** phead, ListNode* node) {
    ListNode* prev = previous_node(phead,node->data);
    if (prev==NULL)
        *phead=(*phead)->link;
    prev->link=node->link;
    free(node);
}

ListNode* create_node(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode==NULL)
        exit(0);
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

ListNode* find_node(ListNode** phead, int key) {
    ListNode* head = *phead;
    while(head->link!=NULL) {
        if (head->data==key)
            return head;
        else
            head=head->link;        
    }
    return NULL;
}

ListNode* previous_node(ListNode** phead, int key) {
    ListNode* head = *phead;
    while(head!=NULL) {
        if (head->link->data=key)
            return head;
        head=head->link;
    }
    return head;
}