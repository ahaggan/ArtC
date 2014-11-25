#include "artc_sdl2.h"

void draw_sdl(draw *object)
{
    SDL_Win sw;

    Interface area; //Arbitrary struct to make events function work!

    int x, y;
    char *win_name = "Display_test";
    x = (WIN_WIDTH / 2) - (object->size / 2);
    y = (WIN_HEIGHT / 2) - (object->size / 2);

    SDL_Win_Init(&sw, win_name);

    do{
        if (strcmp(object->colour, "blue") == 0)
        {
            SDL_SetRenderDrawColor(sw.renderer, 0, 0, 255, 50);
        }

        else if (strcmp(object->colour, "red") == 0)
        {
            SDL_SetRenderDrawColor(sw.renderer, 255, 0, 0, 50);
        }

        else if (strcmp(object->colour, "green") == 0)
        {
            SDL_SetRenderDrawColor(sw.renderer, 0, 255, 0, 50);
        }

        else if (strcmp(object->colour, "pink") == 0)
        {
            SDL_SetRenderDrawColor(sw.renderer, 180, 0, 100, 50);
        }

        else if (strcmp(object->colour, "purple") == 0)
        {
            SDL_SetRenderDrawColor(sw.renderer, 100, 0, 150, 50);
        }


        if (strcmp(object->shape, "square") == 0)
        {
            SDL_Rect rectangle;
            rectangle.w = object->size;
            rectangle.h = object->size;
            rectangle.x = x;
            rectangle.y = y;
            SDL_RenderFillRect(sw.renderer, &rectangle);

        }

        else if (strcmp(object->shape, "circle") == 0)
        {
            SDL_RenderFillCircle(sw.renderer, x, y, object->size, 1);

        }

        else if (strcmp(object->shape, "line") == 0)
        {
            SDL_RenderDrawLine(sw.renderer, object->startx, object->starty, object->endx, object->endy);

        }

        SDL_RenderPresent(sw.renderer);
      
        SDL_Events(&sw, &area);
    }while (!sw.finished);

    //calls SDL_Quit when the program terminates
    atexit(SDL_Quit);
}
