//
// Created by Antoi on 25/04/2020.
//

#include "fonctions.h"

void dessinerfond(){
    if (lvl1){
        al_draw_bitmap(fond.fondniveau1, 0, 0, 0);
    }
    else if (lvl2){
        al_draw_bitmap(fond.fondniveau2, 0, 0, 0);
    }
    else if (lvl3){
        al_draw_bitmap(fond.fondniveau3, 0, 0, 0);
    }
}

void toutdessiner1 () {
    dessinerfond();
    for (int i=0; i < 10; i++){
        al_draw_bitmap(archer[i].imagetour1, archer[i].xt, archer[i].yt, 0);
        al_draw_bitmap(sorcierdeglace[i].imagetour1, sorcierdeglace[i].xt, sorcierdeglace[i].yt, 0);
        al_draw_bitmap(bomber[i].imagetour1, bomber[i].xt, bomber[i].yt, 0);
    }
    for (int i=0; i < 10; i++){
        al_draw_bitmap(monstre[i].imagemonstre1, monstre[i].x, monstre[i].y, 0);
    }
    for (int i=10; i<30;i++){
        if (i%5 ==0){
            al_draw_bitmap(monstre[i].imagemonstre3, monstre[i].x, monstre[i].y, 0);
        }
        else{
            al_draw_bitmap(monstre[i].imagemonstre1, monstre[i].x, monstre[i].y, 0);
        }
    }
    for (int i=30; i<80;i++){
        if (i%3 ==0){
            al_draw_bitmap(monstre[i].imagemonstre3, monstre[i].x, monstre[i].y, 0);
        }
        else{
            al_draw_bitmap(monstre[i].imagemonstre1, monstre[i].x, monstre[i].y, 0);
        }
    }
    for (int i=80; i<180;i++){
        al_draw_bitmap(monstre[i].imagemonstre3, monstre[i].x, monstre[i].y, 0);
    }
    for (int i=0; i<180; i++){
        al_draw_rectangle(monstre[i].x, monstre[i].y - 15, monstre[i].x + (monstre[i].hp / (15+(i/10))), monstre[i].y-10,al_map_rgb(0,255,0),2);
    }
    al_draw_bitmap(dragon.imagedragon1, dragon.x, 300, 0);
    if(dragon.x < 1050 && dragon.x > 850){
        al_draw_bitmap(dragon.flammes,0,0,0);
    }
    al_draw_bitmap(fond.argent,575,10,0);
    al_draw_line(580,30,585+joueur->or *5,30,al_map_rgb(200,200,0),20);
    al_draw_bitmap(al_load_bitmap("../piece.PNG"),500,-15,0);

    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 10, 0, "Store:                        S");
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 40, 0, "Play/Pause:  ESPACE");
}

void toutdessiner2 () {
    dessinerfond();
    for (int i=0; i < 10; i++){
        al_draw_bitmap(archer[i].imagetour2, archer[i].xt, archer[i].yt, 0);
        al_draw_bitmap(sorcierdeglace[i].imagetour2, sorcierdeglace[i].xt, sorcierdeglace[i].yt, 0);
        al_draw_bitmap(bomber[i].imagetour2, bomber[i].xt -56, bomber[i].yt-36, 0);
    }
    for (int i=0; i < 10; i++){
        al_draw_bitmap(monstre[i].imagemonstre2, monstre[i].x, monstre[i].y, 0);
    }
    for (int i=10; i<30;i++){
        if (i%5 ==0){
            al_draw_bitmap(monstre[i].imagemonstre4, monstre[i].x, monstre[i].y, 0);
        }
        else{
            al_draw_bitmap(monstre[i].imagemonstre2, monstre[i].x, monstre[i].y, 0);
        }
    }
    for (int i=30; i<80;i++){
        if (i%3 ==0){
            al_draw_bitmap(monstre[i].imagemonstre4, monstre[i].x, monstre[i].y, 0);
        }
        else{
            al_draw_bitmap(monstre[i].imagemonstre2, monstre[i].x, monstre[i].y, 0);
        }
    }
    for (int i=80; i<180;i++){
        al_draw_bitmap(monstre[i].imagemonstre4, monstre[i].x, monstre[i].y, 0);
    }
    for(int i=0; i<180; i++){
        al_draw_rectangle(monstre[i].x, monstre[i].y - 15, monstre[i].x + (monstre[i].hp / (15+(i/10))), monstre[i].y-10,al_map_rgb(0,255,0),2);
    }
    al_draw_bitmap(dragon.imagedragon2, dragon.x, 300, 0);
    if(dragon.x < 1050 && dragon.x > 850){
        al_draw_bitmap(dragon.flammes,0,0,0);
    }

    al_draw_bitmap(fond.argent,575,10,0);
    al_draw_line(580,30,585+joueur->or *5,30,al_map_rgb(200,200,0),20);
    al_draw_bitmap(al_load_bitmap("../piece.PNG"),500,-15,0);

    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 10, 0, "Store:                        S");
    al_draw_text(robotoRegular40, al_map_rgb(0, 0, 0), 1700, 40, 0, "Play/Pause:  ESPACE");
}

