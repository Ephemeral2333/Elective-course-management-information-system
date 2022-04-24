#define MAXN 50

typedef struct students
{
	char name[MAXN];            //姓名
	char num[MAXN];             //学号
	char majorclass[20];        //专业班级
	double score_all;           //应选总学分
	double score_sel;           //已选总学分
	char password[9];           //密码,8位
	int course_sum;             //选课总数
	char college[MAXN];         //学生所在学院
	char course[MAXN][MAXN];    //记录选课课程的编号
	struct students* next;      //链表指针
}student;

typedef struct courses
{
	char num[MAXN];             //课程编号
	char name[MAXN];            //课程名称
	char nature[MAXN];          //课程性质
	char term[MAXN];            //开课学期
	double time_all;
	double time_teach;
	double time_exp;
	double score;
	int stu_max;
	int stu_sum;
	char college[MAXN];         //课程所在学院
	char stu[100][MAXN];
	struct courses* next;
}course;

student* stuInfile(); //将学生文件生成链表,返回链表头指针
void stuOutfile(student* p_head); //将学生链表存入学生文件,需传入链表头指针
course* courInfile(); //将课程文件生成链表，返回链表头指针
void courOutfile(course* p_head); //将课程链表存入课程文件，需传入链表头指针
student* endsLocate(student* head); //传入头节点，返回尾节点
course* endcLocate(course* head); //传入头节点，返回尾节点v
void help(); //显示帮助信息
int linkCounts(student* head);
int linkCountc(course* head); //计算链表节点数量

int manLogin(); //管理员登陆函数
void manmenu();
void manMenu(); //管理员主菜单，返回对应的输入值
void stuAdd(student* head); // 增 加 学 生 的 函 数 
void stuDel(student* head); //删除学生的函数
void stuFinding(student* head); //搜索学生的函数
void stuModify(student* head); //管理员修改学生信息
void courAdd(course* head); //增加课程的函数
void courDel(course* head); //删除课程的函数
void courModify(course* head); //修改课程信息的函数
void Print(); //打印所有学生和课程的函数
void keyModify(); //管理员修改密码
void backups_recover(); //管理员备份和恢复数据
void courPrint_man(course* ad); //管理员显示一门课程信息
void coursPrint_man(course* ad); //管理员显示所有课程信息

student* stuLogin(student* head); //学生登陆函数
void stuMenu(); //学生菜单，返回对应的输入值
void stuPrint(student* p); //显示一个学生的信息
void stusPrint(student* head); //显示所有学生的信息
student* stunameFind(student* head, char tar[]); //根据学生姓名查找学生，如果学生为头节点则返回空指针，不为头节点则返回前一个节点的指针，不存在则返回尾节点
student* stunumFind(student* head, char tar[]); //根据学生学号查找学生，如果学生为头节点则返回空指针，不为头节点则返回前一个节点的指针，不存在则返回尾节点
void stu_keyModify(student* stu); //学生修改密码
void courChoose(course* head, student* stu); //选课函数,min为最少要达到的学分
void showNature(course* head); //根据课程性质查找并显示课程信息
void showTerm(course* head); //根据开课学期查找并显示课程信息
void nat_teFind(course* head); //根据课程性质与开课学期组合查找课程信息
void numFind(course* head); //查课子函数
void nameFind(course* head); //查课子函数2
void delCourse(course* head, student* stu); //删除已选课程

void courPrint(course* ad); //显示一门的信息
void coursPrint(course* head); //显示所有课程的信息
void courFind(course* head); //搜索课程的函数
course* cournameFind(course* head, char tar[]); //根据课程名称查找课程节点，如果课程为头节点则返回空指针，不为头节点则返回前一个节点的指针，不存在则返回尾节点
course* cournumFind(course* head, char tar[]); //根据课程编号查找课程，如果课程为头节点则返回空指针，不为头节点则返回前一个节点的指针，不存在则返回尾节点
void GetPasswd(char passwd[], int min, int max);//获取密码
void webNet();//登录网页
