/*
** EPITECH PROJECT, 2022
** animate_duck
** File description:
** animate_duck
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_hunter.h"

void animate_duck(t_game *duck, sfClock *clock)
{
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    float seconds;
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1){
        move_rect(&duck->rect, 110, 330);
        sfClock_restart(clock);
    }
}

void move_duck(sfRenderWindow *window, t_game *duck, sfClock *clock)
{
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    float seconds;
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.02){
        sfSprite_move(duck->sprite, duck->movesprite);
        sfClock_restart(clock);
    }
}
