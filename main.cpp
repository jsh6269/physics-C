#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char k[50];
int experience[25];
int rec[18]={0,1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,19,23};
char n[50];                      // menu���� ��弱��Ű
char t[30];
void startingmenu(void);    // �λ��Ʈ
void menu(void);            // �޴����� ��弱�ð���
void showscience(void);     // ���л������
void testscience(void);     // ���л�� �׽�Ʈ
void showelement(void);     // ���Һ� ����������
void calculating(void);     // ����ȯ��
void mathmatics(void);      // �����ڷ�
void information(void);     // ����
void filesci(void);
void testmain(int n);
void choose(void);
void recommend(void);
void hardcore(void);
void gorandom(void);
void fileele(void);
void filecon(void);
void testelement(void);
void quit(void);
struct converting{
    char title[30];
    double exactly;
}hang[38];
struct science{
    char ename[6];
    char kname[30];
    char fnum[15];
    char dnum[8];
    char unit[8];
}sci[24];
struct element{
    char number[5];
    char period[5];
    char group[5];
    char symbol[5];
    char name[30];
    char mass[20];
    char radius[10];
    char valence[10];
    char stableisotopes[10];
    char meltingpoint[30];
    char boilingpoint[30];
    char density[20];
}ele[130];
int main()
{
    filesci();
    fileele();
    filecon();
    startingmenu();
    printf("\n");
    while(1)
    {
        menu();
        if(!strcmp(n,"1"))
            showscience();
        else if(!strcmp(n,"2"))
            testscience();
        else if(!strcmp(n,"3"))
            calculating();
        else if(!strcmp(n,"4"))
            mathmatics();
        else if(!strcmp(n,"5"))
            showelement();
        else if(!strcmp(n,"6"))
            information();
        else if(!strcmp(n,"7"))
            return 0;
        else if(!strcmp(n,"8"))
        {
            FILE* p5;
            p5=fopen("history.txt","w");
            fprintf(p5,"�Ʒ��� ����� �׽�Ʈ ����Դϴ�.\n");
            fclose(p5);
            system("cls");
        }
        else if(!strcmp(n,"9"))
            testelement();
        else
        {
            printf("���α׷� ����. �����ڿ��� �����ϼ���.");
            return 0;
        }
    }
}
void quit(void)
{
    while(1)
    {
        scanf("%s",t);
        if(!strcmp(t,"0"))
        {
            system("cls");
            return;
        }
    }
}
void startingmenu(void)
{

printf("\nW               W   E E E E E    L             C C C C      O O      M       M   E E E E E \n");
printf(" W       W     W    E            L           C             O    O    M M   M M   E\n");
printf("  W    W  W   W     E E E E E    L           C             O    O    M   M   M   E E E E \n");
printf("   W W     W W      E            L           C             O    O    M       M   E\n");
printf("    W       W       E E E E E    L L L L L     C C C C       O O     M       M   E E E E E \n");
    printf("\n  �����н����α׷��� ���Ű��� ȯ���մϴ�.\n  �̿����ּż� �����մϴ�.");
    return;
}
void menu(void)
{
    printf("\n  ���л��������� press 1\n  ���л���ϱ��׽�Ʈ press 2\n  ����ȯ������ press 3\n  �����ڷ῭�����  press 4\n  ���Һ� ������ ����  press 5\n  ���� press 6\n  ���α׷� ���� press 7\n  �׽�Ʈ��ϻ��� press 8\n  �������ֱ��׽�Ʈ press 9\n  ");
    scanf("%s",n);
    while(strcmp(n,"1")&&strcmp(n,"2")&&strcmp(n,"3")&&strcmp(n,"4")&&strcmp(n,"5")&&strcmp(n,"6")&&strcmp(n,"7")&&strcmp(n,"8")&&strcmp(n,"9"))
    {

        printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.\n");
        scanf("%s",n);
    }
    return;
}
void information(void)
{
    system("cls");
    printf("\n  �� ���α׷��� ����л��� ȿ������ �������θ� �������� ���۵Ǿ�����\n ���л������ �� �׽�Ʈ, ����ȯ��, ���Һ� ��������������, �����ڷ῭���� ����� �ֽ��ϴ�.\n");
    printf("  �� ���α׷��� ���۱��� suhan8984���� ������ �����ϴ�.");
    printf("\n\n ���θ޴��� ���ư��� press 0\n");
    quit();
    return;
}
void showscience(void)  //���л�� ���
{
    int i;
    char t[30];
    system("cls");
    for(i=1;i<=23;i++)
    {
        if(i==7)
            printf("\n  mp/me �缺�ڿ������������� 1840");
        else if(i==23)
            printf("\n  F �䷯���̻�� 96485 C/mol");
        else if(strcmp(sci[i].unit,"x")==0)
        {
            if(sci[i].dnum==0)
                printf("\n  %s %s %s",sci[i].ename,sci[i].kname,sci[i].fnum);
            else
                printf("\n  %s %s %sx10^%s",sci[i].ename,sci[i].kname,sci[i].fnum,sci[i].dnum);
        }
        else
        {
            if(sci[i].dnum==0)
                printf("\n  %s %s %s %s",sci[i].ename,sci[i].kname,sci[i].fnum,sci[i].unit);
            else
                printf("\n  %s %s %sx10^%s %s",sci[i].ename,sci[i].kname,sci[i].fnum,sci[i].dnum,sci[i].unit);
        }

    }
    printf("\n\n �޴��� ���ư��� press 0\n");
    quit();
    return;
}
void testscience(void)  //���л���׽�Ʈ
{
    int i;
    int check=0;
    system("cls");
    printf("\n  ��Ģ: �Ҽ�����°¥������ �Է��ϼž� �մϴ�.(�����ϳ��� Ʋ���� ����)\n  ���� �Է��ϴ� ����� ������� 23.532x10^7kg�� 23.53 7 kg ���� �ۼ��Ͻð�\n  ������ ���� ������ 0���� ������ ���� ��� x�� �����ſ�.\n  SIǥ�ش����踦 ����ϼſ�. (��, H������ u�� ǥ��)\n");
        while(check==0){
        printf("\n  �������� 10�� ���� press 1\n  suhan8984�� ��õ�ϴ� �׸���� ���� press 2\n  ����ڰ� ������ �׸� ���� press 3\n  hardcore ���� press 4\n  ���θ޴��� ���ư��� press 5\n");
        while(check==0){
        scanf("%s",k);
        if(!strcmp(k,"1"))
        {
            system("cls");
            gorandom();
            break;
        }
        else if(!strcmp(k,"2"))
        {
            system("cls");
            recommend();
            break;
        }
        else if(!strcmp(k,"3"))
        {
            system("cls");
            choose();
            break;
        }
        else if(!strcmp(k,"4"))
        {
            system("cls");
            hardcore();
            break;
        }
        else if(!strcmp(k,"5"))
            check=1;
        else
            printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.");
        }
        }
        system("cls");
        return;
}
void testmain(int n)
{
    FILE * p4;
    int i,s=0;
    int num;
    char t[30];
    char x[18],y[18];
    char temp[15];
    time_t ti=time(NULL);
    struct tm tm=*localtime(&ti);
    p4=fopen("history.txt","a");
    fprintf(p4,"\n%d.%d.%d. %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
    fprintf(p4,"\nƲ������:\n");
    printf("\n  �׽�Ʈ���Ḧ ���Ͻø� ���ڿ� quit�� �Է��ϼ���.\n");
    for(i=1;i<=n;i++)
    {
        do{
        num=rand()%23;
        if(num==0)
            num=23;
        }while(experience[num]!=1);
        experience[num]=0;
        printf("\n  %s %s ",sci[num].ename,sci[num].kname);
        scanf("%s",x);
            if(!strcmp("quit",x))
            {
                fprintf(p4,"\n�����ߴ�\n---------------------------------------------\n");
                system("cls");
                return;
            }
        scanf("%s",y);
                    if(!strcmp("quit",y))
            {
                fprintf(p4,"\n�����ߴ�\n---------------------------------------------\n");
                system("cls");
                return;
            }
        scanf("%s",temp);
                    if(!strcmp("quit",temp))
            {
                fprintf(p4,"\n�����ߴ�\n---------------------------------------------\n");
                system("cls");
                return;
            }
        if(!strcmp(x,sci[num].fnum)&&!strcmp(y,sci[num].dnum)&&!strcmp(temp,sci[num].unit))
            {
                printf("  correct!\n");
                s++;
            }
        else
        {
            printf("  wrong!\a ");
            if(num==7)
                fprintf(p4,"\n  mp/me �缺�ڿ������������� 1840");
            else if(num==23)
            fprintf(p4,"\n  F �䷯���̻�� 96485 C/mol");
            else if(strcmp(sci[num].unit,"x")==0)
            {
                if(sci[num].dnum==0)
                    fprintf(p4,"\n  %s %s %s",sci[num].ename,sci[num].kname,sci[num].fnum);
                else
                    fprintf(p4,"\n  %s %s %sx10^%s",sci[num].ename,sci[num].kname,sci[num].fnum,sci[num].dnum);
            }
            else
            {
                if(sci[num].dnum==0)
                    fprintf(p4,"\n  %s %s %s %s",sci[num].ename,sci[num].kname,sci[num].fnum,sci[num].unit);
                else
                    fprintf(p4,"\n  %s %s %sx10^%s %s",sci[num].ename,sci[num].kname,sci[num].fnum,sci[num].dnum,sci[num].unit);
            }
            fprintf(p4,"\n");
            if(num==7)
            printf("1840\n");
            else if(num==23)
            printf("96485 C/mol\n");
            else if(strcmp(sci[num].unit,"x")==0)
            {
            if(sci[num].dnum==0)
                printf("%s\n",sci[num].fnum);
            else
                printf("%sx10^%s\n",sci[num].fnum,sci[num].dnum);
            }
            else
            {
            if(sci[num].dnum==0)
                printf("%s %s\n",sci[num].fnum,sci[num].unit);
            else
                printf("%sx10^%s %s\n",sci[num].fnum,sci[num].dnum,sci[num].unit);
            }
        }

    }
    printf("\n ��� : %d/%d\n ���� : %.2f\n",s,n,((float)s/n)*100);
    switch((int)(((float)s/n)*100)/10)
    {
        case 10: printf("\n excellent\n\n"); break;
        case 9: case 8: case 7: printf("\n good\n\n"); break;
        case 6: case 5: printf("\n not bad\n\n"); break;
        case 4: case 3: printf("\n bad\n\n"); break;
        case 2: case 1: printf("\n awful\n\n"); break;
        default: printf("\n .....terrible.....\n\n");
    }
    fprintf(p4,"\n ��� : %d/%d\n ���� : %.2f\n---------------------------------------------\n",s,n,((float)s/n)*100);
    fclose(p4);
    printf(" �����޴��� ���ư��� press 0\n");
    quit();
    return;
}
void gorandom(void)
{
    int i;
    srand(time(NULL));
    system("cls");
    printf("\n  ��Ģ: �Ҽ�����°¥������ �Է��ϼž� �մϴ�.(�����ϳ��� Ʋ���� ����)\n  ���� �Է��ϴ� ����� ������� 23.532x10^7kg�� 23.53 7 kg ���� �ۼ��Ͻð�\n  ������ ���� ������ 0���� ������ ���� ��� x�� �����ſ�.\n  SIǥ�ش����踦 ����ϼſ�. (��, H������ u�� ǥ��)\n");
    for(i=0;i<=24;i++)
        experience[i]=1;
    testmain(10);
    for(i=0;i<=24;i++)
        experience[i]=0;
    return;
}
void recommend(void)
{
    int i;
    srand(time(NULL));
    system("cls");
    printf("\n  ��Ģ: �Ҽ�����°¥������ �Է��ϼž� �մϴ�.(�����ϳ��� Ʋ���� ����)\n  ���� �Է��ϴ� ����� ������� 23.532x10^7kg�� 23.53 7 kg ���� �ۼ��Ͻð�\n  ������ ���� ������ 0���� ������ ���� ��� x�� �����ſ�.\n  SIǥ�ش����踦 ����ϼſ�. (��, H������ u�� ǥ��)\n");
   //1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,19,23
   for(i=1;i<=17;i++)
        experience[rec[i]]=1;
    testmain(17);
    for(i=0;i<=24;i++)
        experience[i]=0;
    return;
}
void choose(void)
{
    int temp,cnt=0;
    int x,i;
    printf("\n  ����� ���躸�ðڽ��ϱ�? (�ּ� 1�� �ִ� 23��, ���� ���ڳ� ���ڿ�,Ư����ȣ���� �Է����� ������.)\n  (���� ������ �ߺ��Է����� ����.) ");
    scanf("%d",&temp);
    if(temp>23||temp<1){
    do{
    printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n  ");
    scanf("%d",&temp);
    }while(temp>23||temp<1);
    }
    system("cls");
    printf("\n  ���躼������ ��ȣ�� �Է��ϼ���\n");
    for(i=1;i<=23;i++)
    {
        printf("%d %s  ",i,sci[i].kname);
        cnt++;
        if(cnt%3==0)
            printf("\n");
    }
    printf("\n");
    for(i=1;i<=temp;i++)
    {
        scanf("%d",&x);
        if(x>23||x<1)
            while(x>23||x<1)
            {
                printf("�߸��Է��ϼ̽��ϴ�. �ٽ��Է����ּ���.\n");
                scanf("%d",&x);
            }
        experience[x]=1;
    }
    srand(time(NULL));
    system("cls");
    printf("\n  ��Ģ: �Ҽ�����°¥������ �Է��ϼž� �մϴ�.(�����ϳ��� Ʋ���� ����)\n  ���� �Է��ϴ� ����� ������� 23.532x10^7kg�� 23.53 7 kg ���� �ۼ��Ͻð�\n  ������ ���� ������ 0���� ������ ���� ��� x�� �����ſ�.\n  SIǥ�ش����踦 ����ϼſ�. (��, H������ u�� ǥ��)\n");
    testmain(temp);
    for(i=0;i<=24;i++)
        experience[i]=0;
    return;
}
void hardcore(void)
{
    int i;
    srand(time(NULL));
    system("cls");
    printf("\n  ��Ģ: �Ҽ�����°¥������ �Է��ϼž� �մϴ�.(�����ϳ��� Ʋ���� ����)\n  ���� �Է��ϴ� ����� ������� 23.532x10^7kg�� 23.53 7 kg ���� �ۼ��Ͻð�\n  ������ ���� ������ 0���� ������ ���� ��� x�� �����ſ�.\n  SIǥ�ش����踦 ����ϼſ�. (��, H������ u�� ǥ��)\n");
   //1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,19,23����
    for(i=0;i<=24;i++)
        experience[i]=1;
   for(i=1;i<=17;i++)
        experience[rec[i]]=0;
    testmain(6);
    for(i=0;i<=24;i++)
        experience[i]=0;
    return;
}
void calculating(void)  //������ȯ
{
    int i,k;
    double l;
    int check=0;
    system("cls");
    for(i=1;i<=36;i++)
        printf("%d %s\n",i,hang[i].title);
    printf("37 C->F\n38 F->C\n");
    printf("\n  ��ȯ�� ���ϴ� ��ȣ�� �Է��ϼ���.���ڿ�, ����, Ư����ȣ�� ���� �Է����� ������.\n  ���Ḧ ���ϸ� 0�� �Է��ϼ���.\n");
    while(1){
    if(check==1)
        printf("\n������ȣ?\n");
    scanf("%d",&k);
    if(k==0)
    {
        system("cls");
        return;
    }
    while(k<1||k>38)
    {
        printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
        scanf("%d",&k);
        if(k==0)
            return;
    }
    if(k==37)
    {
        printf("\n x -> y\n x = ?\n");
        scanf("%lf",&l);
        printf("%lf",l*9/5+32);
    }
    else if(k==38)
    {
        printf("\n x -> y\n x = ?\n");
        scanf("%lf",&l);
        printf("%lf",(l-32)*9/5);
    }
    else{
    printf("\n x -> y\n x = ?\n");
    scanf("%lf",&l);
    printf("\n %lf\n",l*hang[k].exactly);
    }
    check=1;
    }
}
void mathmatics(void)  //�����ڷ�
{
    char x[50];
    int i,j;
    system("cls");
    FILE * p3;
    p3=fopen("mathmatics.txt","r");
    fscanf(p3,"%s",x);
    while(strcmp(x,"finish1"))
    {
        if(!strcmp(x,"n"))
            printf("\n");
        else
            printf("%s",x);
        fscanf(p3,"%s",x);
    }
    fscanf(p3,"%s",x);
    printf("%s",x);
    printf("\n \n");
        for(i=1;i<=21;i++)
        {
            for(j=1;j<=6;j++)
            {
                fscanf(p3,"%s",&x);
                printf("%s ",x);
            }
            printf("\n");
        }
    fscanf(p3,"%s",x);
    while(strcmp(x,"finish"))
    {
        if(!strcmp(x,"n"))
            printf("\n");
        else
            printf("%s",x);
        fscanf(p3,"%s",x);
    }
    fclose(p3);
    printf("\n ���θ޴��� ���ư��� press 0\n");
    quit();
    return;
}
void showelement(void)  //������ ����������
{
    int i=1;
    system("cls");
    printf("\n  ������ ���ϴ� ���ҿ� �ش��ϴ� ��ȣ�� �Է��ϼ���.\n  ���Ḧ ���ҽ� 0�� �Է��ϼ���.\n  ����� ����,���ڿ�,Ư����ȣ�� �Է����� ������.\n ");
    while(i!=0)
    {
        scanf("%d",&i);
        if(i==0)
            break;
        else if(i<1||i>118)
        {
            while(i<1||i>118)
            {
                if(i==0)
                    break;
                printf("�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
                scanf("%d",&i);
            }
        }
        if(i!=0)
            printf(" Number: %s\n Period: %s\n Group: %s\n Symbol: %s\n Name: %s\n Mass: %s\n Radius: %s\n Valence electron: %s\n Stable isotopes: %s\n Melting point: %s\n Boiling point: %s\n Density: %s\n\n",ele[i].number,ele[i].period,ele[i].group,ele[i].symbol,ele[i].name,ele[i].mass,ele[i].radius,ele[i].valence,ele[i].stableisotopes,ele[i].meltingpoint,ele[i].boilingpoint,ele[i].density);
    }
    system("cls");
    return;
}
void filesci(void)
{
    int i;
    FILE* p1;
    p1=fopen("science.txt","r");
    for(i=1;i<=23;i++)
        fscanf(p1,"%s %s %s %s %s",sci[i].ename,sci[i].kname,sci[i].fnum,sci[i].dnum,sci[i].unit);
    fclose(p1);
}
void fileele(void)
{
    int i;
    FILE* p2;
    p2=fopen("element.txt","r");
    for(i=1;i<=118;i++)
        fscanf(p2,"%s %s %s %s %s %s %s %s %s %s %s %s",ele[i].number,ele[i].period,ele[i].group,ele[i].symbol,ele[i].name,ele[i].mass,ele[i].radius,ele[i].valence,ele[i].stableisotopes,ele[i].meltingpoint,ele[i].boilingpoint,ele[i].density);
    fclose(p2);
}
void filecon(void)
{
    int i;
    FILE * p6;
    p6=fopen("convert.txt","r");
    for(i=1;i<=36;i++)
        fscanf(p6,"%s %lf",hang[i].title,&hang[i].exactly);
    fclose(p6);
    return;
}
void testelement(void)
{
    char t[30],p[30];
    FILE * p7;
    p7=fopen("history.txt","a");
    int num;
    srand(time(NULL));
    system("cls");
    time_t ti=time(NULL);
    struct tm tm=*localtime(&ti);
    p7=fopen("history.txt","a");
    fprintf(p7,"\n%d.%d.%d. %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
    fprintf(p7,"\nƲ������:\n");
    printf("���Ḧ ���Ͻø� ���ڿ� quit�� �Է��ϼ���.\n\n");
    while(1)
    {
    num=rand()%118+1;
    printf("%s %s �� �ֱ� �� ���Դϱ�?\n",ele[num].symbol,ele[num].name);
    scanf("%s",t);
    if(!strcmp(t,"quit"))
        break;
    scanf("%s",p);
    if(!strcmp(p,"quit"))
        break;
    if(!strcmp(t,ele[num].period)&&!strcmp(p,ele[num].group))
        printf("correct!\n\n");
    else{
        printf("wrong!  %s %s\n\n",ele[num].period,ele[num].group);
        fprintf(p7,"\n%s %s %s�ֱ� %s��\n",ele[num].symbol,ele[num].name,ele[num].period,ele[num].group);
    }
    }
    fprintf(p7,"\n---------------------------------------------\n");
    fclose(p7);
    system("cls");
    return;
}
