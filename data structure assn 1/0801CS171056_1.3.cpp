#include<stdio.h>
struct rational{
	int numerator,denominator;
	};
void reduce(struct rational *inputrational, struct rational *outputrational) {
	int n,m,i,min;
    n=inputrational->numerator;
    m=inputrational->denominator;
    min=n>m?m:n;
    for(i=min;i>0;i--)
	{
        if(n%i==0 && m%i==0)
		{
            n=n/i;
            m=m/i;
            break;
        }
    }
    outputrational->numerator=n;
    outputrational->denominator=m;
}
int isEqual (struct rational num1, struct rational num2){
	struct rational n1,n2;
	reduce(&num1,&n1);
	reduce(&num2,&n2);
	if((n1.denominator==0)||(n2.denominator==0))
	return 0;
	if((n1.numerator==n2.numerator)&&(n1.denominator==n2.denominator))
	return 1;
		else 
	return 0;
}
int main(){
	struct rational num1,num2;
	printf("enter the first number\n");
	scanf("%d%d",&num1.numerator,&num1.denominator); 
	printf("enter the second number\n");
	scanf("%d%d",&num2.numerator,&num2.denominator);
	int result = isEqual(num1,num2);
	if(result ==1)
	printf("TRUE\n");
	else
	printf("FALSE\n");
	return 0;
}
