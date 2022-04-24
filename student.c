#include<stdio.h>
#include<string.h> 
#include"Declare.h" 
#include<stdlib.h> 
#include<malloc.h> 
#include<ctype.h>
#include<conio.h>

extern student* stu_head;
extern course* cour_head;
extern course* cour_tail;
extern student* stu_tail;

student* stuLogin(student* head)
{
	student* copy_head = head;
	char input[100];
	printf("\t\t*******请输入学号:");
	scanf("%s", input);
	while (getchar() != '\n');
	student* temp;
	temp = stunumFind(head, input);
	if (temp == NULL)
		return copy_head;
	else if ((temp != NULL) && (temp->next == NULL))
		return NULL;
	else
		return temp->next;
}

void stuMenu()
{
	student* p_stu = stuLogin(stu_head);
	if (p_stu != NULL)
	{
		printf("\t\t*******请输入登陆密码:");
		char mima[10];
		GetPasswd(mima, 6, 9);
		//while (getchar() != '\n');
		if (strcmp(p_stu->password, mima) == 0)
		{
			printf("\n\n\t\t-----------------------------------登陆成功!	\n\n");
			system("pause");
			system("cls");
			printf("\n\n\t\t-----------------------------%s 欢迎进入选课系统!	\n\n", p_stu->name);
			printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~学生菜单~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printf("\n\t\t---[1]:打印课程信息");
			printf("\n\t\t---[2]:查找课程信息");
			printf("\n\t\t---[3]:选择新的课程");
			printf("\n\t\t---[4]:删除已选课程");
			printf("\n\t\t---[5]:查看个人信息");
			printf("\n\t\t---[6]:修改登陆密码");
			printf("\n\t\t---[0]:注销");
			printf("\n\n\t\t---请从<0-6>中选择操作类型:");
			int n;
			scanf("%d", &n);
			while (1)
			{
				switch (n)
				{
					case 1: coursPrint(cour_head); break;
					case 2: courFind(cour_head); break;
					case 3: courChoose(cour_head, p_stu); break;
					case 4: delCourse(cour_head, p_stu); break;
					case 5: stuPrint(p_stu); break;
					case 6: stu_keyModify(p_stu); break;
					case 0: break;
					default:
						printf("输入有误!请重新输入:");
				}
				if (n == 0)
					break;
				scanf("%d", &n);
			}
		}
		else
			printf("\t\t#####密码错误，请重新登陆!#######\n");

	}
	else
		printf("\t\t#####该学号不存在，请重新登陆!######\n");
	p_stu = NULL;
}

void stumenu()
{
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~学生菜单~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t---[1]:打印课程信息");
	printf("\n\t\t---[2]:查找课程信息");
	printf("\n\t\t---[3]:选择新的课程");
	printf("\n\t\t---[4]:删除已选课程");
	printf("\n\t\t---[5]:查看个人信息");
	printf("\n\t\t---[6]:修改登陆密码");
	printf("\n\t\t---[0]:注销");
	printf("\n\n\t\t---请从<0-6>中选择操作类型:");
}

void showNature(course* head)
{
	course* p;
	char ad[MAXN];
	while (1)
	{
		int flag = 0, sum = 0;
		p = head;
		printf("\t\t请输入要查找课程的性质，取消查找请输入0000:");
		scanf("%s", ad);
		while (getchar() != '\n');
		if (strcmp(ad, "0000") == 0)
			break;
		while (p != NULL)
		{
			if (strcmp(ad, p->nature) == 0)
			{
				courPrint(p);
				flag = 1;
				sum++;
			}
			p = p->next;
		}
		if (flag == 0)
			printf("\n\t\t没有该课程！####");
	}
	return;
}

void showTerm(course* head)
{
	course* p;
	char ad[MAXN];
	while (1)
	{
		int flag = 0, sum = 0;
		p = head;
		printf("\t\t请输入要查找课程的开课学期,取消查找请输入0000:");
		scanf("%s", ad);
		while (getchar() != '\n');
		if (strcmp(ad, "0000") == 0)
			break;
		while (p != NULL)
		{
			if (strcmp(ad, p->term) == 0)
			{
				courPrint(p);
				flag = 1;
				sum++;

			}
			p = p->next;
		}
		if (flag == 0)
			printf("\n\t\t#####没有该课程!#####");
	}
	return;
}

