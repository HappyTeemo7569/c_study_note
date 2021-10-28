#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <curses.h>
#include <conio.h>
#include <time.h>
#define N 20

void input();//����ѧ����Ϣ
void del();//ɾ��ѧ����Ϣ
void change();//�޸�ѧ����Ϣ
void find();//��ѯѧ����Ϣ
void sorting();//����
void save();//���浽�ļ�
void read();//��ȡ�ļ�
void stu_search();//ѧ����ѯ��Ϣ
void modify();//ѧ���޸��Լ�����

struct score_stu//��������ṹ��
{
	int score1;
	int score2;
	int score3;
	int sum;
}score;

struct student //����ѧ���ṹ��
{
	int no;
	char name[20];
	char spwd[20];
	int classnum;
	struct score_stu score;
	int age;
	int ranking;
}stu[N],*p;

void inputPasswd(char passwd[])//��������
{
	char s[20];
	char temp[2];
	int n;
	//strcpy(s," ");
	s[0]='\0';
	while(1)
	{
		while(1)
		{
			n=getch();
			if(n == 13)//13Ϊ�س�'\r'
			{
				break;
			}
			printf("*");
			memset(temp,0,sizeof(temp));//��temp�����������0�滻
			sprintf(temp,"%c",n);//��n��ӡ��һ���ַ����浽temp����
			strcat(s,temp);//��temp��ָ�ַ�����ӵ�s��β��(����s��β����'\0')
		}
		break;
	}
	printf("\n");
	strcpy(passwd, s);
}

void captcha(char str[],int n)//��֤��
{
	char a[]="1234567890abcdefghijkmnopqrstuvwxyzABCDEFGHIJLMNPQRSTUVWXYZ";
	int i,j,k;
	k=strlen(a);//k��ʾ�ַ����ĳ���
	srand(time(0));//�������ʼ��
	for(i=0;i<n;i++)
	{
		j=rand()%k;//ȡ0-58�������
		str[i]=a[j];
	}
	str[i]='\0';
}

void admin()//����Ա����
{
	int choose1;
	printf("\t\t1:����ѧ����Ϣ\t2:ɾ��ѧ����Ϣ\t3:�޸�ѧ����Ϣ\t4:��ѯѧ����Ϣ\t5:����ѧ����Ϣ\t6:�˳�����\n");
	printf("\t\t");
	scanf("%d",&choose1);
	printf("\t\t=========================================================================================\n");
	fflush(stdin);
	switch(choose1)
	{
	case 1: input();break;
	case 2: del();break;
	case 3: change();break;
	case 4: find();break;
	case 5: sorting();break;
	case 6: printf("\t\t�˳��ɹ���\n");
		exit(0);
		break;
	default :
		printf("\t\t����ѡ��Ĳ�����������������������ѡ��\n");
		admin();
		break;
	}
}

void admin_login()//����Ա��¼
{
	static int i=0;
	int j=3;
	char username[10];
	char pwd[10];
	char code[N],str[N];
	printf("\t\t**********************************��ӭ�������Ա��¼����**********************************\n");
	printf("\t\t�������ʺţ�\n");
	printf("\t\t");
	gets(username);
	printf("\t\t=========================================================================================\n");
	printf("\t\t���������룺\n");
	printf("\t\t");
	inputPasswd(pwd);
	printf("\t\t=========================================================================================\n");
	fflush(stdin);
	if((strcmp(username,"admin")==0) &&(strcmp(pwd,"admin")==0))
	{
		while(1)
		{
			captcha(code,4);
			printf("\t\t��������֤�룺%s\n",code);
			printf("\t\t");
			scanf("%s",str);
			printf("\t\t=========================================================================================\n");
			if(strcmp(code,str)==0)
			{
				printf("\n\t\t ���ѳɹ���¼ \n ");
				printf("\t\t��ѡ����Ҫִ�еĲ�����\n");
				admin();
			}
			else
			{
				j--;
				if(j==0)
				{
					printf("\t\t����������࣬ϵͳ�Զ��˳�\n");
					exit(0);
				}
			}
		}
	}
	else
	{
		while(i<2)
		{
			printf("\n �û�����/��������Ч���������� \n ");
			i++;
			admin_login();
		}
		printf("��¼�������ޣ��Զ��˳���\n");
		exit(0);
	}
}

