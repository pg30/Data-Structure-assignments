#include<stdio.h>
struct vertex{
    float x;
    float y;
};

struct triangle{
    struct vertex vertices[3];
};

float cal_area(struct triangle aTriangle) {
    float area1;
    area1 = ((aTriangle.vertices[0].x)*(aTriangle.vertices[1].y - aTriangle.vertices[2].y) + (aTriangle.vertices[1].x)*(aTriangle.vertices[2].y-aTriangle.vertices[0].y) + (aTriangle.vertices[2].x)*(aTriangle.vertices[0].y-aTriangle.vertices[1].y))/2;
    if(area1>=0)
        return area1;
    else
        return -area1;
    }
    int main(){
    struct triangle aTriangle;
    printf("enter the first coordinate\n");
    scanf("%f%f",&aTriangle.vertices[0].x,&aTriangle.vertices[0].y);
    printf("enter the second coordinate\n");
    scanf("%f%f",&aTriangle.vertices[1].x,&aTriangle.vertices[1].y);
    printf("enter the third coordinate\n");
    scanf("%f%f",&aTriangle.vertices[2].x,&aTriangle.vertices[2].y);
    float area = cal_area(aTriangle);
    printf("area of the triangle is %f",area);
    return 0;
}

