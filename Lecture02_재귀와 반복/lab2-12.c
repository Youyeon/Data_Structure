// 다른 방식으로의 실행 시간 측정
#include <stdio.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNING
long long facto(long long);

int main(void) {
	int N;
	long long FACTO; //팩토리얼 값
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;
	__int64 elapsed;
	double duringtime;
	QueryPerformanceFrequency(&Frequency); //CPU 주파수에 따른 1초당 진행되는 틱수를 의미함
	scanf("%d", &N);
	QueryPerformanceCounter(&BeginTime); //측정 시작
	FACTO = facto(N);
	QueryPerformanceCounter(&Endtime); //측정 종료
	elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	duringtime = (double)elapsed / (double)Frequency.QuadPart; //시간차를 주파수 값으로 나눔
	printf("n = %d\n", N);
	printf("The factorial of %d = %lld\n", N, FACTO); //팩토리얼 출력
	printf("The execution time = %f msec\n", duringtime*1000); //실행시간 출력
	return 0;
}

long long facto(long long n) {
	if (n == 0)
		return 1; //0일 때 1
	else
		return n*facto(n - 1); //재귀 호출
}