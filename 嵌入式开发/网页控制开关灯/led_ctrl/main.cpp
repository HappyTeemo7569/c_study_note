#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "dev_ctrl.h"
using namespace std;

int main()
{
	cout<<"Content-Type: text/html;charset=utf8\n\n";

	char* cmd=getenv("QUERY_STRING");

	if(cmd==NULL) goto end;

	if(strcmp(cmd,"1")==0)
	{
		if(led_ctrl(1)) //开灯
		{
			cout<<"开灯成功！ <a href=\"/\">返回</a>";
		}
		else
		{
			cout<<"开灯失败！ <a href=\"/\">返回</a>";
		}
	}
	else if(strcmp(cmd,"2")==0)
	{
		if(led_ctrl(0)) //关灯
		{
			cout<<"关灯成功！ <a href=\"/\">返回</a>";
		}
		else
		{
			cout<<"关灯失败！ <a href=\"/\">返回</a>";
		}
	}
	else
	{
		end:
			cout<<"参数错误！  <a href=\"/\">返回</a>";
	}

	return 0;
}