// INITIALISATIONS


void initialiserjoueur(){
    joueur[0].or =100;
    joueur[0].vie= 2000;
}

void creermonstre() {
    for (int i = 0; i < 10; i++) {
        monstre[i].x = (-40*i)-100;
        monstre[i].y = 450;
        monstre[i].hp = 500;
        monstre[i].or = 1;
        monstre[i].vit = 4;
        monstre[i].gel = 0;
    }
    for (int i = 10; i < 30; i++) {
        if(i%5 == 0){
            monstre[i].x = (-40*i)+300;
            monstre[i].y = 450;
            monstre[i].hp = 1000;
            monstre[i].or = 1;
            monstre[i].vit = 4;
            monstre[i].gel = 0;
        }
        else {
            monstre[i].x = (-40 * i) + 300;
            monstre[i].y = 450;
            monstre[i].hp = 500;
            monstre[i].or = 1;
            monstre[i].vit = 4;
            monstre[i].gel = 0;
        }
    }
    for (int i = 30; i < 80; i++) {
        if(i%3 == 0){
            monstre[i].x = (-40*i)+1000;
            monstre[i].y = 450;
            monstre[i].hp = 1000;
            monstre[i].or = 1;
            monstre[i].vit = 4;
            monstre[i].gel = 0;
        }
        else {
            monstre[i].x = (-40 * i) + 1000;
            monstre[i].y = 450;
            monstre[i].hp = 500 +2*i;
            monstre[i].or = 1;
            monstre[i].vit = 4;
            monstre[i].gel = 0;
        }
    }
    for (int i = 80; i < 180; i++) {
        monstre[i].x = (-40*i)+3000;
        monstre[i].y = 450;
        monstre[i].hp = 1000 + 5*i;
        monstre[i].or = 1;
        monstre[i].vit = 4;
        monstre[i].gel = 0;
    }
    monstre[9].or = 30;
    monstre[29].or = 50;
    monstre[79].or = 70;
}

void creerarcher(){
    for (int i = 0; i < 10; i++) {
        archer[i].xt = 2000;
        archer[i].yt = 2000;
        archer[i].cout = 80;
        archer[i].degats =34;
        archer[i].rng = 100;
        archer[i].place = 0;
    }
}

