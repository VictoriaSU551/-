//���¹������
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100  //ÿ��������������

//һ���˵ĵ���
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

//һ������
struct Department
{
	struct People sp[MAX];
	int n;  //��ǰ��������
};

//����1����ӡ���˵�
void print_main_menu()
{
	printf("    ���¹���ϵͳ     \n");
	printf("*********************\n");
	printf("1.�����Ա��Ϣ\n");
	printf("2.��ʾ������Ա��Ϣ\n");
	printf("3.��ѯ��Ա��Ϣ\n");
	printf("4.ɾ����Ա��Ϣ\n");
	printf("5.�޸���Ա��Ϣ\n");
	printf("6.�˳�\n");
	printf("*********************\n");
	printf("������ѡ�����ţ�\n");
}

//����2�������Ա��Ϣ
void add_people(struct Department* peo)
{
	printf("������������\n");
	scanf("%s", peo->sp[peo->n].name);
	printf("�����벿�ţ�\n");
	scanf("%s", peo->sp[peo->n].dept);
	printf("�����뼮�᣺\n");
	scanf("%s", peo->sp[peo->n].homt);
	printf("��������������գ�\n");
	scanf("%s", peo->sp[peo->n].birdy);
	printf("������ѧ����\n");
	scanf("%s", peo->sp[peo->n].edu);
	printf("������ְ��\n");
	scanf("%s", peo->sp[peo->n].job);
	printf("�����빤�ʣ�\n");
	scanf("%d", &peo->sp[peo->n].salary);  //�����������������ַ�����������
	printf("�����뽱�ͼ�¼��\n");
	scanf("%s", peo->sp[peo->n].recd);

	peo->n++;  //��������+1
}

//����3����ʾ��Ա��Ϣ
void show_people(struct Department* peo)
{
	int i;
	for (i = 0; i < peo->n; i++)
	{
		printf("������%s\n",peo->sp[i].name);
		printf("���ţ�%s\n", peo->sp[i].dept);
		printf("���᣺%s\n", peo->sp[i].homt);
		printf("���������գ�%s\n", peo->sp[i].birdy);
		printf("ѧ����%s\n", peo->sp[i].edu);
		printf("ְ��%s\n", peo->sp[i].job);
		printf("���ʣ�%d\n", peo->sp[i].salary);
		printf("���ͼ�¼��%s\n", peo->sp[i].recd);
	}
}

//����4����������������Ա��Ϣ
char find_people(struct Department* peo)
{
	int i;
	char name[20];
	printf("������Ҫ���ҵ���Ա��������\n");
	scanf("%s", name);
	for (i = 0; i < peo->n; i++)
	{
		if (!strcmp(name,peo->sp[i].name))
		{
			printf("������%s\n", peo->sp[i].name);
			printf("���ţ�%s\n", peo->sp[i].dept);
			printf("���᣺%s\n", peo->sp[i].homt);
			printf("���������գ�%s\n", peo->sp[i].birdy);
			printf("ѧ����%s\n", peo->sp[i].edu);
			printf("ְ��%s\n", peo->sp[i].job);
			printf("���ʣ�%d\n", peo->sp[i].salary);
			printf("���ͼ�¼��%s\n", peo->sp[i].recd);
			return i;
		}
	}
	printf("���˲�����\n");
	return -1;
}

//����5��ɾ��ָ����Ա
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
	printf("��ɾ��\n");
}

//����6���޸���Ϣ
void change_people(struct Department* peo)
{
	int ret, choose;
	ret = find_people(peo);
	if (ret != -1)
	{
	loop1:
		printf("�޸���һ�\n");
		printf("1.����\n");
		printf("2.����\n");
		printf("3.����\n");
		printf("4.����������\n");
		printf("5.ѧ��\n");
		printf("6.ְ��\n");
		printf("7.����\n");
		printf("8.���ͼ�¼\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("��������������\n");
			scanf("%s", peo->sp[ret].name);
			break;
		case 2:
			printf("�������²��ţ�\n");
			scanf("%s", peo->sp[ret].dept);
			break;
		case 3:
			printf("�������¼��᣺\n");
			scanf("%s", peo->sp[ret].homt);
			break;
		case 4:
			printf("�������³��������գ�\n");
			scanf("%s", peo->sp[ret].birdy);
			break;
		case 5:
			printf("��������ѧ����\n");
			scanf("%s", peo->sp[ret].edu);
			break;
		case 6:
			printf("��������ְ��\n");
			scanf("%s", peo->sp[ret].job);
			break;
		case 7:
			printf("�������¹��ʣ�\n");
			scanf("%d", &peo->sp[ret].salary);
			break;
		case 8:
			printf("�������½��ͼ�¼��\n");
			scanf("%s", peo->sp[ret].recd);
			break;
		default:
			printf("�����������������\n");
			goto loop1;
		}
	}
	printf("�޸ĳɹ�");
}

//������
int main()
{
	struct Department peo;  //����һ������peo������
	peo.n = 0;  //��ʼ�����ʼû����
	while (1)  //����ѭ��
	{
	loop:
		print_main_menu();
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			add_people(&peo);  //���
			break;
		case 2:
			show_people(&peo);  //��ʾȫ��
			break;
		case 3:
			find_people(&peo);  //����
			break;
		case 4:
			remove_people(&peo);  //ɾ��
			break;
		case 5:
			change_people(&peo);  //�޸�
			break;
		case 6:
			return 0;  //�˳�
		default:
			printf("�����������������\n");
			goto loop;
		}
	}
}