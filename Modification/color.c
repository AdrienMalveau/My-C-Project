#include <stdio.h>
#include "color.h"

void choose_color_from_list(Color *color)
{
    if (color == NULL)
        return;

    int choice = 0;

    printf("\n..| (<===== COLOR SELECTION =====>) |\n\n");
    printf(" 1.|  🔴 Red      |\n");
    printf(" 2.|  🟢 Green    |\n");
    printf(" 3.|  🔵 Blue     |\n");
    printf(" 4.|  🟡 Yellow   |\n");
    printf(" 5.|  🟣 Purple   |\n");
    printf(" 6.|  ⚪ White    |\n");
    printf(" 7.|  ⚫ Black    |\n");

    printf("\nSelect a number (1-7) : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        color->red = 255;
        color->green = 0;
        color->blue = 0;
        printf("=> Selected color : Red\n");
        break;
    case 2:
        color->red = 0;
        color->green = 255;
        color->blue = 0;
        printf("=> Selected color : Green\n");
        break;
    case 3:
        color->red = 0;
        color->green = 0;
        color->blue = 255;
        printf("=> Selected color : Blue\n");
        break;
    case 4:
        color->red = 255;
        color->green = 255;
        color->blue = 0;
        printf("=> Selected color : Yellow\n");
        break;
    case 5:
        color->red = 128;
        color->green = 0;
        color->blue = 128;
        printf("=> Selected color : Purple\n");
        break;
    case 6:
        color->red = 255;
        color->green = 255;
        color->blue = 255;
        printf("=> Selected color : White\n");
        break;
    case 7:
        color->red = 0;
        color->green = 0;
        color->blue = 0;
        printf("=> Selected color : Black\n");
        break;
    default:
        printf("Invalid choice! Color remains unchanged (Default: Black).\n");
        break;
    }
}
