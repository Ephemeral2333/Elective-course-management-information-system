#include"Declare.h"
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

student* stu_head;
course* cour_head;
course* cour_tail;
student* stu_tail;

int main()
{

	stu_head = stuInfile();             //stu_headָ��ѧ������ͷ
	stu_tail = endsLocate(stu_head);   //stu_tailָ��ѧ������β
	cour_head = courInfile();           //cour_headָ��γ�����ͷ
	cour_tail = endcLocate(cour_head); //cour_tailָ��γ�����β
	/*
	{
		FILE* fp = fopen("manager.txt", "w+");
		for (int i = 0; i < 10; i++)
		{
			fputc('0', fp);
		}
		fclose(fp);
	}
	*/
	stuInfile();
	courInfile();
	printf("\n\n\t\t****************��ӭʹ�ú��Ϲ�ҵ��ѧѡ��ϵͳ*******************\n\n\n");
	printf("\t\t\t��������������������������������������������������������������������������\n");
	printf("\t\t\t��        [1].ѧ����¼               ��\n");
	printf("\t\t\t��        [2].����Ա��¼             ��\n");
	printf("\t\t\t��        [3].��ʾ����               ��\n");
	printf("\t\t\t��        [4].������ҳ�����ϵͳ     ��\n");
	printf("\t\t\t��        [0].�˳�                   ��\n");
	printf("\t\t\t��������������������������������������������������������������������������\n");
	printf("\n\n\n\t\t\t����������ѡ��");
	int i;
	scanf("%d", &i);
	if (i == 1)
	{
		stuMenu();
	}
	else if (i == 2)
	{
		manMenu();
	}
	else if (i == 3)
	{
		help();
	}
	else if (i == 4)
	{
		webNet();
	}
	else if (i == 0)
	{
		printf("�������˳���\n");
		exit(0);
	}
	else
	{
		printf("��������\n");
	}
}
