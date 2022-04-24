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

int manLogin()
{
	FILE* fp;
	if ((fp = fopen("manager.txt", "r")) == NULL)
	{
		printf("\t\t#######�޷��ҵ��ļ���manager.txt######\n");
		return -1;
	}
	char key[11];
	fread(key, 10, 1, fp);
	key[10] = '\0';
	fclose(fp);
	char input[12];
	printf("\t\t*******���������Ա����(Ĭ������Ϊ10��0):");
	GetPasswd(input, 8, 11);
	while (getchar() != '\n');   //���뻺�����û����������
	if (strcmp(input, key) == 0)
		return 1;
	else
		return 0;
}

void manMenu()
{
	if (manLogin() == 1)
	{
		printf("\n\n\t\t-----------------------------------����Ա��½�ɹ�!	\n\n");
		system("pause");
		system("cls");
		printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����Ա�˵�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n\t\t---[1]:���ѧ��");
		printf("\n\t\t---[2]:ɾ��ѧ��");
		printf("\n\t\t---[3]:�޸�ѧ����Ϣ");
		printf("\n\t\t---[4]:����ѧ����Ϣ\n");
		printf("\n\t\t---[5]:��ӿγ�");
		printf("\n\t\t---[6]:ɾ���γ�");
		printf("\n\t\t---[7]:�޸Ŀγ���Ϣ");
		printf("\n\t\t---[8]:���ҿγ���Ϣ\n");
		printf("\n\t\t---[9]:��ӡ���пγ�/ѧ����Ϣ");
		printf("\n\t\t---[10]:�޸Ĺ���Ա����");
		printf("\n\t\t---[11]:���ݱ�����ָ�");
		printf("\n\t\t---[0]:ע��\n");
		printf("\n\t\t	���<0-10>��ѡ���������:");
		int n;
		scanf("%d", &n);
		while (1)
		{
			switch (n)
			{
				case 1: stuAdd(stu_head); break;
				case 2: stuDel(stu_head); break;
				case 3: stuModify(stu_head); break;
				case 4: stuFinding(stu_head); break;
				case 5: courAdd(cour_head); break;
				case 6: courDel(cour_head); break;
				case 7: courModify(cour_head); break;
				case 8: courFind(cour_head); break;
				case 9: Print(); break;
				case 10: keyModify(); break;
				case 11: backups_recover(); break;
				case 0: exit(0); break;
				default:
					printf("\t\t\t#####�����������������######!\n");
			}
			if (n == 0)
				break;
			scanf("%d", &n);
		}
	}
	else
	{
		printf("\t\t######������������µ�½!######\n");
	}
}

void manmenu()
{
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~����Ա�˵�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t---[1]:���ѧ��");
	printf("\n\t\t---[2]:ɾ��ѧ��");
	printf("\n\t\t---[3]:�޸�ѧ����Ϣ");
	printf("\n\t\t---[4]:����ѧ����Ϣ\n");
	printf("\n\t\t---[5]:��ӿγ�");
	printf("\n\t\t---[6]:ɾ���γ�");
	printf("\n\t\t---[7]:�޸Ŀγ���Ϣ");
	printf("\n\t\t---[8]:���ҿγ���Ϣ\n");
	printf("\n\t\t---[9]:��ӡ���пγ�/ѧ����Ϣ");
	printf("\n\t\t---[10]:�޸Ĺ���Ա����");
	printf("\n\t\t---[11]:���ݱ�����ָ�");
	printf("\n\t\t---[0]:ע��\n");
	printf("\n\t\t	���<0-10>��ѡ���������:");
	int n;
	scanf("%d", &n);
	while (1)
	{
		switch (n)
		{
			case 1: stuAdd(stu_head); break;
			case 2: stuDel(stu_head); break;
			case 3: stuModify(stu_head); break;
			case 4: stuFinding(stu_head); break;
			case 5: courAdd(cour_head); break;
			case 6: courDel(cour_head); break;
			case 7: courModify(cour_head); break;
			case 8: courFind(cour_head); break;
			case 9: Print(); break;
			case 10: keyModify(); break;
			case 11: backups_recover(); break;
			case 0: exit(0);
			default:
				printf("\t\t\t#####�����������������######!\n");
		}
		if (n == 0)
			break;
		scanf("%d", &n);
	}
}

