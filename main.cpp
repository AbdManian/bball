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


void apply_collision(Ball& ball_1, int screen_width, int screen_height)
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

}

void ball_movement(Ball& ball_1)
{
	ball_1.x = ball_1.x + ball_1.vx;
	ball_1.y = ball_1.y + ball_1.vy;
}

void draw_ball(const Ball& ball_1)
{
    DrawCircle(ball_1.x, ball_1.y, ball_1.radius, ball_1.color);
}


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    Ball ball_1 {100, 300, 2, -2, 40, RED};
    Ball ball_2 {screen_width/2, screen_height/2, 3, 3, 10, GREEN};

    InitWindow(screen_width, screen_height, "Bouncing Ball");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	apply_collision(ball_1, screen_width, screen_height);
    	apply_collision(ball_2, screen_width, screen_height);


    	ball_movement(ball_1);
    	ball_movement(ball_2);


    	// Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_ball(ball_1);
            draw_ball(ball_2);

            DrawText(TextFormat("Ball1 X=%d Y=%d", ball_1.x, ball_1.y),20 , screen_height-50, 40 , BLACK);

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
