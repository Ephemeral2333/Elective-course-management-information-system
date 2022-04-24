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

student* stuInfile()      //ѧ���ļ�������������
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
		rewind(fp);                   //���ļ��ڲ���ָ������ָ��һ�����Ŀ�ͷ
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
		printf("\t***û���ҵ�student.txt�������ļ��Ƿ�����!\n\n");
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
		printf("\t***û���ҵ�course.txt�������ļ��Ƿ�����!\n\n");
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
		printf("\n\t\t*****��ѡ����Ҫ���������� [1]ѧ������ [2]����Ա���� [0]������ҳ\n");
		scanf("%d", &input);
		while (getchar() != '\n');
		if (input == 0)
			break;
		else if (input == 1)
		{
			printf("\n\t\t--------------------------------ѧ��ʹ��˵��	\n");
			printf("\t\t��ʼ����Ϊ8��0��������������ϵ����Ա\n");
			printf("\t\t\n");
			printf("\t\t\n"); printf("\t\t\n");
			printf("\t\t	\n\n");
		}
		else if (input == 2)
		{
			printf("\n\t\t-------------------------------����Աʹ��˵��	\n");
			printf("\t\t����:��ʼ����Ϊ10��0���״�ʹ������޸����룡\n");
			printf("\t\t��ʾ���붨ʱ�������ݣ���ֹ���ݶ�ʧ!\n");
			printf("\t\t��ʾ��ѧ��ѧ�źͿγ̱��ֻ��������!\n");
			printf("\t\t	\n\n");
		}
		else
			printf("��������!����������\n");
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
	printf("\n\t\tѧ�ţ�%s", p->num);
	printf("\n\t\t������%s", p->name);
	printf("\n\t\t����ѧԺ��%s", p->college);
	printf("\n\t\tרҵ�༶��%s", p->majorclass);
	printf("\n\t\t���룺%s", p->password);
	if (p->course_sum == 0)
		printf("\n\t\t��ѧ������ѡ�γ�!\n");
	else
	{
		printf("\n\t\t��ѡ�γ�:\n");
		for (int i = 0; i < p->course_sum; i++)
		{
			printf("\n\t\t[%d]:%s\n", i + 1, p->course[i]);
		}
	}
	printf("\t\tѡ������:%d", p->course_sum);
	printf("\n\t\t��ѡ�γ�ѧ��:%.2lf", p->score_sel);
	printf("\n\t\t����ѧ��ͳ��:%.2lf", p->score_all);
	printf("\n\t\t-------------------------------------");*/
	printf("\n\t\t_____________________________________________________________________________________________________\n");
	printf("\n\t\t|    ѧ��    |   �� ��   |   ����ѧԺ   |   רҵ�༶   |    �� ��    |ѡ������| ��ѡѧ�� |  ��ѡ�γ� \n");
	printf("\n\t\t|%12s|%11s|%14s|%14s|%13s|%8d|%10.2lf|", p->num,p->name,p->college,p->majorclass,p->password,p->course_sum,p->score_all);
	if (p->course_sum == 0)
		printf("\n\t\t��ѧ������ѡ�γ�!\n");
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
	printf("\n\t\t|    ѧ��    |   �� ��   |   ����ѧԺ   |   רҵ�༶   |    �� ��    |ѡ������| ��ѡѧ�� |  ��ѡ�γ� \n");
	while (p != NULL)
	{
		printf("\n\t\t|%12s|%11s|%14s|%14s|%13s|%8d|%10.2lf|", p->num, p->name, p->college, p->majorclass, p->password, p->course_sum, p->score_all);
		if (p->course_sum == 0)
			printf("\n\t\t��ѧ������ѡ�γ�!\n");
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
		printf("\t\t�޿γ�\n");
	else
	{
		/*
		printf("\n\t\t----------------------------------");
		printf("\n\t\t�γ�����:%s\n", ad->name);
		printf("\n\t\t�γ̱��:%s\n", ad->num);
		printf("\t\t�γ�����:%s\n", ad->nature);
		printf("\n\t\t����ѧԺ��%s", ad->college);
		printf("\n\t\t����ѧ��:%s\n", ad->term);
		printf("\t\t��ѧʱ:%.2lf\n", ad->time_all);
		printf("\t\t�ڿ�ѧʱ:%.2lf\n", ad->time_teach);
		printf("\t\tʵ����ϻ�ѧʱ:%.2lf\n", ad->time_exp);
		printf("\t\tѧ��:%.1lf\n\n", ad->score);
		printf("\n\t\t----------------------------------");
		*/
		printf("\n\t\t|    �γ̱��    |   �γ�����   |   �γ�����   |    ����ѧԺ    |  ����ѧ��  |��ѧʱ| �ڿ�ѧʱ |  ʵ����ϻ�ѧʱ  | ѧ�� | \n");
		printf("\n\t\t|%16s|%14s|%14s|%16s|%12s|%6.2lf|%10.2lf|%18.2lf|%6.1lf|",ad->num,ad->name,ad->nature,ad->college,ad->term,ad->time_all,ad->time_teach,ad->time_exp,ad->score);

	}
}

void coursPrint(course* head)
{
	course* p;
	p = head;
	printf("\n\t\t|    �γ̱��    |   �γ�����   |   �γ�����   |    ����ѧԺ    |  ����ѧ��  |��ѧʱ| �ڿ�ѧʱ |  ʵ����ϻ�ѧʱ  | ѧ�� | \n");
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
		printf("\n\t\t������������� [1]�γ̱�� [2]�γ����� [3]�γ�����\n\t\t[4]����ѧ�� [0]�����ϼ��˵�:");
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
			printf("\n\t\t#####�����������������!#####");
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
			printf("\n�������������������:");
			strcpy(s, " ");
			continue;
		}
		if (strlen(s) < min + 1)
		{
			memset(s, 0, sizeof(s));
			printf("\n������̣�����������:");
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