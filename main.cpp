#include "raylib.h"


struct Ball
{
	int x;
	int y;
	int vx;
	int vy;
	float radius;
	Color color;
};


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    Ball ball_1 {100, 300, 2, -2, 15, RED};
    Ball ball_2 {screen_width/2, screen_height/2, 1, 1, 10, GREEN};





    InitWindow(screen_width, screen_height, "Bouncing Ball");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {


    	if (ball_1.y <= ball_1.radius) {
    		ball_1.vy = ball_1.vy*-1;
    	}

    	if (ball_1.x>(screen_width-ball_1.radius)) {
    		ball_1.vx *= -1;
    	}

    	if (ball_1.y >= (screen_height-ball_1.radius)) {
    		ball_1.vy = ball_1.vy*-1;
    	}

    	if (ball_1.x <= ball_1.radius) {
    		ball_1.vx = ball_1.vx*-1;
    	}


    	if (ball_2.y <= ball_2.radius) {
    		ball_2.vy = ball_2.vy*-1;
    	}

    	if (ball_2.x>(screen_width-ball_2.radius)) {
    		ball_2.vx *= -1;
    	}

    	if (ball_2.y >= (screen_height-ball_2.radius)) {
    		ball_2.vy = ball_2.vy*-1;
    	}

    	if (ball_2.x <= ball_2.radius) {
    		ball_2.vx = ball_2.vx*-1;
    	}


    	ball_1.x = ball_1.x + ball_1.vx;
    	ball_1.y = ball_1.y + ball_1.vy;

    	ball_2.x = ball_2.x + ball_2.vx;
    	ball_2.y = ball_2.y + ball_2.vy;


    	// Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircle(ball_1.x, ball_1.y, ball_1.radius, ball_1.color);

            DrawCircle(ball_2.x, ball_2.y, ball_2.radius, ball_2.color);


            //DrawText("Raylib is working!", 5, screen_height - 55, 50, LIGHTGRAY);

            //DrawText(TextFormat("x=%d Y=%d", ball_x, ball_y),20 , screen_height-50, 30 , BLACK);

            //DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
