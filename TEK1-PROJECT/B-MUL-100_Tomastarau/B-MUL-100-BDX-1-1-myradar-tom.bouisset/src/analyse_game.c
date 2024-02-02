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
#include <SFML/System/Types.h>
#include "my.h"
#include "printf.h"

void analyse_events(sfRenderWindow *window, sfEvent event)
{

    while (sfRenderWindow_pollEvent(window, &event)){
        if (sfKeyboard_isKeyPressed(sfKeyEscape)){
            sfRenderWindow_close(window);
        }
        switch (event.type){
            case sfEvtClosed:
                sfRenderWindow_close(window);
                break;
        }
    }
}