void stuAdd(student* head)
{
	while (1)
	{
		char n[50];
		printf("\n\t\t������Ҫ���ѧ����ѧ��(����)�������ϼ��˵�������0000��");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if (stunumFind(stu_head, n) != stu_tail)
		{
			printf("\t\t###�Ѵ��ڸ�ѧ��,����������!####\n");
			continue;
		}
		//��ʼ��ѧ����Ϣ
		student* p = (student*)malloc(sizeof(student));
		strcpy(p->num, n);
		printf("\t\t������ѧ������:");
		scanf("%s", p->name);
		while (getchar() != '\n');
		printf("\t\t������ѧ��רҵ�༶(��--����):");
		scanf("%s", p->majorclass);
		while (getchar() != '\n');
		printf("\t\t�����뵱ǰ��ѧ����ѧ��:");
		scanf("%lf", &p->score_all);
		while (getchar() != '\n');
		printf("\t\t������ѧ������ѧԺ:");
		scanf("%s", p->college);
		p->course_sum = 0;
		p->score_sel = 0.0;
		strcpy(p->password, "00000000");       //������Ĭ����Ϊѧ��
		if (stu_head == NULL)
		{
			p->next = NULL;
			stu_head = p;
			stu_tail = p;
		}
		else
		{
			if (strcmp(p->num, stu_head->num) < 0)      //����ѧ�����С�ڱ����С��ѧ��
			{
				p->next = stu_head;
				stu_head = p;
			}
			else if (strcmp(p->num, stu_tail->num) > 0)  //����ѧ����Ŵ��ڱ������ѧ��
			{
				p->next = NULL;
				stu_tail->next = p;
				stu_tail = p;
			}
			else                                          //��ѧ�����Ϊ�м���
			{
				student* temp = stu_head;
				while (temp != stu_tail)
				{
					if (strcmp(p->num, temp->num) > 0)
					{
						p->next = temp->next;
						temp->next = p;
						break;
					}
				}
			}
		}
		printf("\n\t\tѧ����Ϣ¼��ɹ�!\n");
		stuOutfile(stu_head);
	}
	return;
}

void stuDel(student* head)
{
	while (1)
	{
		printf("\n\t\t������Ҫɾ��ѧ����ѧ�Ż�����,ȡ��ɾ��������0000:");
		char n[50];
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		student* p;
		if ((n[0] >= 48) && (n[0] <= 57))         //�ж�ASCII���Ƿ���0~9
			p = stunumFind(stu_head, n);
		else
			p = stunameFind(stu_head, n);

		if (p == stu_tail)        //û�и�ѧ��
		{
			printf("\n\t\t####û�и�ѧ����Ϣ!#####");
			continue;
		}
		printf("\n\t\tȷ��ɾ��%s��[1]�� [0]��:", n);
		int opt = 0;
		scanf("%d", &opt);
		if (opt == 1)
		{
			if (p == NULL)                  //ͷ���        
			{
				if (stu_head->next == NULL)
				{
					stu_tail = NULL;
				}
				student* temp = stu_head;
				stu_head = stu_head->next;
				free(temp);
				temp = NULL;
			}
			else if (p->next == stu_tail)   //β���
			{
				p->next = NULL;
				free(stu_tail);
				stu_tail = p;
			}
			else                            //�м���
			{
				student* delete_point = p->next;
				p->next = delete_point->next;
				free(delete_point);
				delete_point = NULL;
			}
			printf("\n\t\t�Ѿ�ɾ����ѧ������Ϣ��\n");
		}
		else
			printf("\n\t\t####δɾ����ѧ������Ϣ!####\n");
		stuOutfile(stu_head);
	}
}

