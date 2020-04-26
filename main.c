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
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};
    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_KEYBOARD_STATE keyboard_state;
    clock_t start, stop,reset1,reset2;
    Joueur joueur[1];
    Tour tourelle[10];
    Monstre monstre[50];
    Tour tourdegel[10];
    creermonstre(monstre);
    creertourelle(tourelle);
    creertourdegel(tourdegel);
    initialiserjoueur(joueur);


    bool isEnd = 0;
    bool pause = 1;
    bool quittermenu = 0;
    bool poser = 0;
    int vit0 = 0;
    int vit2 = 0;
    int vit1 = 1;
    int a = 0;
    int queltour=0;
    int degat =0;
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

for (int i=0; i<10; i++){
    tourelle[i].imagetour1 = al_load_bitmap("../tourelle.PNG");
    tourdegel[i].imagetour1 = al_load_bitmap("../tourdegel.PNG");
}
for (int i=0; i<50; i++){
    monstre[i].imagemonstre1 = al_load_bitmap("../monstre1.PNG");
    monstre[i].imagemonstre2 = al_load_bitmap("../monstre2.PNG");
    monstre[i].imagemonstre3 = al_load_bitmap("../monstre3.PNG");
}


    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));

    robotoRegular40 = al_load_font("../Roboto-Regular.TTF", 20, 0);
    robotoRegular50 = al_load_font("../Roboto-Regular.TTF", 100, 0);

    toutdessiner1(tourelle, tourdegel, monstre);
    reset1 = clock();
    while (!isEnd) {
        al_wait_for_event(queue, &event);
        al_start_timer(timer);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            isEnd = 1;
        }
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_P) {
                pause = 1;
                quittermenu = 0;
                poser = 0;
                al_draw_bitmap(al_load_bitmap("../menutour.PNG"),-15,-20,0);
                al_flip_display();
                while (!quittermenu) {
                    al_get_keyboard_state(&keyboard_state);
                    al_get_mouse_state(&mouse_state);
                    al_stop_timer(timer);
                    if (al_key_down(&keyboard_state,ALLEGRO_KEY_ESCAPE)) {
                        quittermenu = 1;
                    }
                    if (mouse_state.buttons & 1) {
                        if (mouse_state.x < 1000) {
                            if (joueur[0].or > 30) {
                                start =clock();
                                while (!poser) {
                                    stop =clock();
                                    al_get_mouse_state(&mouse_state);
                                    toutdessiner1(tourelle, tourdegel, monstre);
                                    al_flip_display();
                                    if (queltour>9) {
                                        al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 550, 300, ALLEGRO_ALIGN_CENTER,
                                                     "Plus de tour d'archers disponible");
                                        al_flip_display();
                                        if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                            quittermenu = 1;
                                            pause = 0;
                                            poser = 1;
                                        }
                                    }
                                    else if (mouse_state.buttons & 2) {
                                        tourelle[queltour].xt = mouse_state.x;
                                        tourelle[queltour].yt = mouse_state.y;
                                        quittermenu = 1;
                                        pause = 0;
                                        joueur[0].or -= tourelle[queltour].cout;
                                        poser = 1;
                                        queltour+=1;
                                    }
                                }
                            } else if (joueur[0].or < 30) {
                                start = clock();
                                while (!poser) {
                                    stop = clock();
                                    al_get_mouse_state(&mouse_state);
                                    al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 550, 300, 0,
                                                 "Pas assez d'argent");
                                    al_flip_display();
                                    if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                        quittermenu = 1;
                                        pause = 0;
                                        poser = 1;
                                    }
                                }
                            }
                        } else if (mouse_state.x > 1000) {
                            if (joueur[0].or > 50) {
                                while (!poser) {
                                    al_get_mouse_state(&mouse_state);
                                    toutdessiner1(tourelle, tourdegel, monstre);
                                    al_flip_display();
                                    if (mouse_state.buttons & 2) {
                                        tourdegel[0].xt = mouse_state.x;
                                        tourdegel[0].yt = mouse_state.y;
                                        quittermenu = 1;
                                        pause = 0;
                                        joueur[0].or -= 50;
                                        poser = 1;
                                    }
                                }
                            } else if (joueur[0].or < 50) {
                                start = clock();
                                while (!poser) {
                                    stop = clock();
                                    al_get_mouse_state(&mouse_state);
                                    al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 550, 300, 0,
                                                 "Pas assez d'argent");
                                    al_flip_display();
                                    if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                        poser = 1;
                                        quittermenu = 1;
                                        pause = 0;
                                        poser = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                if (!vit1) {
                    vitessenormale(tourelle, tourdegel,monstre);
                    vit1 = 1;
                    vit2 = 0;
                    vit0 = 0;
                } else {
                    vitesselente(tourelle, tourdegel,monstre);
                    vit0 = 1;
                    vit1 = 0;
                    vit2 = 0;
                }
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                if (!vit1) {
                    vitessenormale(tourelle, tourdegel,monstre);
                    vit1 = 1;
                    vit2 = 0;
                    vit0 = 0;
                } else {
                    vitesserapide(tourelle,tourdegel,monstre);
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
                reset2=clock();
                if (vit0==1) {
                    if (((reset1 - reset2) / CLOCKS_PER_SEC) % 4 == 0) {
                        for (int i = 0; i < 50; i++) {
                            monstre[i].gel = 0;
                        }
                    }
                }
                if (vit1==1) {
                    if (((reset1 - reset2) / CLOCKS_PER_SEC) % 2 == 0) {
                        for (int i = 0; i < 50; i++) {
                            monstre[i].gel = 0;
                        }
                    }
                }
                if (vit2==1) {
                    if (((reset1 - reset2) / CLOCKS_PER_SEC) % 1 == 0) {
                        for (int i = 0; i < 50; i++) {
                            monstre[i].gel = 0;
                        }
                    }
                }
                // deplacement des monstres et dégats
                degattourdegel(tourdegel, monstre);
                deplacementmonstre(monstre, vit0, vit1, vit2, joueur);
                degattourelle(tourelle, monstre, degat);
            }

            //Dessins
            if (a <= 20) {
                toutdessiner1(tourelle, tourdegel, monstre);
                a += 1;
            } else if (a >= 60 || (40 >= a && a > 20)) {
                toutdessiner3(tourelle, tourdegel, monstre);
                if (a >= 40) {
                    a = 1;
                } else a += 1;
            } else {
                toutdessiner2(tourelle, tourdegel, monstre);
                a += 1;
            }
        }
    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    return 0;
}