void  student(int userNO)//ѧ������
{
	int x;
	printf("\t\t1:��ѯ������Ϣ\t2:�޸�����\t3:�˳�\n");
	printf("\t\t");
	scanf("%d",&x);
	printf("\t\t=========================================================================================\n");
	switch(x)
	{
	case 1:stu_search(userNO);break;
	case 2:modify(userNO);break;
	case 3:printf("\t\t�˳��ɹ���\n");
		exit(0);break;
	default:printf("\t\t����ѡ�����Ŀ��������ѡ��");
		student(userNO);break;
	}


}

int  student_login()//ѧ����¼
{
	static int j=0;
	int i;
	int k=3;
	int userNO;
	char pwd[20];
	char code[N+1],str[N+1];
	printf("\t\t**********************************��ӭ����ѧ����¼����**********************************\n");
	printf("\t\t������ѧ�ţ�\n");
	printf("\t\t");
	fflush(stdin);
	scanf("%d",&userNO);
	printf("\t\t=========================================================================================\n");
	printf("\t\t���������룺\n");
	printf("\t\t");
	fflush(stdin);
	inputPasswd(pwd);
	printf("\t\t=========================================================================================\n");
	read();
	for(i=0;i<N;i++)
	{
		if((userNO == stu[i].no)&&(strcmp(pwd,stu[i].spwd)==0))
		{
			while(1)
			{
				captcha(code,4);
				printf("\t\t��������֤�룺%s\n",code);
				printf("\t\t");
				scanf("%s",str);
				printf("\t\t=========================================================================================\n");
				if(strcmp(code,str)==0)
				{
					printf("\t\t��¼�ɹ���\n");
					printf("\t\t��ѡ�������\n");
					student(userNO);
				}
				else
				{
					k--;
					if(k==0)
					{
						printf("\t\t����������࣬ϵͳ�Զ��˳�\n");
						exit(0);
					}
				}
			}
		}
		else
		{
			while(j<2)
			{
				printf("\t\t��¼ʧ�ܣ������µ�¼!\n");
				j++;
				student_login();
			}
			printf("\t\t��½�������ޣ�ϵͳ�Զ��˳���");
			exit(0);
		}
	}
	return userNO;
}

void stu_ranking()//��������
{
	int i,j;
	int count=1;
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		for(j=0;stu[j].no!=0;j++)
		{
			if(stu[i].score.sum<stu[j].score.sum)
			{
				count++;
			}
		}
		stu[i].ranking=count;
		count=1;
	}
	save();
}

void  stu_search(int userNO)//ѧ����ѯ������Ϣ
{
	int i,x;
	read();
	for(i=0;i<N;i++)
	{
		if(userNO == stu[i].no)
		{
			printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\n",stu[i].no,stu[i].name,stu[i].spwd,stu[i].classnum,
				stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,stu[i].score.sum,
				stu[i].age,stu[i].ranking);
			printf("\t\t=========================================================================================\n");
			printf("\t\t��ѡ���˳�ϵͳ�򷵻����˵�\n");
			printf("\t\t1:�������˵�\t2���˳�\n");
			printf("\t\t");
			scanf("%d",&x);
			printf("\t\t=========================================================================================\n");
			switch(x)
			{
			case 1:student(userNO);break;
			case 2:printf("\t\t�˳��ɹ�!\n");
				exit(0);
			}
		}
		else
		{
			printf("\t\t�������ϵͳ�Զ��������˵���\n");
			student(userNO);
		}
	}
}

void modify(int userNO)//ѧ���޸ĸ�������
{
	fflush(stdin);
	static int k=0;
	int i;
	char pwd_old[20];
	char pwd_new[20];
	char pwd_new1[20];
	read();
	for(i=0;i<N;i++)
	{
		if(userNO == stu[i].no)
		{
			printf("\t\t����������룺\n");
			printf("\t\t");
			gets(pwd_old);
			printf("\t\t=========================================================================================\n");
			if(strcmp(pwd_old,stu[i].spwd)==0)
			{
				printf("\t\t�����������룺\n");
				printf("\t\t");
				gets(pwd_new);
				printf("\t\t=========================================================================================\n");
				printf("\t\t���ٴ�����������:\n");
				printf("\t\t");
				gets(pwd_new1);
				printf("\t\t=========================================================================================\n");
				if(strcmp(pwd_new,pwd_new1)==0)
				{
					printf("\t\t�޸���ɣ�\n");
					strcpy(stu[i].spwd,pwd_new);
					printf("\t\t=========================================================================================\n");
					break;
				}
				else
				{
					while(1)
					{
						k++;
						if(k==3)
						{
							printf("\t\t����������࣬�Զ��������˵���\n");
							printf("\t\t=========================================================================================\n");
							student(userNO);
						}
						else
						{
							printf("\t\t�����������벻һ�� �����½��룡\n");
							printf("\t\t=========================================================================================\n");
							modify(userNO);
						}

					}
				}

			}
			else
			{
				printf("\t\t�������벻��ȷ���Զ��������˵�\n");
				printf("\t\t=========================================================================================\n");
				student(userNO);
			}
		}
	}
	save();
	student(userNO);
}

