
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>


struct Punto {
	int x;
	int y;
	Color c;
	Texture2D immagine;
	int dir;
};

struct android{

    int x;
    int y;
    Texture2D immagine2;

};




// Initialization
//--------------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;
struct Punto punti[100];
struct android punti2[1];
int numeroPunti = 0;



void inizializzaPunti() {
	int i;
	numeroPunti=10;
	for (i=0; i<numeroPunti; i++) {
        punti[i].x = rand()%screenWidth;
		punti[i].y = rand()%screenHeight;
		punti[i].c.r = rand()%255;
		punti[i].c.g = rand()%255;
		punti[i].c.b = rand()%255;
		punti[i].c.a = 120;
		punti[i].dir = 1;

	}

}

void inizializzaAndroide(){

    int i=0;
    punti2[0].x=9;
    punti2[0].y = 374;
    punti2[0].immagine2 = LoadTexture("resources/android.png");
    printf ("%d",punti2[0]);



}



void aggiornaPunti() {
	int i;
	int b;
	for (i=0; i<numeroPunti; i++) {
		if (punti[i].x==screenWidth-40) {
			punti[i].dir*=-1;
		}
		if (punti[i].x==0) {
			punti[i].dir*=-1;
		}

		punti[i].x+=punti[i].dir;
	}
}


void disegnaPunti() {
	int i;
	for (i=0; i<numeroPunti; i++) {
		DrawTexture(punti[i].immagine, punti[i].x, punti[i].y, punti[i].c);
	}
}

void disegnaAndroid(){

    DrawTexture(punti2[0].immagine2, punti2[0].x, punti2[0].y, punti[0].c);
}


void aggiungiPunto() {
	if (numeroPunti<99) {
		punti[numeroPunti].x = rand()%screenWidth;
		punti[numeroPunti].y = rand()%screenHeight;
		punti[numeroPunti].c.r = rand()%255;
		punti[numeroPunti].c.g = rand()%255;
		punti[numeroPunti].c.b = rand()%255;
		punti[numeroPunti].c.a = 120;
		punti[numeroPunti].dir = 1;
		punti[numeroPunti].immagine = LoadTexture("resources/apple.png");
		numeroPunti++;
	}
}

void togliPunto() {
	if (numeroPunti>0) {
		numeroPunti--;
	}
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{

    InitWindow(screenWidth, screenHeight, "Eat the apples! (G start/add)");

	inizializzaPunti();
	inizializzaAndroide();
	int i;
	int score=0;
    int g=0;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

	// Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
		aggiornaPunti();

		if (IsKeyPressed(KEY_G)) {

			aggiungiPunto();
		}


		if(IsKeyPressed(KEY_D))
        {
             punti2[0].x = punti2[0].x+40;

            disegnaAndroid();
        }
        if(IsKeyPressed(KEY_A)){

            punti2[0].x = punti2[0].x-40;
            disegnaAndroid();
        }

        if(IsKeyPressed(KEY_W)){


            punti2[0].y = punti2[0].y-40;
            disegnaAndroid();

        }
        if(IsKeyPressed(KEY_S)){
             punti2[0].y = punti2[0].y+40;
            disegnaAndroid();


        }


        for(i=0;i<100;i++){

        if(punti2[0].x == punti[i].x || punti2[0].y == punti[i].y){

            punti[i].x = NULL;
           punti[i].y = NULL;

           punti[i].immagine = LoadTexture("resources/paper-texture.png");
            disegnaAndroid();
            numeroPunti--;
            score++;


        }
        }





		//----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText(TextFormat("Score %d",score),screenWidth - 150, 50, 20, BLACK);

            disegnaPunti();
            disegnaAndroid();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



