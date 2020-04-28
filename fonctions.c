//
// Created by Antoi on 25/04/2020.
//

#include "fonctions.h"


void toutdessiner1 () {
    al_draw_bitmap(fond.imagefond, 0, 0, 0);
    for (int i=0; i < 10; i++){
        al_draw_bitmap(archer[i].imagetour1, archer[i].xt, archer[i].yt, 0);
        al_draw_bitmap(sorcierdeglace[i].imagetour1, sorcierdeglace[i].xt, sorcierdeglace[i].yt, 0);
        al_draw_bitmap(bomber[i].imagetour1, bomber[i].xt, bomber[i].yt, 0);
    }
    for (int i=0; i < 50; i++){
        al_draw_bitmap(monstre[i].imagemonstre1, monstre[i].x, monstre[i].y, 0);
    }
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 50, 0, "boutique:        P");
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 100, 0, "Play/Pause: ESPACE");
}

void toutdessiner2 () {
    al_draw_bitmap(fond.imagefond, 0,0,0);
    for (int i=0; i < 10; i++){
        al_draw_bitmap(archer[i].imagetour2, archer[i].xt, archer[i].yt, 0);
        al_draw_bitmap(sorcierdeglace[i].imagetour2, sorcierdeglace[i].xt, sorcierdeglace[i].yt, 0);
        al_draw_bitmap(bomber[i].imagetour2, bomber[i].xt, bomber[i].yt, 0);
    }
    for (int i=0; i < 50; i++){
        al_draw_bitmap(monstre[i].imagemonstre3, monstre[i].x, monstre[i].y, 0);
    }
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 50, 0, "boutique:        P");
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 100, 0, "Play/Pause: ESPACE");
}

void initialiserjoueur(){
    joueur[0].or =1000;
    joueur[0].vie= 2000;
}

void creermonstre() {
    for (int i = 0; i < 50; i++) {
        monstre[i].x = (-40*i)-100;
        monstre[i].y = 450;
        monstre[i].hp = 500;
        monstre[i].or = 20;
        monstre[i].vit = 4;
        monstre[i].gel = 0;
    }
}

void creerarcher(){
    for (int i = 0; i < 10; i++) {
        archer[i].xt = 2000;
        archer[i].yt = 2000;
        archer[i].cout = 30;
        archer[i].degats = 50;
        archer[i].rng = 100;
        archer[i].place = 0;
    }
}

void creersorcierdeglace(){
    for (int i = 0; i < 10; i++) {
        sorcierdeglace[i].xt = 2000;
        sorcierdeglace[i].yt = 2000;
        sorcierdeglace[i].cout = 50;
        sorcierdeglace[i].degats = 2;
        sorcierdeglace[i].rng = 100;
        sorcierdeglace[i].place = 0;
    }
}

void creerbomber(){
    for (int i = 0; i < 10; i++) {
        bomber[i].xt = 2000;
        bomber[i].yt = 2000;
        bomber[i].cout = 40;
        bomber[i].degats = 8;
        bomber[i].rng = 50;
        bomber[i].place = 0;
    }
}

void degatsarcher(){
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 50; i++) {
            monstre[i].target = 0;
            if (monstre[i].x+25<(archer[j].xt + 50 + archer[j].rng) && monstre[i].x+25>(
                    archer[j].xt - archer[j].rng) &&
                monstre[i].y+25<(archer[j].yt + 100 + archer[j].rng) && monstre[i].y+25>(
                        archer[j].yt - archer[j].rng)) {
                monstre[i].target += 1;
                degat = 1;
            }
        }
        int i = 0;
        while (degat) {
            if (monstre[i].target >= 1) {
                monstre[i].hp -= archer[j].degats * monstre[i].target;
                degat = 0;
            } else {
                i++;
            }
        }
    }
}

void degatssorcierdeglace(){
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 10; j++) {
            if (monstre[i].x+25<(sorcierdeglace[j].xt + 50 + sorcierdeglace[j].rng) && monstre[i].x+25>(
                    sorcierdeglace[j].xt - sorcierdeglace[j].rng) &&
                monstre[i].y+25<(sorcierdeglace[j].yt + 100 + sorcierdeglace[j].rng) && monstre[i].y+25>(
                        sorcierdeglace[j].yt - sorcierdeglace[j].rng)) {
                monstre[i].gel = 1;
            }
        }
    }
}

