/* 실습 2-2. 피보나치수(Fibonacci number) 구하기
문제 정의: 음이 아닌 정수값 n에 대해, 피보나치 수 Fn을 구하는 재귀 프로그램을 작성하여 다양한 n 값 (n=8, 21, 50 등)에 대해 테스트하여 그 결과값과 실행 시간을 nsec 또는 msec 단위로 출력해 본다.
입력: 음이 아닌 정수값 n
*/
#include <stdio.h>
#include <time.h>
int fibo(int);

int main(void) {
    clock_t begin,end;
    int n,res;
    scanf("%d",&n);
    begin=clock();
    res=fibo(n);
    end=clock();
    printf("n = %d\n",n);
    printf("The %d-th Fibonacci number = %d\n",n,res);
    printf("The execution time = %lf msec",(double)(end-begin));
}

int fibo(int n) {
    if (n==1||n==2)
        return 1;
    else
        return fibo(n-2)+fibo(n-1);
}