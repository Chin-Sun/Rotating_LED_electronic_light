#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
const uchar code clock[12][16]={

0xFF,0xFF,0x1F,0xF0,0xEF,0xEF,0xF7,0xDF,0xF7,0xDF,0xEF,0xEF,0x1F,0xF0,0xFF,0xFF,/*0*/

0xFF,0xFF,0xFF,0xFF,0xEF,0xDF,0xEF,0xDF,0x07,0xC0,0xFF,0xDF,0xFF,0xDF,0xFF,0xFF,/*1*/

0xFF,0xFF,0x8F,0xCF,0xF7,0xD7,0xF7,0xDB,0xF7,0xDD,0xF7,0xDE,0x0F,0xCF,0xFF,0xFF,/*2*/

0xFF,0xFF,0xCF,0xE7,0xF7,0xDF,0xF7,0xDE,0xF7,0xDE,0x77,0xDD,0x8F,0xE3,0xFF,0xFF,/*3*/

0xFF,0xFF,0xFF,0xF9,0x7F,0xFA,0xBF,0xDB,0xCF,0xDB,0x07,0xC0,0xFF,0xDB,0xFF,0xDB,/*4*/

0xFF,0xFF,0x07,0xE6,0x77,0xDF,0x77,0xDF,0x77,0xDF,0xF7,0xEE,0xF7,0xF1,0xFF,0xFF,/*5*/

0xFF,0xFF,0x1F,0xF0,0xEF,0xEE,0x77,0xDF,0x77,0xDF,0x6F,0xDF,0xFF,0xE0,0xFF,0xFF,/*6*/

0xFF,0xFF,0xE7,0xFF,0xF7,0xFF,0xF7,0xC1,0x77,0xFE,0x97,0xFF,0xE7,0xFF,0xFF,0xFF,/*7*/

0xFF,0xFF,0x8F,0xE3,0x77,0xDD,0xF7,0xDE,0xF7,0xDE,0x77,0xDD,0x8F,0xE3,0xFF,0xFF,/*8*/

0xFF,0xFF,0x0F,0xFE,0xF7,0xED,0xF7,0xDD,0xF7,0xDD,0xEF,0xEE,0x1F,0xF0,0xFF,0xFF,/*9*/

0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0xCF,0x3F,0xCF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,/*:*/

0xFF,0xFF,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFE,0xFF,0xFF,/*-*/
};
unsigned int code text[] = {


0xFF,0xDF,0xDF,0x9F,0xDF,0xDF,0xDF,0xEF,0xDF,0xEF,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0x00,0xC0,0xBF,0xBF,0xDF,0xBF,0xEF,0xBF,0xF7,0xBF,0xFF,0x87,0xFF,0xFF,/*��*/

0xFB,0xFF,0xFB,0xBF,0xFB,0xDF,0x1B,0xE4,0xDB,0xFD,0xDB,0xBD,0xDA,0x7D,0xD9,0x81,
0xDB,0xFD,0xDB,0xFD,0xDB,0xFD,0x1B,0xF4,0xFB,0xEF,0xFB,0x9F,0xFB,0xFF,0xFF,0xFF,/*��*/

0xEF,0xFB,0xEF,0xFC,0x2F,0xFF,0x00,0x00,0x6F,0xFF,0xEF,0xEE,0xFF,0xF7,0xEF,0xFB,
0xEF,0xFC,0x2F,0xFF,0x00,0x00,0x2F,0xFF,0xEF,0xFC,0xEF,0xFB,0xEF,0xF7,0xFF,0xFF,/*��*/

0xFF,0xBF,0xEF,0xBF,0x9F,0xBF,0x7F,0xBC,0xFF,0xBF,0x00,0x80,0xFF,0xBF,0xFF,0xBF,
0xFF,0xBF,0x00,0x80,0xFF,0xBD,0xFF,0xBE,0x3F,0xBF,0xCF,0xBF,0xFF,0xBF,0xFF,0xFF,/*ҵ*/

0xDF,0x7F,0xDF,0x7F,0xDF,0xBF,0xDF,0xDF,0xDF,0xEF,0xDF,0xF3,0xDF,0xFC,0x00,0xFF,
0xDF,0xFC,0xDF,0xF3,0xDF,0xEF,0xDF,0xDF,0xDF,0xBF,0xDF,0x7F,0xDF,0x7F,0xFF,0xFF,/*��*/

0xBF,0xFB,0xCF,0xFB,0xEE,0xFB,0x69,0xFB,0x6F,0xFB,0x6F,0xBB,0x6E,0x7B,0x69,0x81,
0x6F,0xF9,0x6F,0xFA,0x67,0xFB,0xEB,0xFB,0xEC,0xFB,0xAF,0xFB,0xCF,0xFB,0xFF,0xFF,/*ѧ*/
};