void stuModify(student* head)
{
	char n[100];
	student* find = NULL;
	while (1)
	{
		printf("\t\t������Ҫ�޸�ѧ����ѧ�Ż�������ȡ���޸�������0000:");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if ((n[0] >= 48) && (n[0] <= 57))            //��ѧ�Ų���
			find = stunumFind(head, n);
		else                                         //����������
			find = stunameFind(head, n);

		if (find == stu_tail)
		{
			printf("\n\t\t####�������ҵ�ѧ�������ڣ�");
			continue;
		}
		else
		{
			char temp[50];
			if (find == NULL)
				find = head;
			else
				find = find->next;
			printf("\n\t\t��ֱ�������Ҫ�޸ĵ����ݣ���ĳһ���Ҫ�޸�������0");
			printf("\n\t\tԭ����:%s �޸ĺ��������", find->name);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->name, temp);

			printf("\t\tԭѧԺ:%s �޸ĺ��ѧԺ��", find->college);
			scanf("%s", &temp);
			while (getchar() != '\n')
				if (strcmp(temp, "0") != 0)
					strcpy(find->college, temp);

			printf("\t\tԭרҵ�Ͱ༶:%s �޸ĺ��רҵ�Ͱ༶(�м���--����)��", find->majorclass);
			scanf("%s", &temp);
			while (getchar() != '\n')
				if (strcmp(temp, "0") != 0)
					strcpy(find->majorclass, temp);

			printf("\t\tԭ����:%s �޸ĺ������:", find->password);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->password, temp);

			printf("\t\tԭ��ѧ��:%.1lf (����ѧ����ʹ��+,����ѧ����ʹ��-,����-10 +10):", find->score_all);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
			{
				int change = (int)temp[0];
				temp[0] = '0';
				double number = atof(temp);
				if (change == 43)
					find->score_all += number;
				else if (change == 45)
					find->score_all -= number;
			}
			printf("\t\t�޸����!\n\n");
		}
		stuOutfile(stu_head);
	}
}

void courAdd(course* head)
{
	while (1)
	{
		char n[50];
		printf("\n\t\t������Ҫ��ӿγ̵ı�ţ�������һ���˵�������0000��");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if (cournumFind(cour_head, n) != cour_tail)
		{
			printf("\t\t###�Ѵ��ڸÿγ�,����������!####\n");
			continue;
		}

		course* p = (course*)malloc(sizeof(course));
		//��ʼ���γ���Ϣ
		strcpy(p->num, n);
		printf("\n\t\t������γ����ƣ�");
		scanf("%s", p->name);
		while (getchar() != '\n');
		printf("\n\t\t������γ�����:");
		scanf("%s", p->nature);
		while (getchar() != '\n');
		printf("\n\t\t�����뿪��ѧԺ:");
		scanf("%s", p->college);
		while (getchar() != '\n');
		printf("\n\t\t������γ���ѧʱ:");
		scanf("%lf", &p->time_all);
		printf("\n\t\t������γ��ڿ�ѧʱ:");
		scanf("%lf", &p->time_teach);
		printf("\n\t\t������γ�ʵ����ϻ�ѧʱ:");
		scanf("%lf", &p->time_exp);
		printf("\n\t\t������γ������������:");
		scanf("%d", &p->stu_max);
		printf("\n\t\t������γ�ѧ��:");
		scanf("%lf", &p->score);
		printf("\n\t\t������γ̿���ѧ��:");
		scanf("%s", p->term);
		while (getchar() != '\n');
		p->stu_sum = 0;
		if (cour_head == NULL)//������û�нڵ�
		{
			p->next = NULL;
			cour_head = p;
			cour_tail = p;
		}
		else
		{
			if (strcmp(p->num, cour_head->num) < 0)       //�����γ̱��С����С���
			{
				p->next = cour_head;
				cour_head = p;
			}
			else if (strcmp(p->num, cour_tail->num) > 0)  //�����γ̱�Ŵ��������
			{
				p->next = NULL;
				cour_tail->next = p;
				cour_tail = p;
			}
			else                                          //�����ڵ�ı����ͷ�ڵ��β�ڵ�֮��
			{
				course* temp = cour_head;
				while (temp != cour_tail)
				{
					if (strcmp(p->num, temp->num) > 0)
					{
						p->next = temp->next;
						temp->next = p;
						break;
					}
				}
			}
		}
		printf("\n\t\t�γ���Ϣ¼��ɹ�!\n");
		courOutfile(cour_head);
	}
}

void courDel(course* head)
{
	course* p;
	char n[50];
	while (1)
	{
		printf("\n\t\t������Ҫɾ���γ̵ı�Ż����ƣ�ȡ��ɾ��������0000:");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if ((n[0] >= 48) && (n[0] <= 57))
			p = cournumFind(head, n);
		else
			p = cournameFind(head, n);

		if (p == cour_tail)//û�иÿγ�

		{
			printf("\n\t\t####û�иÿγ���Ϣ!####");
			continue;
		}
		printf("\n\t\tȷ��ɾ��%s��[1]�� [0]��:", n);
		int in = 0;
		scanf("%d", &in);
		if (in == 1)
		{
			if (p == NULL)//����ͷ�ڵ�
			{
				if (head->next == NULL)
					cour_tail = NULL;
				course* temp = head;
				head = head->next;
				cour_head = head;
				free(temp);
			}
			else if (p->next == cour_tail)//����β�ڵ�
			{
				free(cour_tail);
				p->next = NULL;
				cour_tail = p;
			}
			else//�����м�ڵ�
			{
				course* delete_point = p->next;
				p = p->next;
				p = p->next;
				free(delete_point);
			}
			printf("\n\t\t%s�Ѿ�ɾ����\n", n);
		}
		else
			printf("\n\t\t#####δɾ���γ�%s����Ϣ!######\n", n);
		courOutfile(cour_head);
	}
}