void chargerimages() {
    fond.fondniveau1 = al_load_bitmap("../fondniveau1.PNG");
    fond.fondniveau2 = al_load_bitmap("../fondniveau2.PNG");
    fond.fondniveau3 = al_load_bitmap("../fondniveau3.PNG");
    fond.fondmenutour = al_load_bitmap("../fondmenutour.PNG");
    fond.victoire = al_load_bitmap("../Victoire manche.PNG");
    fond.argent = al_load_bitmap("../argent.PNG");
    dragon.imagedragon1 = al_load_bitmap("../dragon1.PNG");
    dragon.imagedragon2 = al_load_bitmap("../dragon2.PNG");
    dragon.flammes = al_load_bitmap("../flammes");
    dragon.flammes = al_load_bitmap("../brute1.PNG");
    for (int i = 0; i < 10; i++) {
        archer[i].imagetour1 = al_load_bitmap("../archer.PNG");
        archer[i].imagetour2 = al_load_bitmap("../archer.PNG");
        sorcierdeglace[i].imagetour1 = al_load_bitmap("../sorcierdeglace.PNG");
        sorcierdeglace[i].imagetour2 = al_load_bitmap("../sorcierdeglace.PNG");
        bomber[i].imagetour1 = al_load_bitmap("../bomber.PNG");
        bomber[i].imagetour2 = al_load_bitmap("../bombexplosion.PNG");

    }
    for (int i=0; i<180; i++){
        monstre[i].imagemonstre1 = al_load_bitmap("../goblin1.PNG");
        monstre[i].imagemonstre2 = al_load_bitmap("../goblin2.PNG");
        monstre[i].imagemonstre3 = al_load_bitmap("../brute1.PNG");
        monstre[i].imagemonstre4 = al_load_bitmap("../brute2.PNG");
    }
}

// DEGATS / PERTES VIE DU JOUEUR


void creersorcierdeglace(){
    for (int i = 0; i < 10; i++) {
        sorcierdeglace[i].xt = 2000;
        sorcierdeglace[i].yt = 2000;
        sorcierdeglace[i].cout = 70;
        sorcierdeglace[i].degats = 2;
        sorcierdeglace[i].rng = 100;
        sorcierdeglace[i].place = 0;
    }
}

void creerbomber(){
    for (int i = 0; i < 10; i++) {
        bomber[i].xt = 2000;
        bomber[i].yt = 2000;
        bomber[i].cout = 50;
        bomber[i].degats = 8;
        bomber[i].rng = 60;
        bomber[i].place = 0;
    }
}

void creerdragon(){
    dragon.x = -500;
}

void degatsarcher(){
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 180; i++) {
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
            if (monstre[i].target >= 1 && monstre[i].hp>0) {
                monstre[i].hp -= archer[j].degats * monstre[i].target;
                degat = 0;
            } else {
                i++;
            }
        }
    }
}