unsigned int change(uint a)//��ȡ��ģ
{
	uint b=0x00,j,c;
	for(j=0;j<8;j++)
	{
		c=a&0x01;
		a=a>>1;
		b=b+c;
		if(j!=7)
		{
			b=b<<1;
		}
	}
	return b;
}

uchar starts_time[7]={0x30,0x59,0x14,0x19,0x07,0x03,0x19};	 //��ʼ�������� �� �� ʱ �� �� ���� ��//
uchar Sec;
uchar Cent;
uchar Hour;
uchar Year;
uchar Day;
uchar Week;
uchar Month;

sbit CLK =P3^5;		    //DS1302��������
sbit IO =P3^6;
sbit RST=P3^7;

sbit ACC0=ACC^0;           //1bit���ݴ洢λ
sbit ACC7=ACC^7;
/******************************************************************/

//����ѡ�������Ӧ��Ŀ
//********DS1302��д����***************//
/******************************************************************** 
�� �� ����RTInputByte()
��    �ܣ�ʵʱʱ��д��һ�ֽ�
˵    ������DS1302д��1Byte���� (�ڲ�����)
��ڲ�����d д������� 
�� �� ֵ����  
***********************************************************************/
void RTInputByte(uchar d) 
{ 
    uchar h;
    ACC = d;
    for(h=8; h>0; h--)
    {
        IO = ACC0;           /*�൱�ڻ���е� RRC */
        CLK = 1;
        CLK = 0;
        ACC = ACC >> 1; 
    } 
}
/******************************************************************** 
�� �� ����RTOutputByte()
��    �ܣ�ʵʱʱ�Ӷ�ȡһ�ֽ�
˵    ������DS1302��ȡ1Byte���� (�ڲ�����)
��ڲ�������  
�� �� ֵ��ACC
��    �ƣ�zhaojunjie           ��    �ڣ�2002-03-19
��    �ģ�                     ��    �ڣ� 
***********************************************************************/
uchar RTOutputByte(void) 
{ 
    uchar h;
    for(h=8; h>0; h--)
    {
        ACC = ACC >>1;         /*�൱�ڻ���е� RRC */
        ACC7 = IO;
        CLK = 0;
        CLK = 1;
    } 
    return(ACC); 
}
/******************************************************************** 
�� �� ����R1302()
��    �ܣ���ȡDS1302ĳ��ַ������
˵    ������д��ַ���������/���� (�ڲ�����)
��    �ã�RTInputByte() , RTOutputByte()
��ڲ�����ucAddr: DS1302��ַ
�� �� ֵ��ucData :��ȡ������
***********************************************************************/
uchar R1302(uchar ucAddr)
{
    uchar ucData;
    RST = 0;
    CLK = 0;
    RST = 1;
    RTInputByte(ucAddr);             /* ��ַ������ */
		CLK = 1;
    ucData = RTOutputByte();         /* ��1Byte���� */
    RST = 0;
    return(ucData);
}
/******************************************************************** 
�� �� ����W1302()
��    �ܣ���DS1302д������
˵    ������д��ַ����д����/���� (�ڲ�����)
��    �ã�RTInputByte() , RTOutputByte()
��ڲ�����ucAddr: DS1302��ַ, ucData: Ҫд������
�� �� ֵ����
***********************************************************************/
void W1302(uchar ucAddr, uchar ucDa)
{
    RST = 0;
    CLK = 0;
    RST = 1;
    RTInputByte(ucAddr);       /* ��ַ������ */
    RTInputByte(ucDa);       /* д1Byte����*/
    CLK = 1;
    RST = 0;
}
/******************��ȡDS1302�е�ʱ��****************/
void du1302()
{
    Sec=R1302(0x81);   //��ȡ �� �� ʱ �� �� ���� ��
	  Cent=R1302(0x83);
	  Hour=R1302(0x85);
	  Day=R1302(0x87);
	  Month=R1302(0x89);
	  Week=R1302(0x8b);
	  Year=R1302(0x8d);				
	  //b=R1302(0xc1);
      //a=R1302(0xc3);
	  //a=a/16*10+a%16;
	 
}
/******************************************************************** 
�� �� ����Set1302()
��    �ܣ����ó�ʼʱ��
˵    ������д��ַ���������/����(�Ĵ������ֽڷ�ʽ)
��    �ã�W1302()
��ڲ�����pClock: ����ʱ�����ݵ�ַ ��ʽΪ: �� �� ʱ �� �� ���� ��
                               7Byte (BCD��)1B 1B 1B 1B 1B  1B  1B
�� �� ֵ����
***********************************************************************/
void Set1302(uchar *pClock) 
{
    uchar h;
    uchar ucAddr = 0x80; 
    W1302(0x8e,0x00);           /* ��������,WP=0,д����?*/
    for(h =7; h>0; h--)
    { 
        W1302(ucAddr,*pClock);  /* �� �� ʱ �� �� ���� �� */ 
        pClock++;
        ucAddr +=2;
    }
		//W1302(0xc0,0x01);
		//W1302(0XC2,0X03);
		W1302(0x8e,0x80);
}

