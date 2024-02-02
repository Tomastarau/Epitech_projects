/*
** EPITECH PROJECT, 2022
** create duck
** File description:
** create duck
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

t_game *create_duck(void)
{
    sfVector2f movingsprite = {10, rand() % 5};
    t_game *duck = malloc(sizeof(t_game));
    duck->background = sfMusic_createFromFile("./extra/song.wav");
    sfMusic_setLoop(duck->background, sfTrue);
    duck->score = 0;
    sfMusic_play(duck->background);
    duck->heart = 20;
    duck->duck_speed = 10;
    duck->texture = sfTexture_createFromFile("./extra/my_image.png", NULL);
    duck->sprite = sfSprite_create();
    sfSprite_setTexture(duck->sprite, duck->texture, sfFalse);
    duck->rect.top = 0, duck->rect.left = 0, duck->rect.width = 110, \
    duck->rect.height = 110;
    duck->movesprite = movingsprite;
    return duck;
}
