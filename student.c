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
	printf("\t\t*******������ѧ��:");
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
		printf("\t\t*******�������½����:");
		char mima[10];
		GetPasswd(mima, 6, 9);
		//while (getchar() != '\n');
		if (strcmp(p_stu->password, mima) == 0)
		{
			printf("\n\n\t\t-----------------------------------��½�ɹ�!	\n\n");
			system("pause");
			system("cls");
			printf("\n\n\t\t-----------------------------%s ��ӭ����ѡ��ϵͳ!	\n\n", p_stu->name);
			printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ѧ���˵�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printf("\n\t\t---[1]:��ӡ�γ���Ϣ");
			printf("\n\t\t---[2]:���ҿγ���Ϣ");
			printf("\n\t\t---[3]:ѡ���µĿγ�");
			printf("\n\t\t---[4]:ɾ����ѡ�γ�");
			printf("\n\t\t---[5]:�鿴������Ϣ");
			printf("\n\t\t---[6]:�޸ĵ�½����");
			printf("\n\t\t---[0]:ע��");
			printf("\n\n\t\t---���<0-6>��ѡ���������:");
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
						printf("��������!����������:");
				}
				if (n == 0)
					break;
				scanf("%d", &n);
			}
		}
		else
			printf("\t\t#####������������µ�½!#######\n");

	}
	else
		printf("\t\t#####��ѧ�Ų����ڣ������µ�½!######\n");
	p_stu = NULL;
}

void stumenu()
{
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ѧ���˵�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t---[1]:��ӡ�γ���Ϣ");
	printf("\n\t\t---[2]:���ҿγ���Ϣ");
	printf("\n\t\t---[3]:ѡ���µĿγ�");
	printf("\n\t\t---[4]:ɾ����ѡ�γ�");
	printf("\n\t\t---[5]:�鿴������Ϣ");
	printf("\n\t\t---[6]:�޸ĵ�½����");
	printf("\n\t\t---[0]:ע��");
	printf("\n\n\t\t---���<0-6>��ѡ���������:");
}

void showNature(course* head)
{
	course* p;
	char ad[MAXN];
	while (1)
	{
		int flag = 0, sum = 0;
		p = head;
		printf("\t\t������Ҫ���ҿγ̵����ʣ�ȡ������������0000:");
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
			printf("\n\t\tû�иÿγ̣�####");
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
		printf("\t\t������Ҫ���ҿγ̵Ŀ���ѧ��,ȡ������������0000:");
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
			printf("\n\t\t#####û�иÿγ�!#####");
	}
	return;
}

void courChoose(course* head, student* stu)
{
	if (stu->score_sel < stu->score_all)
		printf("\n\t\t�����ѧ������%.1lf,�Ͽ�ȥѡ�ΰɣ�\n", stu->score_all);
	while (1)
	{
		printf("\n\t\t������γ̵ı�Ż����ƽ���ѡ�Σ�ȡ��ѡ��������0000:");
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
			printf("\n\t\t#####�ÿγ̲�����!����������#####\n");
			continue;
		}
		else if (find == NULL)
			find = head;
		else
			find = find->next;

		if (find->stu_sum == find->stu_max)
			printf("\n\t\t####�ÿγ���������,�޷�ѡ��!#####\n");
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
				printf("\n\t\t####�ÿγ��Ѿ�ѡ�����!####\n");
				continue;
			}
			else
			{
				stu->course_sum++;
				strcpy(stu->course[stu->course_sum - 1], find->num);
				stu->score_sel += find->score;

				find->stu_sum++;
				strcpy(find->stu[find->stu_sum - 1], stu->num);
				printf("\n\t\t�ÿγ�ѡ��ɹ�!\n");
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
		printf("\t\t������Ҫ���ҿγ̵ı��,ȡ������������0000:");
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
			printf("\t\t#####û�иÿγ̣�#####\n");
	}
}

void nameFind(course* head)
{
	char buf[MAXN];
	course* result;
	while (1)
	{
		printf("\t\t������Ҫ���ҿγ̵�����,ȡ������������0000:");
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
			printf("\t\t#####�������ҵĿγ�!#####\n");
	}
}

void delCourse(course* head, student* stu)
{
	while (1)
	{
		printf("\n\t\t��������Ҫɾ���γ̵ı��,�����ϼ��˵�������0000:");
		char input[50];
		scanf("%s", input);
		while (getchar() != '\n');
		if (strcmp(input, "0000") == 0)
		{
			break;
		}
		int i = 0, result = -1;

		/*ɾ����ѧ����¼��ѡ�ε���Ϣ*/
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
			printf("\n\t\t####��û��ѡ�����ſγ̣�����������!");
			continue;
		}
		strcpy(stu->course[result], stu->course[stu->course_sum - 1]);
		stu->course_sum--;

		course* find = cournumFind(head, input);
		if (find == NULL)
			find = head;
		else
			find = find->next;

		/*ɾ���ÿγ̼�¼��ѧ������Ϣ*/
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
		printf("\n\t\t�γ�ɾ���ɹ�!\n");
	}
	stuOutfile(stu_head);
	courOutfile(cour_head);
}

void stu_keyModify(student* stu)
{
	printf("\t\t******������ԭ����(8λ):");
	char input[20];
	scanf("%s", input);
	while (getchar() != '\n');

	char keyOld[10];
	strcpy(keyOld, stu->password);
	if (!strcmp(keyOld, input))//�޸�
	{
		char new1[100];
		char new2[100];
		while (1)
		{
			printf("\t\t*******�����������루8λ��:");
			scanf("%s", new1);
			while (getchar() != '\n');
			printf("\t\t******���ٴ�ȷ�������루8λ��:");
			scanf("%s", new2);
			while (getchar() != '\n');
			if (!strcmp(new1, new2))
			{
				strcpy(stu->password, new1);
				stuOutfile(stu_head);
				printf("\n\t\t	�����޸ĳɹ�!\n");
				system("pause");
				system("cls");
				stumenu();
				break;
			}
			else
				printf("\t\t####ǰ�����벻һ�£����������룡####\n");
		}
	}
	else
		printf("\t\t####ԭ�����������������ѡ���������####\n");
}

