#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "Forms/line.h"
#include "Forms/circle.h"
#include "Forms/square.h"
#include "Forms/rectangle.h"
#include "Forms/ellipse.h"
#include "Modification/color.h"
#include "Modification/resize.h"
#include "delete.h"

void home(Shape *listshape[], int *nbr_shape);
void menu(Shape *listshape[], int *nbr_shape);
void create(Shape *listshape[], int *nbr_shape);
void modify(Shape *listshape[], int nbr_shape);
void menu_modification_forme(Shape *shape_to_modify);
void delete_shape(Shape *listshape[], int *nbr_shape);

void home(Shape *listshape[], int *nbr_shape)
{
    int choice = 0;
    printf("..| (<=====HOME=====>) |\n\n");
    printf("1.|   (<===MENU===>)   |\n");
    printf("2.|   (<===EXIT===>)   |\n");

    printf("Select :");
    scanf("%d", &choice);

    if (choice == 1)
    {
        menu(listshape, nbr_shape);
        return;
    }
    else if (choice == 2)
    {
        return;
    }
    else
    {
        printf("Wrong choice ! Retry.\n");
        home(listshape, nbr_shape);
        return;
    }
}

void menu(Shape *listshape[], int *nbr_shape)
{
    int choice = 0;
    printf("..| (<=====MENU=====>) |\n\n");
    printf("1.|  (<===CREATE===>)  |\n");
    printf("2.|   (<==MODIFY==>)   |\n");
    printf("3.|   (<==DELETE==>)   |\n");
    printf("4.|   (<===LIST===>)   |\n");
    printf("5.|   (<===BACK===>)   |\n");

    printf("Select :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        create(listshape, nbr_shape);
        break;
    case 2:
        modify(listshape, *nbr_shape);
        menu(listshape, nbr_shape);
        break;
    case 3:
        delete_shape(listshape, nbr_shape);
        menu(listshape, nbr_shape);
        break;
    case 4:
        list_shape(listshape, *nbr_shape);
        menu(listshape, nbr_shape);
        break;
    case 5:
        home(listshape, nbr_shape);
        break;
    default:
        printf("Wrong choice ! Retry.\n");
        menu(listshape, nbr_shape);
        break;
    }
}

void create(Shape *listshape[], int *nbr_shape)
{
    int choice = 0;
    printf(" ..| (<=====CREATE=====>) |\n\n");
    printf(" 1.|    (<===LINE===>)    |\n");
    printf(" 2.|    (<==CIRCLE==>)    |\n");
    printf(" 3.|    (<==SQUARE==>)    |\n");
    printf(" 4.|   (<==RECTANGLE=>)   |\n");
    printf(" 5.|    (<==ELLIPSE=>)    |\n");
    printf(" 6.|     (<==BACK=>)      |\n");

    printf("Select :");
    scanf("%d", &choice);

    Shape *new_shape = NULL;

    switch (choice)
    {
    case 1:
        printf("Let's make a line !\n");
        new_shape = create_shape(LINE);
        break;
    case 2:
        printf("Let's make a circle !\n");
        new_shape = create_shape(CIRCLE);
        break;
    case 3:
        printf("Let's make a square !\n");
        new_shape = create_shape(SQUARE);
        break;
    case 4:
        printf("Let's make a rectangle !\n");
        new_shape = create_shape(RECTANGLE);
        break;
    case 5:
        printf("Let's make an ellipse !\n");
        new_shape = create_shape(ELLIPSE);
        break;
    case 6:
        menu(listshape, nbr_shape);
        return;
    default:
        printf("Wrong choice ! Retry.\n");
        create(listshape, nbr_shape);
        return;
    }

    if (new_shape != NULL)
    {
        listshape[*nbr_shape] = new_shape;
        (*nbr_shape)++;
        printf("Shape saved successfully!\n");
    }

    menu(listshape, nbr_shape);
}

void modify(Shape *listshape[], int nbr_shape)
{
    if (nbr_shape == 0)
    {
        printf("The storage is empty. Nothing to modify.\n");
        return;
    }

    list_shape(listshape, nbr_shape);

    int index_selectionne = 0;
    printf("\nEnter the shape number to modify (1-%d): ", nbr_shape);
    scanf("%d", &index_selectionne);

    index_selectionne = index_selectionne - 1;

    if (index_selectionne >= 0 && index_selectionne < nbr_shape)
    {
        menu_modification_forme(listshape[index_selectionne]);
    }
    else
    {
        printf("Invalid shape number! Retry.\n");
        modify(listshape, nbr_shape);
    }
}

void menu_modification_forme(Shape *shape_to_modify)
{
    int choice = 0;
    printf("\n ..|  (<==== MODIFY ====>)  |\n\n");
    printf(" 1.|    (<=== COLOR ===>)    |\n");
    printf(" 2.|    (<== RESIZE ===>)    |\n");
    printf(" 3.|     (<== BACK ===>)     |\n");

    printf("Select :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        choose_color_from_list(shape_to_modify->color);
        break;
    case 2:
        modify_size(shape_to_modify);
        break;
    case 3:

        break;
    default:
        printf("Wrong choice ! Retry.\n");
        menu_modification_forme(shape_to_modify);
        break;
    }
}

int main(void)
{
    Shape *my_storage[50];
    int total_shapes = 0;

    home(my_storage, &total_shapes);

    return EXIT_SUCCESS;
}