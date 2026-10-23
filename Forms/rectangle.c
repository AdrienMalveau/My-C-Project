#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

Rectangle *create_rectangle(double x, double y, double length, double width)
{
    Rectangle *new_rectangle = malloc(sizeof(Rectangle));
    new_rectangle->x = x;
    new_rectangle->y = y;
    new_rectangle->length = length;
    new_rectangle->width = width;
    return new_rectangle;
}

Rectangle *ask_user_to_create_rectangle()
{
    double x, y, length, width;
    printf("Enter center X coordinate :");
    scanf("%lf", &x);
    printf("Enter center Y coordinate :");
    scanf("%lf", &y);
    printf("Enter length :");
    scanf("%lf", &length);
    printf("Enter width :");
    scanf("%lf", &width);

    return create_rectangle(x, y, length, width);
}

/*
int main()
{
    Rectangle* rectangle = ask_user_to_create_rectangle();

    return EXIT_SUCCESS;
}
*/