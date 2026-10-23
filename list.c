#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "Forms/circle.h"
#include "Forms/ellipse.h"
#include "Forms/line.h"
#include "Forms/rectangle.h"
#include "Forms/square.h"
#include "Modification/color.h"

Shape *create_shape(ShapeEnum choice)
{
    Shape *shape = calloc(1, sizeof(*shape));
    if (shape == NULL)
        return NULL;

    shape->shape_enum = choice;
    shape->color = calloc(1, sizeof(*shape->color));
    if (shape->color == NULL)
    {
        free(shape);
        return NULL;
    }

    choose_color_from_list(shape->color);

    int geometry_created;
    switch (choice)
    {
    case LINE:
        shape->shape_union.line = ask_user_to_create_line();
        geometry_created = shape->shape_union.line != NULL;
        break;
    case SQUARE:
        shape->shape_union.square = ask_user_to_create_square();
        geometry_created = shape->shape_union.square != NULL;
        break;
    case CIRCLE:
        shape->shape_union.circle = ask_user_to_create_circle();
        geometry_created = shape->shape_union.circle != NULL;
        break;
    case RECTANGLE:
        shape->shape_union.rectangle = ask_user_to_create_rectangle();
        geometry_created = shape->shape_union.rectangle != NULL;
        break;
    case ELLIPSE:
        shape->shape_union.ellipse = ask_user_to_create_ellipse();
        geometry_created = shape->shape_union.ellipse != NULL;
        break;
    default:
        free(shape->color);
        free(shape);
        return NULL;
    }

    if (!geometry_created)
    {
        free(shape->color);
        free(shape);
        return NULL;
    }

    return shape;
}

void list_shape(Shape *listshape[], int nbr_shape)
{
    if (nbr_shape == 0)
    {
        printf("The storage is empty\n");
        return;
    }

    for (int i = 0; i < nbr_shape; i++)
    {
        printf("Shapes number %d : ", i + 1);

        switch (listshape[i]->shape_enum)
        {
        case LINE:
            printf("Line from point A: (X1 %.2f, Y1 %.2f) to point B: (X2 %.2f, Y2 %.2f)\n",
                   listshape[i]->shape_union.line->x, listshape[i]->shape_union.line->y,
                   listshape[i]->shape_union.line->x2, listshape[i]->shape_union.line->y2);
            break;
        case CIRCLE:
            printf("Circle of center (X : %.2f, Y : %.2f) and radius (%.2f)\n",
                   listshape[i]->shape_union.circle->x, listshape[i]->shape_union.circle->y,
                   listshape[i]->shape_union.circle->radius);
            break;
        case RECTANGLE:
            printf("Rectangle at point A: (X1 %.2f, Y1 %.2f), a length of: %.2f and width of: %.2f\n",
                   listshape[i]->shape_union.rectangle->x, listshape[i]->shape_union.rectangle->y,
                   listshape[i]->shape_union.rectangle->length, listshape[i]->shape_union.rectangle->width);
            break;
        case SQUARE:
            printf("Square at point A (X1 %.2f, Y1 %.2f) and with length of: %.2f\n",
                   listshape[i]->shape_union.square->x, listshape[i]->shape_union.square->y,
                   listshape[i]->shape_union.square->length);
            break;
        case ELLIPSE:
            printf("Ellipse of center (X1 %.2f, Y1 %.2f), with a small radius: %.2f, and a big radius: %.2f\n",
                   listshape[i]->shape_union.ellipse->x, listshape[i]->shape_union.ellipse->y,
                   listshape[i]->shape_union.ellipse->small_radius, listshape[i]->shape_union.ellipse->big_radius);
            break;
        }
    }
}
