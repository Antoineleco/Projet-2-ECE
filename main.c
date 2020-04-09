#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct{
    int x1,y1,hp1,deg1,or1;
    ALLEGRO_BITMAP *imagemonstre1;
}Monstre1;

typedef struct{
    int or,vie;
}Joueur;

void toutdessiner(Monstre1 mon11,Monstre1 mon12, Monstre1 mon13){
    al_clear_to_color(al_map_rgb(150, 150, 150));
    al_draw_bitmap(mon11.imagemonstre1,mon11.x1, mon11.y1, 0);
    al_draw_bitmap(mon12.imagemonstre1,mon12.x1, mon12.y1, 0);
    al_draw_bitmap(mon13.imagemonstre1,mon13.x1, mon13.y1, 0);

}

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_FONT* robotoRegular40;
    Joueur joueur = {30,200};
    Monstre1 mon11 = {50, 450, 50, 50,10, NULL};
    Monstre1 mon12 = {50, 450, 50, 50,10, NULL};
    Monstre1 mon13 = {50, 450, 50, 50,10, NULL};
    int isEnd = 0;


    assert (al_init());
    assert (al_install_mouse());
    assert(al_init_image_addon());
    assert (al_install_keyboard());
    assert (al_create_event_queue());
    assert (al_init_primitives_addon());

    display = al_create_display(1900, 1000);
    assert (display);
    al_set_window_title(display, "Le chat et la souris");

    timer = al_create_timer(0.8 / 60);
    assert (timer);

    queue = al_create_event_queue();
    assert (queue);


    mon11.imagemonstre1 = al_load_bitmap("../chat.PNG");
    mon12.imagemonstre1 = al_load_bitmap("../chat.PNG");
    mon13.imagemonstre1 = al_load_bitmap("../chat.PNG");


    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    toutdessiner(mon11,mon12,mon13);
    al_flip_display();
    al_start_timer(timer);

    while (!isEnd) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            isEnd = 1;
        }
        toutdessiner(mon11,mon12,mon13);
            }


    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}