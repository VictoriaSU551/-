//人事管理程序
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100  //每个部门最多的人数

//一个人的档案
struct People
{
	char name[20];
	char dept[20];
	char homt[20];
	char birdy[10];
	char edu[10];
	char job[20];
	int salary;
	char recd[30];
};

//一个部门
struct Department
{
	struct People sp[MAX];
	int n;  //当前部门人数
};

//函数1：打印主菜单
void print_main_menu()
{
	printf("    人事管理系统     \n");
	printf("*********************\n");
	printf("1.添加人员信息\n");
	printf("2.显示所有人员信息\n");
	printf("3.查询人员信息\n");
	printf("4.删除人员信息\n");
	printf("5.修改人员信息\n");
	printf("6.退出\n");
	printf("*********************\n");
	printf("请输入选择的序号：\n");
}

//函数2：添加人员信息
void add_people(struct Department* peo)
{
	printf("请输入姓名：\n");
	scanf("%s", peo->sp[peo->n].name);
	printf("请输入部门：\n");
	scanf("%s", peo->sp[peo->n].dept);
	printf("请输入籍贯：\n");
	scanf("%s", peo->sp[peo->n].homt);
	printf("请输入出生年月日：\n");
	scanf("%s", peo->sp[peo->n].birdy);
	printf("请输入学历：\n");
	scanf("%s", peo->sp[peo->n].edu);
	printf("请输入职务：\n");
	scanf("%s", peo->sp[peo->n].job);
	printf("请输入工资：\n");
	scanf("%d", &peo->sp[peo->n].salary);  //其他都是数组名表地址，但这个不是
	printf("请输入奖惩记录：\n");
	scanf("%s", peo->sp[peo->n].recd);

	peo->n++;  //部门人数+1
}

//函数3：显示人员信息
void show_people(struct Department* peo)
{
	int i;
	for (i = 0; i < peo->n; i++)
	{
		printf("姓名：%s\n",peo->sp[i].name);
		printf("部门：%s\n", peo->sp[i].dept);
		printf("籍贯：%s\n", peo->sp[i].homt);
		printf("出生年月日：%s\n", peo->sp[i].birdy);
		printf("学历：%s\n", peo->sp[i].edu);
		printf("职务：%s\n", peo->sp[i].job);
		printf("工资：%d\n", peo->sp[i].salary);
		printf("奖惩记录：%s\n", peo->sp[i].recd);
	}
}

//函数4：根据姓名查找人员信息
char find_people(struct Department* peo)
{
	int i;
	char name[20];
	printf("请输入要查找的人员的姓名：\n");
	scanf("%s", name);
	for (i = 0; i < peo->n; i++)
	{
		if (!strcmp(name,peo->sp[i].name))
		{
			printf("姓名：%s\n", peo->sp[i].name);
			printf("部门：%s\n", peo->sp[i].dept);
			printf("籍贯：%s\n", peo->sp[i].homt);
			printf("出生年月日：%s\n", peo->sp[i].birdy);
			printf("学历：%s\n", peo->sp[i].edu);
			printf("职务：%s\n", peo->sp[i].job);
			printf("工资：%d\n", peo->sp[i].salary);
			printf("奖惩记录：%s\n", peo->sp[i].recd);
			return i;
		}
	}
	printf("此人不存在\n");
	return -1;
}

//函数5：删除指定人员
void remove_people(struct Department* peo)
{
	int ret, i;
	ret = find_people(peo);
	if (ret != -1)
	{
		for (i = ret; i < peo->n - 1; i++)
		{
			strcpy(peo->sp[i].name, peo->sp[i + 1].name);
			strcpy(peo->sp[i].dept, peo->sp[i + 1].dept);
			strcpy(peo->sp[i].homt, peo->sp[i + 1].homt);
			strcpy(peo->sp[i].birdy, peo->sp[i + 1].birdy);
			strcpy(peo->sp[i].edu, peo->sp[i + 1].edu);
			strcpy(peo->sp[i].job, peo->sp[i + 1].job);
			peo->sp[i].salary = peo->sp[i + 1].salary;
			strcpy(peo->sp[i].recd, peo->sp[i + 1].recd);
		}
		peo->n--;
	}
	printf("已删除\n");
}

//函数6：修改信息
void change_people(struct Department* peo)
{
	int ret, choose;
	ret = find_people(peo);
	if (ret != -1)
	{
	loop1:
		printf("修改哪一项？\n");
		printf("1.姓名\n");
		printf("2.部门\n");
		printf("3.籍贯\n");
		printf("4.出生年月日\n");
		printf("5.学历\n");
		printf("6.职务\n");
		printf("7.工资\n");
		printf("8.奖惩记录\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("请输入新姓名：\n");
			scanf("%s", peo->sp[ret].name);
			break;
		case 2:
			printf("请输入新部门：\n");
			scanf("%s", peo->sp[ret].dept);
			break;
		case 3:
			printf("请输入新籍贯：\n");
			scanf("%s", peo->sp[ret].homt);
			break;
		case 4:
			printf("请输入新出生年月日：\n");
			scanf("%s", peo->sp[ret].birdy);
			break;
		case 5:
			printf("请输入新学历：\n");
			scanf("%s", peo->sp[ret].edu);
			break;
		case 6:
			printf("请输入新职务：\n");
			scanf("%s", peo->sp[ret].job);
			break;
		case 7:
			printf("请输入新工资：\n");
			scanf("%d", &peo->sp[ret].salary);
			break;
		case 8:
			printf("请输入新奖惩记录：\n");
			scanf("%s", peo->sp[ret].recd);
			break;
		default:
			printf("输出错误，请重新输入\n");
			goto loop1;
		}
	}
	printf("修改成功");
}

//主函数
int main()
{
	struct Department peo;  //定义一个部门peo来存人
	peo.n = 0;  //初始化，最开始没有人
	while (1)  //无限循环
	{
	loop:
		print_main_menu();
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			add_people(&peo);  //添加
			break;
		case 2:
			show_people(&peo);  //显示全部
			break;
		case 3:
			find_people(&peo);  //查找
			break;
		case 4:
			remove_people(&peo);  //删除
			break;
		case 5:
			change_people(&peo);  //修改
			break;
		case 6:
			return 0;  //退出
		default:
			printf("输出错误，请重新输入\n");
			goto loop;
		}
	}
}