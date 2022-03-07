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

    float ball_r {15};

    int ball_x_2 {screen_width/2};
    int ball_y_2 {screen_height/2};

    int vx_2 {1};
    int vy_2 {1};

    float ball_r_2 {10};




    InitWindow(screen_width, screen_height, "Bouncing Ball");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	if (ball_y <= ball_r) {
    		vy = vy*-1;
    	}

    	if (ball_x>(screen_width-ball_r)) {
    		vx *= -1;
    	}

    	if (ball_y >= (screen_height-ball_r)) {
    		vy = vy*-1;
    	}

    	if (ball_x <= ball_r) {
    		vx = vx*-1;
    	}



    	if (ball_y_2 <= ball_r_2) {
    		vy_2 = vy_2*-1;
    	}

    	if (ball_x_2>(screen_width-ball_r_2)) {
    		vx_2 *= -1;
    	}

    	if (ball_y_2 >= (screen_height-ball_r_2)) {
    		vy_2 = vy_2*-1;
    	}

    	if (ball_x_2 <= ball_r_2) {
    		vx_2 = vx_2*-1;
    	}


    	ball_x = ball_x + vx;
    	ball_y = ball_y + vy;

    	ball_x_2 = ball_x_2 + vx_2;
    	ball_y_2 = ball_y_2 + vy_2;
    	// Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircle(ball_x, ball_y, ball_r, RED);

            DrawCircle(ball_x_2, ball_y_2, ball_r_2, GREEN);


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
