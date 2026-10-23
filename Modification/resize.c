#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void modify_size(Shape *shape_to_modify)
{
    if (shape_to_modify == NULL)
        return;

    printf("\n==================================================\n");
    printf("               RESIZE YOUR SHAPE                  \n");
    printf("==================================================\n");

    switch (shape_to_modify->shape_enum)
    {
    case LINE:
        printf("Current Line points: A(%.2f, %.2f) to B(%.2f, %.2f)\n",
               shape_to_modify->shape_union.line->x, shape_to_modify->shape_union.line->y,
               shape_to_modify->shape_union.line->x2, shape_to_modify->shape_union.line->y2);

        printf("Enter new X1: ");
        scanf("%lf", &shape_to_modify->shape_union.line->x);
        printf("Enter new Y1: ");
        scanf("%lf", &shape_to_modify->shape_union.line->y);
        printf("Enter new X2: ");
        scanf("%lf", &shape_to_modify->shape_union.line->x2);
        printf("Enter new Y2: ");
        scanf("%lf", &shape_to_modify->shape_union.line->y2);
        break;

    case CIRCLE:
        printf("Current Circle: Center(%.2f, %.2f) | Radius = %.2f\n",
               shape_to_modify->shape_union.circle->x,
               shape_to_modify->shape_union.circle->y,
               shape_to_modify->shape_union.circle->radius);

        printf("Enter new radius: ");
        scanf("%lf", &shape_to_modify->shape_union.circle->radius);
        printf("Enter new Center X: ");
        scanf("%lf", &shape_to_modify->shape_union.circle->x);
        printf("Enter new Center Y: ");
        scanf("%lf", &shape_to_modify->shape_union.circle->y);
        break;

    case RECTANGLE:
        printf("Current Rectangle: Top-Left(%.2f, %.2f) | Length = %.2f, Width = %.2f\n",
               shape_to_modify->shape_union.rectangle->x, shape_to_modify->shape_union.rectangle->y,
               shape_to_modify->shape_union.rectangle->length, shape_to_modify->shape_union.rectangle->width);

        printf("Enter new length: ");
        scanf("%lf", &shape_to_modify->shape_union.rectangle->length);
        printf("Enter new width:  ");
        scanf("%lf", &shape_to_modify->shape_union.rectangle->width);
        printf("Enter new Top-Left X: ");
        scanf("%lf", &shape_to_modify->shape_union.rectangle->x);
        printf("Enter new Top-Left Y: ");
        scanf("%lf", &shape_to_modify->shape_union.rectangle->y);
        break;

    case SQUARE:
        printf("Current Square: Top-Left(%.2f, %.2f) | Side length = %.2f\n",
               shape_to_modify->shape_union.square->x,
               shape_to_modify->shape_union.square->y,
               shape_to_modify->shape_union.square->length);

        printf("Enter new side length: ");
        scanf("%lf", &shape_to_modify->shape_union.square->length);
        printf("Enter new Top-Left X: ");
        scanf("%lf", &shape_to_modify->shape_union.square->x);
        printf("Enter new Top-Left Y: ");
        scanf("%lf", &shape_to_modify->shape_union.square->y);
        break;

    case ELLIPSE:
        printf("Current Ellipse: Center(%.2f, %.2f) | Small Radius = %.2f, Big Radius = %.2f\n",
               shape_to_modify->shape_union.ellipse->x, shape_to_modify->shape_union.ellipse->y,
               shape_to_modify->shape_union.ellipse->small_radius, shape_to_modify->shape_union.ellipse->big_radius);

        printf("Enter new small radius: ");
        scanf("%lf", &shape_to_modify->shape_union.ellipse->small_radius);
        printf("Enter new big radius:   ");
        scanf("%lf", &shape_to_modify->shape_union.ellipse->big_radius);
        printf("Enter new Center X: ");
        scanf("%lf", &shape_to_modify->shape_union.ellipse->x);
        printf("Enter new Center Y: ");
        scanf("%lf", &shape_to_modify->shape_union.ellipse->y);
        break;
    }

    printf("\nDimensions and positions updated successfully!\n");
}