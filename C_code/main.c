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
0xFF,0xFF,0x00,0xC0,0xBF,0xBF,0xDF,0xBF,0xEF,0xBF,0xF7,0xBF,0xFF,0x87,0xFF,0xFF,/*北*/

0xFB,0xFF,0xFB,0xBF,0xFB,0xDF,0x1B,0xE4,0xDB,0xFD,0xDB,0xBD,0xDA,0x7D,0xD9,0x81,
0xDB,0xFD,0xDB,0xFD,0xDB,0xFD,0x1B,0xF4,0xFB,0xEF,0xFB,0x9F,0xFB,0xFF,0xFF,0xFF,/*京*/

0xEF,0xFB,0xEF,0xFC,0x2F,0xFF,0x00,0x00,0x6F,0xFF,0xEF,0xEE,0xFF,0xF7,0xEF,0xFB,
0xEF,0xFC,0x2F,0xFF,0x00,0x00,0x2F,0xFF,0xEF,0xFC,0xEF,0xFB,0xEF,0xF7,0xFF,0xFF,/*林*/

0xFF,0xBF,0xEF,0xBF,0x9F,0xBF,0x7F,0xBC,0xFF,0xBF,0x00,0x80,0xFF,0xBF,0xFF,0xBF,
0xFF,0xBF,0x00,0x80,0xFF,0xBD,0xFF,0xBE,0x3F,0xBF,0xCF,0xBF,0xFF,0xBF,0xFF,0xFF,/*业*/

0xDF,0x7F,0xDF,0x7F,0xDF,0xBF,0xDF,0xDF,0xDF,0xEF,0xDF,0xF3,0xDF,0xFC,0x00,0xFF,
0xDF,0xFC,0xDF,0xF3,0xDF,0xEF,0xDF,0xDF,0xDF,0xBF,0xDF,0x7F,0xDF,0x7F,0xFF,0xFF,/*大*/

0xBF,0xFB,0xCF,0xFB,0xEE,0xFB,0x69,0xFB,0x6F,0xFB,0x6F,0xBB,0x6E,0x7B,0x69,0x81,
0x6F,0xF9,0x6F,0xFA,0x67,0xFB,0xEB,0xFB,0xEC,0xFB,0xAF,0xFB,0xCF,0xFB,0xFF,0xFF,/*学*/
};

unsigned int change(uint a)//读取字模
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

uchar starts_time[7]={0x30,0x59,0x14,0x19,0x07,0x03,0x19};	 //初始化后设置 秒 分 时 日 月 星期 年//
uchar Sec;
uchar Cent;
uchar Hour;
uchar Year;
uchar Day;
uchar Week;
uchar Month;

sbit CLK =P3^5;		    //DS1302引脚连接
sbit IO =P3^6;
sbit RST=P3^7;

sbit ACC0=ACC^0;           //1bit数据存储位
sbit ACC7=ACC^7;
/******************************************************************/