void courModify(course* head)
{
	char n[100];
	course* find = NULL;
	while (1)
	{
		printf("\t\t������Ҫ�޸Ŀγ̵ı�źŻ�����,ȡ���޸�������0000:");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if ((n[0] >= 48) && (n[0] <= 57))//��ѧ�Ų���
			find = cournumFind(head, n);
		else//����������
			find = cournameFind(head, n);
		if (find == cour_tail)
		{
			printf("\n\t\t####�������ҵĿγ̲����ڣ�####");
			continue;
		}
		else
		{
			char temp[50];
			if (find == NULL)
				find = head;
			else
				find = find->next;
			printf("\n\t\t��ֱ�������Ҫ�޸ĵ����ݣ���ĳһ���Ҫ�޸�������0");
			printf("\n\t\tԭ����:%s �޸ĺ�����ƣ�", find->name);

			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->name, temp);

			printf("\t\tԭ����:%s �޸ĺ�����ʣ�", find->nature);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->nature, temp);

			printf("\t\tԭ����ѧ��:%s �޸ĺ�Ŀ���ѧ�ڣ�", find->term);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->term, temp);

			printf("\t\tԭ����ѧԺ:%s �޸ĺ�Ŀ���ѧԺ��", find->college);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->college, temp);

			printf("\t\tԭ��ѧʱ:%.1lf �޸ĺ����ѧʱ��", find->time_all);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->time_all = atof(temp);

			printf("\t\tԭ�ڿ�ѧʱ:%.1lf �޸ĺ���ڿ�ѧʱ��", find->time_teach);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->time_teach = atof(temp);

			printf("\t\tԭʵ����ϻ�ѧʱ:%.1lf �޸ĺ��ʵ����ϻ�ѧʱ��", find->time_exp);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->time_exp = atof(temp);

			printf("\t\tԭ�γ�ѧ��:%.1lf �޸ĺ�Ŀγ�ѧ�֣�", find->score);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->score = atof(temp);    //�ַ���ת��Ϊ������

			printf("\t\tԭ������ѧ������:%d �޸ĺ��������ѧ��������", find->stu_max);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->stu_max = atoi(temp);   //�ַ���ת��Ϊ����
			printf("\t\t�޸���ɣ�\n\n");
		}
		courOutfile(cour_head);
	}
}

void Print()
{
	while (1)
	{
		printf("\n\t\tѡ���������: [1]��ӡ����ѧ����Ϣ [2]��ӡ���пγ���Ϣ [0]�������˵�:");
		int n = 0;
		scanf("%d", &n);
		while (getchar() != '\n');
		if (n == 1)
		{

			printf("\n\t\tѧ��������%d", linkCounts(stu_head));
			stusPrint(stu_head);
		}
		else if (n == 2)
		{
			printf("\n\t\t�γ�������%d\n", linkCountc(cour_head));
			coursPrint(cour_head);
		}
		else if (n == 0)
		{
			system("cls");
			manmenu();
		}
		else
			printf("\n\t\t####�����������������!#####\n");
	}
}

void keyModify()
{
	printf("\t\t******������ԭ����(10λ):");
	char input[20];
	scanf("%s", input);
	while (getchar() != '\n');

	FILE* fp;
	if ((fp = fopen("manager.txt", "r")) == NULL)
	{
		printf("\t\t	�޷����ļ�:manager.txt\n");
		exit(0);
	}
	char keyOld[11];
	fread(keyOld, 10, 1, fp);
	keyOld[10] = '\0';
	if (strcmp(keyOld, input) == 0)//�޸�
	{
		fclose(fp);
		char new1[100];
		char new2[100];
		while (1)
		{
			printf("\t\t*******�����������루10λ��:");
			scanf("%s", new1);
			while (getchar() != '\n');
			printf("\t\t******���ٴ�ȷ�������루10λ��:");
			scanf("%s", new2);
			while (getchar() != '\n');
			if (!strcmp(new1, new2))
			{
				fp = fopen("manager.txt", "w");
				fwrite(new1, 10, 1, fp);
				fclose(fp);
				printf("\n\t\t	�����޸ĳɹ�!\n");
				system("pause");
				system("cls");
				manmenu();
			}
			else
				printf("\t\t####ǰ�����벻һ�£����������룡####\n");
		}
	}
	else
	{
		fclose(fp);
		printf("\t\t####ԭ�����������������ѡ���������####\n");
	}
}

