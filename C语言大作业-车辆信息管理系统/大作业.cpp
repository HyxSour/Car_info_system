#include <stdio.h>
#include <math.h>//
#include <string.h>//
#include"stdlib.h" //通过该函数头部里的函数，改变控制台的背景和颜色 
#include"windows.h" //头文件声明，下文用到了改变控制台的宽度和高度 
#define M 100  //
struct car{ //结构体定义并声明 
	char model[20];//车辆型号 
	char made[20];//厂商
	char level[20];//车型级别
	int sit[10];//座位数
	int pay[20];//价格
	char out[20];//排量
	char carcolour[20];//车身颜色
	char changespeedbox[20];};//变速箱


//****************************************函数的声明********************************************


void input(struct car c[M]); //输入函数 
void output(struct car c[M]); //输出函数
void lookfor(struct car c[M]); //查询函数 
void modify(struct car c[M]); //修改函数 
void delete_car(struct car c[M]); //删除函数 
void xinghao(struct car c[M]);
void changshang(struct car c[M]);



//****************************************开始菜单*****************************************************

int count=0;
struct car t;

int main()
{
	int choice,sum;
	struct car c[M];
	system("mode con:cols=100 lines=50 "); //调节控制台的宽度和高度
	system("color 0b"); //调节控制台的背景和字体颜色 
	point1: 
	 sum=0; 
	  printf("欢迎你使用车辆信息管理系统\n"); 
	  do {
		   printf(" ***************\n");  
		    printf(" 1、添加车辆信息\n"); 
			 printf(" 2、浏览车辆信息\n"); 
			  printf(" 3、查询车辆信息\n"); 
			   printf(" 4、修改车辆信息\n"); 
			    printf(" 5、删除车辆信息\n"); 							  
				 printf(" 6、退出系统\n"); 
					printf(" ***************\n"); 
					  printf("请输入你的选择\n"); 
					   scanf("%d",&choice); 
                        fflush(stdin); //清除输入缓冲区 
                   if (choice>9||choice<=0) 
				   {
					   sum++;
					   if (sum>=5) 
					   {
						    printf("输入错误次数过多,程序将重新开始\n"); 
							system("pause"); //程序暂停 
							system("cls"); //清屏语句 
							goto point1; 
					   }
				   }
 switch (choice) 
 {
		 case 1:input(c);break;  
		 case 2:output(c);break; 
		 case 3:lookfor(c);break; 
		 case 4:modify(c);break; 
		 case 5:delete_car(c);break; 
		 case 6:printf("感谢你使用车辆信息管理系统,请关掉程序!!!\n");system("pause");break; 
		 default:printf("无效的选择!!!请重新输入!!!\n");break; 	
 }

	  }while (choice!=6); 
	   printf("程序结束!!!\n"); 
 return 0; 
}


//*************************************输入********************************************************


void input(struct car c[M]) //自定义输入函数 
{
	 system("cls"); //清屏
	 printf("请添加要输入车辆的信息\n"); 
		 printf("请输入厂商名\n"); 
		 scanf("%s",&c[count].made); 
		printf("请输入车辆型号\n"); 
		scanf("%s",&c[count].model);
		printf("请输入车辆级别\n");
		scanf("%s",&c[count].level);
		printf("请输入车身颜色\n"); 
		scanf("%s",&c[count].carcolour); 
		printf("请输入车辆变速箱：1 手动 、2 手自一体 、3 无级变速\n");  
		 scanf("%s",&c[count].changespeedbox);  
		  printf("请输入车辆座位数\n"); 
		   scanf("%s",&c[count].sit);
		   printf("请输入车辆价格\n");
		   scanf("%s",&c[count].pay);
		    printf("请输入车辆排量\n");
		   scanf("%s",&c[count].out);
		   count++;
}

//***********************************输出**********************************************************


void output(struct car c[M]) //自定义输出函数 
{
	int j;
	system("cls");
	if (count==0)
	{
		 printf("当前已存车辆信息为0个\n"); 
		  return; 
	}
	 for (j=0;j<count;j++)  
	 {
		 printf("车辆型号\t\t厂商\t\t车型级别\t座位数\t\价格\t\t排量\t\t车身颜色\t变速箱\t\n");
		 for (j=0;j<count;j++)
		 {
			 printf("%s\t",c[j].model);
			 printf("%s\t",c[j].made);
			 printf("%s\t",c[j].level);
			 printf("%s\t",c[j].sit);
			 printf("%s\t",c[j].pay);
			 printf("%s\t",c[j].out);
			 printf("%s\t",c[j].carcolour);
			 printf("%s\t",c[j].changespeedbox);
		
		 }
	 }


}

