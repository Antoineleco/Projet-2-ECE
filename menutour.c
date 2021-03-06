//
// Created by Antoi on 28/04/2020.
//

#include "fonctions.h"

void menutours(){
    pause = 1;
    quittermenu = 0;
    poser = 0;
    al_draw_bitmap(fond.fondmenutour,0,0,0);
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 10, 0, "Quitter: Q");
    al_flip_display();
    while (!quittermenu) {
        al_get_keyboard_state(&keyboard_state);
        al_get_mouse_state(&mouse_state);
        al_stop_timer(timer);
        if (al_key_down(&keyboard_state,ALLEGRO_KEY_Q)) {
            quittermenu = 1;
            pause=0;
        }
        if (mouse_state.buttons & 1) { // CHOISIT UNE TOUR

            // CHOIX: ARCHER
            if (mouse_state.x < 650) {
                if (joueur[0].or >= 80) {
                    start =clock();
                    while (!poser) {
                        stop =clock();
                        al_get_mouse_state(&mouse_state);
                        toutdessiner1();
                        if (quelarcher >= 9) {
                            al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 550, 300, ALLEGRO_ALIGN_CENTER,
                                         "Plus de tour d'archers disponible");
                            al_flip_display();
                            if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                quittermenu = 1;
                                pause = 0;
                                poser = 1;
                            }
                        }
                        // PREVISUALISATION
                        if (mouse_state.buttons & 1){
                            al_draw_bitmap(archer[quelarcher].imagetour1,mouse_state.x-35,mouse_state.y-50, 0);
                            al_draw_rectangle(mouse_state.x - archer[quelarcher].rng,mouse_state.y - archer[quelarcher].rng,mouse_state.x  + archer[quelarcher].rng,mouse_state.y + archer[quelarcher].rng, al_map_rgb(255, 0, 0),5);
                            al_flip_display();
                        }
                        // POSE DE LA TOUR
                        if (mouse_state.buttons & 2) {
                            indisponnible =0;
                            poserlatour();
                            if (lvl1){
                                estsurlechemin1();
                            }
                            else if(lvl2){
                                estsurlechemin2();
                            }
                            else if (lvl3){
                                estsurlechemin3();
                            }
                            if (!indisponnible) {
                                archer[quelarcher].xt = mouse_state.x - 50;
                                archer[quelarcher].yt = mouse_state.y - 50;
                                quittermenu = 1;
                                pause = 0;
                                joueur->or -= archer[quelarcher].cout;
                                poser = 1;
                                quelarcher += 1;
                            }
                            else {
                                al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), mouse_state.x-100, mouse_state.y, 0,
                                             "emplacement indisponible");
                                al_flip_display();
                            }
                        }
                    }
                } else if (joueur[0].or < 80) {  // PAS ASSEZ D'ARGENT
                    start = clock();
                    while (!poser) {
                        stop = clock();
                        al_get_mouse_state(&mouse_state);
                        al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 600, 300, 0,
                                     "Pas assez d'argent");
                        al_flip_display();
                        if ((stop - start) / CLOCKS_PER_SEC == 2) {
                            quittermenu = 1;
                            pause = 0;
                            poser = 1;
                        }
                    }
                }
            }
            // CHOIX SORCIER DE GLACE
            if (mouse_state.x > 1250) {
                if (joueur[0].or >= 70) {
                    start =clock();
                    while (!poser) {
                        stop =clock();
                        al_get_mouse_state(&mouse_state);
                        al_draw_bitmap(sorcierdeglace[quelsorcierdeglace].imagetour1,mouse_state.x,mouse_state.y, 0);
                        toutdessiner1();
                        if (quelsorcierdeglace >= 9) {
                            al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), mouse_state.x-100, mouse_state.y, 0,
                                         "Plus de sorcier de glace disponible");
                            al_flip_display();
                            if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                quittermenu = 1;
                                pause = 0;
                                poser = 1;
                            }
                        }
                        // PREVISUALISATION
                        if (mouse_state.buttons & 1){
                            al_draw_bitmap(sorcierdeglace[quelsorcierdeglace].imagetour1,mouse_state.x-35,mouse_state.y-50, 0);
                            al_draw_rectangle(mouse_state.x - sorcierdeglace[quelsorcierdeglace].rng,mouse_state.y - sorcierdeglace[quelsorcierdeglace].rng,mouse_state.x  + sorcierdeglace[quelsorcierdeglace].rng,mouse_state.y + sorcierdeglace[quelsorcierdeglace].rng, al_map_rgb(255, 0, 0),5);
                            al_flip_display();
                        }
                        // POSE DE LA TOUR
                        if (mouse_state.buttons & 2) {
                            indisponnible =0;
                            poserlatour();
                            if (lvl1){
                                estsurlechemin1();
                            }
                            else if(lvl2){
                                estsurlechemin2();
                            }
                            else if (lvl3){
                                estsurlechemin3();
                            }
                            if (!indisponnible) {
                                sorcierdeglace[quelsorcierdeglace].xt = mouse_state.x - 35;
                                sorcierdeglace[quelsorcierdeglace].yt = mouse_state.y - 50;
                                quittermenu = 1;
                                pause = 0;
                                joueur->or -= sorcierdeglace[quelsorcierdeglace].cout;
                                poser = 1;
                                quelsorcierdeglace++;
                            }
                            else {
                                al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), mouse_state.x-100, mouse_state.y, 0,
                                             "emplacement indisponible");
                                al_flip_display();

                            }
                        }
                    }
                }
                else if (joueur[0].or < 70) { // PAS ASSEZ D'ARGENT
                    start = clock();
                    while (!poser) {
                        stop = clock();
                        al_get_mouse_state(&mouse_state);
                        al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 600, 300, 0,
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
            // CHOIX BOMBER
            else if (mouse_state.y < 600){
                if (joueur[0].or >= (50)) {
                    start =clock();
                    while (!poser) {
                        stop =clock();
                        al_get_mouse_state(&mouse_state);
                        al_draw_bitmap(bomber[quelbomber].imagetour1,mouse_state.x,mouse_state.y, 0);
                        toutdessiner1();
                        if (quelbomber >= 9) {
                            al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), mouse_state.x-100, mouse_state.y, 0,
                                         "Plus de sorcier de glace disponible");
                            al_flip_display();
                            if ((stop - start) / CLOCKS_PER_SEC == 2) {
                                quittermenu = 1;
                                pause = 0;
                                poser = 1;
                            }
                        }
                        // PREVISUALISATION
                        if (mouse_state.buttons & 1){
                            al_draw_bitmap(bomber[quelbomber].imagetour1,mouse_state.x-35,mouse_state.y-50, 0);
                            al_draw_rectangle(mouse_state.x - bomber[quelbomber].rng,mouse_state.y - bomber[quelbomber].rng,mouse_state.x  + bomber[quelbomber].rng,mouse_state.y +bomber[quelbomber].rng, al_map_rgb(255, 0, 0),5);
                            al_flip_display();
                        }
                        // POSE DE LA TOUR
                        if (mouse_state.buttons & 2) {
                            indisponnible =0;
                            poserlatour();
                            if (lvl1){
                                estsurlechemin1();
                            }
                            else if(lvl2){
                                estsurlechemin2();
                            }
                            else if (lvl3){
                                estsurlechemin3();
                            }
                            if (!indisponnible) {
                                bomber[quelbomber].xt = mouse_state.x - 35;
                                bomber[quelbomber].yt = mouse_state.y - 50;
                                quittermenu = 1;
                                pause = 0;
                                joueur->or -= bomber[quelbomber].cout;
                                poser = 1;
                                quelbomber++;
                            }
                            else {
                                al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), mouse_state.x-100, mouse_state.y, 0,
                                             "emplacement indisponible");
                                al_flip_display();
                            }
                        }
                    }
                }
                else if (joueur[0].or < 50) { // PAS ASSEZ D'ARGENT
                    start = clock();
                    while (!poser) {
                        stop = clock();
                        al_get_mouse_state(&mouse_state);
                        al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 600, 300, 0,
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

            // CHOIX DRAGON
            else if (mouse_state.y > 600) {
                if (mouse_state.buttons & 1){
                    if (joueur[0].or >= 100) {
                        dragon.x = 1900;
                        quittermenu = 1;
                        joueur->or -= 100;
                        pause = 1;
                    }
                    else if (joueur->or < 100){
                        start = clock();
                        while (!poser) {
                            stop = clock();
                            al_get_mouse_state(&mouse_state);
                            al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 600, 300, 0,
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
}