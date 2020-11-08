#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define MAX_LEN 150
#define C 6
typedef struct student
{
    int score[C],sum_stu;
    long num;
    char name[MAX_LEN];
}STUDENT;
void Readscore(STUDENT stu[],int course,int n);
void Printscore(STUDENT stu[],int n,int course);
void SelectionSort_num(STUDENT stu[],int n,int(*compare)(int a,int b));
void SelectionSort_score(STUDENT stu[],int n,int(*compare)(int a,int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void Swap(int *x,int *y);
void Statistic_course(STUDENT stu[],int n,int sum_course[]);
void Statistic_stu(STUDENT stu[],int n);
int Search_num(STUDENT stu[],int n);
int Search_name(STUDENT stu[],int n);
void Classification(STUDENT stu[],int n,int course);
void Sortstring(STUDENT stu[],int n);

int main()
{
    int a=1,s,b,course,i,j,k,ret;
    STUDENT stu[N];
    int sum_course[N];
    s=0;
    while(a!=0)
    {
        printf("1.Input record\n");
        printf("2.Calculate total and average score of every course\n");
        printf("3.Calculate total and average score of every student\n");
        printf("4.Sort in descending order by total score of every student\n");
        printf("5.Sort in ascending order by total score of every student\n");
        printf("6.Sort in ascending order by number\n");
        printf("7.Sort in dictionary order by name\n");
        printf("8.Search by number\n");
        printf("9.Search by name\n");
        printf("10.Statistic analysis for every course\n");
        printf("11.List record\n");
        printf("0.Exit.\n");
        printf("Please enter your choice:\n");
        scanf("%d",&a);
        getchar();
        switch(a)
            {
                case 1:
                    printf("please enter the number of classes and the total number of students\n");
                    ret=scanf("%d%*c%d",&course,&s);
                    while(ret==0)
        {
            printf("错误！请重新输入：\n");
            ret=scanf("%d%*c%d",&course,&s);
        }
                     Readscore(stu,course,s);
                    break;
                case 2:
                	if(s!=0)
                Statistic_course(stu,s,sum_course);
                else printf("请先输入数据\n");
                break;
                case 3:
                    if(s!=0)
                        Statistic_stu(stu,s);
                        else printf("请先输入数据\n");
                break;
                case 4:
                	if(s!=0)
                    {
					SelectionSort_score(stu,s,Descending);
                }
                else printf("请先输入数据\n");
                    break;
                case 5:
                    if(s!=0)
					{
					SelectionSort_score(stu,s,Ascending);
                 }
                 else printf("请先输入数据\n");
                    break;
                case 6:
                     if(s!=0)
					 {
					 SelectionSort_num(stu,s,Ascending);
                 }
                 else printf("请先输入数据\n");
					 break;

                case 7:
                	if(s!=0)
                    {
					Sortstring(stu,s);
                }
                else printf("请先输入数据\n");
					break;
                case 8:
                	 if(s!=0)
                        {
                             int i,k;
    char temp[MAX_LEN];
    for(i=0;i<s-1;i++)
    {
        k=i;
        for(j=i+1;j<s;j++)
        {
            if(stu[j].sum_stu>stu[k].sum_stu)
                k=j;
            if(k!=i)
                {swap(&stu[k].sum_stu,&stu[i].sum_stu);
                swap(&stu[k].num,&stu[i].num);
                strcpy(temp,stu[i].name);
                strcpy(stu[i].name,stu[k].name);
                strcpy(stu[k].name,temp);
                }
        }

    }
                    b=Search_num(stu,s);
                    if(b!=-1)
                    {
                        for(j=0;j<course;j++)
                        {
					printf("course%d:%4d",j+1,stu[b].score[j]);
                        }
					printf("\n");
                    printf("排名为%d\n",b+1);
                }
                    else
                        printf("Not found!\n");}
                        else printf("请先输入数据\n");
                    break;
                case 9:
                     if(s!=0) {
					 char temp[MAX_LEN];
    for(i=0;i<s-1;i++)
    {
        k=i;
        for(j=i+1;j<s;j++)
        {
            if(stu[j].sum_stu>stu[k].sum_stu)
                k=j;
            if(k!=i)
                {swap(&stu[k],&stu[i]);
                }

        }}
					b=Search_name(stu,s);
                    if(b!=-1)
                    {
                        for(j=0;j<course;j++)
                        {
					printf("course%d:%4d",j+1,stu[b].score[j]);}
					printf("\n");
                    printf("排名为%d\n",b+1);
                }
                    else
                        printf("Not found!\n");
            }
            else printf("请先输入数据\n");
					break;
                case 10:
                    if(s!=0)
					Classification(stu,s,course);
                    break;
                case 11:
                	if(s!=0)
                    {
					Printscore(stu,s,course);
                    }
                    else printf("请先输入数据\n");
                    break;
                case 0:
                    return 0;
                    break;

}

}
}
void Readscore(STUDENT stu[],int course,int n)
{
    int i=-1,j,ret;
    printf("Input student'sID,name and score as course 1  course 2...... \n");
        for(i=0;i<n;i++)
        {
        ret=scanf("%ld",&stu[i].num);
        while(ret==0)
        {
            printf("错误！请重新输入：\n");
            getchar();
            scanf("%ld",&stu[i].num);
            ret=scanf("%ld",&stu[i].num);
        }
        getchar();
        ret=scanf("%s",&stu[i].name);
         while(ret==0)
        {
            printf("错误！请重新输入：\n");
             getchar();
            scanf("%s",&stu[i].name);
            ret=scanf("%s",&stu[i].name);
        }
        getchar();
        stu[i].sum_stu=0;
        for(j=0;j<course;j++)
        {
            ret=scanf("%d",&stu[i].score[j]);
        while(stu[i].score[j]>100)
        {
		printf("分数不能超过100！请重新输入：\n");
        scanf("%d",&stu[i].score[j]);
		}
		 while(ret==0)
        {
            printf("错误！请重新输入：\n");
            scanf("%d",&stu[i].score[j]);
        }
		stu[i].sum_stu=stu[i].sum_stu+stu[i].score[j];
		}
        }
}
void Statistic_course(STUDENT stu[],int n,int sum_course[])
{
    float average[N];
    int i,j,ret;

    for(j=0;j<n;j++)
    {
        sum_course[j]=0;
        for(i=0;i<n;i++)
        {
            sum_course[j]=sum_course[j]+stu[i].score[j];
        }
        average[j]=(float)sum_course[j]/n;
    printf("course%d:total: %d,average:%f\n",j+1,sum_course[j],average[j]);

    }

}
void Statistic_stu(STUDENT stu[],int n)
{
    float average[N];
    int i,j;

    for(i=0;i<n;i++)
    {
        stu[i].sum_stu=0;
        for(j=0;j<n;j++)
        {
            stu[i].sum_stu=stu[i].sum_stu+stu[i].score[j];
        }
        average[i]=(float)stu[i].sum_stu/n;
        printf("%12ld%10s total:%5d average:%6f\n",stu[i].num,stu[i].name,stu[i].sum_stu,average[i]);


    }

}
void SelectionSort_score(STUDENT stu[],int n,int(*compare)(int a,int b))
{
    int i,j,k;
    char temp[MAX_LEN];
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(stu[j].sum_stu,stu[k].sum_stu))
                k=j;
            if(k!=i)
                {swap(&stu[k].sum_stu,&stu[i].sum_stu);
                swap(&stu[k].num,&stu[i].num);
                strcpy(temp,stu[i].name);
                strcpy(stu[i].name,stu[k].name);
                strcpy(stu[k].name,temp);
                }

        }
                 printf("%d %12ld%10s%10d\n",i+1,stu[i].num,stu[i].name,stu[i].sum_stu);
    }
    printf("%d %12ld%10s%10d\n",n,stu[n-1].num,stu[n-1].name,stu[n-1].sum_stu);

}
void SelectionSort_num(STUDENT stu[],int n,int(*compare)(int a,int b))
{
    int i,j,k;
    char temp[MAX_LEN];
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(stu[j].num,stu[k].num))
                k=j;
            if(k!=i)
                {swap(&stu[k].sum_stu,&stu[i].sum_stu);
                swap(&stu[k].num,&stu[i].num);
                strcpy(temp,stu[i].name);
                strcpy(stu[i].name,stu[k].name);
                strcpy(stu[k].name,temp);
                }

        }
                 printf("%d %12ld%10s%10d\n",i+1,stu[i].num,stu[i].name,stu[i].sum_stu);
    }
    printf("%d %12ld%10s%10d\n",n,stu[n-1].num,stu[n-1].name,stu[n-1].sum_stu);

}

