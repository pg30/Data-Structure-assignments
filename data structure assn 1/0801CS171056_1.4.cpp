#include<stdio.h>
#include<string.h>
int main(){
	FILE *fp;
	char str[100];
	int year[1000];
	int constituency_no[1000];
	char constituency_name[200];
	char category[1000][5];
	char name[1000][200];
	char gender[1000];
	char party_name[1000][200];
	char abb[1000][10];
	int votes[1000];
	int voters[1000];
	int numberofentry;
	fp = fopen("Indore_Election_data_modified.txt","r");
	if(fp==NULL)
	printf("unable to open the file");
	else{
		int i=0;
		while(!feof(fp)){
		fscanf(fp,"%[^\t]",str);
		//printf("%s",str);
		fscanf(fp,"%d\t%d\t",&year[i],&constituency_no[i]);
		//printf(" %d %d",year[i],constituency_no[i]);
		fscanf(fp,"%[^\t]\t",constituency_name);
		//printf(" %s",constituency_name);
		fscanf(fp,"%[^\t]\t",&category[i]);
		//printf(" %s",category[i]);
		fscanf(fp,"%[^\t]\t",&name[i]);
		//printf(" %s",name[i]);
		fscanf(fp,"%[^\t]\t",&gender[i]);
		//printf(" %c",gender[i]);
		if((constituency_no[i]==204)||(constituency_no[i]==206)||(constituency_no[i]==207))
		{
		fscanf(fp,"%[^\t]\t",&abb[i]);
		fscanf(fp,"%d\t%d\n",&votes[i],&voters[i]);
	}
		else
		{
		fscanf(fp,"%[^\t]\t",&party_name[i]);
		//printf(" %s",party_name[i]);
		fscanf(fp,"%[^\t]\t",&abb[i]);
		//printf(" %s",abb[i]);
		fscanf(fp,"%d\t%d\n",&votes[i],&voters[i]);
		//printf(" %d %d",votes[i],voters[i]);
	}
		i++;
		numberofentry = i;

		}
		fclose(fp);
	}
	    //finding winner of each election
	    printf("year	constituency no	winner \n");
	    int max=votes[0];
		int winner[400][300]={0};
	
		for(int i=0;i<numberofentry;i++)
		{
				if(constituency_no[i]==constituency_no[i+1])
				{
					if(max<=votes[i+1])
					max=votes[i+1];
					continue;
				}
				if(winner[year[i]-1900][constituency_no[i]-100]==0) 
				winner[year[i]-1900][constituency_no[i]-100]=i;
		}
		int flg[400][300]={0};
		for(int i=0;i<numberofentry;i++)
		{
			if(flg[year[i]-1900][constituency_no[i]-100]==0)
			{
					printf("%d	%d		",year[i],constituency_no[i]);
					printf("%s\n",name[winner[year[i]-1900][constituency_no[i]-100]]);
					flg[year[i]-1900][constituency_no[i]-100]=1;
			}
		}
		//% of male candidates as well as female candidates
		printf("\nyear	male%%		female%%\n");
		int male=0,female=0,total;
		int data[100]={0};
		for(int i=0;i<numberofentry;i++)
		{
			if(year[i]==year[i+1])
			{ 
				if(gender[i]=='M')
				male++;
				else
				female++;
		        continue;
			}
			else
			{
			    if(gender[i]=='M')
				male++;
				else
				female++;
		    
			total = male+female;
			float p1,p2;
			p1=(float)(male*100)/total;
			p2=(float)(female*100)/total;
			printf("%d	%f%%	%f%% \n",year[i],p1,p2);
			male=0;
			female=0;
		}
		}
		//total % of votes recieved by a party
		printf("\nyear	party abb	vote%%\n");
		
		
        int hash[200][400]={0};
    
           for(int j=0;j<numberofentry;j++)
		{
			if(strcmp(abb[j],"IND")==0)
			hash[year[j]-1900][0]=hash[year[j]-1900][0]+votes[j];
			if(strcmp(abb[j],"INC")==0)
			hash[year[j]-1900][1]=hash[year[j]-1900][1]+votes[j];
			if(strcmp(abb[j],"JNP")==0)
			hash[year[j]-1900][2]=hash[year[j]-1900][2]+votes[j];
			if(strcmp(abb[j],"JNP(SR)")==0)
			hash[year[j]-1900][3]=hash[year[j]-1900][3]+votes[j];
			if(strcmp(abb[j],"JNP(JP)")==0)
			hash[year[j]-1900][4]=hash[year[j]-1900][4]+votes[j];
			if(strcmp(abb[j],"JNP(SC)")==0)
			hash[year[j]-1900][5]=hash[year[j]-1900][5]+votes[j];
			if(strcmp(abb[j],"BJP")==0)
			hash[year[j]-1900][6]=hash[year[j]-1900][6]+votes[j];
			if(strcmp(abb[j],"INC(I)")==0)
			hash[year[j]-1900][7]=hash[year[j]-1900][7]+votes[j];
			if(strcmp(abb[j],"ICS")==0)
			hash[year[j]-1900][8]=hash[year[j]-1900][8]+votes[j];
			if(strcmp(abb[j],"CPI")==0)
			hash[year[j]-1900][9]=hash[year[j]-1900][9]+votes[j];
			if(strcmp(abb[j],"DDP")==0)
			hash[year[j]-1900][10]=hash[year[j]-1900][10]+votes[j];
			if(strcmp(abb[j],"CPM")==0)
			hash[year[j]-1900][11]=hash[year[j]-1900][11]+votes[j];
			if(strcmp(abb[j],"JD")==0)
			hash[year[j]-1900][12]=hash[year[j]-1900][12]+votes[j];
			if(strcmp(abb[j],"BSP")==0)
			hash[year[j]-1900][13]=hash[year[j]-1900][13]+votes[j];
			if(strcmp(abb[j],"SHS")==0)
			hash[year[j]-1900][14]=hash[year[j]-1900][14]+votes[j];
			if(strcmp(abb[j],"SP")==0)
			hash[year[j]-1900][15]=hash[year[j]-1900][15]+votes[j];
			if(strcmp(abb[j],"RPI(D)")==0)
			hash[year[j]-1900][16]=hash[year[j]-1900][16]+votes[j];
			if(strcmp(abb[j],"KMGR")==0)
			hash[year[j]-1900][17]=hash[year[j]-1900][17]+votes[j];
			if(strcmp(abb[j],"RPI")==0)
			hash[year[j]-1900][18]=hash[year[j]-1900][18]+votes[j];
			if(strcmp(abb[j],"NCP")==0)
			hash[year[j]-1900][19]=hash[year[j]-1900][19]+votes[j];
			if(strcmp(abb[j],"RPI(A)")==0)
			hash[year[j]-1900][20]=hash[year[j]-1900][20]+votes[j];
			if(strcmp(abb[j],"BJSH")==0)
			hash[year[j]-1900][21]=hash[year[j]-1900][21]+votes[j];
		}
		int total1[400]={0},sum1=0;
		for(int j=0;j<400;j++){
		for(int i=0;i<22;i++)
		{
			if(year[j]!=year[j+1])
			sum1=sum1+hash[year[j]-1900][i];
			else
			break;
		}
		total1[year[j]-1900]=sum1;
		sum1=0;
	}
		     int flag[200][400]={0},temp;
			for(int j=0;j<numberofentry;j++)
			{
				if(strcmp(abb[j],"IND")==0){
				
			if(flag[year[j]-1900][0]==0)
			{
				temp=(hash[year[j]-1900][0])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][0]=1;
			}}
			if(strcmp(abb[j],"INC")==0){
			if(flag[year[j]-1900][1]==0)
			{
				temp=(hash[year[j]-1900][1])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][1]=1;
			}
			}
			if(strcmp(abb[j],"JNP")==0){
			if(flag[year[j]-1900][2]==0)
			{
				temp=(hash[year[j]-1900][2])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][2]=1;
			}
			}
			if(strcmp(abb[j],"JNP(SR)")==0){
				if(flag[year[j]-1900][3]==0)
			{
				temp=(hash[year[j]-1900][3])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][3]=1;
			}
			}
			if(strcmp(abb[j],"JNP(JP)")==0){
				if(flag[year[j]-1900][4]==0)
			{
				temp=(hash[year[j]-1900][4])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][4]=1;
			}
			}
			if(strcmp(abb[j],"JNP(SC)")==0){
				if(flag[year[j]-1900][5]==0)
			{
				temp=(hash[year[j]-1900][5])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][5]=1;
			}
			}
			if(strcmp(abb[j],"BJP")==0){
				if(flag[year[j]-1900][6]==0)
			{
				temp=(hash[year[j]-1900][6])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][6]=1;
			}
			}
			if(strcmp(abb[j],"INC(I)")==0){
				if(flag[year[j]-1900][7]==0)
			{
				temp=(hash[year[j]-1900][7])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][7]=1;
			}
			}
			if(strcmp(abb[j],"ICS")==0){
				if(flag[year[j]-1900][8]==0)
			{
				temp=(hash[year[j]-1900][8])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][8]=1;
			}
			}
			if(strcmp(abb[j],"CPI")==0){
				if(flag[year[j]-1900][9]==0)
			{
				temp=(hash[year[j]-1900][9])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][9]=1;
			}
			}
			if(strcmp(abb[j],"DDP")==0){
				if(flag[year[j]-1900][10]==0)
			{
				temp=(hash[year[j]-1900][10])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][10]=1;
			}
			}
			if(strcmp(abb[j],"CPM")==0){
				if(flag[year[j]-1900][11]==0)
			{
				temp=(hash[year[j]-1900][11])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][11]=1;
			}
			}
			if(strcmp(abb[j],"JD")==0){
				if(flag[year[j]-1900][12]==0)
			{
				temp=(hash[year[j]-1900][12])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][12]=1;
			}
			}
			if(strcmp(abb[j],"BSP")==0){
				if(flag[year[j]-1900][13]==0)
			{
				temp=(hash[year[j]-1900][13])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][13]=1;
			}
			}
			if(strcmp(abb[j],"SHS")==0){
				if(flag[year[j]-1900][14]==0)
			{
				temp=(hash[year[j]-1900][14])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][14]=1;
			}
			}
			if(strcmp(abb[j],"SP")==0){
				if(flag[year[j]-1900][15]==0)
			{
				temp=(hash[year[j]-1900][15])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][15]=1;
			}
			}
			if(strcmp(abb[j],"RPI(D)")==0){
				if(flag[year[j]-1900][16]==0)
			{
				temp=(hash[year[j]-1900][16])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][16]=1;
			}
			}
			if(strcmp(abb[j],"KMGR")==0){
				if(flag[year[j]-1900][17]==0)
			{
				temp=(hash[year[j]-1900][17])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][17]=1;
			}
			}
			if(strcmp(abb[j],"RPI")==0){
				if(flag[year[j]-1900][18]==0)
			{
				temp=(hash[year[j]-1900][18])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][18]=1;
			}
			}
			if(strcmp(abb[j],"NCP")==0){
				if(flag[year[j]-1900][19]==0)
			{
				temp=(hash[year[j]-1900][19])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][19]=1;
			}
			}
			if(strcmp(abb[j],"RPI(A)")==0){
				if(flag[year[j]-1900][20]==0)
			{
				temp=(hash[year[j]-1900][20])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][20]=1;
			}
		}
			if(strcmp(abb[j],"BJSH")==0){
				if(flag[year[j]-1900][21]==0)
			{
				temp=(hash[year[j]-1900][21])*100/total1[year[j]-1900];
				printf("%d	%s		%d%%\n",year[j],abb[j],temp);
					flag[year[j]-1900][21]=1;
			}
			}
		}
				
	
	return 0;
}

