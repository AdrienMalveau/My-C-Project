#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double radius;
    double x;
    double y;
} Circle;

typedef struct
{
    double big_radius;
    double small_radius;
    double x;
    double y;
} Ellipse;

typedef struct
{
    double x;
    double y;
    double x2;
    double y2;
} Line;

typedef struct
{
    double length;
    double width;
    double x;
    double y;
} Rectangle;

typedef struct
{
    double length;
    double x;
    double y;
} Square;

typedef enum
{
    LINE,
    SQUARE,
    CIRCLE,
    RECTANGLE,
    ELLIPSE
} ShapeEnum;

typedef union
{
    Circle *circle;
    Rectangle *rectangle;
    Ellipse *ellipse;
    Square *square;
    Line *line;
} ShapeUnion;

// 4. La structure de couleur RVB
typedef struct
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
} Color;

typedef struct
{
    ShapeEnum shape_enum;
    ShapeUnion shape_union;
    Color *color;
} Shape;

Shape *create_shape(ShapeEnum choice);
void list_shape(Shape *listshape[], int nbr_shape);
void delete_shape(Shape *listshape[], int *nbr_shape);

#endif