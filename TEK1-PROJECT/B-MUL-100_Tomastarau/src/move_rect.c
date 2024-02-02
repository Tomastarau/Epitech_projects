/*
** EPITECH PROJECT, 2022
** move_rect
** File description:
** move_rect
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

void move_rect (sfIntRect *rect, int offset, int max_value)
{
    if (rect->left == 220){
        rect->left = 0;
    } else{
        rect->left += offset;
    }
}