void input()//����ѧ����Ϣ
{
	char ch;
	int i,n,count= 0;
	printf("\t\t���������ѧ����Ϣ��������\n");
	printf("\t\t");
	scanf("%d",&n);
	printf("\t\t=========================================================================================\n");
	if(n<1||n>N)
	{
		printf("\t\t���벻�Ϸ������������룺\n");
		input();
	}
	printf("\t\t�����ѧ����Ϣ��\n");
	printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t����\n");
	read();
	for(i=0;i<N;i++)
	{
		if(count == n)
		{
			break;
		}
		if(stu[i].no==0)
		{
			fflush(stdin);
			printf("\t\t");
			scanf("%d%s%s%d%d%d%d%d",&stu[i].no,stu[i].name,stu[i].spwd,&stu[i].classnum,
				&stu[i].score.score1,&stu[i].score.score2,&stu[i].score.score3,&stu[i].age);
			stu[i].score.sum=stu[i].score.score1+stu[i].score.score2+stu[i].score.score3;
			count++;
		}
	}
	save();
	stu_ranking();
	printf("\t\t=========================================================================================\n");
	printf("\t\t���ѧ����Ϣ�ɹ���\n");
	printf("\t\t�Ƿ������(Y/N)\n");
	fflush(stdin);
	printf("\t\t");
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{
		input();
	}
	admin();
}

void del()//ɾ��ѧ����Ϣ
{
	fflush(stdin);
	int i,j;
	char ch;
	int  del_no;
	printf("\t\t��������Ҫɾ����¼��ID��\n");
	printf("\t\t");
	scanf("%d",&del_no);
	printf("\t\t=========================================================================================\n");
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		if(del_no == stu[i].no)
		{
			for(j=i;j<N-1;j++)
			{
				stu[j]=stu[j+1];
			}
		}
	}
	save();
	stu_ranking();
	printf("\t\t=========================================================================================\n");
	printf("\t\tɾ����Ϣ�ɹ���\n");
	printf("\t\t�Ƿ������(Y/N)\n");
	fflush(stdin);
	printf("\t\t");
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{
		del();
	}
	admin();
}

void change()//�޸�ѧ����Ϣ
{
	fflush(stdin);
	int i;
	char ch;
	int  change_no;
	printf("\t\t��������Ҫ�޸ļ�¼��ID��\n");
	printf("\t\t");
	scanf("%d",&change_no);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t����\n");
	for(i=0;stu[i].no!=0;i++)
	{
		if(change_no == stu[i].no)
		{
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,stu[i].age);
			printf("\t\t��������Ҫ�޸ĺ����Ϣ��\n");
			printf("\t\t=========================================================================================\n");
			printf("\t\t");
			scanf("%d%s%s%d%d%d%d%d",&stu[i].no,stu[i].name,stu[i].spwd,&stu[i].classnum,
				&stu[i].score.score1,&stu[i].score.score2,&stu[i].score.score3,&stu[i].age);
		}
		stu[i].score.sum=stu[i].score.score1+stu[i].score.score2+stu[i].score.score3;
	}
	save();
	stu_ranking();
	printf("\t\t=========================================================================================\n");
	printf("\t\t�޸�ѧ����Ϣ�ɹ���\n");
	printf("\t\t�Ƿ������(Y/N)\n");
	fflush(stdin);
	printf("\t\t");
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{
		change();
	}
	admin();
}

