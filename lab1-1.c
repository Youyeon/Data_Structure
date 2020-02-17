/* 실습 1-1. 배열에서 최대값/최소값 찾기
문제 정의: 키보드 또는 파일에서 n개의 정수를 1차원 배열로 모두 읽어 들인 후, 최대값과 최소값을 동시에 찾는 함수 findMaxMin()을 작성하고(for 문을 하나만 사용), n값 및 정수 데이터를 변화시켜 가면서 적어도 3번 이상 테스트한다.
입력 첫줄: 데이터의 개수
입력 둘째줄: n개의 정수값(음수 및 0도 포함)
*/
#include <stdio.h>
#include <stdlib.h>
void findMaxMin(int*,int);
int max,min;

int main(void) {
    int n;
    scanf("%d",&n);
    int* nums=(int*)malloc(sizeof(int)*n);
    for (int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    findMaxMin(nums,n);
    printf("n = %d\n",n);
    printf("data = %d",nums[0]);
    for (int i=1;i<n;i++)
        printf(", %d", nums[i]);
    printf("\n\nMaximum = %d\nMinimun = %d",max,min);
}

void findMaxMin(int* nums,int n) {
    max=nums[0];
    min=nums[0]; //초기화
    for (int i=1;i<n;i++) {
        max=max>nums[i]?max:nums[i];
        min=min<nums[i]?min:nums[i];
    }
}