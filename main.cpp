#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    int ball_x {100};
    int ball_y {300};

    int vx {2};
    int vy {-2};

    InitWindow(screen_width, screen_height, "Bouncing Ball");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	if (ball_y <= 0) {
    		vy = vy*-1;
    	}

    	if (ball_x>screen_width) {
    		vx *= -1;
    	}

    	if (ball_y >= screen_height) {
    		vy = vy*-1;
    	}

    	if (ball_x <= 0) {
    		vx = vx*-1;
    	}


    	ball_x = ball_x + vx;
    	ball_y = ball_y + vy;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircle(ball_x, ball_y, 15, RED);

            //DrawText("Raylib is working!", 5, screen_height - 55, 50, LIGHTGRAY);

            DrawText(TextFormat("x=%d Y=%d", ball_x, ball_y),20 , screen_height-50, 30 , BLACK);

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
