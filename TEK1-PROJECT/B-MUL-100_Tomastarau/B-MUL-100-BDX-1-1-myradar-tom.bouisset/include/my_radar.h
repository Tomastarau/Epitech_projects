/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
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
unsigned int pixels, char* title);

struct circle_s {
    sfCircleShape *circle;
    sfVector2f *pos_circle;
    
};

typedef struct circle_s circle_t;

void analyse_events(sfRenderWindow *window, sfEvent event);

int is_intersecting_circles (sfCircleShape *c1, sfCircleShape *c2);

sfCircleShape *create_circle(sfVector2f position , float radius);

#endif /* !MY_RADAR_H_ */
