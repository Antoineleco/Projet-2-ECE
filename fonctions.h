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

typedef struct{
    int hp,or,vit,gel,target;
   double x,y;
    ALLEGRO_BITMAP *imagemonstre1;
    ALLEGRO_BITMAP *imagemonstre3;
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
    ALLEGRO_BITMAP *imagefond;
}Fond;

ALLEGRO_FONT *robotoRegular40;
ALLEGRO_FONT *robotoRegular50;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *timer;
ALLEGRO_EVENT event;
ALLEGRO_MOUSE_STATE mouse_state;
ALLEGRO_KEYBOARD_STATE keyboard_state;
clock_t start, stop,reset1,reset2;
Joueur joueur[1];
Tour archer[10];
Monstre monstre[50];
Tour sorcierdeglace[10];
Fond fond;
Tour bomber[10];
bool poser;
bool isEnd ;
bool pause;
bool quittermenu;
bool indisponnible;
int vit0;
int vit1;
int vit2;
int a;
int quelarcher;
int quelsorcierdeglace;
int quelbomber;
int degat;


void toutdessiner1();
void toutdessiner2();
void creersorcierdeglace();
void creermonstre();
void creerarcher();
void degatssorcierdeglace();
void creerbomber();
void vague1();
void vague2();
void initialiserjoueur();
void vitessenormale();
void vitesselente();
void vitesserapide();
void degatsarcher();
void chargerimages();
void degatsbomber();
void poserlatour();

#endif //PROJET_2_ECE_FONCTIONS_H
