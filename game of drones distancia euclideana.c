#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define maxD 11 // maxima cantidad de drones posibles

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
struct zona{
    int id;     // id de la zona
    int posX;   // coordenada X de la zona
    int posY;   // coordenada Y de la zona
    int TID;    // id del jugador que controla la zona
};

struct jugador{
    int id;           // id del jugador
    int dron[maxD];   // id de cada dron
    int posX[maxD];   // coordenada X de cada dron
    int posY[maxD];   // coordenada Y de cada dron
};


// funciones
int distancia_euclideana(int x1, int y1,int x2,int y2);


int main()
{
    int P;      // number of players in the game (2 to 4 players)
    int ID;     // ID of your player (0, 1, 2, or 3)
    int D;      // number of drones in each team (3 to 11)
    int Z;      // number of zones on the map (4 to 8)
    
    scanf("%d%d%d%d", &P, &ID, &D, &Z);  // recibimos P, ID, D, Z
    
    struct jugador jugador[P];    // creamos nuestro vector de jugadores
    struct zona zona[Z];          // creamos nuestro vector de zonas
    
    // ciclo FOR para guardar las coordenadas de cada zona
    for (int i = 0; i < Z; i++) { 
        int X;  // corresponds to the position of the center of a zone. A zone is a circle with a radius of 100 units.
        int Y;
        
        scanf("%d%d", &X, &Y);  // recibimos las coordenadas X e Y de la zona i
        
        zona[i].id = i;    // guardamos el id de la zona
        zona[i].posX = X;  // guardamos la coordenada X de la zona
        zona[i].posY = Y;  // guardamos la coordenada Y de la zona
    }

    // game loop
    while (1) {
        // ciclo FOR para guardar los id de los jugadores que controlan una zona
        for (int i = 0; i < Z; i++) {
            int TID; // ID of the team controlling the zone (0, 1, 2, or 3) or -1 if it is not controlled. The zones are given in the same order as in the initialization.
            scanf("%d", &TID);  // recibimos el id del jugador que controla la zona
            zona[i].TID = TID; // guardamos el id del jugador que controla la zona
        }
        
        // ciclo FOR anidado para guardar las coordenadas de todos los drones
        for (int i = 0; i < P; i++) { // jugador i 
            jugador[i].id = i;  // guadamos el id del jugador
            
            for (int j = 0; j < D; j++) { // dron j
                int DX; // The first D lines contain the coordinates of drones of a player with the ID 0, the following D lines those of the drones of player 1, and thus it continues until the last player.
                int DY;
                
                scanf("%d%d", &DX, &DY);   // recibimos las coordenadas X e Y del dron j del jugador i
                
                jugador[i].dron[j] = j;    // guardamos el id del dron
                jugador[i].posX[j] = DX;   // guardamos la coordenada X del dron
                jugador[i].posY[j] = DY;   // guardamos la coordenada Y del dron
            }
        }
        
        // ciclo FOR para realizar el movimiento de cada dron
        for (int i = 0; i < D; i++) { // dron i
            int id_zona = 0;     // id de la zona mas cercana  (parte en 0 en caso de que la primera zona sea la mas cercana)
            int distancia = 0;   // distancia entre el dron i y la zona j (parte en 0 por darle un valor de inicio)
            int menor = 9999;    // menor distancia hallada entre el dron y la zona (parte en 9999 para que la primera distancia siempre sea menor que esta variable)
            
            // Write an action using printf(). DON'T FORGET THE TRAILING \n
            // To debug: fprintf(stderr, "Debug messages...\n");
            // output a destination point to be reached by one of your drones. The first line corresponds to the first of your drones that you were provided as input, the next to the second, etc.
            
            // ciclo FOR para obtener el id de la zona mas cercana al dron, utilizando para ello la formula de distancia euclideana
            for(int j = 0; j < Z; j++) {  // zona j
                distancia = distancia_euclideana(jugador[ID].posX[i], jugador[ID].posY[i], zona[j].posX, zona[j].posY); // (coord X del dron , coord Y del dron, coord X de la zona, coord Y de la zona)
                
                if(distancia < menor){  // si la distancia calculada es menor a menor entonces se sobrescribe y guardamos el id de la nueva zona mas cercana
                    menor = distancia;
                    id_zona = j;
                }
            }
            
            printf("%d %d\n",zona[id_zona].posX, zona[id_zona].posY); // movemos el dron a la zona mas cercana
        }
    }

    return 0;
}

int distancia_euclideana(int x1, int y1,int x2,int y2){
    int result; 
    
    result = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); 

    return result;
}



