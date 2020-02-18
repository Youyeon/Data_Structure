/* 실습 2-1. 계승값(Factorial) 구하기
문제 정의: 음이 아닌 정수값 n에 대해, 계승값 n!을 구하는 재귀 프로그램을 작성하여 다양한 n 값(n=10, 20, 30 등)에 대해 테스트하여 그 결과값과 실행 시간을 nsec 또는 msec 단위로 출력해 본다. 
입력: 음이 아닌 정수값 n
*/
#include <stdio.h>
#include <time.h>
long long fact(int);

int main(void) {
    clock_t begin,end;
    int n;
    long long res;
    scanf("%d",&n);
    begin=clock();
    res=fact(n);
    end=clock();
    printf("n = %d\n",n);
    printf("The factorial of %d = %lld\n",n,res);
    printf("The execution time = %.2lf msec", (double)(end-begin));
}

long long fact(int n) {
    if (n==0)
        return 1;
    else
        return n*fact(n-1);   
}