void backups_recover()
{
	printf("\t\t*****[1]���ݱ��� [2]���ݻָ� [3]ȡ��\n");
	printf("\t\t*****ѡ���������:");
	int n = 0;
	scanf("%d", &n);
	if (n == 1)
	{
		FILE* fp_source;
		FILE* fp_destination;

		//�γ���Ϣ����
		if ((fp_source = fopen("course.txt", "r")) == NULL)
		{
			printf("\t\t##�γ����ݱ���ʧ�ܣ��޷��ҵ�course.txt�ļ���##\n");
			exit(0);
		}
		fp_destination = fopen("course_backup.txt", "w");
		char temp;
		int count = 0;
		while (!feof(fp_source))
		{
			if (fread(&temp, 1, 1, fp_source))
				count++;
		}
		rewind(fp_source);
		int i;
		for (i = 0; i < count; i++)
		{
			fread(&temp, 1, 1, fp_source);
			fwrite(&temp, 1, 1, fp_destination);
		}
		fclose(fp_destination);
		fclose(fp_source);

		//ѧ����Ϣ����
		{
			if ((fp_source = fopen("student.txt", "r")) == NULL)
			{
				printf("\t\t##ѧ�����ݱ���ʧ�ܣ��޷��ҵ�student.txt�ļ���##\n");
				exit(0);
			}
			fp_destination = fopen("student_backup.txt", "w");
			char temp;
			int count = 0;
			while (!feof(fp_source))
			{
				if (fread(&temp, 1, 1, fp_source)) 
					count++;
			}
			rewind(fp_source);
			int i;
			for (i = 0; i < count; i++)
			{
				fread(&temp, 1, 1, fp_source);
				fwrite(&temp, 1, 1, fp_destination);
			}
			fclose(fp_destination); 
			fclose(fp_source);
		}
		{//����Ա��Ϣ����
			if ((fp_source = fopen("manager.txt", "r")) == NULL)
			{
				printf("\t\t##����Ա���ݱ���ʧ�ܣ��޷��ҵ�manager.txt�ļ���##\n");
				exit(0);
			}
			fp_destination = fopen("manager_backup.txt", "w");
			char temp;
			int i;
			for (i = 0; i < 10; i++)
			{
				fread(&temp, 1, 1, fp_source);
				fwrite(&temp, 1, 1, fp_destination);
			}
			fclose(fp_destination); 
			fclose(fp_source);

		}
		printf("\n\t\t���������Ѿ�������ϣ�����Ŀ¼Ϊstudent_backup.txt��course_backup.txt\n");
		system("pause");
		system("cls");
		manmenu();
	}
	else if (n == 2)
	{
		printf("\t\tѡ��ָ�����:[1]�γ����� [2]ѧ������ [3]����Ա����:");
		int in = 0;
		scanf("%d", &in);
		while (getchar() != '\n');
		FILE* fp_source;
		FILE* fp_destination;

		if (in == 1)//course information recover
		{ //�γ���Ϣ�ָ�
			if ((fp_source = fopen("course_backup.txt", "r")) == NULL)
			{
				printf("\t\t###�γ���Ϣ�ָ�ʧ�ܣ�δ���ҵ�course.txt###\n");
				exit(0);
			}
			fp_destination = fopen("course.txt", "w");
			char temp;
			int count = 0;
			while (!feof(fp_source))
			{
				if (fread(&temp, 1, 1, fp_source)) count++;
			}
			rewind(fp_source);
			int i;
			for (i = 0; i < count; i++)
			{
				fread(&temp, 1, 1, fp_source);
				fwrite(&temp, 1, 1, fp_destination);
			}
			fclose(fp_destination); fclose(fp_source);
			printf("\n\t\t�γ���Ϣ�ָ��ɹ���\n");
			cour_head = courInfile();
			cour_tail = endcLocate(cour_head);
		}
		else if (in == 2)
		{
			if ((fp_source = fopen("student_backup.txt", "r")) == NULL)
			{
				printf("\t\t###ѧ����Ϣ�ָ�ʧ�ܣ�δ���ҵ�student.txt\n");
				exit(0);
			}
			fp_destination = fopen("student.txt", "w");
			char temp;
			int count = 0;
			while (!feof(fp_source))
			{
				if (fread(&temp, 1, 1, fp_source))
					count++;
			}
			rewind(fp_source);
			int i;
			for (i = 0; i < count; i++)
			{
				fread(&temp, 1, 1, fp_source);
				fwrite(&temp, 1, 1, fp_destination);
			}
			fclose(fp_destination);
			fclose(fp_source);
			printf("\n\t\tѧ�����ݻָ��ɹ���\n");
			stu_head = stuInfile();
			stu_tail = endsLocate(stu_head);
		}
		else if (in == 3)
		{
			if ((fp_source = fopen("manager_backup.txt", "r")) == NULL)
			{

				printf("\t\t###����Ա���ݻָ�ʧ�ܣ�δ���ҵ�manager.txt\n");
				exit(0);
			}
			fp_destination = fopen("manager.txt", "w");
			char temp;
			int i;
			for (i = 0; i < 10; i++)
			{
				fread(&temp, 1, 1, fp_source);
				fwrite(&temp, 1, 1, fp_destination);
			}
			fclose(fp_destination);
			fclose(fp_source);
			printf("\n\t\t����Ա���ݻָ��ɹ���\n");
		}
		else
			printf("\t\t###�������###\n");
		system("pause");
		system("cls");
		manmenu();
	}
	else if (n == 3)
	{
		system("cls");
		manmenu();
	}
	else
	{
		printf("\t\t###�����������������!####\n");
	}
}