int Ascending(int a,int b)
{
    return a<b;
}
int Descending(int a,int b)
{
    return a>b;
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Printscore(STUDENT stu[],int n,int course)
{
    int i,j;
    float average;
    for(i=0;i<n;i++)
    {
        printf("%12ld%10s",stu[i].num,stu[i].name);
        for(j=0;j<course;j++)
          {
            printf("%4d",stu[i].score[j]);
    }
    average=(float)stu[i].sum_stu/course;
    printf(" total:%4d average: %6f\n",stu[i].sum_stu,average);
    }
}
int Search_num(STUDENT stu[],int n)
{
	printf("Please enter the ID you want to check:\n");
    long x;
    int i,ret;
    ret=scanf("%d",&x);
     while(ret==0)
        {
            printf("错误！请重新输入：\n");
            scanf("%d",&x);
        }


    for(i=0;i<n;i++)
    {

        if(stu[i].num==x)
        {
            return i;}
    }
    return -1;

}
int Search_name(STUDENT stu[],int n)
{
    int i;
    char M[MAX_LEN];
    printf("Please enter the name you want to check:\n");
    gets(M);
        for(i=0;i<n;i++)
        {if(strcmp(stu->name[i],M)==0)
        {
            return i;}
        }
    return -1;

}
void Classification(STUDENT stu[],int n,int course)
{
    int i,A,B,D,E,F,j;
    A=0;
    B=0,D=0,E=0,F=0;
    for(j=0;j<course;j++)
    {for(i=0;i<n;i++)
    {
        if(stu[i].score[j]>=90&&stu[i].score[j]<=100)
            A=A+1;
        else if(stu[i].score[j]>=70&&stu[i].score[j]<80)
            E=E+1;
        else if(stu[i].score[j]>=80&&stu[i].score[j]<90)
            B=B+1;
        else if(stu[i].score[j]>=60&&stu[i].score[j]<70)
            D=D+1;
        else if(stu[i].score[j]>=0&&stu[i].score[j]<60)
            F=F+1;
    }
    printf("course%d\n",j+1);
    printf("90-100共%d人，占比%d%%\n",A,100*A/n);
    printf("80-89共%d人，占比%d%%\n",B,100*B/n);
    printf("70-79共%d人，占比%d%%\n",E,100*E/n);
    printf("60-69共%d人，占比%d%%\n",D,100*D/n);
    printf("0-59共%d人，占比%d%%\n",F,100*F/n);
}
}
void Sortstring(STUDENT stu[],int n)
{
    int i,j;
    char temp[MAX_LEN];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(stu[j].name,stu[i].name)<0)
            {
                strcpy(temp,stu[i].name);
                strcpy(stu[i].name[i],stu[j].name);
                strcpy(stu[j].name,temp);
                swap(&stu[i],&stu[j]);

            }
        }
        printf("%d %12ld%10s%10d\n",i+1,stu[i].num,stu[i].name,stu[i].sum_stu);
    }
     printf("%d %12ld%10s%10d\n",n,stu[n-1].num,stu[n-1].name,stu[n-1].sum_stu);
}
