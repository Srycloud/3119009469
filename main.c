#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int mode();
int integer(int max);
int problem();

int problem() /*生成题目*/
{
	int max, n1, n2;
	printf("\n请输入算式最大整数:");
	scanf("%d", &max);
	printf("\n请输入生成题目的数量:");
	scanf("%d", &n2);
	for (int i = 1; i <= n2; i++) /*生成题目数量*/
	{
		FILE* fp1;
		fp1 = fopen("exercise.txt", "a");
		fprintf(fp1, "第%d题.", i);
		fclose(fp1);
		n1 = rand() % 3; /*随机获取算式长度*/
		integer(max); /*预留算式第一个数*/
		for (int i = 0; i <= n1; i++)
		{
			mode();
			integer(max); /*将随机得到的整数和运算符组合*/
		}
		FILE* fp2;
		fp2 = fopen("exercise.txt", "a");
		fprintf(fp2, "=\n"); /*补上算式等号*/
		fclose(fp2);
	}
	return 0;
}

int integer(int max) /*随机获取自然数*/
{
	int n3;
	FILE* fp3;
	fp3 = fopen("exercise.txt", "a");
A:n3 = rand() % (max + 1);
	if (n3 == 0) /*除数为0不好计算，所以直接去掉*/
		goto A;
	else
	{
		fprintf(fp3, "%d", n3);
		fclose(fp3);
	}
	return 0;
}

int mode() /*随机生成四则运算符*/
{
	int n4;
	n4 = rand() % 4;
	if (n4 == 0)
	{
		FILE* fp4;
		fp4 = fopen("exercise.txt", "a");
		fprintf(fp4, "+");
		fclose(fp4);
	}
	else if (n4 == 1)
	{
		FILE* fp5;
		fp5 = fopen("exercise.txt", "a");
		fprintf(fp5, "-");
		fclose(fp5);
	}
	else if (n4 == 2)
	{
		FILE* fp6;
		fp6 = fopen("exercise.txt", "a");
		fprintf(fp6, "*");
		fclose(fp6);
	}
	else if (n4 == 3)
	{

		FILE* fp7;
		fp7 = fopen("exercise.txt", "a");
		fprintf(fp7, "/");
		fclose(fp7);
	}
	return 0;
}

main()
{
	srand(time(NULL));
	FILE* fp0;
	fp0 = fopen("exercise.txt", "w");
	fclose(fp0);
	int n0;
	printf("请确定功能\n1.生成题目\n2.批改作业\n");
	scanf("%d", &n0);
	if (n0 == 1)
		problem();
	else if (n0 == 2)
		printf("暂不支持此功能");
	else
		printf("请输入正确数字");
	return 0;
}