/*
** EPITECH PROJECT, 2022
** create my window
** File description:
** create my window
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

sfRenderWindow *createmywindow(unsigned int width, unsigned int height, \
unsigned int pixels, char* title)
{
    sfVideoMode mode = {width, height, pixels};

    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}
