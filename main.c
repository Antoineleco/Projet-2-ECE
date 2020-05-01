#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "fonctions.h"


int main() {

    creermonstre();
    creerarcher();
    creersorcierdeglace();
    creerbomber();
    creerdragon();
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

    display = al_create_display(1000, 1000);
    assert (display);
    al_set_window_title(display, "Tower defense");

    timermenu = al_create_timer(1);
    assert (timermenu);

    queuemenu = al_create_event_queue();
    assert (queuemenu);

    al_register_event_source(queuemenu, al_get_display_event_source(display));
    al_register_event_source(queuemenu, al_get_keyboard_event_source());
    al_register_event_source(queuemenu, al_get_mouse_event_source());
    al_register_event_source(queuemenu, al_get_timer_event_source(timermenu));

    fond.fondmenuprincipal = al_load_bitmap("../fondaccueil.PNG");
    fond.regles = al_load_bitmap("../règles.PNG");
    isEnd =0;

    robotoRegular40 = al_load_font("../Roboto-Regular.TTF", 20, 0);
    robotoRegular50 = al_load_font("../Roboto-Regular.TTF", 100, 0);

    al_start_timer(timermenu);
    al_draw_bitmap(fond.fondmenuprincipal,0,0,0);
    al_flip_display();
    lvl1=0;
    lvl2=0;
    lvl3 =1;

    while (!isEnd) {
        al_draw_bitmap(fond.fondmenuprincipal, 0, 0, 0);
        al_flip_display();
        al_wait_for_event(queuemenu, &eventmenu);
        al_get_mouse_state(&mouse_state);

        switch (eventmenu.type) {
            case ALLEGRO_EVENT_TIMER:
                al_draw_bitmap(fond.fondmenuprincipal, 0, 0, 0);
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                isEnd = 1;
                break;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :

                //QUIT
                if (mouse_state.x >= 250.75 && mouse_state.x <= 752.25 && mouse_state.y >= 725.59 &&
                    mouse_state.y <= 870.71) {
                    isEnd = 1;
                }
                //PLAY NEW GAME
                if (mouse_state.x >= 250.75 && mouse_state.x <= 752.25 && mouse_state.y >= 118.73 &&
                    mouse_state.y <= 270.45) {
                    lvl1=1;
                    lvl2=0;
                    lvl3=0;
                    niveau();
                }
                //PLAY CONTINUE
                if (mouse_state.x >= 250.75 && mouse_state.x <= 752.25 && mouse_state.y >= 323.22 &&
                    mouse_state.y <= 468.34) {
                    if (lvl2) {
                        niveau();
                    } else if (lvl3) {
                        niveau();
                    } else {
                        start = clock();
                        while (!poser) {
                            stop = clock();
                            al_draw_text(robotoRegular40, al_map_rgb(255, 50, 50), 380, 280, 0,
                                         "Aucune partie commencée");
                            al_flip_display();
                            if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                poser = 1;
                            }
                        }
                    }
                }

                //RULES
                if (mouse_state.x >= 250.75 && mouse_state.x <= 752.25 && mouse_state.y >= 521.12 &&
                    mouse_state.y <= 672.82) {
                    afficherregles();
                }
                break;
        }
    }

    al_destroy_event_queue(queuemenu);
    al_destroy_event_queue(queue);
    al_destroy_event_queue(queueregles);
    al_destroy_display(display);
    al_destroy_timer(timermenu);
    al_destroy_timer(timer);


    return 0;
}