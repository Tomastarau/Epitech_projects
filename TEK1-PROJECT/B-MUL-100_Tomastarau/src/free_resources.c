/*
** EPITECH PROJECT, 2022
** free resources
** File description:
** free resources
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

void free_clock(sfClock *clock1, sfClock *clock2)
{
    sfClock_destroy(clock1);
    sfClock_destroy(clock2);
}

void free_duck_backgrnd_window(t_game *duck, sfTexture *texture, sfSprite \
*sprite, sfRenderWindow *window)
{
    sfTexture_destroy(duck->texture);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    sfSprite_destroy(duck->sprite);
    sfRenderWindow_destroy(window);
    sfMusic_destroy(duck->background);
}
