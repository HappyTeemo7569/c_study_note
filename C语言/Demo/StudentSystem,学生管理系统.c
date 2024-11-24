#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <curses.h>
#include <conio.h>
#include <time.h>
#define N 20

void input();//增加学生信息
void del();//删除学生信息
void change();//修改学生信息
void find();//查询学生信息
void sorting();//排序
void save();//保存到文件
void read();//读取文件
void stu_search();//学生查询信息
void modify();//学生修改自己密码

struct score_stu//定义分数结构体
{
	int score1;
	int score2;
	int score3;
	int sum;
}score;

struct student //定义学生结构体
{
	int no;
	char name[20];
	char spwd[20];
	int classnum;
	struct score_stu score;
	int age;
	int ranking;
}stu[N],*p;

void inputPasswd(char passwd[])//隐藏密码
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
			if(n == 13)//13为回车'\r'
			{
				break;
			}
			printf("*");
			memset(temp,0,sizeof(temp));//将temp里面的数据用0替换
			sprintf(temp,"%c",n);//将n打印成一个字符保存到temp里面
			strcat(s,temp);//把temp所指字符串添加到s结尾处(覆盖s结尾处的'\0')
		}
		break;
	}
	printf("\n");
	strcpy(passwd, s);
}

void captcha(char str[],int n)//验证码
{
	char a[]="1234567890abcdefghijkmnopqrstuvwxyzABCDEFGHIJLMNPQRSTUVWXYZ";
	int i,j,k;
	k=strlen(a);//k表示字符串的长度
	srand(time(0));//随机数初始化
	for(i=0;i<n;i++)
	{
		j=rand()%k;//取0-58的随机数
		str[i]=a[j];
	}
	str[i]='\0';
}

void admin()//管理员操作
{
	int choose1;
	printf("\t\t1:增加学生信息\t2:删除学生信息\t3:修改学生信息\t4:查询学生信息\t5:排序学生信息\t6:退出程序\n");
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
	case 6: printf("\t\t退出成功！\n");
		exit(0);
		break;
	default :
		printf("\t\t你所选择的操作不是上述操作，请重新选择\n");
		admin();
		break;
	}
}

void admin_login()//管理员登录
{
	static int i=0;
	int j=3;
	char username[10];
	char pwd[10];
	char code[N],str[N];
	printf("\t\t**********************************欢迎进入管理员登录界面**********************************\n");
	printf("\t\t请输入帐号：\n");
	printf("\t\t");
	gets(username);
	printf("\t\t=========================================================================================\n");
	printf("\t\t请输入密码：\n");
	printf("\t\t");
	inputPasswd(pwd);
	printf("\t\t=========================================================================================\n");
	fflush(stdin);
	if((strcmp(username,"admin")==0) &&(strcmp(pwd,"admin")==0))
	{
		while(1)
		{
			captcha(code,4);
			printf("\t\t请输入验证码：%s\n",code);
			printf("\t\t");
			scanf("%s",str);
			printf("\t\t=========================================================================================\n");
			if(strcmp(code,str)==0)
			{
				printf("\n\t\t 您已成功登录 \n ");
				printf("\t\t请选择你要执行的操作：\n");
				admin();
			}
			else
			{
				j--;
				if(j==0)
				{
					printf("\t\t错误次数过多，系统自动退出\n");
					exit(0);
				}
			}
		}
	}
	else
	{
		while(i<2)
		{
			printf("\n 用户名和/或密码无效请重新输入 \n ");
			i++;
			admin_login();
		}
		printf("登录次数超限，自动退出！\n");
		exit(0);
	}
}

void  student(int userNO)//学生操作
{
	int x;
	printf("\t\t1:查询个人信息\t2:修改密码\t3:退出\n");
	printf("\t\t");
	scanf("%d",&x);
	printf("\t\t=========================================================================================\n");
	switch(x)
	{
	case 1:stu_search(userNO);break;
	case 2:modify(userNO);break;
	case 3:printf("\t\t退出成功！\n");
		exit(0);break;
	default:printf("\t\t你所选择的项目错误！重新选择！");
		student(userNO);break;
	}


}

int  student_login()//学生登录
{
	static int j=0;
	int i;
	int k=3;
	int userNO;
	char pwd[20];
	char code[N+1],str[N+1];
	printf("\t\t**********************************欢迎进入学生登录界面**********************************\n");
	printf("\t\t请输入学号：\n");
	printf("\t\t");
	fflush(stdin);
	scanf("%d",&userNO);
	printf("\t\t=========================================================================================\n");
	printf("\t\t请输入密码：\n");
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
				printf("\t\t请输入验证码：%s\n",code);
				printf("\t\t");
				scanf("%s",str);
				printf("\t\t=========================================================================================\n");
				if(strcmp(code,str)==0)
				{
					printf("\t\t登录成功！\n");
					printf("\t\t请选择操作！\n");
					student(userNO);
				}
				else
				{
					k--;
					if(k==0)
					{
						printf("\t\t错误次数过多，系统自动退出\n");
						exit(0);
					}
				}
			}
		}
		else
		{
			while(j<2)
			{
				printf("\t\t登录失败，请重新登录!\n");
				j++;
				student_login();
			}
			printf("\t\t登陆次数超限！系统自动退出！");
			exit(0);
		}
	}
	return userNO;
}

