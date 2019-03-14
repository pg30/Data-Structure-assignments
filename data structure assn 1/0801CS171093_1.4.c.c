#include<stdio.h>
#include<string.h>

#define LINE_SIZE 250

int k;
 struct info
  {
     char st_name[30];
     char year[8];
     char ac_no[6];
     char ac_name[30];
     char ac_type[30];
     char cand_name[30];
     char cand_sex[4];
     char partyname[30];
     char partyabbre[8];
     char totalvotpoll[10];
     char electors[10];
  };

void getfile_content(char *file,struct info *inf)
{
    char line[279];
    FILE *fp;
    char *buf=0;
    k=-1;

    fp = fopen(file,"r");

    while(fgets(line,10000,fp))
    {
        k++;
       if(k<253)
       {
        buf = strtok(line,"\t\n");
        if(buf)strcpy(inf[k].st_name,buf);

        buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].year,buf);

        buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].ac_no,buf);

        buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].ac_name,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].ac_type,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].cand_name,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].cand_sex,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].partyname,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].partyabbre,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].totalvotpoll,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].electors,buf);
       }
       else
       {

           // because year 2008 onwards party abbreviation is not there (i.e after line no 253 on the election file
        buf = strtok(line,"\t\n");
        if(buf)strcpy(inf[k].st_name,buf);

        buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].year,buf);

        buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].ac_no,buf);

        buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].ac_name,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].ac_type,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].cand_name,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].cand_sex,buf);



         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].partyabbre,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].totalvotpoll,buf);

         buf = strtok(NULL,"\t\n");
        if(buf)strcpy(inf[k].electors,buf);
       }
    }
    fclose(fp);
}

int main()
{


  struct info inf[280],d,*tmp;
  FILE *fr;

  char line[LINE_SIZE];

  fr = fopen("Indore_Election_data_modified.txt","rb");

  tmp = &inf[0];

  getfile_content("Indore_Election_data_modified.txt",tmp);

  int j=0,q,i,l=0,cinc=0,cjnp=0,cbjp=0;
   double m=0,f=0;

  printf("\n                     Winners of Election   \n\n");

  for(i=0;i<=k;i++)
  {

      if(atoi(inf[i].year) == atoi(inf[i+1].year))
      {
          if(atoi(inf[i].ac_no) == atoi(inf[i+1].ac_no))
          {
              if(atoi(inf[i+1].totalvotpoll) > atoi(inf[j].totalvotpoll))
               j=i+1;
          }
          else
          {
             if(strcmp(inf[j].partyabbre,"INC")==0)
                cinc++;

             if(strcmp(inf[j].partyabbre,"JNP")==0)
                cjnp++;

             if(strcmp(inf[j].partyabbre,"BJP")==0)
                cbjp++;

             printf("%s  %s  %s  %s  %s  %s  %s  %s\n\n",inf[j].year,inf[j].ac_no,inf[j].ac_name,inf[j].ac_type,inf[j].cand_name,inf[j].cand_sex,inf[j].partyabbre,inf[j].totalvotpoll);
             j = i+1;
          }
      }
      else
      {
          if(strcmp(inf[j].partyabbre,"INC")==0)
                cinc++;

             if(strcmp(inf[j].partyabbre,"JNP")==0)
                cjnp++;

             if(strcmp(inf[j].partyabbre,"BJP")==0)
                cbjp++;

          printf("%s  %s  %s  %s  %s  %s  %s  %s\n\n",inf[j].year,inf[j].ac_no,inf[j].ac_name,inf[j].ac_type,inf[j].cand_name,inf[j].cand_sex,inf[j].partyabbre,inf[j].totalvotpoll);
          j = i+1;
      }
  }

     float IND=0,JNP=0,BJP=0,INC=0,CPI=0,DDP=0,CPM=0,BSP=0;
      printf("\n\npercentage of male and female year wise :\n");
      printf("  year        male        female\n\n");

      for(i=0;i<=k;i++)
      {

         if(atoi(inf[i].year) == atoi(inf[i+1].year))
         {
                 if(strcmp(inf[i].cand_sex,"M")==0)
                    m++;
                 else
                    f++;
         }
         else
         {

                 if(strcmp(inf[i].cand_sex,"M")==0)
                    m++;
                 else
                    f++;

             double pm,pf;

             pm = (m/(m+f))*100;
             pf = (f/(m+f))*100;

             m=0,f=0;

             printf("   %s     %f      %f\n",inf[i].year,pm,pf);
         }
      }

      printf("\n\npercentage of votes received by party : \n\n");

      printf("  year    party abbreviation    percent votes\n\n");
      for(i=0;i<=k;i++)
      {

         if(atoi(inf[i].year) == atoi(inf[i+1].year))
         {
                if(strcmp(inf[i].partyabbre,"IND")==0)
                    IND += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"JNP")==0)
                    JNP += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"BJP")==0)
                    BJP += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"INC")==0)
                    INC += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"CPI")==0)
                    CPI += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"DDP")==0)
                    DDP += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"CPM")==0)
                    CPM += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"BSP")==0)
                    BSP += atoi(inf[i].totalvotpoll);
         }
         else
         {
                if(strcmp(inf[i].partyabbre,"IND")==0)
                    IND += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"JNP")==0)
                    JNP += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"BJP")==0)
                    BJP += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"INC")==0)
                    INC += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"CPI")==0)
                    CPI += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"DDP")==0)
                    DDP += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"CPM")==0)
                    CPM += atoi(inf[i].totalvotpoll);

                if(strcmp(inf[i].partyabbre,"BSP")==0)
                    BSP += atoi(inf[i].totalvotpoll);

                double p1,p2,p3,p4,p5,p7,p6,t,p8;

                t = IND+JNP+BJP+INC+CPI+DDP+CPM+BSP;

                p1 = IND/t;
                p2 = JNP/t;
                p3 = BJP/t;
                p4 = INC/t;
                p5 = CPI/t;
                p6 = DDP/t;
                p7 = CPM/t;
                p8 = BSP/t;

                if(p1)
                printf("  %s          IND              %f\n",inf[i].year,p1);
                if(p2)
                printf("  %s          JNP              %f\n",inf[i].year,p2);
                if(p3)
                printf("  %s          BJP              %f\n",inf[i].year,p3);
                if(p4)
                printf("  %s          INC              %f\n",inf[i].year,p4);
                if(p5)
                printf("  %s          CPI              %f\n",inf[i].year,p5);
                if(p6)
                printf("  %s          DDP              %f\n",inf[i].year,p6);
                if(p7)
                printf("  %s          CPM              %f\n",inf[i].year,p7);
                if(p8)
                printf("  %s          BSP              %f\n",inf[i].year,p8);

                IND=0,JNP=0,BJP=0,INC=0,CPI=0,DDP=0,CPM=0,BSP=0;
         }
      }

      printf("\n\nParty wins most number of times : ");
     if(cinc > cbjp && cinc > cjnp)
        printf("INC\n\n");
     else if(cbjp > cinc && cbjp > cjnp)
        printf("BJP\n\n");
     else
        printf("JNP\n\n");

  return 0;
}