void degatssorcierdeglace(){
    for (int i = 0; i < 180; i++) {
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
    for (int i = 0; i < 180; i++) {
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

void degatjoueur(){
    for(int i=0; i<180; i++){
        if (monstre[i].x > 1900){
            joueur->vie -= monstre[i].hp;
            monstre[i].hp = 0;
        }
    }
}

void pouvoirdragon(){
    dragon.x -= 8;
    if (dragon.x<= 954 && dragon.x > 946){
        for (int i=0; i<180; i++){
            if (monstre[i].x < 1900 && monstre[i].x > 0){
                monstre[i].hp -= monstre[i].hp/2 + monstre[i].hp/4;
            }
        }
    }
}


// VAGUES DE MONSTRES

void vague1nv2(){
    for (int i = 0; i < 10; i++) {
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
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}


void vague2nv2(){
    for (int i = 10; i < 30; i++) {
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
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague3nv2(){
        for (int i = 30; i < 80; i++) {
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
                joueur->or += monstre[i].or;
                monstre[i].or = 0;
            }
        }
}

void vague4nv2(){
        for (int i = 80; i < 180; i++) {
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
                joueur->or += monstre[i].or;
                monstre[i].or = 0;
            }
        }
}

void vague1nv3(){
    for (int i = 0; i < 10; i++) {
        if (monstre[i].x <= 500){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        else if (monstre[i].y< 800 && monstre[i].y > 100) {
            monstre[i].x = 501;
            if (i % 2 == 0) {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y += 2;
                    }
                    if(vit1){
                        monstre[i].y += 4;
                    }
                    if(vit2){
                        monstre[i].y += 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y += 1;
                    }
                    if(vit1){
                        monstre[i].y += 2;
                    }
                    if(vit2){
                        monstre[i].y += 4;
                    }
                }
            } else {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y -= 2;
                    }
                    if(vit1){
                        monstre[i].y -= 4;
                    }
                    if(vit2){
                        monstre[i].y -= 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y -= 1;
                    }
                    if(vit1){
                        monstre[i].y -= 2;
                    }
                    if(vit2){
                        monstre[i].y -= 4;
                    }
                }
            }
        }
        if (monstre[i].y >= 800) {
            monstre[i].y = 800;
            if (!monstre[i].gel) {
                if (vit0) {
                    monstre[i].x += 2;
                }
                if (vit1) {
                    monstre[i].x += 4;
                }
                if (vit2) {
                    monstre[i].x += 8;
                }
            } else {
                if (vit0) {
                    monstre[i].x += 1;
                }
                if (vit1) {
                    monstre[i].x += 2;
                }
                if (vit2) {
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].y <= 100){
            monstre[i].y =100;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague2nv3(){
    for (int i = 10; i < 30; i++) {
        if (monstre[i].x <= 500){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        else if (monstre[i].y< 800 && monstre[i].y > 100) {
            monstre[i].x = 501;
            if (i % 2 == 0) {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y += 2;
                    }
                    if(vit1){
                        monstre[i].y += 4;
                    }
                    if(vit2){
                        monstre[i].y += 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y += 1;
                    }
                    if(vit1){
                        monstre[i].y += 2;
                    }
                    if(vit2){
                        monstre[i].y += 4;
                    }
                }
            } else {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y -= 2;
                    }
                    if(vit1){
                        monstre[i].y -= 4;
                    }
                    if(vit2){
                        monstre[i].y -= 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y -= 1;
                    }
                    if(vit1){
                        monstre[i].y -= 2;
                    }
                    if(vit2){
                        monstre[i].y -= 4;
                    }
                }
            }
        }
        if (monstre[i].y >= 800) {
            monstre[i].y = 800;
            if (!monstre[i].gel) {
                if (vit0) {
                    monstre[i].x += 2;
                }
                if (vit1) {
                    monstre[i].x += 4;
                }
                if (vit2) {
                    monstre[i].x += 8;
                }
            } else {
                if (vit0) {
                    monstre[i].x += 1;
                }
                if (vit1) {
                    monstre[i].x += 2;
                }
                if (vit2) {
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].y <= 100){
            monstre[i].y =100;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague3nv3(){
    for (int i = 30; i < 80; i++) {
        if (monstre[i].x <= 500){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        else if (monstre[i].y< 800 && monstre[i].y > 100) {
            monstre[i].x = 501;
            if (i % 2 == 0) {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y += 2;
                    }
                    if(vit1){
                        monstre[i].y += 4;
                    }
                    if(vit2){
                        monstre[i].y += 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y += 1;
                    }
                    if(vit1){
                        monstre[i].y += 2;
                    }
                    if(vit2){
                        monstre[i].y += 4;
                    }
                }
            } else {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y -= 2;
                    }
                    if(vit1){
                        monstre[i].y -= 4;
                    }
                    if(vit2){
                        monstre[i].y -= 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y -= 1;
                    }
                    if(vit1){
                        monstre[i].y -= 2;
                    }
                    if(vit2){
                        monstre[i].y -= 4;
                    }
                }
            }
        }
        if (monstre[i].y >= 800) {
            monstre[i].y = 800;
            if (!monstre[i].gel) {
                if (vit0) {
                    monstre[i].x += 2;
                }
                if (vit1) {
                    monstre[i].x += 4;
                }
                if (vit2) {
                    monstre[i].x += 8;
                }
            } else {
                if (vit0) {
                    monstre[i].x += 1;
                }
                if (vit1) {
                    monstre[i].x += 2;
                }
                if (vit2) {
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].y <= 100){
            monstre[i].y =100;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague4nv3(){
    for (int i = 80; i < 180; i++) {
        if (monstre[i].x <= 500){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        else if (monstre[i].y< 800 && monstre[i].y > 100) {
            monstre[i].x = 501;
            if (i % 2 == 0) {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y += 2;
                    }
                    if(vit1){
                        monstre[i].y += 4;
                    }
                    if(vit2){
                        monstre[i].y += 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y += 1;
                    }
                    if(vit1){
                        monstre[i].y += 2;
                    }
                    if(vit2){
                        monstre[i].y += 4;
                    }
                }
            } else {
                if (!monstre[i].gel){
                    if(vit0){
                        monstre[i].y -= 2;
                    }
                    if(vit1){
                        monstre[i].y -= 4;
                    }
                    if(vit2){
                        monstre[i].y -= 8;
                    }
                }
                else{
                    if(vit0){
                        monstre[i].y -= 1;
                    }
                    if(vit1){
                        monstre[i].y -= 2;
                    }
                    if(vit2){
                        monstre[i].y -= 4;
                    }
                }
            }
        }
        if (monstre[i].y >= 800) {
            monstre[i].y = 800;
            if (!monstre[i].gel) {
                if (vit0) {
                    monstre[i].x += 2;
                }
                if (vit1) {
                    monstre[i].x += 4;
                }
                if (vit2) {
                    monstre[i].x += 8;
                }
            } else {
                if (vit0) {
                    monstre[i].x += 1;
                }
                if (vit1) {
                    monstre[i].x += 2;
                }
                if (vit2) {
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].y <= 100){
            monstre[i].y =100;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague1(){
    for(int i=0; i<10; i++){
        if(monstre[i].x<1200 && monstre[i].y == 450){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].x>= 1200 && monstre[i].y<=450 && monstre[i].y > 200 ){
            monstre[i].x = 1200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y -= 2;
                }
                if(vit1){
                    monstre[i].y -= 4;
                }
                if(vit2){
                    monstre[i].y -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y -= 1;
                }
                if(vit1){
                    monstre[i].y -= 2;
                }
                if(vit2){
                    monstre[i].y -= 4;
                }
            }
        }
        if(monstre[i].y<=200 && monstre[i].x > 500){
            monstre[i].y = 200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x -= 2;
                }
                if(vit1){
                    monstre[i].x -= 4;
                }
                if(vit2){
                    monstre[i].x -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x -= 1;
                }
                if(vit1){
                    monstre[i].x -= 2;
                }
                if(vit2){
                    monstre[i].x -= 4;
                }
            }
        }
        if (monstre[i].y >= 200 && monstre[i].y < 430 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if (monstre[i].x == 500 && monstre[i].y>=430 && monstre[i].y < 470 && monstre[i].y !=450){
            monstre[i].x = 500;
            monstre[i].y = 470;
        }
        if (monstre[i].y >= 470 && monstre[i].y < 800 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if(monstre[i].y >= 800){
            monstre[i].y = 800;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague2(){
    for(int i=10; i<30; i++){
        if(monstre[i].x<1200 && monstre[i].y == 450){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].x>= 1200 && monstre[i].y<=450 && monstre[i].y > 200 ){
            monstre[i].x = 1200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y -= 2;
                }
                if(vit1){
                    monstre[i].y -= 4;
                }
                if(vit2){
                    monstre[i].y -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y -= 1;
                }
                if(vit1){
                    monstre[i].y -= 2;
                }
                if(vit2){
                    monstre[i].y -= 4;
                }
            }
        }
        if(monstre[i].y<=200 && monstre[i].x > 500){
            monstre[i].y = 200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x -= 2;
                }
                if(vit1){
                    monstre[i].x -= 4;
                }
                if(vit2){
                    monstre[i].x -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x -= 1;
                }
                if(vit1){
                    monstre[i].x -= 2;
                }
                if(vit2){
                    monstre[i].x -= 4;
                }
            }
        }
        if (monstre[i].y >= 200 && monstre[i].y < 430 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if (monstre[i].x == 500 && monstre[i].y>=430 && monstre[i].y < 470 && monstre[i].y !=450){
            monstre[i].x = 500;
            monstre[i].y = 470;
        }
        if (monstre[i].y >= 470 && monstre[i].y < 800 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if(monstre[i].y >= 800){
            monstre[i].y = 800;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague3(){
    for(int i=30; i<80; i++){
        if(monstre[i].x<1200 && monstre[i].y == 450){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].x>= 1200 && monstre[i].y<=450 && monstre[i].y > 200 ){
            monstre[i].x = 1200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y -= 2;
                }
                if(vit1){
                    monstre[i].y -= 4;
                }
                if(vit2){
                    monstre[i].y -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y -= 1;
                }
                if(vit1){
                    monstre[i].y -= 2;
                }
                if(vit2){
                    monstre[i].y -= 4;
                }
            }
        }
        if(monstre[i].y<=200 && monstre[i].x > 500){
            monstre[i].y = 200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x -= 2;
                }
                if(vit1){
                    monstre[i].x -= 4;
                }
                if(vit2){
                    monstre[i].x -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x -= 1;
                }
                if(vit1){
                    monstre[i].x -= 2;
                }
                if(vit2){
                    monstre[i].x -= 4;
                }
            }
        }
        if (monstre[i].y >= 200 && monstre[i].y < 430 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if (monstre[i].x == 500 && monstre[i].y>=430 && monstre[i].y < 470 && monstre[i].y !=450){
            monstre[i].x = 500;
            monstre[i].y = 470;
        }
        if (monstre[i].y >= 470 && monstre[i].y < 800 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if(monstre[i].y >= 800){
            monstre[i].y = 800;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}

void vague4(){
    for(int i=80; i<180; i++){
        if(monstre[i].x<1200 && monstre[i].y == 450){
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if (monstre[i].x>= 1200 && monstre[i].y<=450 && monstre[i].y > 200 ){
            monstre[i].x = 1200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y -= 2;
                }
                if(vit1){
                    monstre[i].y -= 4;
                }
                if(vit2){
                    monstre[i].y -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y -= 1;
                }
                if(vit1){
                    monstre[i].y -= 2;
                }
                if(vit2){
                    monstre[i].y -= 4;
                }
            }
        }
        if(monstre[i].y<=200 && monstre[i].x > 500){
            monstre[i].y = 200;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x -= 2;
                }
                if(vit1){
                    monstre[i].x -= 4;
                }
                if(vit2){
                    monstre[i].x -= 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x -= 1;
                }
                if(vit1){
                    monstre[i].x -= 2;
                }
                if(vit2){
                    monstre[i].x -= 4;
                }
            }
        }
        if (monstre[i].y >= 200 && monstre[i].y < 430 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if (monstre[i].x == 500 && monstre[i].y>=430 && monstre[i].y < 470 && monstre[i].y !=450){
            monstre[i].x = 500;
            monstre[i].y = 470;
        }
        if (monstre[i].y >= 470 && monstre[i].y < 800 && monstre[i].x<=500){
            monstre[i].x = 500;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].y += 2;
                }
                if(vit1){
                    monstre[i].y += 4;
                }
                if(vit2){
                    monstre[i].y += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].y += 1;
                }
                if(vit1){
                    monstre[i].y += 2;
                }
                if(vit2){
                    monstre[i].y += 4;
                }
            }
        }
        if(monstre[i].y >= 800){
            monstre[i].y = 800;
            if (!monstre[i].gel){
                if(vit0){
                    monstre[i].x += 2;
                }
                if(vit1){
                    monstre[i].x += 4;
                }
                if(vit2){
                    monstre[i].x += 8;
                }
            }
            else{
                if(vit0){
                    monstre[i].x += 1;
                }
                if(vit1){
                    monstre[i].x += 2;
                }
                if(vit2){
                    monstre[i].x += 4;
                }
            }
        }
        if(monstre[i].hp<1){
            monstre[i].x = 3000;
            joueur->or += monstre[i].or;
            monstre[i].or = 0;
        }
    }
}


// VITESSES DE JEU


void vitesselente() {
    for (int i = 0; i < 180; i++) {
        monstre[i].vit = 2;
    }
    for (int i = 0; i < 10; i++) {
        archer[i].degats = 17;
        sorcierdeglace[i].degats = 1;
        bomber[i].degats = 4;
    }
}

void vitessenormale(){
        for (int i = 0; i < 180; i++) {
            monstre[i].vit = 4;
        }
        for (int i = 0; i < 10; i++) {
            archer[i].degats = 34;
            sorcierdeglace[i].degats = 2;
            bomber[i].degats = 8;
        }
}

void vitesserapide(){
    for (int i = 0; i < 180; i++) {
        monstre[i].vit = 8;
    }
    for (int i = 0; i < 10; i++) {
        archer[i].degats = 68;
        sorcierdeglace[i].degats = 4;
        bomber[i].degats = 16;
    }
}


// FONCTIONS COMPLEMENTAIRES


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

void estsurlechemin2() {
    if ((mouse_state.y < cos(mouse_state.x / 80) * 100 + 525) &&
        (mouse_state.y > cos(mouse_state.x / 80) * 100 + 400)) {
        indisponnible = 1;
    }
}


void estsurlechemin1(){
    if (mouse_state.x <= 1225 && mouse_state.y > 400 && mouse_state.y < 525 ){
        indisponnible=1;
    }
    if (mouse_state.x>1175 && mouse_state.x < 1275 && mouse_state.y < 550 && mouse_state.y > 125){
        indisponnible=1;
    }
    if (mouse_state.x <= 1225 && mouse_state.x >= 475 && mouse_state.y > 125 && mouse_state.y < 300){
        indisponnible=1;
    }
    if (mouse_state.x < 575 && mouse_state.x > 475 && mouse_state.y > 125 && mouse_state.y < 900){
        indisponnible = 1;
    }
    if (mouse_state.y > 750 && mouse_state.y < 900 && mouse_state.x > 475){
        indisponnible = 1;
    }
}

void estsurlechemin3(){
    if (mouse_state.x <= 475 && mouse_state.y > 400 && mouse_state.y < 525 ){
        indisponnible=1;
    }
    if (mouse_state.y >= 75 && mouse_state.y <= 850 && mouse_state.x >= 475 && mouse_state.x <= 575){
        indisponnible =1;
    }
    if (mouse_state.x > 475 && mouse_state.y > 50 && mouse_state.y < 200){
        indisponnible = 1;
    }
    if (mouse_state.x > 475 && mouse_state.y > 750 && mouse_state.y < 875){
        indisponnible =1;
    }
}

void findujeu() {
    if (joueur->vie <= 0) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(robotoRegular50, al_map_rgb(255, 255, 255), 700, 400, 0, "GAME OVER");
        al_flip_display();
        pause = 1;
        if(al_key_down(&keyboard_state, ALLEGRO_KEY_ESCAPE)) {
            finduniveau = 1;
        }
    }
    if (monstre[179].hp <= 0) {
        while(!finduniveau) {
            toutdessiner1();
            al_draw_bitmap(fond.victoire,50,0,0);
            al_flip_display();
            al_get_keyboard_state(&keyboard_state);
            if (al_key_down(&keyboard_state, ALLEGRO_KEY_ESCAPE)) {
                finduniveau = 1;
                if (lvl1){
                    lvl2=1;
                    lvl1=0;
                }
                else if (lvl2){
                    lvl2=0;
                    lvl3=1;
                }
            }
        }
    }
}

void afficherregles(){

    finduniveau =0;
    queueregles = al_create_event_queue();
    assert (queueregles);

    fond.regles = al_load_bitmap("../règles.PNG");


    al_register_event_source(queueregles, al_get_display_event_source(display));
    al_register_event_source(queueregles, al_get_keyboard_event_source());
    al_register_event_source(queueregles, al_get_mouse_event_source());


    while (!finduniveau) {
        al_wait_for_event(queueregles, &eventregles);
        al_draw_bitmap(fond.regles,0,0,0);
        al_flip_display();

        if (eventregles.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            finduniveau = 1;
        }
        if (eventregles.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (eventregles.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                finduniveau = 1;
            }
        }
    }
}