void stu_ranking()//计算排名
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

void  stu_search(int userNO)//学生查询个人信息
{
	int i,x;
	read();
	for(i=0;i<N;i++)
	{
		if(userNO == stu[i].no)
		{
			printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\n",stu[i].no,stu[i].name,stu[i].spwd,stu[i].classnum,
				stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,stu[i].score.sum,
				stu[i].age,stu[i].ranking);
			printf("\t\t=========================================================================================\n");
			printf("\t\t请选择退出系统或返回主菜单\n");
			printf("\t\t1:返回主菜单\t2：退出\n");
			printf("\t\t");
			scanf("%d",&x);
			printf("\t\t=========================================================================================\n");
			switch(x)
			{
			case 1:student(userNO);break;
			case 2:printf("\t\t退出成功!\n");
				exit(0);
			}
		}
		else
		{
			printf("\t\t输入错误，系统自动返回主菜单！\n");
			student(userNO);
		}
	}
}

void modify(int userNO)//学生修改个人密码
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
			printf("\t\t请输入旧密码：\n");
			printf("\t\t");
			gets(pwd_old);
			printf("\t\t=========================================================================================\n");
			if(strcmp(pwd_old,stu[i].spwd)==0)
			{
				printf("\t\t请输入新密码：\n");
				printf("\t\t");
				gets(pwd_new);
				printf("\t\t=========================================================================================\n");
				printf("\t\t请再次输入新密码:\n");
				printf("\t\t");
				gets(pwd_new1);
				printf("\t\t=========================================================================================\n");
				if(strcmp(pwd_new,pwd_new1)==0)
				{
					printf("\t\t修改完成！\n");
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
							printf("\t\t错误次数过多，自动返回主菜单！\n");
							printf("\t\t=========================================================================================\n");
							student(userNO);
						}
						else
						{
							printf("\t\t输入两次密码不一致 请重新进入！\n");
							printf("\t\t=========================================================================================\n");
							modify(userNO);
						}

					}
				}

			}
			else
			{
				printf("\t\t密码输入不正确！自动返回主菜单\n");
				printf("\t\t=========================================================================================\n");
				student(userNO);
			}
		}
	}
	save();
	student(userNO);
}

void input()//增加学生信息
{
	char ch;
	int i,n,count= 0;
	printf("\t\t请输入添加学生信息的条数：\n");
	printf("\t\t");
	scanf("%d",&n);
	printf("\t\t=========================================================================================\n");
	if(n<1||n>N)
	{
		printf("\t\t输入不合法，请重新输入：\n");
		input();
	}
	printf("\t\t请添加学生信息：\n");
	printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t年龄\n");
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
	printf("\t\t添加学生信息成功！\n");
	printf("\t\t是否继续？(Y/N)\n");
	fflush(stdin);
	printf("\t\t");
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{
		input();
	}
	admin();
}

void del()//删除学生信息
{
	fflush(stdin);
	int i,j;
	char ch;
	int  del_no;
	printf("\t\t请输入想要删除记录的ID：\n");
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
	printf("\t\t删除信息成功！\n");
	printf("\t\t是否继续？(Y/N)\n");
	fflush(stdin);
	printf("\t\t");
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{
		del();
	}
	admin();
}

