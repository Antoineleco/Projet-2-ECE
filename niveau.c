//
// Created by Antoi on 28/04/2020.
//

#include "fonctions.h"

void niveau(){

    creermonstre();
    creerarcher();
    creersorcierdeglace();
    creerbomber();
    creerdragon();
    initialiserjoueur();
    finduniveau =0;

    al_resize_display(display,1900,1080);
    assert (display);

    timer = al_create_timer(2.0 / 60);
    assert (timer);

    queue = al_create_event_queue();
    assert (queue);

    chargerimages();

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer));


    toutdessiner1();
    al_flip_display();
    vit1 =1;
    pause = 1;
    while (!finduniveau) {
        al_wait_for_event(queue, &event);
        al_start_timer(timer);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            finduniveau = 1;
        }
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                finduniveau =1;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_S) {
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
                for (int i=0; i<180; i++){
                    monstre[i].gel =0;
                }
                // deplacement des monstres et dégats
                degatssorcierdeglace();
                degatsarcher();
                degatsbomber();
                degatjoueur();
                pouvoirdragon();
                if (lvl1){
                    vague1();
                    if (monstre[9].hp <=0 || monstre[9].x >= 1900){
                        vague2();
                    }
                    if (monstre[29].hp <= 0 || monstre[29].x >= 1900){
                        vague3();
                    }

                    if (monstre[79].hp <= 0 || monstre[79].x >= 1900){
                        vague4();
                    }
                }
                else if (lvl2){
                    vague1nv2();
                    if (monstre[9].hp <=0 || monstre[9].x >= 1900){
                        vague2nv2();
                    }
                    if (monstre[29].hp <= 0 || monstre[29].x >= 1900){
                        vague3nv2();
                    }

                    if (monstre[79].hp <= 0 || monstre[79].x >= 1900){
                        vague4nv2();
                    }
                }
                else if (lvl3){
                    vague1nv3();
                    if (monstre[9].hp <=0 || monstre[9].x >= 1900){
                        vague2nv3();
                    }
                    if (monstre[29].hp <= 0 || monstre[29].x >= 1900){
                        vague3nv3();
                    }

                    if (monstre[79].hp <= 0 || monstre[79].x >= 1900){
                        vague4nv3();
                    }
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
            findujeu();
        }
    }
    al_resize_display(display,1000,1000);
}