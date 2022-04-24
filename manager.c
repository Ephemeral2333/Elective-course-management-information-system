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
		printf("\t\t#######无法找到文件：manager.txt######\n");
		return -1;
	}
	char key[11];
	fread(key, 10, 1, fp);
	key[10] = '\0';
	fclose(fp);
	char input[12];
	printf("\t\t*******请输入管理员密码(默认密码为10个0):");
	GetPasswd(input, 8, 11);
	while (getchar() != '\n');   //读入缓冲区用户输入的密码
	if (strcmp(input, key) == 0)
		return 1;
	else
		return 0;
}

void manMenu()
{
	if (manLogin() == 1)
	{
		printf("\n\n\t\t-----------------------------------管理员登陆成功!	\n\n");
		system("pause");
		system("cls");
		printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~管理员菜单~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n\t\t---[1]:添加学生");
		printf("\n\t\t---[2]:删除学生");
		printf("\n\t\t---[3]:修改学生信息");
		printf("\n\t\t---[4]:查找学生信息\n");
		printf("\n\t\t---[5]:添加课程");
		printf("\n\t\t---[6]:删除课程");
		printf("\n\t\t---[7]:修改课程信息");
		printf("\n\t\t---[8]:查找课程信息\n");
		printf("\n\t\t---[9]:打印所有课程/学生信息");
		printf("\n\t\t---[10]:修改管理员密码");
		printf("\n\t\t---[11]:数据备份与恢复");
		printf("\n\t\t---[0]:注销\n");
		printf("\n\t\t	请从<0-10>中选择操作类型:");
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
					printf("\t\t\t#####输入错误，请重新输入######!\n");
			}
			if (n == 0)
				break;
			scanf("%d", &n);
		}
	}
	else
	{
		printf("\t\t######密码错误，请重新登陆!######\n");
	}
}

void manmenu()
{
	printf("\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~管理员菜单~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t---[1]:添加学生");
	printf("\n\t\t---[2]:删除学生");
	printf("\n\t\t---[3]:修改学生信息");
	printf("\n\t\t---[4]:查找学生信息\n");
	printf("\n\t\t---[5]:添加课程");
	printf("\n\t\t---[6]:删除课程");
	printf("\n\t\t---[7]:修改课程信息");
	printf("\n\t\t---[8]:查找课程信息\n");
	printf("\n\t\t---[9]:打印所有课程/学生信息");
	printf("\n\t\t---[10]:修改管理员密码");
	printf("\n\t\t---[11]:数据备份与恢复");
	printf("\n\t\t---[0]:注销\n");
	printf("\n\t\t	请从<0-10>中选择操作类型:");
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
				printf("\t\t\t#####输入错误，请重新输入######!\n");
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
		printf("\n\t\t请输入要添加学生的学号(数字)，返回上级菜单请输入0000：");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if (stunumFind(stu_head, n) != stu_tail)
		{
			printf("\t\t###已存在该学生,请重新输入!####\n");
			continue;
		}
		//初始化学生信息
		student* p = (student*)malloc(sizeof(student));
		strcpy(p->num, n);
		printf("\t\t请输入学生姓名:");
		scanf("%s", p->name);
		while (getchar() != '\n');
		printf("\t\t请输入学生专业班级(用--隔开):");
		scanf("%s", p->majorclass);
		while (getchar() != '\n');
		printf("\t\t请输入当前该学生总学分:");
		scanf("%lf", &p->score_all);
		while (getchar() != '\n');
		printf("\t\t请输入学生所在学院:");
		scanf("%s", p->college);
		p->course_sum = 0;
		p->score_sel = 0.0;
		strcpy(p->password, "00000000");       //将密码默认设为学号
		if (stu_head == NULL)
		{
			p->next = NULL;
			stu_head = p;
			stu_tail = p;
		}
		else
		{
			if (strcmp(p->num, stu_head->num) < 0)      //若该学生编号小于编号最小的学生
			{
				p->next = stu_head;
				stu_head = p;
			}
			else if (strcmp(p->num, stu_tail->num) > 0)  //若该学生编号大于编号最大的学生
			{
				p->next = NULL;
				stu_tail->next = p;
				stu_tail = p;
			}
			else                                          //该学生编号为中间编号
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
		printf("\n\t\t学生信息录入成功!\n");
		stuOutfile(stu_head);
	}
	return;
}

