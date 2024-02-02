/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"
#include "my_hunter.h"
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>

const char *comm(void)
{
    char *hunter_info = "My_hunter, a remastered duck hunt. \
        Epitech 2022 project.\n\nPlease use ./my_hunter to launch the game.\n\n\
Inputs : Press [ESCAPE] to quit the game and close the window\n \
        Press [MOUSE LEFT CLICK] to shoot targets";
    return hunter_info;
}

void my_game(void)
{
    sfRenderWindow *window = createmywindow(1000, 1000, 32, "My hunter");
    sfEvent event;
    sfClock *clock1 = sfClock_create();
    sfClock *clock2 = sfClock_create();
    t_game *duck = create_duck();
    sfTexture *texture = sfTexture_createFromFile("./extra/duck_bk.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    while (sfRenderWindow_isOpen(window)){
        sfRenderWindow_clear(window, sfBlack);
        animate_duck(duck, clock1);
        move_duck(window, duck, clock2);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        analyses_n_show_duck(window, event, duck);
        sfRenderWindow_display(window);
    }
    free_duck_backgrnd_window(duck, texture, sprite, window);
    free_clock(clock1, clock2);
}

int main(int argc, char *argv[])
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0){
        my_printf("%s%s%s\n", KYEL, comm(), KNRM);
        return 1;
    }
    if (argc == 1){
        my_game();
        return 1;
    }
    write(2, KRED"Please refer to ./my_hunter -h command\n"KNRM, 49);
    return 84;
}