//*********************************查询************************************************************


void lookfor(struct car c[M])   //自定义查询车辆信息函数 
{
	int j,flag=0; 
	char xh[25]; 
	system("cls"); 
	if (count==0){
		printf("当前已存车辆信息为0个,无法查询!!!\n"); 
		return;
	}
	else{
		 printf("请输入你想要查看的车辆型号\n");
		 scanf("%s",&xh); 
		 fflush(stdin); //清空输入缓冲区
		  for (j=0;j<count;j++) 
		  {
			  if(strcmp(c[j].model,xh)==0)//通过字符函数对已存入的车辆信息进行比较,找出要查看的车辆 
			  {
				printf("车辆型号\t\t厂商\t\t车型级别\t座位数\t\价格\t\t排量\t\t车身颜色\t变速箱\t\n");
					printf("%s\t",c[j].model);
					printf("%s\t",c[j].made);
					printf("%s\t",c[j].level);
					printf("%s\t",c[j].sit);
					printf("%s\t",c[j].pay);
					printf("%s\t",c[j].out);
					printf("%s\t",c[j].carcolour);
					printf("%s\t",c[j].changespeedbox);
			  }
		  }
	if (j==count)
		 printf("很抱歉,没有你所需要的车辆信息\n"); 
	}
}

//**********************************修改***********************************************************


void modify(struct car c[M]) //自定义修改函数 
{
	int j,flag=0,number;
	char xh[25];
	system("cls");
	if (count==0)
	{
		printf("当前已存车辆信息为0个,无法修改!!!\n"); 
		return; 
	}
	else
	{
		printf("请输入你想要修改的车辆型号\n"); 
		scanf("%s",&xh);
		fflush(stdin); //清空缓存区
		for (j=0;j<count;j++) 
			if (strcmp(c[j].model,xh)==0)
			{
				printf("你确定要修改车辆的信息吗???如果不确定的话,请关掉本程序吧!!!\n"); 
				printf("选择需要修改的数据：1、车辆型号 2、厂商 3、车型类别 4、座位数、 5、价格 6、排量 7、车身颜色 8、变速箱\n");
				scanf("%d",&number);
				printf("请输入修改的车辆信息:\n");
				switch(number)
				{
					case 1:scanf("%s",&c[j].model);break;
					case 2:scanf("%s",&c[j].made);break;
					case 3:scanf("%s",&c[j].level);break;
					case 4:scanf("%s",&c[j].sit);break;
					case 5:scanf("%s",&c[j].pay);break;
					case 6:scanf("%s",&c[j].out);break;
					case 7:scanf("%s",&c[j].carcolour);break;
					case 8:scanf("%s",&c[j].changespeedbox);break;
					default:printf("无效的选择！！请重新输入\n");break;	
				}
			}
	}
}


//***********************************删除**********************************************************


void delete_car(struct car c[M])//自定义删除函数
{
	int choice;
	system("cls");
	if (count == 0)
	{
		printf("当前已存的车辆信息为0个，无法删除！！！\n");
		return;
	}
	else
	{
		printf("请选择你做需要删除的方式：1、型号 2、厂商 3、取消\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:xinghao(c);break;
		case 2:changshang(c);break;
		case 3:return;break;
		default:printf("无效选择，请重新输入");break;
		}
	}
}


void xinghao(struct car c[M])//自定义通过选择型号删除车辆信息
{
	int j,index = 0,k = count;
	char xh[20];
	system("cls");
	printf("请输入想要删除的车辆型号:\n");
	scanf("%s",xh);
	fflush(stdin);//清空缓存区
	for (j=0;j<count;j++)
	{
		if (strcmp(c[j].model,xh) == 0)
		{
			for(j=index;j<count;j++)
				c[j] = c[j+1];
			count--;
			if(count<k)
				printf("删除成功！\n");
		}
		index++;
	}
	if(j == count)
		printf("抱歉！没有需要删除的车辆信息\n");
}



void changshang(struct car c[M])
{
	int a=0,j,k = count;
	char cs[20];
	system("cls");
	printf("请输入需要删除车辆的厂商\n");
	scanf("%s",cs);
	fflush(stdin); 
	for (j=0;j<count;j++)
	{
		if (strcmp(c[j].model,cs) == 0)
		{
			for (j=a-1;j<count;j++)
				c[j] = c[j+1];
			count--;
			if(count<k)
				printf("删除成功！\n");
		}
		a++;
	}
	if(j == count)
		printf("抱歉！没有需要删除的车辆信息\n");
}





















