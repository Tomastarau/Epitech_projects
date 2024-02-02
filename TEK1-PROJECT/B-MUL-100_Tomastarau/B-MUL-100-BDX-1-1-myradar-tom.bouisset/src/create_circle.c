/*
** EPITECH PROJECT, 2022
** creae_circle fonction
** File description:
** create_circle fonction
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
#include "my_radar.h"
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>


sfCircleShape *create_circle(sfVector2f position , float radius)
{
    sfCircleShape *circle = sfCircleShape_create();
    if (circle == NULL) {
        exit(0);
    }
    sfCircleShape_setPosition (circle, position);
    sfCircleShape_setRadius(circle, 25);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineColor (circle, sfBlack);
    sfCircleShape_setOutlineThickness (circle, 2);
    return circle;
}