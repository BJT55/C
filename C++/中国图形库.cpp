#include <graphics.h>
#include <conio.h>
#define PI 3.14159265

// ������
int main()
{   
	
	// ������СΪ 800 * 600 �Ļ�ͼ����
	initgraph(800, 600);

	// ����ԭ�� (0, 0) Ϊ��Ļ���루Y��Ĭ������Ϊ����
	setorigin(0,0);

	// ʹ�ð�ɫ��䱳��
	setbkcolor(WHITE);
	cleardevice();


	//���챳��
	setfillcolor(RGB(232, 23, 23));						
	setlinecolor(BLACK);
	solidrectangle(100,100,700,500);


	//����
    setfillcolor(RGB(255, 2557, 0));               //���ֿ�
    setlinecolor(BLACK);
    solidrectangle(150,220,340,300);
    
	setfillcolor(RGB(255, 2557, 0));              //��
    setlinecolor(BLACK);
    solidrectangle(235,170,260,430);

	setfillcolor(RGB(232, 23, 23));                 //���
    setlinecolor(BLACK);
    solidrectangle(170,240,235,280);

	setfillcolor(RGB(232, 23, 23));                 //�ұ�
    setlinecolor(BLACK);
    solidrectangle(260,240,320,280);


	//����
	setfillcolor(RGB(255, 2557, 0));              //����1
    setlinecolor(BLACK);
    solidrectangle(440,170,640,430);

	setfillcolor(RGB(232, 23, 23));              //����2
    setlinecolor(BLACK);
    solidrectangle(460,190,620,410);



	//����
	setfillcolor(RGB(255, 2557, 0));              //һ��
    setlinecolor(BLACK);
    solidrectangle(480,220,600,240);

	setfillcolor(RGB(255, 2557, 0));              //����
    setlinecolor(BLACK);
    solidrectangle(480,290,600,310);

	setfillcolor(RGB(255, 2557, 0));              //����
    setlinecolor(BLACK);
    solidrectangle(480,360,600,380);

	setfillcolor(RGB(255, 2557, 0));              //һ��
    setlinecolor(BLACK);
    solidrectangle(530,240,555,360);

	setfillcolor(RGB(255, 2557, 0));              //һ��
    setlinecolor(BLACK);
    solidrectangle(575,320,590,355);


	// ��������˳�
	_getch();
	closegraph();
}