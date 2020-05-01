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
#include <math.h>
#include <stdio.h>

typedef struct{
    int hp,or,vit,gel,target;
   double x,y;
    ALLEGRO_BITMAP *imagemonstre1;
    ALLEGRO_BITMAP *imagemonstre2;
    ALLEGRO_BITMAP *imagemonstre3;
    ALLEGRO_BITMAP *imagemonstre4;
}Monstre;

typedef struct{
    int cout,degats,rng,place;
    float xt,yt;
    ALLEGRO_BITMAP *imagetour1;
    ALLEGRO_BITMAP *imagetour2;

}Tour;

typedef struct{
    int or,vie;
}Joueur;

typedef struct{
    int x;
    ALLEGRO_BITMAP *imagedragon1;
    ALLEGRO_BITMAP *imagedragon2;
    ALLEGRO_BITMAP *flammes;
}Dragon;

typedef struct{
    ALLEGRO_BITMAP *fondniveau1;
    ALLEGRO_BITMAP *fondniveau2;
    ALLEGRO_BITMAP *fondniveau3;
    ALLEGRO_BITMAP *victoire;
    ALLEGRO_BITMAP *defaite;
    ALLEGRO_BITMAP *fondmenutour;
    ALLEGRO_BITMAP *fondmenuprincipal;
    ALLEGRO_BITMAP *regles;
    ALLEGRO_BITMAP *argent;
}Fond;


ALLEGRO_FONT *robotoRegular40;
ALLEGRO_FONT *robotoRegular50;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_EVENT_QUEUE *queuemenu;
ALLEGRO_EVENT_QUEUE *queueregles;
ALLEGRO_TIMER *timer;
ALLEGRO_TIMER *timermenu;
ALLEGRO_EVENT event;
ALLEGRO_EVENT eventmenu;
ALLEGRO_EVENT eventregles;

ALLEGRO_MOUSE_STATE mouse_state;
ALLEGRO_KEYBOARD_STATE keyboard_state;
clock_t start, stop;
Joueur joueur[1];
Tour archer[10];
Monstre monstre[180];
Tour sorcierdeglace[10];
Fond fond;
Tour bomber[10];
Dragon dragon;
bool poser;
bool finduniveau;
bool isEnd ;
bool pause;
bool quittermenu;
bool indisponnible;
int lvl1,lvl2,lvl3;
int vit0;
int vit1;
int vit2;
int a;
int quelarcher;
int quelsorcierdeglace;
int quelbomber;
int degat;

void niveau();
void dessinerfond();
void toutdessiner1();
void toutdessiner2();
void chargerimages();
void initialiserjoueur();
void creermonstre();
void creersorcierdeglace();
void creerarcher();
void creerbomber();
void creerdragon();
void degatsarcher();
void degatssorcierdeglace();
void degatsbomber();
void degatjoueur();
void pouvoirdragon();
void vague1();
void vague2();
void vague3();
void vague4 ();
void vague1nv2();
void vague2nv2();
void vague3nv2();
void vague4nv2();
void vague1nv3();
void vague2nv3();
void vague3nv3();
void vague4nv3();
void vitessenormale();
void vitesselente();
void vitesserapide();
void poserlatour();
void estsurlechemin1();
void estsurlechemin2();
void estsurlechemin3();
void findujeu();
void menutours();
void afficherregles();
#endif //PROJET_2_ECE_FONCTIONS_H
