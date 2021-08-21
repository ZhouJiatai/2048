/*
　　黑米粥工作室 2048 V1.2.1 程序
　　版权所有（C）2020 - 2021 黑米粥工作室
　　本程序为自由软件，在自由软件联盟发布的GNU通用公共许可协议的约束下，你可以对其进行再发布及修改。协议版本为第三版或（随你）更新的版本。
　　我们希望发布的这款程序有用，但不保证，甚至不保证它有经济价值和适合特定用途。详情参见GNU通用公共许可协议。
　　你理当已收到一份GNU通用公共许可协议的副本，如果没有，请查阅<http://www.gnu.org/licenses/>
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void out(int a[4][4])
{
	system("cls");
	cout<<"\n┌────┬────┬────┬────┐\n";
	for(int i=0;i<4;i++)
	{
	cout<<"│";
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0)	cout<<"    │";
			else if(a[i][j]<10)	cout<<"  "<<a[i][j]<<" │";
			else if(a[i][j]<100)	cout<<' '<<a[i][j]<<" │";
			else if(a[i][j]<1000)	cout<<' '<<a[i][j]<<"│";
			else	cout<<a[i][j]<<"│";
		}
		if(i<3)	cout<<"\n├────┼────┼────┼────┤\n";	//输出画面
	}
	cout<<"\n└────┴────┴────┴────┘\n";
}
bool setrand(int a[4][4])
{
	int r,ra,rb;
	do
	{
		srand(time(0));
		r=rand()%16,ra=r%4,rb=r/4;
	}
	while(a[ra][rb]!=0);
	srand(time(0));
	bool istwo=1;
	if(rand()%4==4)	istwo=0;
	if(istwo)	a[ra][rb]=2;
	else	a[ra][rb]=4;	//随机生成2或4
	out(a);	//输出画面
	//以上得随机位置并将该位置的数值改为2或4
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==a[i+1][j]||a[i][j]==a[i+1][j])	return 1;	//检测下面和右边是否与本身数值相等
			if(a[i][j]==0)	return 1;	//检测本身是否为0
		}
	for(int i=0;i<3;i++)	if(a[i][3]==0||a[3][i]==0)	return 1;	//检测底端及最右侧是否为0（不含右下角）
	if(a[3][3]==0)	return 1;	//检测右下角是否是0
	for(int i=0;i<3;i++)	if(a[i][3]==a[i+1][3]||a[3][i]==a[3][i+1])	return 1;	//检测底端及最右侧是否有相同数相邻的情况
	cout<<"\a\n你输了！如果不想玩了，按右上角的×退出；如果还想玩，";	//失败
	system("pause");	//暂停程序
	return 0;
}
bool setmove(int a[4][4])
{
	char c;
	get:cin>>c;	//获取指令
	cout<<"请稍等...";
	cout<<'\a';
	bool valid=0;
	switch(c)
	{
		case 'w':
			for(int i=1;i<4;i++)	//排除最顶端
				for(int j=0;j<4;j++)
				{
					if(a[i][j]==0)	continue;	//本身是空位，不执行任何操作，执行下一次循环
					int k=1;
					if(a[i-1][j]==0)
					{
						do	a[i-k][j]=a[i-k+1][j],a[i-k+1][j]=0,valid=1,k++;	//上面是空位，则把本身数值移到上面，判定移动有效
						while(a[i-k][j]==0&&i-k>=0);
					}
					if(a[i-k][j]==a[i-k+1][j]&&i-k>=0)
					{
						a[i-k][j]+=a[i-k+1][j],a[i-k+1][j]=0,valid=1;	//上面与本身数值相等，则把两者数值相加，判定移动有效
						if(a[i-k][j]==2048)	return 1;
					}
					//如果上面不是空位且与本身数值不相等，不执行任何操作，执行下一次循环
				}
			break;
		case 's':
			for(int i=2;i>=0;i--)	//排除最底端
				for(int j=0;j<4;j++)
				{
					if(a[i][j]==0)	continue;	//本身是空位，不执行任何操作，执行下一次循环
					int k=1;
					if(a[i+1][j]==0)
					{
						do	a[i+k][j]=a[i+k-1][j],a[i+k-1][j]=0,valid=1,k++;	//下面是空位，则把本身数值移到下面，判定移动有效
						while(a[i+k][j]==0&&i+k<=3);
					}
					if(a[i+k][j]==a[i+k-1][j]&&i+k<=3)
					{
						a[i+k][j]+=a[i+k-1][j],a[i+k-1][j]=0,valid=1;	//下面与本身数值相等，则把两者数值相加，判定移动有效
						if(a[i+k][j]==2048)	return 1;
					}
					//如果下面不是空位且与本身数值不相等，不执行任何操作，执行下一次循环
				}
			break;
		case 'a':
			for(int i=0;i<4;i++)	//排除最左侧
				for(int j=1;j<4;j++)
				{
					if(a[i][j]==0)	continue;	//本身是空位，不执行任何操作，执行下一次循环
					int k=1;
					if(a[i][j-1]==0)
					{
						do	a[i][j-k]=a[i][j-k+1],a[i][j-k+1]=0,valid=1,k++;	//上面是空位，则把本身数值移到上面，判定移动有效
						while(a[i][j-k]==0&&j-k>=0);
					}
					if(a[i][j-k]==a[i][j-k+1]&&j-k>=0)
					{
						a[i][j-k]+=a[i][j-k+1],a[i][j-k+1]=0,valid=1;	//上面与本身数值相等，则把两者数值相加，判定移动有效
						if(a[i][j-k]==2048)	return 1;
					}
					//如果上面不是空位且与本身数值不相等，不执行任何操作，执行下一次循环
				}
			break;
		case 'd':
			for(int i=0;i<4;i++)	//排除最右侧
				for(int j=2;j>=0;j--)
				{
					if(a[i][j]==0)	continue;	//本身是空位，不执行任何操作，执行下一次循环
					int k=1;
					if(a[i][j+1]==0)
					{
						do	a[i][j+k]=a[i][j+k-1],a[i][j+k-1]=0,valid=1,k++;	//上面是空位，则把本身数值移到上面，判定移动有效
						while(a[i][j+k]==0&&j+k<=3);
					}
					if(a[i][j+k]==a[i][j+k-1]&&j+k<=3)
					{
						a[i][j+k]+=a[i][j+k-1],a[i][j+k-1]=0,valid=1;	//上面与本身数值相等，则把两者数值相加，判定移动有效
						if(a[i][j+k]==2048)	return 1;
					}
					//如果上面不是空位且与本身数值不相等，不执行任何操作，执行下一次循环
				}
			break;
	}
	if(valid==0)
	{
		cout<<"操作无效，请重新输入。\n";
		goto get;
	}
	return 0;
}
int main()
{
	system("title=黑米粥工作室 2048 V1.2.1 PC版");
	cout<<"\a";
	system("color F0");
	char c;
	cout<<"本程序有六种显示模式：\n1.普通模式 \n2.护眼模式 \n3.夜间模式 \n4.活泼模式 \n5.明亮模式\n6.经典模式\n";
	setm:cout<<"请选择（输入数字）：";
	cin>>c;
	switch(c)
	{
		case '1':break;
		case '2':system("color 3A");break;
		case '3':system("color 03");break;
		case '4':system("color B9");break;
		case '5':system("color 4E");break;
		case '6':system("color 0F");break;
		default:
			cout<<"输入错误，请重试。\n";
			goto setm;
	}
	system("cls");
	cout<<"\n        黑米粥工作室\n"
		<<"     Heymmy-Zhou Studio\n\n"
		<<"222222  000000  44  44  888888\n"
		<<"    22  00  00  44  44  88  88\n"
		<<"222222  00  00  444444  888888\n"
		<<"22      00  00      44  88  88\n"
		<<"222222  000000      44  888888\n\n"
		<<"         V1.2.1 PC版\n\n"
		<<"更新日志（2021-8-21）：\n"
		<<"·细微更改。\n"
		<<"更新日志（2020-3-28）：\n"
		<<"1.更改许可协议为GNU通用公共许可协议；\n"
		<<"2.增加了选择显示模式的环节；\n"
		<<"3.取消了胜利和失败时的颜色更改；\n"
		<<"……\n\n\a";
	system("pause");
	system("cls");
    cout<<"\a黑米粥工作室 2048 V1.2.1 PC版 程序\n"
    <<"版权所有（C）2020 - 2021 黑米粥工作室\n"
    <<"本程序为自由软件，在自由软件联盟发布的GNU通用公共许可协议的约束下，你可以对其进行再发布及修改。协议版本为第三版或（随你）更新的版本。\n"
    <<"我们希望发布的这款程序有用，但不保证，甚至不保证它有经济价值和适合特定用途。详情参见GNU通用公共许可协议。\n"
    <<"你理当已收到一份GNU通用公共许可协议的副本，如果没有，请查阅<http://www.gnu.org/licenses/>\n\n"
    <<"要查看该许可协议英文原版，\n请访问<https://www.gnu.org/licenses/gpl-3.0.txt>。\n"
	<<"如需该协议的中文非官方翻译，\n请访问<https://jxself.org/translations/gpl-3.zh.shtml>。\n\n"
	<<"输入1后按回车键查看许可协议英文原版，\n"
	<<"输入2后按回车键查看许可协议的中文非官方翻译，\n"
	<<"输入其他任意字符后按回车键继续使用程序。\n请选择：";
	cin>>c;
	switch(c)
	{
		case '1':system("start https://www.gnu.org/licenses/gpl-3.0.txt");break;
		case '2':system("start https://jxself.org/translations/gpl-3.zh.shtml");break;
	}
	system("cls");
	cout<<"\a\n游戏规则：用WASD键控制，按键后按回车键确认。\n为提升游戏体验，请将你的电脑输入法改为英文输入法！\n\n开始游戏，";
	system("pause");	//暂停程序
	system("cls");
	cout<<"\a请稍等……";
	int now[4][4];	//创建画面
	begin:
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			now[i][j]=0;	//画面初始化
	setrand(now);
	while(1)
	{
		if(!setrand(now))	goto begin;	//重玩
		if(setmove(now))	break;	//胜利
	}
	out(now);
	cout<<"\a\n你赢了！如果不想玩了，按右上角的×退出；如果还想玩，";	//胜利
	system("pause");	//暂停程序
	goto begin;
	return 0;
}