void find1()//��������ѯ
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	char find_name[20];
	printf("\t\t��������Ҫ��ѯ��ѧ��������\n");
	printf("\t\t");
	gets(find_name);
	printf("\t\t=========================================================================================\n");
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		if(strcmp(find_name,stu[i].name)==0)
		{
			printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
				stu[i].score.sum,stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t���������Ƿ������(Y/N)\n");
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find1();
		}
		else
		{
			find();
		}
	}
	else
	{
		printf("\t\t��ѯѧ����Ϣ�ɹ���\n");
		printf("\t\t�Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("=\t\t========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find1();
		}
		else
		{
			find();
		}
	}
}

void find2()//���ɼ�һ��ѯ
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int score;
	printf("\t\t��������Ҫ��ѯ�ĳɼ�һ����\n");
	printf("\t\t");
	scanf("%d",&score);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
	for(i=0;stu[i].no!=0;i++)
	{
		if(stu[i].score.score1 == score)
		{
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
				stu[i].score.sum,stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t���������Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find2();
		}
		else
		{

			find();
		}
	}
	else
	{
		printf("\t\t��ѯѧ����Ϣ�ɹ���\n");
		printf("\t\t�Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find2();
		}
		else
		{
			find();
		}
	}
}

void find3()//���ɼ�����ѯ
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int score;
	printf("\t\t��������Ҫ��ѯ�ĳɼ�������\n");
	printf("\t\t");
	scanf("%d",&score);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
	for(i=0;stu[i].no!=0;i++)
	{
		if(stu[i].score.score2 == score)
		{
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
				stu[i].score.sum,stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t���������Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find3();
		}
		else
		{

			find();
		}
	}
	else
	{
		printf("\t\t��ѯѧ����Ϣ�ɹ���\n");
		printf("\t\t�Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find3();
		}
		else
		{
			find();
		}
	}
}

void find4()//���ɼ�����ѯ
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int score;
	printf("\t\t��������Ҫ��ѯ�ĳɼ�������\n");
	printf("\t\t");
	scanf("%d",&score);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
	for(i=0;stu[i].no!=0;i++)
	{
		if(stu[i].score.score3 == score)
		{
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,stu[i].classnum,
				stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,stu[i].score.sum,
				stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t���������Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find4();
		}
		else
		{

			find();
		}
	}
	else
	{
		printf("\t\t��ѯѧ����Ϣ�ɹ���\n");
		printf("\t\t�Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		if(ch=='Y'||ch=='y')
		{
			find4();
		}
		else
		{
			find();
		}
	}
}

void find5()//��������ѯ
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int ranking;
	printf("\t\t��������Ҫ��ѯ��ѧ��������\n");
	printf("\t\t");
	scanf("%d",&ranking);
	printf("\t\t=========================================================================================\n");
	read();

	for(i=0;stu[i].no!=0;i++)
	{
		if(ranking==stu[i].ranking)
		{
			printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
				stu[i].score.sum,stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t���������Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find5();
		}
		else
		{
			find();
		}
	}
	else
	{
		printf("\t\t��ѯѧ����Ϣ�ɹ���\n");
		printf("\t\t�Ƿ������(Y/N)\n");
		fflush(stdin);
		printf("\t\t");
		scanf("%c",&ch);
		printf("\t\t=========================================================================================\n");
		if(ch=='Y'||ch=='y')
		{
			find5();
		}
		else
		{
			find();
		}
	}
}

void find6()//ȫ����ѯ
{
	int i,j;
	read();
	printf("\t\tѧ��\t����\t����\t�༶\t�ɼ�һ\t�ɼ���\t�ɼ���\t�ܷ�\t����\t����\n");
	for(i=0;stu[i].no!=0;i++)
	{
		printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
			stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
			stu[i].score.sum,stu[i].age,stu[i].ranking);
	}
	printf("\t\t������һ�������˳�?(1,����|2,�˳�)\n\n");
	printf("\t\t");
	scanf("%d",&j);
	printf("\t\t=========================================================================================\n");
	if(j==1)
	{
		find();
	}
	else
	{
		exit(0);
	}
}

