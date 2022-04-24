#define MAXN 50

typedef struct students
{
	char name[MAXN];            //����
	char num[MAXN];             //ѧ��
	char majorclass[20];        //רҵ�༶
	double score_all;           //Ӧѡ��ѧ��
	double score_sel;           //��ѡ��ѧ��
	char password[9];           //����,8λ
	int course_sum;             //ѡ������
	char college[MAXN];         //ѧ������ѧԺ
	char course[MAXN][MAXN];    //��¼ѡ�ογ̵ı��
	struct students* next;      //����ָ��
}student;

typedef struct courses
{
	char num[MAXN];             //�γ̱��
	char name[MAXN];            //�γ�����
	char nature[MAXN];          //�γ�����
	char term[MAXN];            //����ѧ��
	double time_all;
	double time_teach;
	double time_exp;
	double score;
	int stu_max;
	int stu_sum;
	char college[MAXN];         //�γ�����ѧԺ
	char stu[100][MAXN];
	struct courses* next;
}course;

student* stuInfile(); //��ѧ���ļ���������,��������ͷָ��
void stuOutfile(student* p_head); //��ѧ���������ѧ���ļ�,�贫������ͷָ��
course* courInfile(); //���γ��ļ�����������������ͷָ��
void courOutfile(course* p_head); //���γ��������γ��ļ����贫������ͷָ��
student* endsLocate(student* head); //����ͷ�ڵ㣬����β�ڵ�
course* endcLocate(course* head); //����ͷ�ڵ㣬����β�ڵ�v
void help(); //��ʾ������Ϣ
int linkCounts(student* head);
int linkCountc(course* head); //��������ڵ�����

int manLogin(); //����Ա��½����
void manmenu();
void manMenu(); //����Ա���˵������ض�Ӧ������ֵ
void stuAdd(student* head); // �� �� ѧ �� �� �� �� 
void stuDel(student* head); //ɾ��ѧ���ĺ���
void stuFinding(student* head); //����ѧ���ĺ���
void stuModify(student* head); //����Ա�޸�ѧ����Ϣ
void courAdd(course* head); //���ӿγ̵ĺ���
void courDel(course* head); //ɾ���γ̵ĺ���
void courModify(course* head); //�޸Ŀγ���Ϣ�ĺ���
void Print(); //��ӡ����ѧ���Ϳγ̵ĺ���
void keyModify(); //����Ա�޸�����
void backups_recover(); //����Ա���ݺͻָ�����
void courPrint_man(course* ad); //����Ա��ʾһ�ſγ���Ϣ
void coursPrint_man(course* ad); //����Ա��ʾ���пγ���Ϣ

student* stuLogin(student* head); //ѧ����½����
void stuMenu(); //ѧ���˵������ض�Ӧ������ֵ
void stuPrint(student* p); //��ʾһ��ѧ������Ϣ
void stusPrint(student* head); //��ʾ����ѧ������Ϣ
student* stunameFind(student* head, char tar[]); //����ѧ����������ѧ�������ѧ��Ϊͷ�ڵ��򷵻ؿ�ָ�룬��Ϊͷ�ڵ��򷵻�ǰһ���ڵ��ָ�룬�������򷵻�β�ڵ�
student* stunumFind(student* head, char tar[]); //����ѧ��ѧ�Ų���ѧ�������ѧ��Ϊͷ�ڵ��򷵻ؿ�ָ�룬��Ϊͷ�ڵ��򷵻�ǰһ���ڵ��ָ�룬�������򷵻�β�ڵ�
void stu_keyModify(student* stu); //ѧ���޸�����
void courChoose(course* head, student* stu); //ѡ�κ���,minΪ����Ҫ�ﵽ��ѧ��
void showNature(course* head); //���ݿγ����ʲ��Ҳ���ʾ�γ���Ϣ
void showTerm(course* head); //���ݿ���ѧ�ڲ��Ҳ���ʾ�γ���Ϣ
void nat_teFind(course* head); //���ݿγ������뿪��ѧ����ϲ��ҿγ���Ϣ
void numFind(course* head); //����Ӻ���
void nameFind(course* head); //����Ӻ���2
void delCourse(course* head, student* stu); //ɾ����ѡ�γ�

void courPrint(course* ad); //��ʾһ�ŵ���Ϣ
void coursPrint(course* head); //��ʾ���пγ̵���Ϣ
void courFind(course* head); //�����γ̵ĺ���
course* cournameFind(course* head, char tar[]); //���ݿγ����Ʋ��ҿγ̽ڵ㣬����γ�Ϊͷ�ڵ��򷵻ؿ�ָ�룬��Ϊͷ�ڵ��򷵻�ǰһ���ڵ��ָ�룬�������򷵻�β�ڵ�
course* cournumFind(course* head, char tar[]); //���ݿγ̱�Ų��ҿγ̣�����γ�Ϊͷ�ڵ��򷵻ؿ�ָ�룬��Ϊͷ�ڵ��򷵻�ǰһ���ڵ��ָ�룬�������򷵻�β�ڵ�
void GetPasswd(char passwd[], int min, int max);//��ȡ����
void webNet();//��¼��ҳ
