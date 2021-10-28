#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_ROW row; //�кţ���ȡ
	MYSQL_RES* rs2 = NULL; //�����

	//����
	if(!mysql_real_connect(&mysql,"localhost","root","abc123","mydb",0,NULL,0))
	{
		fprintf(stderr, "Failed to change user.  Error: %s\n",
		mysql_error(&mysql));
	}

	char id[100];
	char passwd[100];
	char sql[100];
	printf("�������û������룬�ո����\n");
	scanf("%s %s",&id,&passwd);
	sprintf(sql,"select * from teacher where name = '%s' and passwd = '%s'",id,passwd);

	mysql_query(&mysql,sql); //ִ��sql���
	rs2 = mysql_use_result(&mysql); //��ȡ���������Ҫ��ִ�У�
	
	//��ȡÿһ�У����±����ȡ��Ӧ�ֶ�����
	while(row = mysql_fetch_row(rs1)) 
	{
		printf("%s %s\n",row[0],row[1]);
	} 

	mysql_free_result(rs2); //�ͷŽ����
	mysql_close(&mysql); //�Ͽ�����

}

	}
	else if(c==2)
	{    
		int sno;
		char name[100];
		printf("ѧ��������ѧ���������ո����\n");
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
				printf("1�ǲ�ѯѧ����Ϣ��2�ǲ�ѯ������Ϣ��3���˳�\n");
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
		else printf("ѧ�Ż�����������\n");
		mysql_free_result(rs2);
	}
	else 
	{
		printf("�������\n");
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

	printf("���������\n");
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
	printf("����%d����Ϣ��\n",cnt);
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
	printf("������������ѧ����Ϣ��ѧ�ţ�����\n");
	scanf("%d %s",&sno,name);
	char sql[100];
	sprintf(sql,"insert into student (sno,name) values (%d,'%s')",sno,name);
	if(!mysql_query(&mysql,sql))
	{
		printf("����ѧ����Ϣ�ɹ���\n");
	}    
	else
	{
		fprintf(stderr,"����ʧ�ܣ�%s\n",mysql_error(&mysql));
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
	printf("��ѧ��ɾ����1��������ɾ����2\n");
	int dot;
	scanf("%d",&dot);

	int sno;
	char name[100];
	char str2[100];

	if(dot=1)
	{
		printf("�������ɾ����ѧ��ѧ��\n");
		scanf("%d",&sno);
		sprintf(str2,"delete from student where sno = %d",sno);
	}
	else
	{
		printf("�������ɾ����ѧ������\n");
		scanf("%s",&name);
		sprintf(str2,"delete from student where name = '%s'",name);
	}
	if(mysql_query(&mysql,str2))
	{
		fprintf(stderr,"ɾ��ʧ�ܣ�%s\n",mysql_error(&mysql));
	}
	else
	{
		printf("ɾ���� %d ��ѧ����Ϣ\n",mysql_affected_rows(&mysql));
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
	printf("����ѧ�Ű�1������������2\n");
	int dot;
	scanf("%d",&dot);

	int sno;
	char name[100];
	int sno2;
	char name2[100];
	char str2[100];

	if(dot=1)
	{
		printf("����������ĵ�ѧ��ѧ��\n");
		scanf("%d",&sno);
		printf("��������ĳɵ���ȷѧ��\n");
		scanf("%d",&sno2);
		sprintf(str2,"update student set sno = %d where sno = %d",sno2,sno);
	}
	else
	{
		printf("����������ĵ�ѧ������\n");
		scanf("%s",&name);
		printf("��������ĳɵ���ȷѧ������\n");
		scanf("%s",&name2);
		sprintf(str2,"update student set name = '%s' where name = '%s'",name2,name);
	}

	if(mysql_query(&mysql,str2))
	{
		fprintf(stderr,"����ʧ�ܣ�%s\n",mysql_error(&mysql));
	}
	else
	{
		printf("������ %d ��ѧ����Ϣ\n",mysql_affected_rows(&mysql));
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

	printf("����ѧ�ţ�\n");
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
	printf("����%d����Ϣ��\n",cnt2);
	mysql_free_result(rs2);

	mysql_close(&mysql);
	return 0;
}

