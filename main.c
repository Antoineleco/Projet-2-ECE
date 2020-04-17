#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct{
    int x,y,hp,deg,or,vit;
    ALLEGRO_BITMAP *imagemonstre;
}Monstre;

typedef struct{
    int or,vie;
}Joueur;

typedef struct{
    int xt,yt,cout,degats,rng;
    ALLEGRO_BITMAP *imagetour1;
    ALLEGRO_BITMAP *imagetour2;
}Tour;

void toutdessiner1(Tour tourelle,Tour tourdegel, Monstre monstre1, Monstre monstre2, Monstre monstre3){
    al_clear_to_color(al_map_rgb(200, 200, 200));
    al_draw_bitmap(tourelle.imagetour1, tourelle.xt, tourelle.yt, 0);
    al_draw_bitmap(tourdegel.imagetour2, tourdegel.xt, tourdegel.yt, 0);
    al_draw_bitmap(monstre1.imagemonstre, monstre1.x, monstre1.y, 0);
    al_draw_bitmap(monstre2.imagemonstre, monstre2.x, monstre2.y, 0);
    al_draw_bitmap(monstre3.imagemonstre, monstre3.x, monstre3.y, 0);
    al_flip_display();
}
void toutdessiner2(Tour tourelle, Tour tourdegel, Monstre monstre1, Monstre monstre2, Monstre monstre3){
    al_clear_to_color(al_map_rgb(200, 200, 200));
    al_draw_bitmap(tourelle.imagetour2, tourelle.xt, tourelle.yt, 0);
    al_draw_bitmap(tourdegel.imagetour1, tourdegel.xt, tourdegel.yt, 0);
    al_draw_bitmap(monstre1.imagemonstre, monstre1.x, monstre1.y, 0);
    al_draw_bitmap(monstre2.imagemonstre, monstre2.x, monstre2.y, 0);
    al_draw_bitmap(monstre3.imagemonstre, monstre3.x, monstre3.y, 0);
}

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_FONT* robotoRegular40;
    Joueur joueur = {30,200};
    Tour tourelle = {1000,450,20,5,20,NULL};
    Tour tourdegel = {800,450,20,1,100,NULL};
    Monstre monstre1 = {0, 450, 50, 50, 10, 2, NULL};
    Monstre monstre2 = {-150, 450, 50, 50, 10, 2, NULL};
    Monstre monstre3 = {-300, 450, 50, 50, 10, 2, NULL};
    int isEnd = 0;
    int temps = 0;
    int a=1;
    int pause=0;

    al_init_font_addon();
    al_init_ttf_addon();

    assert (al_init());
    assert (al_install_mouse());
    assert(al_init_image_addon());
    assert (al_install_keyboard());
    assert (al_create_event_queue());
    assert (al_init_primitives_addon());

    display = al_create_display(1900, 1000);
    assert (display);
    al_set_window_title(display, "Tower defense");

    timer = al_create_timer(1.2 / 60);
    assert (timer);

    queue = al_create_event_queue();
    assert (queue);

    robotoRegular40 = al_load_font("../Roboto-Regular.TTF",20,0);

    monstre1.imagemonstre = al_load_bitmap("../monstre.PNG");
    monstre2.imagemonstre = al_load_bitmap("../monstre.PNG");
    monstre3.imagemonstre = al_load_bitmap("../monstre.PNG");
    tourelle.imagetour1 = al_load_bitmap("../tourelle.PNG");
    tourelle.imagetour2 = al_load_bitmap("../monstre.PNG");
    tourdegel.imagetour1 = al_load_bitmap("../tourelle.PNG");
    tourdegel.imagetour2 = al_load_bitmap("../monstre.PNG");



    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    toutdessiner1(tourelle, tourdegel, monstre1, monstre2, monstre3);
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 50, NULL, "boutique: P");
    al_flip_display();
    al_start_timer(timer);

    while (!isEnd) {
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            isEnd = 1;
        }
        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (monstre1.hp > 1) {
                monstre1.x += monstre1.vit;
            }
            if (monstre2.hp > 1) {
                monstre2.x += monstre2.vit;
            }
            if (monstre3.hp > 1) {
                monstre3.x += monstre3.vit;
            }
        }
        if (monstre1.x < (tourelle.xt + 100 + tourelle.rng) && monstre1.x > (tourelle.xt - tourelle.rng) && monstre1.y < (tourelle.yt + 100 + tourelle.rng) && monstre1.y > (tourelle.yt - tourelle.rng)){
            monstre1.hp -= tourelle.degats;
        }
        if (monstre2.x < (tourelle.xt + 100 + tourelle.rng) && monstre2.x > (tourelle.xt - tourelle.rng) && monstre2.y < (tourelle.yt + 100 + tourelle.rng) && monstre2.y > (tourelle.yt - tourelle.rng)){
            monstre2.hp -= tourelle.degats;
        }
        if (monstre3.x < (tourelle.xt + 100 + tourelle.rng) && monstre3.x > (tourelle.xt - tourelle.rng) && monstre3.y < (tourelle.yt + 100 + tourelle.rng) && monstre3.y > (tourelle.yt - tourelle.rng)){
            monstre3.hp -= tourelle.degats;
        }
        if (monstre1.x < (tourdegel.xt + 100 + tourdegel.rng) && monstre1.x > (tourdegel.xt - tourdegel.rng) && monstre1.y < (tourdegel.yt + 100 + tourdegel.rng) && monstre1.y > (tourdegel.yt - tourdegel.rng)) {
            monstre1.vit = tourdegel.degats;
        }
        else monstre1.vit = 2;
        if (monstre1.hp <= 0){
            monstre1.x = 3000;
        }
        if (monstre2.hp <= 0){
            monstre2.x = 3000;
        }
        if (monstre3.hp <= 0){
            monstre3.x = 3000;
        }
        if(a<=50){
            toutdessiner1(tourelle, tourdegel, monstre1, monstre2, monstre3);
            al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 50, NULL, "boutique: P");
            al_flip_display();
            a += 1;
        }
        else if (a > 50){
            toutdessiner2(tourelle, tourdegel, monstre1, monstre2, monstre3);
            al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 50, NULL, "boutique: P");
            al_flip_display();
            if (a>100){
                a=1;
            }
            else a += 1;
        }
    }


    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}