void stuDel(student* head)
{
	while (1)
	{
		printf("\n\t\t请输入要删除学生的学号或姓名,取消删除请输入0000:");
		char n[50];
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		student* p;
		if ((n[0] >= 48) && (n[0] <= 57))         //判断ASCII码是否在0~9
			p = stunumFind(stu_head, n);
		else
			p = stunameFind(stu_head, n);

		if (p == stu_tail)        //没有该学生
		{
			printf("\n\t\t####没有该学生信息!#####");
			continue;
		}
		printf("\n\t\t确定删除%s？[1]是 [0]否:", n);
		int opt = 0;
		scanf("%d", &opt);
		if (opt == 1)
		{
			if (p == NULL)                  //头结点        
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
			else if (p->next == stu_tail)   //尾结点
			{
				p->next = NULL;
				free(stu_tail);
				stu_tail = p;
			}
			else                            //中间结点
			{
				student* delete_point = p->next;
				p->next = delete_point->next;
				free(delete_point);
				delete_point = NULL;
			}
			printf("\n\t\t已经删除该学生的信息！\n");
		}
		else
			printf("\n\t\t####未删除该学生的信息!####\n");
		stuOutfile(stu_head);
	}
}

void stuModify(student* head)
{
	char n[100];
	student* find = NULL;
	while (1)
	{
		printf("\t\t请输入要修改学生的学号或姓名，取消修改请输入0000:");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if ((n[0] >= 48) && (n[0] <= 57))            //按学号查找
			find = stunumFind(head, n);
		else                                         //按姓名查找
			find = stunameFind(head, n);

		if (find == stu_tail)
		{
			printf("\n\t\t####你所查找的学生不存在！");
			continue;
		}
		else
		{
			char temp[50];
			if (find == NULL)
				find = head;
			else
				find = find->next;
			printf("\n\t\t请分别输入需要修改的内容，若某一项不需要修改请输入0");
			printf("\n\t\t原姓名:%s 修改后的姓名：", find->name);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->name, temp);

			printf("\t\t原学院:%s 修改后的学院：", find->college);
			scanf("%s", &temp);
			while (getchar() != '\n')
				if (strcmp(temp, "0") != 0)
					strcpy(find->college, temp);

			printf("\t\t原专业和班级:%s 修改后的专业和班级(中间用--隔开)：", find->majorclass);
			scanf("%s", &temp);
			while (getchar() != '\n')
				if (strcmp(temp, "0") != 0)
					strcpy(find->majorclass, temp);

			printf("\t\t原密码:%s 修改后的密码:", find->password);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->password, temp);

			printf("\t\t原总学分:%.1lf (增加学分请使用+,减少学分请使用-,例如-10 +10):", find->score_all);
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
			printf("\t\t修改完成!\n\n");
		}
		stuOutfile(stu_head);
	}
}

