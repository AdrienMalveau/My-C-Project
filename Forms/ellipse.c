#include <stdio.h>
#include <stdlib.h>
#include "ellipse.h"

Ellipse *create_ellipse(double x, double y, double small_radius, double big_radius)
{
    Ellipse *new_ellipse = malloc(sizeof(Ellipse));
    new_ellipse->x = x;
    new_ellipse->y = y;
    new_ellipse->small_radius = small_radius;
    new_ellipse->big_radius = big_radius;
    return new_ellipse;
}

Ellipse *ask_user_to_create_ellipse()
{
    double x, y, small_radius, big_radius;
    printf("Enter center X coordinate :");
    scanf("%lf", &x);
    printf("Enter center Y coordinate :");
    scanf("%lf", &y);
    printf("Enter small radius :");
    scanf("%lf", &small_radius);
    printf("Enter big radius :");
    scanf("%lf", &big_radius);

    return create_ellipse(x, y, small_radius, big_radius);
}

/*
int main()
{
    ellipse* ellipse = ask_user_to_create_ellipse();

    return EXIT_SUCCESS;
}
*/