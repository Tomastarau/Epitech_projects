/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_
    #define KNRM  "\x1B[0m"
    #define KRED  "\x1B[31m"
    #define KGRN  "\x1B[32m"
    #define KYEL  "\x1B[33m"
    #define KBLU  "\x1B[34m"
    #define KMAG  "\x1B[35m"
    #define KCYN  "\x1B[36m"
    #define KWHT  "\x1B[37m"
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Audio/Music.h>

struct s_game {
    int heart;
    int score;
    int duck_speed;
    sfMusic *background;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f movesprite;
};

typedef struct s_game t_game;

t_game *create_duck(void);

void *show_duck(sfRenderWindow *window, t_game *duck);

void animate_duck(t_game *duck, sfClock *clock);

void analyses_n_show_duck(sfRenderWindow *window, sfEvent event, t_game *duck);

void move_duck(sfRenderWindow *window, t_game *duck, sfClock *clock);

void *show_background(sfRenderWindow *window);

void analyse_shoot_and_pos(sfRenderWindow *window, sfEvent event, t_game *duck);

void move_rect (sfIntRect *rect, int offset, int max_value);

sfRenderWindow *createmywindow(unsigned int width, unsigned int height, \
unsigned int pixels, char* title);

void free_duck_backgrnd_window(t_game *duck, sfTexture *texture, sfSprite \
*sprite, sfRenderWindow *window);

void free_clock(sfClock *clock1, sfClock *clock2);

void analyse_events(sfRenderWindow *window, sfEvent event, t_game *duck);

#endif /* !MY_HUNTER_H_ */