void courAdd(course* head)
{
	while (1)
	{
		char n[50];
		printf("\n\t\t请输入要添加课程的编号，返回上一级菜单请输入0000：");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if (cournumFind(cour_head, n) != cour_tail)
		{
			printf("\t\t###已存在该课程,请重新输入!####\n");
			continue;
		}

		course* p = (course*)malloc(sizeof(course));
		//初始化课程信息
		strcpy(p->num, n);
		printf("\n\t\t请输入课程名称：");
		scanf("%s", p->name);
		while (getchar() != '\n');
		printf("\n\t\t请输入课程性质:");
		scanf("%s", p->nature);
		while (getchar() != '\n');
		printf("\n\t\t请输入开课学院:");
		scanf("%s", p->college);
		while (getchar() != '\n');
		printf("\n\t\t请输入课程总学时:");
		scanf("%lf", &p->time_all);
		printf("\n\t\t请输入课程授课学时:");
		scanf("%lf", &p->time_teach);
		printf("\n\t\t请输入课程实验或上机学时:");
		scanf("%lf", &p->time_exp);
		printf("\n\t\t请输入课程最大容纳人数:");
		scanf("%d", &p->stu_max);
		printf("\n\t\t请输入课程学分:");
		scanf("%lf", &p->score);
		printf("\n\t\t请输入课程开课学期:");
		scanf("%s", p->term);
		while (getchar() != '\n');
		p->stu_sum = 0;
		if (cour_head == NULL)//链表中没有节点
		{
			p->next = NULL;
			cour_head = p;
			cour_tail = p;
		}
		else
		{
			if (strcmp(p->num, cour_head->num) < 0)       //新增课程编号小于最小编号
			{
				p->next = cour_head;
				cour_head = p;
			}
			else if (strcmp(p->num, cour_tail->num) > 0)  //新增课程编号大于最大编号
			{
				p->next = NULL;
				cour_tail->next = p;
				cour_tail = p;
			}
			else                                          //新增节点的标号在头节点和尾节点之间
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
		printf("\n\t\t课程信息录入成功!\n");
		courOutfile(cour_head);
	}
}

void courDel(course* head)
{
	course* p;
	char n[50];
	while (1)
	{
		printf("\n\t\t请输入要删除课程的编号或名称，取消删除请输入0000:");
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

		if (p == cour_tail)//没有该课程

		{
			printf("\n\t\t####没有该课程信息!####");
			continue;
		}
		printf("\n\t\t确定删除%s？[1]是 [0]否:", n);
		int in = 0;
		scanf("%d", &in);
		if (in == 1)
		{
			if (p == NULL)//链表头节点
			{
				if (head->next == NULL)
					cour_tail = NULL;
				course* temp = head;
				head = head->next;
				cour_head = head;
				free(temp);
			}
			else if (p->next == cour_tail)//链表尾节点
			{
				free(cour_tail);
				p->next = NULL;
				cour_tail = p;
			}
			else//链表中间节点
			{
				course* delete_point = p->next;
				p = p->next;
				p = p->next;
				free(delete_point);
			}
			printf("\n\t\t%s已经删除！\n", n);
		}
		else
			printf("\n\t\t#####未删除课程%s的信息!######\n", n);
		courOutfile(cour_head);
	}
}

void courModify(course* head)
{
	char n[100];
	course* find = NULL;
	while (1)
	{
		printf("\t\t请输入要修改课程的编号号或名称,取消修改请输入0000:");
		scanf("%s", n);
		while (getchar() != '\n');
		if (strcmp(n, "0000") == 0)
		{
			system("cls");
			manmenu();
		}
		if ((n[0] >= 48) && (n[0] <= 57))//按学号查找
			find = cournumFind(head, n);
		else//按姓名查找
			find = cournameFind(head, n);
		if (find == cour_tail)
		{
			printf("\n\t\t####你所查找的课程不存在！####");
			continue;
		}
		else
		{
			char temp[50];
			if (find == NULL)
				find = head;
			else
				find = find->next;
			printf("\n\t\t请分别输入需要修改的内容，若某一项不需要修改请输入0");
			printf("\n\t\t原名称:%s 修改后的名称：", find->name);

			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->name, temp);

			printf("\t\t原性质:%s 修改后的性质：", find->nature);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->nature, temp);

			printf("\t\t原开课学期:%s 修改后的开课学期：", find->term);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->term, temp);

			printf("\t\t原开课学院:%s 修改后的开课学院：", find->college);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				strcpy(find->college, temp);

			printf("\t\t原总学时:%.1lf 修改后的总学时：", find->time_all);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->time_all = atof(temp);

			printf("\t\t原授课学时:%.1lf 修改后的授课学时：", find->time_teach);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->time_teach = atof(temp);

			printf("\t\t原实验或上机学时:%.1lf 修改后的实验或上机学时：", find->time_exp);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->time_exp = atof(temp);

			printf("\t\t原课程学分:%.1lf 修改后的课程学分：", find->score);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->score = atof(temp);    //字符串转化为浮点数

			printf("\t\t原能容纳学生总数:%d 修改后的能容纳学生总数：", find->stu_max);
			scanf("%s", &temp);
			while (getchar() != '\n');
			if (strcmp(temp, "0") != 0)
				find->stu_max = atoi(temp);   //字符串转化为整型
			printf("\t\t修改完成！\n\n");
		}
		courOutfile(cour_head);
	}
}

void Print()
{
	while (1)
	{
		printf("\n\t\t选择操作类型: [1]打印所有学生信息 [2]打印所有课程信息 [0]返回主菜单:");
		int n = 0;
		scanf("%d", &n);
		while (getchar() != '\n');
		if (n == 1)
		{

			printf("\n\t\t学生总数：%d", linkCounts(stu_head));
			stusPrint(stu_head);
		}
		else if (n == 2)
		{
			printf("\n\t\t课程总数：%d\n", linkCountc(cour_head));
			coursPrint(cour_head);
		}
		else if (n == 0)
		{
			system("cls");
			manmenu();
		}
		else
			printf("\n\t\t####输入错误！请重新输入!#####\n");
	}
}

void keyModify()
{
	printf("\t\t******请输入原密码(10位):");
	char input[20];
	scanf("%s", input);
	while (getchar() != '\n');

	FILE* fp;
	if ((fp = fopen("manager.txt", "r")) == NULL)
	{
		printf("\t\t	无法打开文件:manager.txt\n");
		exit(0);
	}
	char keyOld[11];
	fread(keyOld, 10, 1, fp);
	keyOld[10] = '\0';
	if (strcmp(keyOld, input) == 0)//修改
	{
		fclose(fp);
		char new1[100];
		char new2[100];
		while (1)
		{
			printf("\t\t*******请输入新密码（10位）:");
			scanf("%s", new1);
			while (getchar() != '\n');
			printf("\t\t******请再次确认新密码（10位）:");
			scanf("%s", new2);
			while (getchar() != '\n');
			if (!strcmp(new1, new2))
			{
				fp = fopen("manager.txt", "w");
				fwrite(new1, 10, 1, fp);
				fclose(fp);
				printf("\n\t\t	密码修改成功!\n");
				system("pause");
				system("cls");
				manmenu();
			}
			else
				printf("\t\t####前后密码不一致，请重新输入！####\n");
		}
	}
	else
	{
		fclose(fp);
		printf("\t\t####原密码输入错误，请重新选择操作类型####\n");
	}
}

