#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "menutours.h"


int main() {
    creermonstre();
    creerarcher();
    creersorcierdeglace();
    creerbomber();
    initialiserjoueur();


    al_init_font_addon();
    al_init_ttf_addon();

    assert (al_init());
    assert (al_install_mouse());
    assert(al_init_image_addon());
    assert (al_install_keyboard());
    assert (al_create_event_queue());
    assert (al_init_primitives_addon());

    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    display = al_create_display(1900, 1000);
    assert (display);
    al_set_window_title(display, "Tower defense");

    timer = al_create_timer(2.0 / 60);
    assert (timer);

    queue = al_create_event_queue();
    assert (queue);

chargerimages();

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    robotoRegular40 = al_load_font("../Roboto-Regular.TTF", 20, 0);
    robotoRegular50 = al_load_font("../Roboto-Regular.TTF", 100, 0);

    toutdessiner1();
    al_flip_display();
    reset1 = clock();
    vit1 =1;
    pause = 1;
    while (!isEnd) {
        al_wait_for_event(queue, &event);
        al_start_timer(timer);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            isEnd = 1;
        }
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_P) {
                menutours();
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                if (!vit1) {
                    vitessenormale();
                    vit1 = 1;
                    vit2 = 0;
                    vit0 = 0;
                } else {
                    vitesselente();
                    vit0 = 1;
                    vit1 = 0;
                    vit2 = 0;
                }
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                if (!vit1) {
                    vitessenormale();
                    vit1 = 1;
                    vit2 = 0;
                    vit0 = 0;
                } else {
                    vitesserapide();
                    vit0 = 0;
                    vit1 = 0;
                    vit2 = 1;
                }
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE){
                if(!pause){
                    pause =1;
                }else{
                    pause =0;
                }
            }
        }

        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (!pause) {
                for (int i=0; i<50; i++){
                    monstre[i].gel =0;
                }
                // deplacement des monstres et dégats
                degatssorcierdeglace();
                degatsarcher();
                degatsbomber();
                vague1();
                if (monstre[19].hp <=0){
                    vague2();
                }
            }

            //Dessins
            if (!pause) {
                if (a <= 10) {
                    toutdessiner1();
                    al_flip_display();
                    a++;
                } else if (a <= 20) {
                    toutdessiner2();
                    al_flip_display();
                    a++;
                } else {
                    a = 1;
                    toutdessiner1();
                    al_flip_display();
                }
            }
        }
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}