#include<stdio.h>
#include<string.h>
#include"Declare.h"
#include<stdlib.h>
#include<malloc.h>
#include<ctype.h>
#include<Windows.h>

extern student* stu_head;
extern course* cour_head;
extern course* cour_tail;
extern student* stu_tail;

student* stuInfile()      //学生文件内容生成链表
{
	int count = 0;
	FILE* fp;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("\t\tcannot open the file:student.txt\n");
		exit(0);
	}
	student* temp = (student*)malloc(sizeof(student));
	while (!feof(fp))
	{
		if (fread(temp, sizeof(student), 1, fp))
			count++;
	}
	free(temp);
	temp = NULL;

	if (count == 0)
		return NULL;
	else
	{
		rewind(fp);                   //将文件内部的指针重新指向一个流的开头
		student* p_head = NULL;
		p_head = (student*)malloc(sizeof(student));
		fread(p_head, sizeof(student), 1, fp);
		p_head->next = NULL;

		count--;
		student* p_new = p_head;
		student* p_end = p_head;
		int i;
		for (i = 0; i < count; i++)
		{
			p_new = (student*)malloc(sizeof(student));
			fread(p_new, sizeof(student), 1, fp);
			p_new->next = NULL;
			p_end->next = p_new;
			p_end = p_new;
		}
		fclose(fp);
		return p_head;
	}
}

void stuOutfile(student* p_head)
{
	FILE* fp;
	if ((fp = fopen("student.txt", "w")) == NULL)
	{
		printf("\t***没有找到student.txt，请检查文件是否完整!\n\n");
		exit(0);
	}
	while (p_head != NULL)
	{
		fwrite(p_head, sizeof(student), 1, fp);
		p_head = p_head->next;
	}
	fclose(fp);
}

course* courInfile()
{
	int count = 0;
	FILE* fp;
	if ((fp = fopen("course.txt", "r")) == NULL)
	{
		printf("\t\tcannot open the file:course.txt\n");
		exit(0);
	}
	course* temp = (course*)malloc(sizeof(course));
	while (!feof(fp))
	{
		if (fread(temp, sizeof(course), 1, fp))
			count++;
	}
	free(temp);
	temp = NULL;
	if (count == 0)
		return NULL;
	else
	{
		rewind(fp);
		course* p_head = NULL;
		p_head = (course*)malloc(sizeof(course));
		fread(p_head, sizeof(course), 1, fp);
		p_head->next = NULL;
		count--;
		course* p_new = p_head;
		course* p_end = p_head;
		int i;
		for (i = 0; i < count; i++)
		{
			p_new = (course*)malloc(sizeof(course));
			fread(p_new, sizeof(course), 1, fp);
			p_new->next = NULL;
			p_end->next = p_new;
			p_end = p_new;
		}
		fclose(fp);
		return p_head;
	}
}

void courOutfile(course* p_head)
{
	FILE* fp;
	if ((fp = fopen("course.txt", "w")) == NULL)
	{
		printf("\t***没有找到course.txt，请检查文件是否完整!\n\n");
		exit(0);
	}
	while (p_head != NULL)
	{
		fwrite(p_head, sizeof(course), 1, fp);
		p_head = p_head->next;
	}
	fclose(fp);
}

student* endsLocate(student* head)
{
	student* end = head;
	while (head != NULL)
	{
		end = head;
		head = head->next;
	}
	return end;
}

course* endcLocate(course* head)
{
	course* end = head;
	while (head != NULL)
	{
		end = head;
		head = head->next;
	}
	return end;
}

