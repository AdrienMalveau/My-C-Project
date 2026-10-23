#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void delete_shape(Shape *listshape[], int *nbr_shape)
{
    if (*nbr_shape == 0)
    {
        printf("The storage is empty. Nothing to delete.\n");
        return;
    }

    list_shape(listshape, *nbr_shape);

    int index_a_supprimer = 0;
    printf("\nEnter the shape number to delete (1-%d): ", *nbr_shape);
    scanf("%d", &index_a_supprimer);

    index_a_supprimer = index_a_supprimer - 1;

    if (index_a_supprimer >= 0 && index_a_supprimer < *nbr_shape)
    {
        if (listshape[index_a_supprimer]->color != NULL)
        {
            free(listshape[index_a_supprimer]->color);
        }

        switch (listshape[index_a_supprimer]->shape_enum)
        {
        case LINE:
            free(listshape[index_a_supprimer]->shape_union.line);
            break;
        case CIRCLE:
            free(listshape[index_a_supprimer]->shape_union.circle);
            break;
        case RECTANGLE:
            free(listshape[index_a_supprimer]->shape_union.rectangle);
            break;
        case SQUARE:
            free(listshape[index_a_supprimer]->shape_union.square);
            break;
        case ELLIPSE:
            free(listshape[index_a_supprimer]->shape_union.ellipse);
            break;
        }

        free(listshape[index_a_supprimer]);

        for (int i = index_a_supprimer; i < (*nbr_shape) - 1; i++)
        {
            listshape[i] = listshape[i + 1];
        }

        (*nbr_shape)--;

        printf("[V] Shape successfully deleted!\n");
    }
    else
    {
        printf("Invalid shape number! Retry.\n");
        delete_shape(listshape, nbr_shape);
    }
}