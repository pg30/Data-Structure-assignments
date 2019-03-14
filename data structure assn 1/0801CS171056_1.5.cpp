#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("IntegerList.txt","r");
     long long int list[100000];
	
	if(fp==NULL)
	{
	  printf("unable to open the file ");	
	}
	else
	{ int k=0;
	 while(!feof(fp))
	{
		fscanf(fp,"%lld",&list[k]);
		k++;
	}
	
}
    fclose(fp);
	unsigned long long int sum=0,max,min,i,j,a;
	for(i=0;i<10000;i++)
	{
		sum = sum+list[i];
	}
	max=list[0];
	min=list[0];
	for(i=0;i<10000;i++)
	{
		if(min>list[i])
		min=list[i];
		if(max<list[i])
		max=list[i];
	}
	
	printf("%lld	%lld\n",sum-max,sum-min);
	
	//challenge part of the question
    for (i=0;i<10000;i++) 
        {
           for (j=i+1;j<10000;j++)
            {
              if (list[i]>list[j]) 
                {
                    a=list[i];
                    list[i]=list[j];
                    list[j]=a;
                } 
            }
 
        }
        int n;
        printf("\nenter the value of n\n");
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
        	sum=sum+list[i];
		}
		printf("%lld  ",sum);
		sum=0;
		for(i=9999;i>9999-n;i--)
		{
			sum=sum+list[i];
		}
		printf("%lld",sum);
	return 0;
}