void degatsbomber(){
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 10; j++) {
            if (monstre[i].x+25 <(bomber[j].xt + 100 + bomber[j].rng) && monstre[i].x +25>(
                    bomber[j].xt - bomber[j].rng) &&
                monstre[i].y+25<(bomber[j].yt + 100 + bomber[j].rng) && monstre[i].y+25>(
                        bomber[j].yt - bomber[j].rng)) {
                monstre[i].hp -= bomber[j].degats;
            }
        }
    }
}

void vague1(){
    for (int i = 0; i < 20; i++) {
        if (monstre[i].gel == 1) {
            if (monstre[i].hp >= 1 && vit0 == 1) {
                monstre[i].x += 1;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit1 == 1) {
                monstre[i].x += 2;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit2 == 1) {
                monstre[i].x += 4;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
        }
        if (monstre[i].gel == 0) {
            if (monstre[i].hp >= 1 && vit0 == 1) {
                monstre[i].x += 2;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit1 == 1) {
                monstre[i].x += 4;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit2 == 1) {
                monstre[i].x += 8;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur[0].or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague2(){
    for (int i = 20; i < 50; i++) {
        if (monstre[i].gel == 1) {
            if (monstre[i].hp >= 1 && vit0 == 1) {
                monstre[i].x += 1;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit1 == 1) {
                monstre[i].x += 2;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit2 == 1) {
                monstre[i].x += 4;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
        }
        if (monstre[i].gel == 0) {
            if (monstre[i].hp >= 1 && vit0 == 1) {
                monstre[i].x += 2;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit1 == 1) {
                monstre[i].x += 4;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
            if (monstre[i].hp >= 1 && vit2 == 1) {
                monstre[i].x += 8;
                monstre[i].y = (cos(monstre[i].x/80)*100 + 450);
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur[0].or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vitessenormale(){
        for (int i = 0; i < 50; i++) {
            monstre[i].vit = 4;
        }
        for (int i = 0; i < 10; i++) {
            archer[i].degats = 8;
            sorcierdeglace[i].degats = 2;
        }
}
void vitesselente() {
    for (int i = 0; i < 50; i++) {
        monstre[i].vit = 2;
    }
    for (int i = 0; i < 10; i++) {
        archer[i].degats = 4;
        sorcierdeglace[i].degats = 1;
    }
}
void vitesserapide(){
    for (int i = 0; i < 50; i++) {
        monstre[i].vit = 8;
    }
    for (int i = 0; i < 10; i++) {
        archer[i].degats = 16;
        sorcierdeglace[i].degats = 4;
    }
}


void chargerimages(){
    fond.imagefond = al_load_bitmap("../fonddujeu.PNG");
    for (int i=0; i<10; i++){
        archer[i].imagetour1 = al_load_bitmap("../archer.PNG");
        archer[i].imagetour2 = al_load_bitmap("../archer.PNG");
        sorcierdeglace[i].imagetour1 = al_load_bitmap("../sorcierdeglace.PNG");
        sorcierdeglace[i].imagetour2 = al_load_bitmap("../sorcierdeglace.PNG");
        bomber[i].imagetour1 = al_load_bitmap("../bomber.PNG");
        bomber[i].imagetour2 = al_load_bitmap("../bomber.PNG");

    }
    for (int i=0; i<50; i++){
        monstre[i].imagemonstre1 = al_load_bitmap("../monstre1.PNG");
        monstre[i].imagemonstre3 = al_load_bitmap("../monstre3.PNG");
    }
}

void poserlatour(){
    for (int j = 0; j < 10; j++) {
        if ((mouse_state.x > archer[j].xt - 25) && (mouse_state.x < archer[j].xt + 150) &&
            (mouse_state.y > archer[j].yt - 25) &&
            (mouse_state.y < archer[j].yt + 150)) {
            indisponnible = 1;
        }
    }
    for (int j = 0; j < 10; j++) {
        if ((mouse_state.x > sorcierdeglace[j].xt - 25) && (mouse_state.x < sorcierdeglace[j].xt + 150) &&
            (mouse_state.y > sorcierdeglace[j].yt - 25) &&
            (mouse_state.y < sorcierdeglace[j].yt + 150)) {
            indisponnible = 1;
        }
    }
    for (int j = 0; j < 10; j++) {
        if ((mouse_state.x > bomber[j].xt - 25) && (mouse_state.x < bomber[j].xt + 150) &&
            (mouse_state.y > bomber[j].yt - 25) &&
            (mouse_state.y < bomber[j].yt + 150)) {
            indisponnible = 1;
        }
    }
}
