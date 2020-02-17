/* 실습 1-2. 행렬의 곱
문제 정의: 두 개의 행렬 A (n x m matrix)와 B (m x l matrix)를 곱하여 그 결과 행렬 C (n x l matrix)를 출력하는 함수를 작성하라. n값, m값, l값, 행렬의 원소값들을 변화시켜 가면서 적어도 3번 이상 테스트한다.
입력 첫줄: n값, m값, l값
입력 둘째줄: 행렬 A의 원소값 (행우선)
입력 셋째줄: 행렬 B의 원소값 (행우선)
*/
#include <stdio.h>
void multiple_matrix();

int A[50][50];
int B[50][50];
int C[50][50] = { 0, };
int n,m,l;

int main(void) {
    scanf("%d %d %d",&n,&m,&l);
    for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]); //A원소 입력
    for (int i = 0; i < m; i++)
		for (int j = 0; j < l; j++)
			scanf("%d", &B[i][j]); //B원소 입력
    multiple_matrix();
    printf("\nA = \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d  ", A[i][j]); //A원소 출력
		printf("\n");
	}
	printf("\nB = \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < l; j++)
			printf("%d  ", B[i][j]); //B원소 출력
		printf("\n");
	}
	printf("\nC = \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++)
			printf("%d  ", C[i][j]); //C원소 출력
		printf("\n");
	}
	return 0;
}

void multiple_matrix() {
    for (int i = 0; i < n; i++)
		for (int j=0;j<l;j++)
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];
}