/*
** EPITECH PROJECT, 2022
** analyse events
** File description:
** analyse all events
*/


#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_hunter.h"
#include <SFML/System/Types.h>
#include "my.h"
#include "printf.h"

void manage_mouse_click(sfMouseButtonEvent event, t_game *duck, \
sfRenderWindow *window)
{
    sfVector2f movingsprite = {duck->duck_speed, rand() % 5};
    sfVector2f new_duck_pos = {0, rand() % 950};
    sfVector2f pos_sprite = sfSprite_getPosition(duck->sprite);

    if (event.x >= pos_sprite.x && event.x <= (pos_sprite.x + 110) && event.y \
>= pos_sprite.y && event.y <= (pos_sprite.y + 110)){
            duck->score = duck->score + 1;
            duck->movesprite = movingsprite;
            sfSprite_setPosition(duck->sprite, new_duck_pos);
            my_printf("%sSCORE = %d\n", KMAG,  duck->score);
            my_printf("%s", KNRM);
            duck->duck_speed = duck->duck_speed + 2;
        }
    if (duck->score == 20){
        my_printf("%sYOU WON\n", KGRN);
        my_printf("%s", KNRM);
        sfRenderWindow_close(window);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, t_game *duck)
{
    sfMouseButtonEvent click;

    while (sfRenderWindow_pollEvent(window, &event)){
        click = event.mouseButton;
        if (sfKeyboard_isKeyPressed(sfKeyEscape)){
            sfRenderWindow_close(window);
        }
        switch (event.type){
            case sfEvtClosed:
                sfRenderWindow_close(window);
                my_printf("%s", KNRM);
                break;
            case sfEvtMouseButtonPressed:
                manage_mouse_click(click, duck, window);
                break;
        }
    }
}

void analyse_shoot_and_pos(sfRenderWindow *window, sfEvent event, t_game *duck)
{
    sfVector2f new_duck_pos = {0, rand() % 950};
    sfVector2f pos_sprite = sfSprite_getPosition(duck->sprite);
    if (pos_sprite.x > 1000 || pos_sprite.y > 1000){
        sfSprite_setPosition(duck->sprite, new_duck_pos);
        duck->heart = duck->heart - 1;
        my_printf("%sHEART = %d\n", KRED, duck->heart);
        my_printf("%s", KNRM);
        if (duck->heart == 0){
            my_printf("%sGAME OVER (in sah you're pété)", KRED);
            my_printf("%s\n", KNRM);
            sfRenderWindow_close(window);
        }
    }
}

void analyses_n_show_duck(sfRenderWindow *window, sfEvent event, t_game *duck)
{
    show_duck(window, duck);
    analyse_events(window, event, duck);
    analyse_shoot_and_pos(window, event, duck);
}