void courChoose(course* head, student* stu)
{
	if (stu->score_sel < stu->score_all)
		printf("\n\t\t你的总学分少于%.1lf,赶快去选课吧！\n", stu->score_all);
	while (1)
	{
		printf("\n\t\t请输入课程的编号或名称进行选课，取消选课请输入0000:");
		char input[50];
		scanf("%s", input);
		while (getchar() != '\n');
		if (strcmp(input, "0000") == 0)
		{
			system("cls");
			stumenu();
			break;
		}
		course* find = NULL;
		if ((input[0] >= 48) && (input[0] <= 57))
			find = cournumFind(head, input);
		else
			find = cournameFind(head, input);

		if (find == cour_tail)
		{
			printf("\n\t\t#####该课程不存在!请重新输入#####\n");
			continue;
		}
		else if (find == NULL)
			find = head;
		else
			find = find->next;

		if (find->stu_sum == find->stu_max)
			printf("\n\t\t####该课程人数已满,无法选择!#####\n");
		else
		{
			int judge = 0;
			for (int i = 0; i < stu->course_sum; i++)
			{
				if (strcmp(stu->course[i], find->num) == 0)
				{
					judge = 1;
					break;
				}
			}
			if (judge == 1)
			{
				printf("\n\t\t####该课程已经选择过了!####\n");
				continue;
			}
			else
			{
				stu->course_sum++;
				strcpy(stu->course[stu->course_sum - 1], find->num);
				stu->score_sel += find->score;

				find->stu_sum++;
				strcpy(find->stu[find->stu_sum - 1], stu->num);
				printf("\n\t\t该课程选择成功!\n");
			}
		}
		courOutfile(cour_head);
		stuOutfile(stu_head);
	}
}

void numFind(course* head)
{
	char buf[MAXN];
	course* result;
	while (1)
	{
		printf("\t\t请输入要查找课程的编号,取消查找请输入0000:");
		scanf("%s", buf);
		while (getchar() != '\n');
		if (strcmp(buf, "0000") == 0)
		{
			break;
		}
		result = cournumFind(head, buf);
		if (result != cour_tail)
		{
			if (result == NULL)
				result = head;
			else
				result = result->next;
			courPrint(result);
		}
		else
			printf("\t\t#####没有该课程！#####\n");
	}
}

void nameFind(course* head)
{
	char buf[MAXN];
	course* result;
	while (1)
	{
		printf("\t\t请输入要查找课程的名称,取消查找请输入0000:");
		scanf("%s", buf);
		while (getchar() != '\n');
		if (strcmp(buf, "0000") == 0)
			break;
		result = cournameFind(head, buf);
		if (result != cour_tail)
		{
			if (result == NULL)
				result = head;
			else
				result = result->next;
			courPrint(result);
		}
		else
			printf("\t\t#####无所查找的课程!#####\n");
	}
}

void delCourse(course* head, student* stu)
{
	while (1)
	{
		printf("\n\t\t请输入需要删除课程的编号,返回上级菜单请输入0000:");
		char input[50];
		scanf("%s", input);
		while (getchar() != '\n');
		if (strcmp(input, "0000") == 0)
		{
			break;
		}
		int i = 0, result = -1;

		/*删除该学生记录中选课的信息*/
		for (; i < stu->course_sum; i++)
		{
			if (strcmp(input, stu->course[i]) == 0)
			{
				result = i;
				break;
			}
		}

		if (result == -1)
		{
			printf("\n\t\t####你没有选择这门课程！请重新输入!");
			continue;
		}
		strcpy(stu->course[result], stu->course[stu->course_sum - 1]);
		stu->course_sum--;

		course* find = cournumFind(head, input);
		if (find == NULL)
			find = head;
		else
			find = find->next;

		/*删除该课程记录中学生的信息*/
		i = 0, result = 0;
		for (; i < find->stu_sum; i++)
		{
			if (strcmp(input, find->stu[i]) == 0)
			{
				result = i;
				break;
			}
		}
		strcpy(find->stu[result], find->stu[find->stu_sum - 1]);
		find->stu_sum--;
		printf("\n\t\t课程删除成功!\n");
	}
	stuOutfile(stu_head);
	courOutfile(cour_head);
}

void stu_keyModify(student* stu)
{
	printf("\t\t******请输入原密码(8位):");
	char input[20];
	scanf("%s", input);
	while (getchar() != '\n');

	char keyOld[10];
	strcpy(keyOld, stu->password);
	if (!strcmp(keyOld, input))//修改
	{
		char new1[100];
		char new2[100];
		while (1)
		{
			printf("\t\t*******请输入新密码（8位）:");
			scanf("%s", new1);
			while (getchar() != '\n');
			printf("\t\t******请再次确认新密码（8位）:");
			scanf("%s", new2);
			while (getchar() != '\n');
			if (!strcmp(new1, new2))
			{
				strcpy(stu->password, new1);
				stuOutfile(stu_head);
				printf("\n\t\t	密码修改成功!\n");
				system("pause");
				system("cls");
				stumenu();
				break;
			}
			else
				printf("\t\t####前后密码不一致，请重新输入！####\n");
		}
	}
	else
		printf("\t\t####原密码输入错误，请重新选择操作类型####\n");
}

