// Écrit une structure pour stocker une chaîne et un nombre
// Ecrit une fonction qui prend un élément de cette structure en argument et imprime la chaîne et le nombre
// Écrire un programme utilisant une structure qui effectuera la géométrie usuelle du plan : calcul du périmètre et de l'aire,
// calcul d'angle_degs, en utilisant des formes usuelles telles que des lignes, des carrés, des rectangles, des cercles, des triangles dans un cartésien
// système de coordonnées. (n'oubliez pas de vérifier que ces formes sont ce qu'elles sont censées être)
// exemple : isRectangle_deg(rectangle_deg rect), isSquare…)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define PI 3.14159265358979224


float carre(int x){
    return x*x;
}

float racine(int x){
    return pow(x,0.5);
}

void error(){
    printf("Calcul impossible");
}

typedef struct point{
    int x;
    int y;
}point;


typedef struct ligne{
    point a;
    point b; 
}ligne;

typedef struct quadrilatere{
    ligne A;
    ligne B;
    ligne C;
    ligne D;
}quadrilatere;


bool isNotsuperpose(point a, point b){
    if(a.x == b.x && a.y == b.y){
        return false;
    }
return true;
}

bool isNotAligne(point a, point b,point c){
    if(a.x == b.x && a.x ==c.x){
        return false;
    }
return true;
}
    
float longueur_ligne(ligne ligne1){
    float longueur;
    longueur = racine(carre(ligne1.b.x-ligne1.a.x)+carre(ligne1.b.y-ligne1.a.y));
    return longueur;
}

float angle_deg(point a,point b, point c){
    float angle;
    ligne A = {a,b};
    ligne B = {b,c};
    ligne C = {c,a};
    angle = carre(longueur_ligne(B))-carre(longueur_ligne(A))-carre(longueur_ligne(C))/(-2*longueur_ligne(A)*longueur_ligne(C));
    printf("long a : %f / long b : %f / long c : %f\n",longueur_ligne(A),longueur_ligne(B),longueur_ligne(C));
    return acos(angle)*360/(PI);  
} 

bool is_quadrilatere(quadrilatere quadri1){
    if ((isNotAligne(quadri1.A.a,quadri1.B.a,quadri1.C.a)&& 
        isNotAligne(quadri1.B.a,quadri1.C.a,quadri1.D.a)&&
        isNotAligne(quadri1.C.a,quadri1.D.a,quadri1.A.a)&&
        isNotAligne(quadri1.D.a,quadri1.A.a,quadri1.B.a))&&
        isNotsuperpose(quadri1.A.a,quadri1.B.a)&&
        isNotsuperpose(quadri1.B.a,quadri1.C.a)&&
        isNotsuperpose(quadri1.C.a,quadri1.D.a)){
           return true; 
        }
        else{            
            return false;   
        }      
 }
 
bool is_carre(quadrilatere quadri1){
    if ((longueur_ligne(quadri1.A)==longueur_ligne(quadri1.B))&&
       (longueur_ligne(quadri1.B)==longueur_ligne(quadri1.C))&&
       (longueur_ligne(quadri1.C)==longueur_ligne(quadri1.D))&&
       is_quadrilatere(quadri1)){
        return true;
       }
    else{
        return false;  
    }
}

bool is_rectangle(quadrilatere quadri1){
    if(angle_deg(quadri1.A.a,quadri1.B.a,quadri1.C.a)==90 && is_quadrilatere(quadri1))
    {
        return true;
    }
    else{
        return false;  
    }
}

int perimetre_quadrilatere(quadrilatere quadri1){
    int perimetre;
    if(is_quadrilatere(quadri1)){
        perimetre = longueur_ligne(quadri1.A)+longueur_ligne(quadri1.B)+longueur_ligne(quadri1.C)+longueur_ligne(quadri1.D);
        return perimetre;  
    }
    else{
        return -1;
    }
}


int main(){

//POINT POUR FAIRE UN CARRE
point a ={2,7};
point b ={1,6};
point c ={2,5};
point d ={3,6};
printf("\033[0;31m""------------coordonnées points rentrez------------\033[0;37m\n");
printf("a(%d,%d) b(%d,%d) c(%d,%d) d(%d,%d)\n",a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y);

//LONGUEUR ab
printf("\033[0;31m""------------calcul longueur ab ------------\033[0;37m\n");
ligne ligne1 ={a,b};
printf("longueur = %f\n",longueur_ligne(ligne1));

//angle_deg abc
printf("\033[0;31m""------------calcul angle abc ------------\033[0;37m\n");
printf("angle_deg : %.1f°\n",angle_deg(a,b,c));


//QUADRILATERRE abcd
printf("\033[0;31m""------------calcul peri ------------\033[0;37m\n");
ligne A = {a,b}, B = {b,c},C = {c,d},D = {d,a};
quadrilatere quadri1 = {A,B,C,D};
printf("Perimetre = %d \n",perimetre_quadrilatere(quadri1));

//isQuadrilatere
printf("\033[0;31m""------------test abcd quadrilatere------------Red\033[0;37m\n");
if(is_quadrilatere(quadri1)){
    printf("c'est un quadrilatere\n");
}
else{
    printf("Ce n'est pas un quadrilatere\n");
}

//isCarre
printf("\033[0;31m""------------test abcd carre------------Red\033[0;37m\n");
if(is_carre(quadri1)){
    printf("c'est un carré\n");
}
else{
    printf("Ce n'est pas un carre\n");
}
//isRectangle
printf("\033[0;31m""------------test abcd rectangle------------\033[0;37m\n");
if(is_rectangle(quadri1)){
    printf("c'est un rectangle\n");
}
else{
    printf("Ce n'est pas un rectangle\n");
}
}