#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int mode();
int integer(int max);
int problem();

int problem() /*������Ŀ*/
{
	int max, n1, n2;
	printf("\n��������ʽ�������:");
	scanf("%d", &max);
	printf("\n������������Ŀ������:");
	scanf("%d", &n2);
	for (int i = 1; i <= n2; i++) /*������Ŀ����*/
	{
		FILE* fp1;
		fp1 = fopen("exercise.txt", "a");
		fprintf(fp1, "��%d��.", i);
		fclose(fp1);
		n1 = rand() % 3; /*�����ȡ��ʽ����*/
		integer(max); /*Ԥ����ʽ��һ����*/
		for (int i = 0; i <= n1; i++)
		{
			mode();
			integer(max); /*������õ�����������������*/
		}
		FILE* fp2;
		fp2 = fopen("exercise.txt", "a");
		fprintf(fp2, "=\n"); /*������ʽ�Ⱥ�*/
		fclose(fp2);
	}
	return 0;
}

int integer(int max) /*�����ȡ��Ȼ��*/
{
	int n3;
	FILE* fp3;
	fp3 = fopen("exercise.txt", "a");
A:n3 = rand() % (max + 1);
	if (n3 == 0) /*����Ϊ0���ü��㣬����ֱ��ȥ��*/
		goto A;
	else
	{
		fprintf(fp3, "%d", n3);
		fclose(fp3);
	}
	return 0;
}

int mode() /*����������������*/
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
	printf("��ȷ������\n1.������Ŀ\n2.������ҵ\n");
	scanf("%d", &n0);
	if (n0 == 1)
		problem();
	else if (n0 == 2)
		printf("�ݲ�֧�ִ˹���");
	else
		printf("��������ȷ����");
	return 0;
}