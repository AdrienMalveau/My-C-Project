#include <stdio.h>
#include <stdlib.h>
#include "square.h"

Square *create_square(double x, double y, double length)
{
    Square *new_square = malloc(sizeof(Square));
    new_square->x = x;
    new_square->y = y;
    new_square->length = length;
    return new_square;
}

Square *ask_user_to_create_square()
{
    double x, y, length;
    printf("Enter center X coordinate :");
    scanf("%lf", &x);
    printf("Enter center Y coordinate  :");
    scanf("%lf", &y);
    printf("Enter side length :");
    scanf("%lf", &length);

    return create_square(x, y, length);
}

/*
int main()
{
     Square* square = ask_user_to_create_square();

    return EXIT_SUCCESS;
}
*/