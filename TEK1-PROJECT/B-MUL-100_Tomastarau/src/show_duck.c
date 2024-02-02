/*
** EPITECH PROJECT, 2022
** show_duck
** File description:
** show duck
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

void *show_duck(sfRenderWindow *window, t_game *duck)
{
    sfSprite_setTexture(duck->sprite, duck->texture, sfFalse);
    sfSprite_setTextureRect(duck->sprite, duck->rect);
    sfRenderWindow_drawSprite(window, duck->sprite, NULL);
}

void *show_background(sfRenderWindow *window)
{
    sfTexture *texture = sfTexture_createFromFile\
    ("./extra/duck_background.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}
