#include <stdio.h>
#include <stdlib.h>
#include "line.h"

Line* create_line(double x, double y, double x2, double y2) 
{
    Line* new_line = malloc(sizeof(Line));
    new_line->x = x;
    new_line->y = y;
    new_line->x2 = x2;
    new_line->y2 = y2;
    return new_line;
}

Line* ask_user_to_create_line() 
{
    double x,y,x2,y2;
    printf("Enter point A X :");
    scanf("%lf", &x);
    printf("Enter point A Y :");
    scanf("%lf", &y);
    printf("Enter point B X :"); 
    scanf("%lf", &x2);
    printf("Enter point B Y :");
    scanf("%lf", &y2);

    return create_line(x,y,x2,y2);
}

/*
int main()
{
    Line* line = ask_user_to_create_line();

    return EXIT_SUCCESS;
}
*/