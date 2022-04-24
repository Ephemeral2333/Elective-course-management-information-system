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

	stu_head = stuInfile();             //stu_head指向学生链表头
	stu_tail = endsLocate(stu_head);   //stu_tail指向学生链表尾
	cour_head = courInfile();           //cour_head指向课程链表头
	cour_tail = endcLocate(cour_head); //cour_tail指向课程链表尾
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
	printf("\n\n\t\t****************欢迎使用河南工业大学选课系统*******************\n\n\n");
	printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t┃        [1].学生登录               ┃\n");
	printf("\t\t\t┃        [2].管理员登录             ┃\n");
	printf("\t\t\t┃        [3].显示帮助               ┃\n");
	printf("\t\t\t┃        [4].访问网页版教务系统     ┃\n");
	printf("\t\t\t┃        [0].退出                   ┃\n");
	printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n\n\n\t\t\t请输入您的选择：");
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
		printf("程序已退出！\n");
		exit(0);
	}
	else
	{
		printf("输入有误！\n");
	}
}