//根据选择调整相应项目
//********DS1302读写程序***************//
/******************************************************************** 
函 数 名：RTInputByte()
功    能：实时时钟写入一字节
说    明：往DS1302写入1Byte数据 (内部函数)
入口参数：d 写入的数据 
返 回 值：无  
***********************************************************************/
void RTInputByte(uchar d) 
{ 
    uchar h;
    ACC = d;
    for(h=8; h>0; h--)
    {
        IO = ACC0;           /*相当于汇编中的 RRC */
        CLK = 1;
        CLK = 0;
        ACC = ACC >> 1; 
    } 
}
/******************************************************************** 
函 数 名：RTOutputByte()
功    能：实时时钟读取一字节
说    明：从DS1302读取1Byte数据 (内部函数)
入口参数：无  
返 回 值：ACC
设    计：zhaojunjie           日    期：2002-03-19
修    改：                     日    期： 
***********************************************************************/
uchar RTOutputByte(void) 
{ 
    uchar h;
    for(h=8; h>0; h--)
    {
        ACC = ACC >>1;         /*相当于汇编中的 RRC */
        ACC7 = IO;
        CLK = 0;
        CLK = 1;
    } 
    return(ACC); 
}
/******************************************************************** 
函 数 名：R1302()
功    能：读取DS1302某地址的数据
说    明：先写地址，后读命令/数据 (内部函数)
调    用：RTInputByte() , RTOutputByte()
入口参数：ucAddr: DS1302地址
返 回 值：ucData :读取的数据
***********************************************************************/
uchar R1302(uchar ucAddr)
{
    uchar ucData;
    RST = 0;
    CLK = 0;
    RST = 1;
    RTInputByte(ucAddr);             /* 地址，命令 */
		CLK = 1;
    ucData = RTOutputByte();         /* 读1Byte数据 */
    RST = 0;
    return(ucData);
}
/******************************************************************** 
函 数 名：W1302()
功    能：往DS1302写入数据
说    明：先写地址，后写命令/数据 (内部函数)
调    用：RTInputByte() , RTOutputByte()
入口参数：ucAddr: DS1302地址, ucData: 要写的数据
返 回 值：无
***********************************************************************/
void W1302(uchar ucAddr, uchar ucDa)
{
    RST = 0;
    CLK = 0;
    RST = 1;
    RTInputByte(ucAddr);       /* 地址，命令 */
    RTInputByte(ucDa);       /* 写1Byte数据*/
    CLK = 1;
    RST = 0;
}
/******************读取DS1302中的时间****************/
void du1302()
{
    Sec=R1302(0x81);   //对取 秒 分 时 日 月 星期 年
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
函 数 名：Set1302()
功    能：设置初始时间
说    明：先写地址，后读命令/数据(寄存器多字节方式)
调    用：W1302()
入口参数：pClock: 设置时钟数据地址 格式为: 秒 分 时 日 月 星期 年
                               7Byte (BCD码)1B 1B 1B 1B 1B  1B  1B
返 回 值：无
***********************************************************************/
void Set1302(uchar *pClock) 
{
    uchar h;
    uchar ucAddr = 0x80; 
    W1302(0x8e,0x00);           /* 控制命令,WP=0,写操作?*/
    for(h =7; h>0; h--)
    { 
        W1302(ucAddr,*pClock);  /* 秒 分 时 日 月 星期 年 */ 
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
		while(receiveData=='A')			/*显示文字*/
		{
			if(KEY==0) //红外接收管 判断起始位
        {         
             for(i=0;i<96;i++) //每转一圈  移动一列  这里定义一圈中同时显示96/16=6个字，
             {                                               
                P0=text[2*i];
                P2=change(text[2*i+1]);	 //字幕数据高位送显示
                Delay_text();	//延时让LED亮起来 每列延时的时间
            }
        }
		}
		while(receiveData=='B')
		{			
			if(KEY==0) //红外接收管 判断起始位
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
								P0=clock[Hour/16][i*2];	//时的十位
								P2=change(clock[Hour/16][i*2+1]);
								Delay();
						}	
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Hour%16][i*2];	//时的个位
								P2=change(clock[Hour%16][i*2+1]);	 
								Delay();	 	
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[10][i*2];			//显示两点
								P2=change(clock[10][i*2+1]);
								Delay();	 	
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Cent/16][i*2];		//分的十位
								P2=change(clock[Cent/16][i*2+1]);	
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Cent%16][i*2];		//分的个位
								P2=change(clock[Cent%16][i*2+1]);	
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[10][i*2];			//显示两点
								P2=change(clock[10][i*2+1]);
								Delay();	 	
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Sec/16][i*2];	   //秒的十位
								P2=change(clock[Sec/16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Sec%16][i*2];		 //秒的个位
								P2=change(clock[Sec%16][i*2+1]);
								Delay();
						}
						Delay_text();
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Day/16][i*2];				 //日期	十位
								P2=change(clock[Day/16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Day%16][i*2];				//日期个位
								P2=change(clock[Day%16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[11][i*2];					//-字符
								P2=change(clock[11][i*2+1]);
								Delay();
						}	
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Month/16][i*2];			 //月的	十位
								P2=change(clock[Month/16][i*2+1]);
								Delay();
						}
						for(i=0;i<8;i++) 
						{ 
								P0=clock[Month%16][i*2];			 //月的个位
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