void help()
{
	int input = -1;
	while (1)
	{
		printf("\n\t\t*****请选择需要帮助的类型 [1]学生帮助 [2]管理员帮助 [0]返回主页\n");
		scanf("%d", &input);
		while (getchar() != '\n');
		if (input == 0)
			break;
		else if (input == 1)
		{
			printf("\n\t\t--------------------------------学生使用说明	\n");
			printf("\t\t初始密码为8个0，忘记密码请联系管理员\n");
			printf("\t\t\n");
			printf("\t\t\n"); printf("\t\t\n");
			printf("\t\t	\n\n");
		}
		else if (input == 2)
		{
			printf("\n\t\t-------------------------------管理员使用说明	\n");
			printf("\t\t密码:初始密码为10个0，首次使用务必修改密码！\n");
			printf("\t\t提示：请定时备份数据，防止数据丢失!\n");
			printf("\t\t提示：学生学号和课程编号只能是数字!\n");
			printf("\t\t	\n\n");
		}
		else
			printf("输入有误!请重新输入\n");
	}
}

int linkCounts(student* head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

int linkCountc(course* head)
{
	int count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

course* cournameFind(course* head, char tar[])
{
	course* p, * q;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		if (strcmp(tar, p->name) == 0)
			return q;
		q = p;
		p = p->next;
	}
	return q;
}

course* cournumFind(course* head, char tar[])
{
	course* p, * q;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		if (strcmp(tar, p->num) == 0)
			return q;
		q = p;
		p = p->next;
	}
	return q;
}

student* stunameFind(student* head, char tar[])
{
	student* p, * q;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		if (strcmp(tar, p->name) == 0)
			return q;
		q = p;
		p = p->next;
	}
	return q;
}

student* stunumFind(student* head, char tar[])
{
	student* p, * q;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		if (strcmp(tar, p->num) == 0)
			return q;
		q = p;
		p = p->next;
	}
	return q;
}

void findingcour(course* head, char id[])
{
	course* result;
	char buf[MAXN];
	result = cournumFind(head, id);
	if (result != cour_tail)
	{
		if (result == NULL)
			result = head;
		else
			result = result->next;
		printf("%s %s", result->name, result->college);
	}
}

void stuPrint(student* p)
{
	/*
	printf("\n\t\t	");
	printf("\n\t\t学号：%s", p->num);
	printf("\n\t\t姓名：%s", p->name);
	printf("\n\t\t所在学院：%s", p->college);
	printf("\n\t\t专业班级：%s", p->majorclass);
	printf("\n\t\t密码：%s", p->password);
	if (p->course_sum == 0)
		printf("\n\t\t该学生无已选课程!\n");
	else
	{
		printf("\n\t\t已选课程:\n");
		for (int i = 0; i < p->course_sum; i++)
		{
			printf("\n\t\t[%d]:%s\n", i + 1, p->course[i]);
		}
	}
	printf("\t\t选课总数:%d", p->course_sum);
	printf("\n\t\t已选课程学分:%.2lf", p->score_sel);
	printf("\n\t\t已修学分统计:%.2lf", p->score_all);
	printf("\n\t\t-------------------------------------");*/
	printf("\n\t\t_____________________________________________________________________________________________________\n");
	printf("\n\t\t|    学号    |   姓 名   |   所在学院   |   专业班级   |    密 码    |选课总数| 已选学分 |  已选课程 \n");
	printf("\n\t\t|%12s|%11s|%14s|%14s|%13s|%8d|%10.2lf|", p->num,p->name,p->college,p->majorclass,p->password,p->course_sum,p->score_all);
	if (p->course_sum == 0)
		printf("\n\t\t该学生无已选课程!\n");
	else
	{
		for (int i = 0; i < p->course_sum; i++)
		{
			printf("[%d]:", i + 1);
			findingcour(cour_head, p->course[i]);
		}
	}
			

}

void stusPrint(student* head)
{
	student* p;
	p = head;
	printf("\n\t\t|    学号    |   姓 名   |   所在学院   |   专业班级   |    密 码    |选课总数| 已选学分 |  已选课程 \n");
	while (p != NULL)
	{
		printf("\n\t\t|%12s|%11s|%14s|%14s|%13s|%8d|%10.2lf|", p->num, p->name, p->college, p->majorclass, p->password, p->course_sum, p->score_all);
		if (p->course_sum == 0)
			printf("\n\t\t该学生无已选课程!\n");
		else
		{
			for (int i = 0; i < p->course_sum; i++)
			{
				printf("[%d]:", i + 1);
				findingcour(cour_head, p->course[i]);
			}
		}
		p = p->next;
	}
}

