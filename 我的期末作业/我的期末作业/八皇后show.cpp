#include"works.h"
#include"raylib.h"
void EightQueensShow(int result[][8])
{
	int len = 1400;
	int width = 1400;
	InitWindow(len, width, "八皇后棋盘");
	SetTargetFPS(60);
	Eight_Queens();
	const int boardSize = 8;
	const int cellSize = len / boardSize;
	Color lightColor = LIGHTGRAY;
	Color darkColor = DARKBROWN;
	Color borderColor = BLACK;
	int currentsolution = 0;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int row = 0; row < boardSize; row++)
		{
			for (int col = 0; col < boardSize; col++)
			{
				int posX = col * cellSize;
				int posY = row * cellSize;
				Color currentColor = ((row + col) % 2 == 0) ? lightColor : darkColor;
				DrawRectangle(posX, posY, cellSize, cellSize, currentColor);
				DrawRectangleLines(posX, posY, cellSize, cellSize, borderColor);
			}
		}
		const char* titleText = "Eight Queens\nChessboard(8*8)";
		int textWidth = MeasureText(titleText, 30);
		DrawText(titleText, (len - textWidth) / 2 - 100, 10, 50, BLACK);
		for (int row = 0; row < boardSize; row++)
		{
			int queenCol = result[currentsolution][row];
			float centerX = queenCol * cellSize + cellSize / 2.0f;
			float centerY = row * cellSize + cellSize / 2.0f;
			float radius = cellSize * 0.35f;
			// 1. 红色主体
			DrawCircle(centerX, centerY, radius, RED);
			// 2. 深红色内圈
			DrawCircle(centerX, centerY, radius * 0.75f, MAROON);
			// 3. 白色皇冠符号 "Q"
			int textSize = radius * 1.2f;
			DrawText("Q", centerX - textSize / 4, centerY - textSize / 3, textSize, WHITE);
			// 4. 金色外框
			DrawCircleLines(centerX, centerY, radius, GOLD);
			DrawCircleLines(centerX, centerY, radius + 1, GOLD);
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			currentsolution = (currentsolution + 1) % 92;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			currentsolution = (currentsolution + 1) % 92;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			currentsolution = (currentsolution - 1) % 92;
			if (currentsolution < 0)
				currentsolution = 92 + currentsolution;
		}
		EndDrawing();
	}
}