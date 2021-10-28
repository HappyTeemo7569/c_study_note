#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_ROW row; //行号，获取
	MYSQL_RES* rs2 = NULL; //结果集

	//连接
	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
		mysql_error(&mysql));
	}

	char id[100];
	char passwd[100];
	char sql[100];
	printf("请输入用户名密码，空格隔开\n");
	scanf("%s %s",&id,&passwd);
	sprintf(sql,"select * from teacher where name = '%s' and passwd = '%s'",id,passwd);

	mysql_query(&mysql,sql); //执行sql语句
	rs2 = mysql_use_result(&mysql); //获取结果集（需要先执行）
	
	//获取每一行，用下标可以取对应字段内容
	while(row = mysql_fetch_row(rs1)) 
	{
		printf("%s %s\n",row[0],row[1]);
	} 

	mysql_free_result(rs2); //释放结果集
	mysql_close(&mysql); //断开连接

}

	}
	else if(c==2)
	{    
		int sno;
		char name[100];
		printf("学生请输入学号姓名，空格隔开\n");
		scanf("%d %s",&sno,&name);
		char a3[100];
		sprintf(a3,"select * from student where sno = %d and name = '%s'",sno,name);

		mysql_query(&mysql,a3);
		rs2 = mysql_use_result(&mysql);
		int cnt2 =0;
		while(row2 = mysql_fetch_row(rs2))
		{
			cnt2++;
		} 

		if(1 == cnt2)
		{
			while(1)
			{
				printf("1是查询学生信息，2是查询考试信息，3是退出\n");
				int c2;        
				scanf("%d",&c2);
				switch(c2)
				{
				case 1:{look();break;}
				case 2:{test();break;}
				case 3:exit(0);
				}
			}
		}
		else printf("学号或者姓名错误！\n");
		mysql_free_result(rs2);
	}
	else 
	{
		printf("输入错误！\n");
	}
	mysql_close(&mysql);    

	return 0;
}

int look()
{
	MYSQL mysql;
	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
			mysql_error(&mysql));
	}
	char table[100];
	mysql_query(&mysql,"set names utf8");

	printf("输入表名：\n");
	scanf("%s",&table);

	char str1[100];
	sprintf(str1,"select * from %s",table);

	mysql_query(&mysql,str1);

	MYSQL_RES * rs1 = NULL;
	rs1 = mysql_use_result(&mysql);

	MYSQL_ROW row;


	int cnt =0;
	while(row = mysql_fetch_row(rs1))
	{
		printf("%s %s\n",row[0],row[1]);
		cnt++;
	} 
	printf("共有%d个信息！\n",cnt);
	mysql_free_result(rs1);

	mysql_close(&mysql);
	return 0;
}
int add()
{
	MYSQL mysql;
	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
			mysql_error(&mysql));
	}
	int sno;
	char name[100];
	printf("请输入待插入的学生信息：学号，姓名\n");
	scanf("%d %s",&sno,name);
	char sql[100];
	sprintf(sql,"insert into student (sno,name) values (%d,'%s')",sno,name);
	if(!mysql_query(&mysql,sql))
	{
		printf("插入学生信息成功！\n");
	}    
	else
	{
		fprintf(stderr,"插入失败：%s\n",mysql_error(&mysql));
	}
	mysql_close(&mysql);
	return 0;
}
int delete()
{
	MYSQL mysql;
	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
			mysql_error(&mysql));
	}
	printf("按学号删除按1，按姓名删除按2\n");
	int dot;
	scanf("%d",&dot);

	int sno;
	char name[100];
	char str2[100];

	if(dot=1)
	{
		printf("请输入待删除的学生学号\n");
		scanf("%d",&sno);
		sprintf(str2,"delete from student where sno = %d",sno);
	}
	else
	{
		printf("请输入待删除的学生姓名\n");
		scanf("%s",&name);
		sprintf(str2,"delete from student where name = '%s'",name);
	}
	if(mysql_query(&mysql,str2))
	{
		fprintf(stderr,"删除失败：%s\n",mysql_error(&mysql));
	}
	else
	{
		printf("删除了 %d 条学生信息\n",mysql_affected_rows(&mysql));
	}
	mysql_close(&mysql);
	return 0;
}
int change()
{
	MYSQL mysql;
	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
			mysql_error(&mysql));
	}
	printf("更改学号按1，更改姓名按2\n");
	int dot;
	scanf("%d",&dot);

	int sno;
	char name[100];
	int sno2;
	char name2[100];
	char str2[100];

	if(dot=1)
	{
		printf("请输入待更改的学生学号\n");
		scanf("%d",&sno);
		printf("请输入想改成的正确学号\n");
		scanf("%d",&sno2);
		sprintf(str2,"update student set sno = %d where sno = %d",sno2,sno);
	}
	else
	{
		printf("请输入待更改的学生姓名\n");
		scanf("%s",&name);
		printf("请输入想改成的正确学生姓名\n");
		scanf("%s",&name2);
		sprintf(str2,"update student set name = '%s' where name = '%s'",name2,name);
	}

	if(mysql_query(&mysql,str2))
	{
		fprintf(stderr,"更改失败：%s\n",mysql_error(&mysql));
	}
	else
	{
		printf("更改了 %d 条学生信息\n",mysql_affected_rows(&mysql));
	}
	mysql_close(&mysql);            
	return 0;
}

int test()
{
	MYSQL mysql;
	mysql_init(&mysql);

	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
			mysql_error(&mysql));
	}
	int sno2;
	mysql_query(&mysql,"set names utf8");

	printf("输入学号：\n");
	scanf("%d",&sno2);

	char str5[1000];
	sprintf(str5,"select student.sno,course_name,sc.score from sc,student,course where student.sno = %d and student.sno=sc.sno and sc.cno=course.cno",sno2);

	mysql_query(&mysql,str5);

	MYSQL_RES * rs2 = NULL;
	rs2 = mysql_use_result(&mysql);

	MYSQL_ROW row;


	int cnt2 =0;
	while(row = mysql_fetch_row(rs2))
	{
		printf("%s %s %s\n",row[0],row[1],row[2]);
		cnt2++;
	} 
	printf("共有%d个信息！\n",cnt2);
	mysql_free_result(rs2);

	mysql_close(&mysql);
	return 0;
}

