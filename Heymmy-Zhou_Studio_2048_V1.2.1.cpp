/*
���������๤���� 2048 V1.2.1 ����
������Ȩ���У�C��2020 - 2021 �����๤����
����������Ϊ���������������������˷�����GNUͨ�ù������Э���Լ���£�����Զ�������ٷ������޸ġ�Э��汾Ϊ����������㣩���µİ汾��
��������ϣ�����������������ã�������֤����������֤���о��ü�ֵ���ʺ��ض���;������μ�GNUͨ�ù������Э�顣
�����������յ�һ��GNUͨ�ù������Э��ĸ��������û�У������<http://www.gnu.org/licenses/>
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void out(int a[4][4])
{
	system("cls");
	cout<<"\n�����������Щ��������Щ��������Щ���������\n";
	for(int i=0;i<4;i++)
	{
	cout<<"��";
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0)	cout<<"    ��";
			else if(a[i][j]<10)	cout<<"  "<<a[i][j]<<" ��";
			else if(a[i][j]<100)	cout<<' '<<a[i][j]<<" ��";
			else if(a[i][j]<1000)	cout<<' '<<a[i][j]<<"��";
			else	cout<<a[i][j]<<"��";
		}
		if(i<3)	cout<<"\n�����������੤�������੤�������੤��������\n";	//�������
	}
	cout<<"\n�����������ة��������ة��������ة���������\n";
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
	else	a[ra][rb]=4;	//�������2��4
	out(a);	//�������
	//���ϵ����λ�ò�����λ�õ���ֵ��Ϊ2��4
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==a[i+1][j]||a[i][j]==a[i+1][j])	return 1;	//���������ұ��Ƿ��뱾����ֵ���
			if(a[i][j]==0)	return 1;	//��Ȿ���Ƿ�Ϊ0
		}
	for(int i=0;i<3;i++)	if(a[i][3]==0||a[3][i]==0)	return 1;	//���׶˼����Ҳ��Ƿ�Ϊ0���������½ǣ�
	if(a[3][3]==0)	return 1;	//������½��Ƿ���0
	for(int i=0;i<3;i++)	if(a[i][3]==a[i+1][3]||a[3][i]==a[3][i+1])	return 1;	//���׶˼����Ҳ��Ƿ�����ͬ�����ڵ����
	cout<<"\a\n�����ˣ�����������ˣ������Ͻǵġ��˳�����������棬";	//ʧ��
	system("pause");	//��ͣ����
	return 0;
}
bool setmove(int a[4][4])
{
	char c;
	get:cin>>c;	//��ȡָ��
	cout<<"���Ե�...";
	cout<<'\a';
	bool valid=0;
	switch(c)
	{
		case 'w':
			for(int i=1;i<4;i++)	//�ų����
				for(int j=0;j<4;j++)
				{
					if(a[i][j]==0)	continue;	//�����ǿ�λ����ִ���κβ�����ִ����һ��ѭ��
					int k=1;
					if(a[i-1][j]==0)
					{
						do	a[i-k][j]=a[i-k+1][j],a[i-k+1][j]=0,valid=1,k++;	//�����ǿ�λ����ѱ�����ֵ�Ƶ����棬�ж��ƶ���Ч
						while(a[i-k][j]==0&&i-k>=0);
					}
					if(a[i-k][j]==a[i-k+1][j]&&i-k>=0)
					{
						a[i-k][j]+=a[i-k+1][j],a[i-k+1][j]=0,valid=1;	//�����뱾����ֵ��ȣ����������ֵ��ӣ��ж��ƶ���Ч
						if(a[i-k][j]==2048)	return 1;
					}
					//������治�ǿ�λ���뱾����ֵ����ȣ���ִ���κβ�����ִ����һ��ѭ��
				}
			break;
		case 's':
			for(int i=2;i>=0;i--)	//�ų���׶�
				for(int j=0;j<4;j++)
				{
					if(a[i][j]==0)	continue;	//�����ǿ�λ����ִ���κβ�����ִ����һ��ѭ��
					int k=1;
					if(a[i+1][j]==0)
					{
						do	a[i+k][j]=a[i+k-1][j],a[i+k-1][j]=0,valid=1,k++;	//�����ǿ�λ����ѱ�����ֵ�Ƶ����棬�ж��ƶ���Ч
						while(a[i+k][j]==0&&i+k<=3);
					}
					if(a[i+k][j]==a[i+k-1][j]&&i+k<=3)
					{
						a[i+k][j]+=a[i+k-1][j],a[i+k-1][j]=0,valid=1;	//�����뱾����ֵ��ȣ����������ֵ��ӣ��ж��ƶ���Ч
						if(a[i+k][j]==2048)	return 1;
					}
					//������治�ǿ�λ���뱾����ֵ����ȣ���ִ���κβ�����ִ����һ��ѭ��
				}
			break;
		case 'a':
			for(int i=0;i<4;i++)	//�ų������
				for(int j=1;j<4;j++)
				{
					if(a[i][j]==0)	continue;	//�����ǿ�λ����ִ���κβ�����ִ����һ��ѭ��
					int k=1;
					if(a[i][j-1]==0)
					{
						do	a[i][j-k]=a[i][j-k+1],a[i][j-k+1]=0,valid=1,k++;	//�����ǿ�λ����ѱ�����ֵ�Ƶ����棬�ж��ƶ���Ч
						while(a[i][j-k]==0&&j-k>=0);
					}
					if(a[i][j-k]==a[i][j-k+1]&&j-k>=0)
					{
						a[i][j-k]+=a[i][j-k+1],a[i][j-k+1]=0,valid=1;	//�����뱾����ֵ��ȣ����������ֵ��ӣ��ж��ƶ���Ч
						if(a[i][j-k]==2048)	return 1;
					}
					//������治�ǿ�λ���뱾����ֵ����ȣ���ִ���κβ�����ִ����һ��ѭ��
				}
			break;
		case 'd':
			for(int i=0;i<4;i++)	//�ų����Ҳ�
				for(int j=2;j>=0;j--)
				{
					if(a[i][j]==0)	continue;	//�����ǿ�λ����ִ���κβ�����ִ����һ��ѭ��
					int k=1;
					if(a[i][j+1]==0)
					{
						do	a[i][j+k]=a[i][j+k-1],a[i][j+k-1]=0,valid=1,k++;	//�����ǿ�λ����ѱ�����ֵ�Ƶ����棬�ж��ƶ���Ч
						while(a[i][j+k]==0&&j+k<=3);
					}
					if(a[i][j+k]==a[i][j+k-1]&&j+k<=3)
					{
						a[i][j+k]+=a[i][j+k-1],a[i][j+k-1]=0,valid=1;	//�����뱾����ֵ��ȣ����������ֵ��ӣ��ж��ƶ���Ч
						if(a[i][j+k]==2048)	return 1;
					}
					//������治�ǿ�λ���뱾����ֵ����ȣ���ִ���κβ�����ִ����һ��ѭ��
				}
			break;
	}
	if(valid==0)
	{
		cout<<"������Ч�����������롣\n";
		goto get;
	}
	return 0;
}
int main()
{
	system("title=�����๤���� 2048 V1.2.1 PC��");
	cout<<"\a";
	system("color F0");
	char c;
	cout<<"��������������ʾģʽ��\n1.��ͨģʽ \n2.����ģʽ \n3.ҹ��ģʽ \n4.����ģʽ \n5.����ģʽ\n6.����ģʽ\n";
	setm:cout<<"��ѡ���������֣���";
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
			cout<<"������������ԡ�\n";
			goto setm;
	}
	system("cls");
	cout<<"\n        �����๤����\n"
		<<"     Heymmy-Zhou Studio\n\n"
		<<"222222  000000  44  44  888888\n"
		<<"    22  00  00  44  44  88  88\n"
		<<"222222  00  00  444444  888888\n"
		<<"22      00  00      44  88  88\n"
		<<"222222  000000      44  888888\n\n"
		<<"         V1.2.1 PC��\n\n"
		<<"������־��2021-8-21����\n"
		<<"��ϸ΢���ġ�\n"
		<<"������־��2020-3-28����\n"
		<<"1.�������Э��ΪGNUͨ�ù������Э�飻\n"
		<<"2.������ѡ����ʾģʽ�Ļ��ڣ�\n"
		<<"3.ȡ����ʤ����ʧ��ʱ����ɫ���ģ�\n"
		<<"����\n\n\a";
	system("pause");
	system("cls");
    cout<<"\a�����๤���� 2048 V1.2.1 PC�� ����\n"
    <<"��Ȩ���У�C��2020 - 2021 �����๤����\n"
    <<"������Ϊ���������������������˷�����GNUͨ�ù������Э���Լ���£�����Զ�������ٷ������޸ġ�Э��汾Ϊ����������㣩���µİ汾��\n"
    <<"����ϣ�����������������ã�������֤����������֤���о��ü�ֵ���ʺ��ض���;������μ�GNUͨ�ù������Э�顣\n"
    <<"�������յ�һ��GNUͨ�ù������Э��ĸ��������û�У������<http://www.gnu.org/licenses/>\n\n"
    <<"Ҫ�鿴�����Э��Ӣ��ԭ�棬\n�����<https://www.gnu.org/licenses/gpl-3.0.txt>��\n"
	<<"�����Э������ķǹٷ����룬\n�����<https://jxself.org/translations/gpl-3.zh.shtml>��\n\n"
	<<"����1�󰴻س����鿴���Э��Ӣ��ԭ�棬\n"
	<<"����2�󰴻س����鿴���Э������ķǹٷ����룬\n"
	<<"�������������ַ��󰴻س�������ʹ�ó���\n��ѡ��";
	cin>>c;
	switch(c)
	{
		case '1':system("start https://www.gnu.org/licenses/gpl-3.0.txt");break;
		case '2':system("start https://jxself.org/translations/gpl-3.zh.shtml");break;
	}
	system("cls");
	cout<<"\a\n��Ϸ������WASD�����ƣ������󰴻س���ȷ�ϡ�\nΪ������Ϸ���飬�뽫��ĵ������뷨��ΪӢ�����뷨��\n\n��ʼ��Ϸ��";
	system("pause");	//��ͣ����
	system("cls");
	cout<<"\a���Եȡ���";
	int now[4][4];	//��������
	begin:
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			now[i][j]=0;	//�����ʼ��
	setrand(now);
	while(1)
	{
		if(!setrand(now))	goto begin;	//����
		if(setmove(now))	break;	//ʤ��
	}
	out(now);
	cout<<"\a\n��Ӯ�ˣ�����������ˣ������Ͻǵġ��˳�����������棬";	//ʤ��
	system("pause");	//��ͣ����
	goto begin;
	return 0;
}
