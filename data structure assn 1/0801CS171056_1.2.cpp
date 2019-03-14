#include<stdio.h>
struct Point {
    int x,y;
};
struct LineSeg {
    struct Point p1,p2;
};
int SegIntersect(struct LineSeg l1,struct LineSeg l2) {
	float m1,m2;
	m1 = (float)(l1.p2.y-l1.p1.y)/(l1.p2.x-l1.p1.x);
	m2 = (float)(l2.p2.y-l2.p1.y)/(l2.p2.x-l2.p1.x);
	if(m1==m2)
	return 0;
	float c1,c2;
	c1=l1.p1.y-m1*l1.p1.x;
	c2=l2.p1.y-m2*l2.p1.x;
	float x,y;
	x = (c1-c2)/(m2-m1);
	y = m1*l1.p1.x+c1;
	if(((l1.p1.x<=x<=l1.p2.x)||(l1.p2.x<=x<=l1.p1.x))&&((l1.p1.y<=y<=l1.p2.y)||(l1.p2.y<=y<=l1.p1.y)))
	return 1;
	else 
	return 0;
	}
int main(){
	struct LineSeg l1,l2;
printf("enter the first point of l1\n");
scanf("%d%d",&l1.p1.x,&l1.p1.y);
printf("enter the second point of l1\n");
scanf("%d%d",&l1.p2.x,&l1.p2.y);
printf("enter the first point of l2\n");
scanf("%d%d",&l2.p1.x,&l2.p1.y);
printf("enter the second point of l2\n");
scanf("%d%d",&l2.p2.x,&l2.p2.y);
int result = SegIntersect(l1,l2);
if(result == 1)
    printf("TRUE\n");
if(result == 0)
    printf("FALSE\n");
return 0;
}

