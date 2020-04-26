//
// Created by Antoi on 25/04/2020.
//

#ifndef PROJET_2_ECE_FONCTIONS_H
#define PROJET_2_ECE_FONCTIONS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

typedef struct{
    int hp,or,vit,gel,target;
    float x,y;
    ALLEGRO_BITMAP *imagemonstre1;
    ALLEGRO_BITMAP *imagemonstre2;
    ALLEGRO_BITMAP *imagemonstre3;
}Monstre;

typedef struct{
    int cout,degats,rng,place;
    float xt,yt;
    ALLEGRO_BITMAP *imagetour1;
}Tour;

typedef struct{
    int or,vie;
}Joueur;

ALLEGRO_FONT *robotoRegular40;
ALLEGRO_FONT *robotoRegular50;


void toutdessiner1(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]);
void toutdessiner2(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]);
void toutdessiner3(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]);
void creertourdegel(Tour tourdegel[10]);
void creermonstre(Monstre monstre[50]);
void creertourelle(Tour tourelle[10]);
void degattourdegel(Tour tourdegel[10], Monstre monstre[50]);
void deplacementmonstre(Monstre monstre[50], int vit0, int vit1,int vit3,Joueur joueur[1]);
void initialiserjoueur(Joueur joueur[1]);
void vitessenormale(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]);
void vitesselente(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]);
void vitesserapide(Tour tourelle[10],Tour tourdegel[10],Monstre monstre[50]);
void degattourelle(Tour tourelle[10], Monstre monstre[50], int degat);
#endif //PROJET_2_ECE_FONCTIONS_H