sbit BELL=P1^1;
sbit KEY=P1^0;
unsigned char receiveData;

void Delay()
{
	unsigned char a,b,c;
	for(a=0;a<1;a++)
	for(b=0;b<1;b++)
	for(c=0;c<128;c++);
}

void Delay_text()
{
	unsigned char a,b,c;
	for(a=0;a<2;a++)
	for(b=0;b<2;b++)
	for(c=0;c<128;c++);
}

void delay500ms(void)
{
	unsigned char i,j,k;
	for(i=15;i>0;i--)
	for(j=202;j>0;j--)
	for(k=81;k>0;k--);
}

void init()  
{  
    TMOD=0x20;              
    TH1=0xfd;      
    TL1=0xfd;  
    TR1=1;        
  
    SM0=0;  
    SM1=1;        
    REN=1;        
    EA=1;         
    ES=1;       
}  

void main()
{	
	uint i;
	uint Cent_56=0;uint Cent_57=0;uint Cent_58=0;uint Cent_59=0;uint Cent_00=0;
	BELL=0;
	P2=0x00;
	P0=0x00;
	init();
	while(1)
	{	
		while(receiveData=='A')			/*��ʾ����*/
		{
			if(KEY==0) //������չ� �ж���ʼλ
        {         
             for(i=0;i<96;i++) //ÿתһȦ  �ƶ�һ��  ���ﶨ��һȦ��ͬʱ��ʾ96/16=6���֣�
             {                                               
                P0=text[2*i];
                P2=change(text[2*i+1]);	 //��Ļ���ݸ�λ����ʾ
                Delay_text();	//��ʱ��LED������ ÿ����ʱ��ʱ��
            }
        }
		}
		while(receiveData=='B')
		{			
			if(KEY==0) //������չ� �ж���ʼλ
        {   
					du1302();   
						if((Cent==0x59)&&(Sec==0x56))
						{									
								while(Cent_56==0)
								{
									BELL=1;
									delay500ms();
									BELL=0;
									Cent_56=1;
								}
						}
						if((Cent==0x59)&&(Sec==0x57))
						{		
								while(Cent_57==0)
								{
									BELL=1;
									delay500ms();
									BELL=0;
									Cent_57=1;
								}
						}
						if((Cent==0x59)&&(Sec==0x58))
						{		
								while(Cent_58==0)
								{
									BELL=1;
									delay500ms();
									BELL=0;
									Cent_58=1;
								}
						}
						if((Cent==0x59)&&(Sec==0x59))
						{		
								while(Cent_59==0)
								{
									BELL=1;
									delay500ms();
									BELL=0;
									Cent_59=1;
								}
						}
						if((Cent==0x00)&&(Sec==0x00))
						{		
								while(Cent_00==0)
								{
									BELL=1;
									delay500ms();
									BELL=0;
									Cent_00=1;
								}
						}
						if((Cent!=0x59)&&(Cent!=0x00))
						{
							Cent_56=Cent_57=Cent_58=Cent_59=Cent_00=0;
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Hour/16][i*2];	//ʱ��ʮλ
								P2=change(clock[Hour/16][i*2+1]);
								Delay();
						}	
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Hour%16][i*2];	//ʱ�ĸ�λ
								P2=change(clock[Hour%16][i*2+1]);	 
								Delay();	 	
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[10][i*2];			//��ʾ����
								P2=change(clock[10][i*2+1]);
								Delay();	 	
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Cent/16][i*2];		//�ֵ�ʮλ
								P2=change(clock[Cent/16][i*2+1]);	
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Cent%16][i*2];		//�ֵĸ�λ
								P2=change(clock[Cent%16][i*2+1]);	
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[10][i*2];			//��ʾ����
								P2=change(clock[10][i*2+1]);
								Delay();	 	
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Sec/16][i*2];	   //���ʮλ
								P2=change(clock[Sec/16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Sec%16][i*2];		 //��ĸ�λ
								P2=change(clock[Sec%16][i*2+1]);
								Delay();
						}
						Delay_text();
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Day/16][i*2];				 //����	ʮλ
								P2=change(clock[Day/16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Day%16][i*2];				//���ڸ�λ
								P2=change(clock[Day%16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[11][i*2];					//-�ַ�
								P2=change(clock[11][i*2+1]);
								Delay();
						}	
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Month/16][i*2];			 //�µ�	ʮλ
								P2=change(clock[Month/16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Month%16][i*2];			 //�µĸ�λ
								P2=change(clock[Month%16][i*2+1]);
								Delay();
						}
				P0=0xff;
				P2=0xff;
			}	
		}
		if(receiveData=='C')
		{
			Set1302(starts_time); 
		}
	}
}
	void ser() interrupt 4  
{  	 
	receiveData=SBUF;
	RI = 0;         
	SBUF=receiveData; 
	while(!TI);		  
	TI=0;			 
}  