/* 실습 3. 다항식 덧셈과 다항식 값 구하기
문제 정의: 주어지는 두 개의 다항식 p(x)와 q(x)에 대해서 p(x)와 q(x)를 더한 다항식 r(x)를 구하고, 주어지는 x값에 대해 r(x)의 값을 구하는 프로그램을 작성한다. 다양한 p(x), q(x) 및 x값에 대해 테스트하여 그 결과가 맞는지 출력해 본다.
입력 첫줄: p(x)의 차수
입력 둘째줄: p(x)의 계수들
입력 셋째줄: q(x)의 차수
입력 넷째줄: q(x)의 계수들
입력 다섯째줄: x값
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DEGREE 20
typedef struct{
    int degree;
    int coef[MAX_DEGREE];
} polynomial;

polynomial poly_add(polynomial, polynomial);
int cal (polynomial, int);

int main(void) {
    int x;
    FILE* fp = fopen("poly1.txt","r");
    if (fp==NULL) {
        printf("File Not Found");
        exit(1);
    }
    polynomial p,q,r;
    fscanf(fp,"%d",&(p.degree));
    for (int i=0;i<p.degree;i++)
        fscanf(fp,"%d",&p.coef[i]);
    fscanf(fp,"%d",&(q.degree));
    for (int i=0;i<q.degree;i++)
        fscanf(fp,"%d",&q.coef[i]);;
    r = poly_add(p,q);
    fscanf(fp,"%d",&x);
    printf("p(x) = "); //p(x)
    for (int i = 0; i <= p.degree; i++) {
		printf("%dx^%d", p.coef[i], i);
		if (i != p.degree)
			printf(" + ");
	}
    printf("\nq(x) = "); //q(x)
	for (int i = 0; i <= q.degree; i++) {
		printf("%dx^%d", q.coef[i], i);
		if (i != q.degree)
			printf(" + ");
	}
	printf("\n\nr(x) = "); //r(x)
	for (int i = 0; i <= r.degree; i++) {
		printf("%dx^%d", r.coef[i], i);
		if (i != r.degree)
			printf(" + ");
    }
    int res = cal(r,x);
    printf("\nr(%d) = %d",x,res);
}

polynomial poly_add(polynomial p, polynomial q) {
    polynomial r;
    if (p.degree>q.degree) {
        int i;
        for (i=0;i<q.degree;i++) 
            r.coef[i]=p.coef[i]+q.coef[i];
        while(i<p.degree)
            r.coef[i]=p.coef[i];
    }
    else {
        int i;
        for (i=0;i<p.degree;i++) 
            r.coef[i]=p.coef[i]+q.coef[i];
        while(i<q.degree)
            r.coef[i]=q.coef[i];
    }
    return r;
}

int cal (polynomial r, int x) {
    int res=0;
    for (int i=0;i<r.degree;i++)
        res+=r.coef[i]*pow(x,i);
    return res;
}