void find()//��ѯѧ����Ϣ
{
	int choose2;
	printf("\t\tѡ����Ҫ��ѯ�ķ�ʽ��\n");
	printf("\t\t0:����������ѯ\t1:���ݵ��Ƴɼ�һ��ѯ\t2:���ݵ��Ƴɼ�����ѯ\t3�����ݵ��Ƴɼ�����ѯ\n");
	printf("\t\t4:��������\t5:ȫ����ѯ\t6:�������˵�\n");
	printf("\t\t");
	scanf("%d",&choose2);
	printf("\t\t=========================================================================================\n");
	switch(choose2)
	{
	case 0:find1();break;
	case 1:find2();break;
	case 2:find3();break;
	case 3:find4();break;
	case 4:find5();break;
	case 5:find6();break;
	case 6:admin();break;
	default :
		printf("\t\t����ѡ��Ĳ�����������������������ѡ��\n");
		find();
	}
}

void sorting1()//����������
{
	int i,j;
	struct student temp;
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		for(j=i;stu[j].no!=0;j++)
		{
			if(strcmp(stu[i].name,stu[j].name)==1)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	save();
	stu_ranking();
	printf("\t\t����ɹ���\n");
	printf("\t\t=========================================================================================\n\n");
	sorting();
}

void sorting2()//���ɼ�һ����
{
	int i,j;
	struct student temp;
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		for(j=i;stu[j].no!=0;j++)
		{
			if(stu[i].score.score1<stu[j].score.score1)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	save();
	stu_ranking();
	printf("\t\t����ɹ���\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void sorting3()//���ɼ�������
{
	int i,j;
	struct student temp;
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		for(j=i;stu[j].no!=0;j++)
		{
			if(stu[i].score.score2<stu[j].score.score2)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	save();
	stu_ranking();
	printf("\t\t����ɹ���\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void sorting4()//���ɼ�������
{
	int i,j;
	struct student temp;
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		for(j=i;stu[j].no!=0;j++)
		{
			if(stu[i].score.score3<stu[j].score.score3)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	save();
	stu_ranking();
	printf("\t\t����ɹ���\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void sorting5()//����������
{
	int i,j;
	struct student temp;
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		for(j=i;stu[j].no!=0;j++)
		{
			if(stu[i].ranking>stu[j].ranking)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	save();
	stu_ranking();
	printf("\t\t����ɹ���\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void  sorting()//����ѧ����Ϣ
{
	int choose3;
	printf("\t\t��ѡ������ķ�ʽ\n");
	printf("\t\t0:������������\t1:���ݵ��Ƴɼ�һ����\t2:���ݵ��Ƴɼ�������\t3:���ݵ��Ƴɼ�������\n\t\t4:����������������\t5:�������˵�\n");
	printf("\t\t");
	scanf("%d",&choose3);
	printf("\t\t=========================================================================================\n");
	switch(choose3)
	{
	case 0: sorting1();break;
	case 1: sorting2();break;
	case 2: sorting3();break;
	case 3: sorting4();break;
	case 4: sorting5();break;
	case 5: admin();break;
	default :
		printf("\t\t����ѡ��Ĳ�����������������������ѡ��\n");
		sorting();
	}

}

void save()//����������Ϣ
{
	int i;
	FILE *fp;
	fp=fopen("C:\\Users\\Administrator\\Desktop\\student.txt","wb+");
	for(i=0;stu[i].no!=0;i++)
	{
		fwrite(&stu[i],sizeof(struct student),1,fp);
	}
	fclose(fp);
}

void  read()//�����ļ�����Ϣ
{
	FILE *fp;
	fp=fopen("C:\\Users\\Administrator\\Desktop\\student.txt","rb");
	fread(&stu[0],sizeof(struct student),N,fp);
	fclose(fp);
}
void title()//��ʼ����
{
	printf("\t\t\t\t\t��Ŀ���ƣ�C�����µ�ѧ������ϵͳ\n");
}
int main()//������
{
	title();
	system("pause");
	system("cls");
	int userNO;
	int choose;
	printf("\t\t**********************************C�����µ�ѧ������ϵͳ**********************************\n");
	printf("\t\t��ã�����ѡ���¼��ݣ�\n");
	printf("\t\t0:����Ա\t 1:ѧ�� \t2:�˳�\n");
	printf("\t\t");
	scanf("%d",&choose);
	fflush(stdin);
	switch(choose)
	{
	case 0:
		{
			admin_login();
			break;
		}
	case 1:
		{
			userNO = student_login();
			student(userNO);
			break;
		}
	case 2:printf("\t\t�˳��ɹ�!\n");
		break;
	default :printf("\t\t��ѡ�����ݲ���ȷ��������ѡ��\n\n\n");
		main();break;
	}
	return 0;
}




