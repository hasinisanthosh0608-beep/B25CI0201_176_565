#include <stdio.h>
#include <stdlib.h>

#define ROWS 25
#define COLS 60

char rectCanvas[ROWS][COLS];
char lineCanvas[ROWS][COLS];
char triCanvas[ROWS][COLS];
char circleCanvas[ROWS][COLS];

/* Initialize Canvas */
void initialize(char canvas[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Display Canvas */
void display(char canvas[ROWS][COLS])
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

/* Rectangle */
void drawRectangle(char canvas[ROWS][COLS],
                   int x, int y,
                   int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

/* Line */
void drawLine(char canvas[ROWS][COLS],
              int x1, int y1,
              int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        if((int)x >= 0 && (int)x < COLS &&
           (int)y >= 0 && (int)y < ROWS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
    }
}

/* Triangle */
void drawTriangle(char canvas[ROWS][COLS],
                  int x, int y,
                  int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = -i; j <= i; j++)
        {
            if(x + j >= 0 &&
               x + j < COLS &&
               y + i >= 0 &&
               y + i < ROWS)
            {
                canvas[y + i][x + j] = '*';
            }
        }
    }
}

/* Circle */
void drawCircle(char canvas[ROWS][COLS],
                int cx, int cy,
                int radius)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int dx = x - cx;
            int dy = y - cy;

            if(dx * dx + dy * dy <= radius * radius)
            {
                canvas[y][x] = '*';
            }
        }
    }
}

/* Delete Object */
void deleteObject(char canvas[ROWS][COLS],
                  int x, int y,
                  int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

/* Modify Rectangle */
void modifyRectangle()
{
    int oldX, oldY, oldW, oldH;
    int newX, newY, newW, newH;

    printf("Enter old rectangle x y width height: ");
    scanf("%d%d%d%d",
          &oldX, &oldY,
          &oldW, &oldH);

    deleteObject(rectCanvas,
                 oldX, oldY,
                 oldW, oldH);

    printf("Enter new rectangle x y width height: ");
    scanf("%d%d%d%d",
          &newX, &newY,
          &newW, &newH);

    drawRectangle(rectCanvas,
                  newX, newY,
                  newW, newH);
}

/* Clear All Canvases */
void clearAllCanvases()
{
    initialize(rectCanvas);
    initialize(lineCanvas);
    initialize(triCanvas);
    initialize(circleCanvas);

    printf("All Canvases Cleared Successfully\n");
}

int main()
{
    int choice;

    initialize(rectCanvas);
    initialize(lineCanvas);
    initialize(triCanvas);
    initialize(circleCanvas);

    do
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Rectangle Canvas\n");
        printf("6. Display Line Canvas\n");
        printf("7. Display Triangle Canvas\n");
        printf("8. Display Circle Canvas\n");
        printf("9. Delete From Rectangle Canvas\n");
        printf("10. Modify Rectangle\n");
        printf("11. Clear All Canvases\n");
        printf("12. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x, y, w, h;

                initialize(rectCanvas);

                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &w, &h);

                drawRectangle(rectCanvas, x, y, w, h);
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                initialize(lineCanvas);

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",
                      &x1, &y1, &x2, &y2);

                drawLine(lineCanvas,
                         x1, y1,
                         x2, y2);
                break;
            }

            case 3:
            {
                int x, y, h;

                initialize(triCanvas);

                printf("Enter top_x top_y height: ");
                scanf("%d%d%d", &x, &y, &h);

                drawTriangle(triCanvas, x, y, h);
                break;
            }

            case 4:
            {
                int cx, cy, r;

                initialize(circleCanvas);

                printf("Enter center_x center_y radius: ");
                scanf("%d%d%d", &cx, &cy, &r);

                drawCircle(circleCanvas, cx, cy, r);
                break;
            }

            case 5:
                printf("\nRECTANGLE CANVAS\n");
                display(rectCanvas);
                break;

            case 6:
                printf("\nLINE CANVAS\n");
                display(lineCanvas);
                break;

            case 7:
                printf("\nTRIANGLE CANVAS\n");
                display(triCanvas);
                break;

            case 8:
                printf("\nCIRCLE CANVAS\n");
                display(circleCanvas);
                break;

            case 9:
            {
                int x, y, w, h;

                printf("Enter x y width height to delete: ");
                scanf("%d%d%d%d",
                      &x, &y, &w, &h);

                deleteObject(rectCanvas,
                             x, y, w, h);
                break;
            }

            case 10:
                modifyRectangle();
                break;

            case 11:
                clearAllCanvases();
                break;

            case 12:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 12);

    return 0;
}