void change()//修改学生信息
{
	fflush(stdin);
	int i;
	char ch;
	int  change_no;
	printf("\t\t请输入想要修改记录的ID：\n");
	printf("\t\t");
	scanf("%d",&change_no);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t年龄\n");
	for(i=0;stu[i].no!=0;i++)
	{
		if(change_no == stu[i].no)
		{
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,stu[i].age);
			printf("\t\t请输入你要修改后的信息！\n");
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
	printf("\t\t修改学生信息成功！\n");
	printf("\t\t是否继续？(Y/N)\n");
	fflush(stdin);
	printf("\t\t");
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{
		change();
	}
	admin();
}

void find1()//按姓名查询
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	char find_name[20];
	printf("\t\t请输入想要查询的学生姓名：\n");
	printf("\t\t");
	gets(find_name);
	printf("\t\t=========================================================================================\n");
	read();
	for(i=0;stu[i].no!=0;i++)
	{
		if(strcmp(find_name,stu[i].name)==0)
		{
			printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
				stu[i].score.sum,stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t操作错误是否继续？(Y/N)\n");
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
		printf("\t\t查询学生信息成功！\n");
		printf("\t\t是否继续？(Y/N)\n");
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

void find2()//按成绩一查询
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int score;
	printf("\t\t请输入你要查询的成绩一分数\n");
	printf("\t\t");
	scanf("%d",&score);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
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
		printf("\t\t操作错误是否继续？(Y/N)\n");
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
		printf("\t\t查询学生信息成功！\n");
		printf("\t\t是否继续？(Y/N)\n");
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

void find3()//按成绩二查询
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int score;
	printf("\t\t请输入你要查询的成绩二分数\n");
	printf("\t\t");
	scanf("%d",&score);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
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
		printf("\t\t操作错误是否继续？(Y/N)\n");
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
		printf("\t\t查询学生信息成功！\n");
		printf("\t\t是否继续？(Y/N)\n");
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

void find4()//按成绩三查询
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int score;
	printf("\t\t请输入你要查询的成绩三分数\n");
	printf("\t\t");
	scanf("%d",&score);
	printf("\t\t=========================================================================================\n");
	read();
	printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
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
		printf("\t\t操作错误是否继续？(Y/N)\n");
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
		printf("\t\t查询学生信息成功！\n");
		printf("\t\t是否继续？(Y/N)\n");
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

void find5()//按排名查询
{
	fflush(stdin);
	int i;
	char ch;
	int count=0;
	int ranking;
	printf("\t\t请输入想要查询的学生排名：\n");
	printf("\t\t");
	scanf("%d",&ranking);
	printf("\t\t=========================================================================================\n");
	read();

	for(i=0;stu[i].no!=0;i++)
	{
		if(ranking==stu[i].ranking)
		{
			printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
			printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
				stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
				stu[i].score.sum,stu[i].age,stu[i].ranking);
			count++;
		}
	}
	if(count==0)
	{
		printf("\t\t操作错误是否继续？(Y/N)\n");
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
		printf("\t\t查询学生信息成功！\n");
		printf("\t\t是否继续？(Y/N)\n");
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

void find6()//全部查询
{
	int i,j;
	read();
	printf("\t\t学号\t姓名\t密码\t班级\t成绩一\t成绩二\t成绩三\t总分\t年龄\t排名\n");
	for(i=0;stu[i].no!=0;i++)
	{
		printf("\t\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].spwd,
			stu[i].classnum,stu[i].score.score1,stu[i].score.score2,stu[i].score.score3,
			stu[i].score.sum,stu[i].age,stu[i].ranking);
	}
	printf("\t\t返回上一级还是退出?(1,返回|2,退出)\n\n");
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

void find()//查询学生信息
{
	int choose2;
	printf("\t\t选择你要查询的方式：\n");
	printf("\t\t0:根据姓名查询\t1:根据单科成绩一查询\t2:根据单科成绩二查询\t3：根据单科成绩三查询\n");
	printf("\t\t4:根据排名\t5:全部查询\t6:返回主菜单\n");
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
		printf("\t\t你所选择的操作不是上述操作，请重新选择\n");
		find();
	}
}

void sorting1()//按姓名排序
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
	printf("\t\t排序成功！\n");
	printf("\t\t=========================================================================================\n\n");
	sorting();
}

void sorting2()//按成绩一排序
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
	printf("\t\t排序成功！\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void sorting3()//按成绩二排序
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
	printf("\t\t排序成功！\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void sorting4()//按成绩三排序
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
	printf("\t\t排序成功！\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void sorting5()//按排名排序
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
	printf("\t\t排序成功！\n");
	printf("\t\t=========================================================================================\n");
	sorting();
}

void  sorting()//排序学生信息
{
	int choose3;
	printf("\t\t请选择排序的方式\n");
	printf("\t\t0:根据姓名排序\t1:根据单科成绩一排序\t2:根据单科成绩二排序\t3:根据单科成绩三排序\n\t\t4:根据排名进行排序\t5:返回主菜单\n");
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
		printf("\t\t你所选择的操作不是上述操作，请重新选择！\n");
		sorting();
	}

}

void save()//保存所有信息
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

void  read()//读出文件的信息
{
	FILE *fp;
	fp=fopen("C:\\Users\\Administrator\\Desktop\\student.txt","rb");
	fread(&stu[0],sizeof(struct student),N,fp);
	fclose(fp);
}
void title()//开始介绍
{
	printf("\t\t\t\t\t项目名称：C语言下的学生管理系统\n");
}
int main()//主函数
{
	title();
	system("pause");
	system("cls");
	int userNO;
	int choose;
	printf("\t\t**********************************C语言下的学生管理系统**********************************\n");
	printf("\t\t你好！，请选择登录身份！\n");
	printf("\t\t0:管理员\t 1:学生 \t2:退出\n");
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
	case 2:printf("\t\t退出成功!\n");
		break;
	default :printf("\t\t你选择的身份不正确，请重新选择\n\n\n");
		main();break;
	}
	return 0;
}




