//
// Created by Antoi on 25/04/2020.
//

#include "fonctions.h"


void toutdessiner1 (Tour tourelle[10],Tour tourdegel[10], Monstre monstre[50]) {
    al_clear_to_color(al_map_rgb(200, 200, 200));
    for (int i=0; i < 10; i++){
        al_draw_bitmap(tourelle[i].imagetour1, tourelle[i].xt, tourelle[i].yt, 0);
        al_draw_bitmap(tourdegel[i].imagetour1, tourdegel[i].xt, tourdegel[i].yt, 0);
    }
    for (int i=0; i < 50; i++){
        al_draw_bitmap(monstre[i].imagemonstre1, monstre[i].x, monstre[i].y, 0);
    }
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 50, 0, "boutique: P");
    al_flip_display();
}

void toutdessiner2 (Tour tourelle[10], Tour tourdegel[10], Monstre monstre[50]) {
    al_clear_to_color(al_map_rgb(200, 200, 200));
    for (int i=0; i < 10; i++){
        al_draw_bitmap(tourelle[i].imagetour1, tourelle[i].xt, tourelle[i].yt, 0);
        al_draw_bitmap(tourdegel[i].imagetour1, tourdegel[i].xt, tourdegel[i].yt, 0);
    }
    for (int i=0; i < 50; i++){
        al_draw_bitmap(monstre[i].imagemonstre2, monstre[i].x, monstre[i].y, 0);
    }
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 50, 0, "boutique: P");
    al_flip_display();
}

void toutdessiner3 (Tour tourelle[10], Tour tourdegel[10], Monstre monstre[50]) {
    al_clear_to_color(al_map_rgb(200, 200, 200));
    for (int i=0; i < 10; i++){
        al_draw_bitmap(tourelle[i].imagetour1, tourelle[i].xt, tourelle[i].yt, 0);
        al_draw_bitmap(tourdegel[i].imagetour1, tourdegel[i].xt, tourdegel[i].yt, 0);
    }
    for (int i=0; i < 50; i++){
        al_draw_bitmap(monstre[i].imagemonstre3, monstre[i].x, monstre[i].y, 0);
    }
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1800, 50, 0, "boutique: P");
    al_flip_display();
}

void initialiserjoueur(Joueur joueur[1]){
    joueur[0].or = 100;
    joueur[0].vie= 2000;
}

void creermonstre(Monstre monstre[50]) {
    for (int i = 0; i < 50; i++) {
        monstre[i].x = (-100*i);
        monstre[i].y = 450;
        monstre[i].hp = 500;
        monstre[i].or = 20;
        monstre[i].vit = 4;
        monstre[i].gel = 0;
    }
}

void creertourelle(Tour tourelle[10]){
    for (int i = 0; i < 10; i++) {
        tourelle[i].xt = 2000;
        tourelle[i].yt = 2000;
        tourelle[i].cout = 30;
        tourelle[i].degats = 8;
        tourelle[i].rng = 100;
        tourelle[i].place = 0;
    }
}

void creertourdegel(Tour tourdegel[10]){
    for (int i = 0; i < 10; i++) {
        tourdegel[i].xt = 2000;
        tourdegel[i].yt = 2000;
        tourdegel[i].cout = 50;
        tourdegel[i].degats = 2;
        tourdegel[i].rng = 100;
        tourdegel[i].place = 0;
    }
}

void degattourdegel(Tour tourdegel[10], Monstre monstre[50]){
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 10; j++) {
            if (monstre[i].x<(tourdegel[j].xt + 100 + tourdegel[j].rng) && monstre[i].x>(
                    tourdegel[j].xt - tourdegel[j].rng) &&
                monstre[i].y<(tourdegel[j].yt + 100 + tourdegel[j].rng) && monstre[i].y>(
                        tourdegel[j].yt - tourdegel[j].rng)) {
                monstre[i].gel = 1;
            }
        }
    }
}

void deplacementmonstre(Monstre monstre[50], int vit0,  int vit1, int vit2,Joueur joueur[1]){
    for (int i = 0; i < 50; i++) {
        if (monstre[i].gel == 1) {
            if (monstre[i].hp >= 1 && vit0 == 1) {
                monstre[i].x += 1;
            }
            if (monstre[i].hp >= 1 && vit1 == 1) {
                monstre[i].x += 2;
            }
            if (monstre[i].hp >= 1 && vit2 == 1) {
                monstre[i].x += 4;
            }
        }
        if (monstre[i].gel == 0) {
            if (monstre[i].hp >= 1 && vit0 == 1) {
                monstre[i].x += 2;
            }
            if (monstre[i].hp >= 1 && vit1 == 1) {
                monstre[i].x += 4;
            }
            if (monstre[i].hp >= 1 && vit2 == 1) {
                monstre[i].x += 8;
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur[0].or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vitessenormale(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]){
        for (int i = 0; i < 50; i++) {
            monstre[i].vit = 4;
        }
        for (int i = 0; i < 10; i++) {
            tourelle[i].degats = 8;
            tourdegel[i].degats = 2;
        }
}
void vitesselente(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]) {
    for (int i = 0; i < 50; i++) {
        monstre[i].vit = 2;
    }
    for (int i = 0; i < 10; i++) {
        tourelle[i].degats = 4;
        tourdegel[i].degats = 1;
    }
}
void vitesserapide(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]){
    for (int i = 0; i < 50; i++) {
        monstre[i].vit = 8;
    }
    for (int i = 0; i < 10; i++) {
        tourelle[i].degats = 16;
        tourdegel[i].degats = 4;
    }
}

void degattourelle(Tour tourelle[10], Monstre monstre[50], int degat){
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 50; i++) {
            monstre[i].target = 0;
            if (monstre[i].x<(tourelle[j].xt + 100 + tourelle[j].rng) && monstre[i].x>(
                    tourelle[j].xt - tourelle[j].rng) &&
                monstre[i].y<(tourelle[j].yt + 100 + tourelle[j].rng) && monstre[i].y>(
                        tourelle[j].yt - tourelle[j].rng)) {
                monstre[i].target += 1;
                degat = 1;
            }
        }
        int i = 0;
        while (degat) {
            if (monstre[i].target >= 1) {
                monstre[i].hp -= tourelle[j].degats * monstre[i].target;
                degat = 0;
            } else {
                i++;
            }
        }
    }
}