void courPrint(course* ad)
{
	if (ad == NULL)
		printf("\t\t无课程\n");
	else
	{
		/*
		printf("\n\t\t----------------------------------");
		printf("\n\t\t课程名称:%s\n", ad->name);
		printf("\n\t\t课程编号:%s\n", ad->num);
		printf("\t\t课程性质:%s\n", ad->nature);
		printf("\n\t\t开课学院：%s", ad->college);
		printf("\n\t\t开课学期:%s\n", ad->term);
		printf("\t\t总学时:%.2lf\n", ad->time_all);
		printf("\t\t授课学时:%.2lf\n", ad->time_teach);
		printf("\t\t实验或上机学时:%.2lf\n", ad->time_exp);
		printf("\t\t学分:%.1lf\n\n", ad->score);
		printf("\n\t\t----------------------------------");
		*/
		printf("\n\t\t|    课程编号    |   课程名称   |   课程性质   |    开课学院    |  开课学期  |总学时| 授课学时 |  实验或上机学时  | 学分 | \n");
		printf("\n\t\t|%16s|%14s|%14s|%16s|%12s|%6.2lf|%10.2lf|%18.2lf|%6.1lf|",ad->num,ad->name,ad->nature,ad->college,ad->term,ad->time_all,ad->time_teach,ad->time_exp,ad->score);

	}
}

void coursPrint(course* head)
{
	course* p;
	p = head;
	printf("\n\t\t|    课程编号    |   课程名称   |   课程性质   |    开课学院    |  开课学期  |总学时| 授课学时 |  实验或上机学时  | 学分 | \n");
	while (p != NULL)
	{
		printf("\n\t\t|%16s|%14s|%14s|%16s|%12s|%6.2lf|%10.2lf|%18.2lf|%6.1lf|", head->num, head->name, head->nature, head->college, head->term, head->time_all, head->time_teach, head->time_exp, head->score);
		p = p->next;
	}
	//system("pause");
	return;
}

void courFind(course* head)
{
	int flag;
	while (1)
	{
		flag = 0;
		printf("\n\t\t请输入查找条件 [1]课程编号 [2]课程名称 [3]课程性质\n\t\t[4]开课学期 [0]返回上级菜单:");
		scanf("%d", &flag);
		switch (flag)
		{
		case 1: numFind(head); break;
		case 2: nameFind(head); break;
		case 3: showNature(head); break;
		case 4: showTerm(head); break;
		case 0:
		{
			break;
		}
		default:
			printf("\n\t\t#####输入错误，请重新输入!#####");
		}
		if (flag == 0)
			break;
	}
}

void GetPasswd(char passwd[], int min, int max)
{
	char s[20];
	char temp[2];
	int n;
	strcpy(s, " ");
	while (1)
	{
		while (1)
		{
			n = getch();
			if (n == 13)
			{
				break;
			}
			printf("*");
			memset(temp, 0, sizeof(temp));
			sprintf(temp, "%c", n);
			strcat(s, temp);
		}
		if (strlen(s) > max + 1)
		{
			memset(s, 0, sizeof(s));
			printf("\n密码过长，请重新输入:");
			strcpy(s, " ");
			continue;
		}
		if (strlen(s) < min + 1)
		{
			memset(s, 0, sizeof(s));
			printf("\n密码过短，请重新输入:");
			strcpy(s, " ");
			continue;
		}
		break;
	}
	printf("\n");
	strcpy(passwd, s + 1);
}

void webNet()
{
	system("start https://jwglxt.haut.edu.cn/jwglxt/xtgl/login_slogin.html");
	//ShellExecute(NULL, "open", "https://jwglxt.haut.edu.cn/jwglxt/xtgl/login_slogin.html",NULL,NULL,SW_SHOWNORMAL);
}