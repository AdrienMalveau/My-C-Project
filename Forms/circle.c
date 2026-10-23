#include <stdio.h>
#include <stdlib.h>
#include "circle.h"

Circle* create_circle(double x, double y, double radius) 
{
    Circle* new_circle = malloc(sizeof(Circle));
    new_circle->x = x;
    new_circle->y = y;
    new_circle->radius = radius;
    return new_circle;
}

Circle* ask_user_to_create_circle() 
{
    double x,y,radius;
    printf("Enter center X coordinate :");
    scanf("%lf", &x);
    printf("Enter center Y coordinate :");
    scanf("%lf", &y);
    printf("Enter radius :"); 
    scanf("%lf", &radius);

    return create_circle(x,y,radius);
}

/*
int main()
{
    Circle* circle = ask_user_to_create_circle();

    return EXIT_SUCCESS;
}
*/