void stuFinding(student* head)
{
	while (1)
	{
		printf("\n\t\t������ѧ�Ż��������в��ң������ϼ��˵�������0000��");
		char n[50];
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		student* p_stu;
		if ((n[0] >= 48) && (n[0] <= 57))
			p_stu = stunumFind(head, n);
		else
			p_stu = stunameFind(head, n);

		if (p_stu == stu_tail)
		{
			printf("\n\t\t#####û�и�ѧ������Ϣ�����������룡#####/n");
			continue;
		}
		if (p_stu == NULL)
			p_stu = head;
		else
			p_stu = p_stu->next;
		printf("\n\t\t��ѧ����Ϣ���£�");
		stuPrint(p_stu);
	}
}

void courPrint_man(course* ad)
{
	if (ad == NULL)
	{
		printf("�޿γ�\n");
	}
	else
	{
		printf("\n\t\t-------------------------------------");
		printf("\n\t\t �� �� �� �� ��%s\n", ad->num);
		printf("\t\t �� �� �� �� ��%s\n", ad->name);
		printf("\t\t �� �� �� �� ��%s\n", ad->nature);
		printf("\t\t �� �� ѧ �� ��%s\n", ad->term);
		printf("\t\t �� ѧ ʱ :%lf\n", ad->time_all);
		printf("\t\t�ڿ�ѧʱ��%lf\n", ad->time_teach);
		printf("\t\tʵ����ϻ�ѧʱ��%lf\n", ad->time_exp);
		printf("\t\tѧ�֣�%lf\n", ad->score);
		printf("\t\t������ѧ��������%d\n", ad->stu_max);
		printf("\t\t��ѡѧ��������%d\n", ad->stu_sum);
		printf("\t\t��ѡѧ����\n");
		if (ad->stu_sum == 0)
			printf("\t\tû����ѡ��ÿγ�\n");
		else
			for (int i = 0; i < ad->stu_sum; i++)
			{
				if (i % 5 == 0)
					printf("\t\t");
				student* temp = stunumFind(stu_head, ad->stu[i]);
				if (temp == NULL)
					temp = stu_head;
				else
					temp = temp->next;
				printf("[%d] %s", i + 1, temp->name);
				if (i > 0 && i % 5 == 0)
					printf("\n");
			}
		printf("\n\t\t-------------------------------------");
	}
}

void coursPrint_man(course* head)
{
	course* p;
	p = head;
	if (p == NULL)
	{
		printf("\t\t�޿γ�\n");
		return;
	}
	while (p != NULL)
	{
		courPrint_man(p);
		p = p->next;
	}
}