void backups_recover()
{
	printf("\t\t*****[1]数据备份 [2]数据恢复 [3]取消\n");
	printf("\t\t*****选择操作类型:");
	int n = 0;
	scanf("%d", &n);
	if (n == 1)
	{
		FILE* fp_source;
		FILE* fp_destination;

		//课程信息备份
		if ((fp_source = fopen("course.txt", "r")) == NULL)
		{
			printf("\t\t##课程数据备份失败：无法找到course.txt文件！##\n");
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

		//学生信息备份
		{
			if ((fp_source = fopen("student.txt", "r")) == NULL)
			{
				printf("\t\t##学生数据备份失败：无法找到student.txt文件！##\n");
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
		{//管理员信息备份
			if ((fp_source = fopen("manager.txt", "r")) == NULL)
			{
				printf("\t\t##管理员数据备份失败：无法找到manager.txt文件！##\n");
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
		printf("\n\t\t所有数据已经备份完毕！备份目录为student_backup.txt及course_backup.txt\n");
		system("pause");
		system("cls");
		manmenu();
	}
	else if (n == 2)
	{
		printf("\t\t选择恢复类型:[1]课程数据 [2]学生数据 [3]管理员数据:");
		int in = 0;
		scanf("%d", &in);
		while (getchar() != '\n');
		FILE* fp_source;
		FILE* fp_destination;

		if (in == 1)//course information recover
		{ //课程信息恢复
			if ((fp_source = fopen("course_backup.txt", "r")) == NULL)
			{
				printf("\t\t###课程信息恢复失败！未能找到course.txt###\n");
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
			printf("\n\t\t课程信息恢复成功！\n");
			cour_head = courInfile();
			cour_tail = endcLocate(cour_head);
		}
		else if (in == 2)
		{
			if ((fp_source = fopen("student_backup.txt", "r")) == NULL)
			{
				printf("\t\t###学生信息恢复失败！未能找到student.txt\n");
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
			printf("\n\t\t学生数据恢复成功！\n");
			stu_head = stuInfile();
			stu_tail = endsLocate(stu_head);
		}
		else if (in == 3)
		{
			if ((fp_source = fopen("manager_backup.txt", "r")) == NULL)
			{

				printf("\t\t###管理员数据恢复失败！未能找到manager.txt\n");
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
			printf("\n\t\t管理员数据恢复成功！\n");
		}
		else
			printf("\t\t###输入错误！###\n");
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
		printf("\t\t###输入错误，请重新输入!####\n");
	}
}

void stuFinding(student* head)
{
	while (1)
	{
		printf("\n\t\t请输入学号或姓名进行查找，返回上级菜单请输入0000：");
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
			printf("\n\t\t#####没有该学生的信息，请重新输入！#####/n");
			continue;
		}
		if (p_stu == NULL)
			p_stu = head;
		else
			p_stu = p_stu->next;
		printf("\n\t\t该学生信息如下：");
		stuPrint(p_stu);
	}
}

void courPrint_man(course* ad)
{
	if (ad == NULL)
	{
		printf("无课程\n");
	}
	else
	{
		printf("\n\t\t-------------------------------------");
		printf("\n\t\t 课 程 编 号 ：%s\n", ad->num);
		printf("\t\t 课 程 名 称 ：%s\n", ad->name);
		printf("\t\t 课 程 性 质 ：%s\n", ad->nature);
		printf("\t\t 开 课 学 期 ：%s\n", ad->term);
		printf("\t\t 总 学 时 :%lf\n", ad->time_all);
		printf("\t\t授课学时：%lf\n", ad->time_teach);
		printf("\t\t实验或上机学时：%lf\n", ad->time_exp);
		printf("\t\t学分：%lf\n", ad->score);
		printf("\t\t总容纳学生人数：%d\n", ad->stu_max);
		printf("\t\t已选学生人数：%d\n", ad->stu_sum);
		printf("\t\t已选学生：\n");
		if (ad->stu_sum == 0)
			printf("\t\t没有人选择该课程\n");
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
		printf("\t\t无课程\n");
		return;
	}
	while (p != NULL)
	{
		courPrint_man(p);
		p = p->next;
	}
}
