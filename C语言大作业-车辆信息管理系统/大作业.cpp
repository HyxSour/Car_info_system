#include <stdio.h>
#include <math.h>//
#include <string.h>//
#include"stdlib.h" //ͨ���ú���ͷ����ĺ������ı����̨�ı�������ɫ 
#include"windows.h" //ͷ�ļ������������õ��˸ı����̨�Ŀ�Ⱥ͸߶� 
#define M 100  //
struct car{ //�ṹ�嶨�岢���� 
	char model[20];//�����ͺ� 
	char made[20];//����
	char level[20];//���ͼ���
	int sit[10];//��λ��
	int pay[20];//�۸�
	char out[20];//����
	char carcolour[20];//������ɫ
	char changespeedbox[20];};//������


//****************************************����������********************************************


void input(struct car c[M]); //���뺯�� 
void output(struct car c[M]); //�������
void lookfor(struct car c[M]); //��ѯ���� 
void modify(struct car c[M]); //�޸ĺ��� 
void delete_car(struct car c[M]); //ɾ������ 
void xinghao(struct car c[M]);
void changshang(struct car c[M]);



//****************************************��ʼ�˵�*****************************************************

int count=0;
struct car t;

int main()
{
	int choice,sum;
	struct car c[M];
	system("mode con:cols=100 lines=50 "); //���ڿ���̨�Ŀ�Ⱥ͸߶�
	system("color 0b"); //���ڿ���̨�ı�����������ɫ 
	point1: 
	 sum=0; 
	  printf("��ӭ��ʹ�ó�����Ϣ����ϵͳ\n"); 
	  do {
		   printf(" ***************\n");  
		    printf(" 1����ӳ�����Ϣ\n"); 
			 printf(" 2�����������Ϣ\n"); 
			  printf(" 3����ѯ������Ϣ\n"); 
			   printf(" 4���޸ĳ�����Ϣ\n"); 
			    printf(" 5��ɾ��������Ϣ\n"); 							  
				 printf(" 6���˳�ϵͳ\n"); 
					printf(" ***************\n"); 
					  printf("���������ѡ��\n"); 
					   scanf("%d",&choice); 
                        fflush(stdin); //������뻺���� 
                   if (choice>9||choice<=0) 
				   {
					   sum++;
					   if (sum>=5) 
					   {
						    printf("��������������,�������¿�ʼ\n"); 
							system("pause"); //������ͣ 
							system("cls"); //������� 
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
		 case 6:printf("��л��ʹ�ó�����Ϣ����ϵͳ,��ص�����!!!\n");system("pause");break; 
		 default:printf("��Ч��ѡ��!!!����������!!!\n");break; 	
 }

	  }while (choice!=6); 
	   printf("�������!!!\n"); 
 return 0; 
}


//*************************************����********************************************************


void input(struct car c[M]) //�Զ������뺯�� 
{
	 system("cls"); //����
	 printf("�����Ҫ���복������Ϣ\n"); 
		 printf("�����볧����\n"); 
		 scanf("%s",&c[count].made); 
		printf("�����복���ͺ�\n"); 
		scanf("%s",&c[count].model);
		printf("�����복������\n");
		scanf("%s",&c[count].level);
		printf("�����복����ɫ\n"); 
		scanf("%s",&c[count].carcolour); 
		printf("�����복�������䣺1 �ֶ� ��2 ����һ�� ��3 �޼�����\n");  
		 scanf("%s",&c[count].changespeedbox);  
		  printf("�����복����λ��\n"); 
		   scanf("%s",&c[count].sit);
		   printf("�����복���۸�\n");
		   scanf("%s",&c[count].pay);
		    printf("�����복������\n");
		   scanf("%s",&c[count].out);
		   count++;
}

//***********************************���**********************************************************


void output(struct car c[M]) //�Զ���������� 
{
	int j;
	system("cls");
	if (count==0)
	{
		 printf("��ǰ�Ѵ泵����ϢΪ0��\n"); 
		  return; 
	}
	 for (j=0;j<count;j++)  
	 {
		 printf("�����ͺ�\t\t����\t\t���ͼ���\t��λ��\t\�۸�\t\t����\t\t������ɫ\t������\t\n");
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

//*********************************��ѯ************************************************************


void lookfor(struct car c[M])   //�Զ����ѯ������Ϣ���� 
{
	int j,flag=0; 
	char xh[25]; 
	system("cls"); 
	if (count==0){
		printf("��ǰ�Ѵ泵����ϢΪ0��,�޷���ѯ!!!\n"); 
		return;
	}
	else{
		 printf("����������Ҫ�鿴�ĳ����ͺ�\n");
		 scanf("%s",&xh); 
		 fflush(stdin); //������뻺����
		  for (j=0;j<count;j++) 
		  {
			  if(strcmp(c[j].model,xh)==0)//ͨ���ַ��������Ѵ���ĳ�����Ϣ���бȽ�,�ҳ�Ҫ�鿴�ĳ��� 
			  {
				printf("�����ͺ�\t\t����\t\t���ͼ���\t��λ��\t\�۸�\t\t����\t\t������ɫ\t������\t\n");
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
		 printf("�ܱ�Ǹ,û��������Ҫ�ĳ�����Ϣ\n"); 
	}
}

//**********************************�޸�***********************************************************


void modify(struct car c[M]) //�Զ����޸ĺ��� 
{
	int j,flag=0,number;
	char xh[25];
	system("cls");
	if (count==0)
	{
		printf("��ǰ�Ѵ泵����ϢΪ0��,�޷��޸�!!!\n"); 
		return; 
	}
	else
	{
		printf("����������Ҫ�޸ĵĳ����ͺ�\n"); 
		scanf("%s",&xh);
		fflush(stdin); //��ջ�����
		for (j=0;j<count;j++) 
			if (strcmp(c[j].model,xh)==0)
			{
				printf("��ȷ��Ҫ�޸ĳ�������Ϣ��???�����ȷ���Ļ�,��ص��������!!!\n"); 
				printf("ѡ����Ҫ�޸ĵ����ݣ�1�������ͺ� 2������ 3��������� 4����λ���� 5���۸� 6������ 7��������ɫ 8��������\n");
				scanf("%d",&number);
				printf("�������޸ĵĳ�����Ϣ:\n");
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
					default:printf("��Ч��ѡ�񣡣�����������\n");break;	
				}
			}
	}
}


//***********************************ɾ��**********************************************************


void delete_car(struct car c[M])//�Զ���ɾ������
{
	int choice;
	system("cls");
	if (count == 0)
	{
		printf("��ǰ�Ѵ�ĳ�����ϢΪ0�����޷�ɾ��������\n");
		return;
	}
	else
	{
		printf("��ѡ��������Ҫɾ���ķ�ʽ��1���ͺ� 2������ 3��ȡ��\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:xinghao(c);break;
		case 2:changshang(c);break;
		case 3:return;break;
		default:printf("��Чѡ������������");break;
		}
	}
}


void xinghao(struct car c[M])//�Զ���ͨ��ѡ���ͺ�ɾ��������Ϣ
{
	int j,index = 0,k = count;
	char xh[20];
	system("cls");
	printf("��������Ҫɾ���ĳ����ͺ�:\n");
	scanf("%s",xh);
	fflush(stdin);//��ջ�����
	for (j=0;j<count;j++)
	{
		if (strcmp(c[j].model,xh) == 0)
		{
			for(j=index;j<count;j++)
				c[j] = c[j+1];
			count--;
			if(count<k)
				printf("ɾ���ɹ���\n");
		}
		index++;
	}
	if(j == count)
		printf("��Ǹ��û����Ҫɾ���ĳ�����Ϣ\n");
}



void changshang(struct car c[M])
{
	int a=0,j,k = count;
	char cs[20];
	system("cls");
	printf("��������Ҫɾ�������ĳ���\n");
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
				printf("ɾ���ɹ���\n");
		}
		a++;
	}
	if(j == count)
		printf("��Ǹ��û����Ҫɾ���ĳ�����Ϣ\n");
}





















