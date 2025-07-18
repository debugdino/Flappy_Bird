#include "game.h"

Rectangle PlayerSource = {0.f, 0.f, 0.f, 0.f};

void Draw() {
    BeginDrawing();
    // Beautiful sky gradient background
    ClearBackground((Color){135, 206, 235, 255}); // Sky blue
    
    DrawTexturePro(BackGR, 
        (Rectangle){0, 0,(float) BackGR.width, (float) BackGR.height}, 
        (Rectangle){0, 0, SCREEN_W, SCREEN_H}, 
        (Vector2){0, 0}, 0.0f, WHITE);
    
    // Add some ground
    DrawRectangle(0, SCREEN_H - 100, SCREEN_W, 100, (Color){34, 139, 34, 255}); // Forest green ground
    DrawRectangle(0, SCREEN_H - 20, SCREEN_W, 20, (Color){139, 69, 19, 255}); // Saddle brown dirt
    
    // Initialize PlayerSource if not already done (check if width is 0)
    if (PlayerSource.width == 0.f && PlayerSprite.width > 0) {
        PlayerSource.width = (float)PlayerSprite.width / 3.f;
        PlayerSource.height = (float)PlayerSprite.height / 2.f;
    }
    
    // Only draw if texture is loaded - scale sprite to match Player rectangle size
    if (PlayerSprite.width > 0) {
        DrawTexturePro(PlayerSprite, 
            PlayerSource, 
            (Rectangle){Player.Player.x, Player.Player.y, Player.Player.width, Player.Player.height}, 
            (Vector2){0, 0}, 
            0.0f, 
            WHITE);
    }
    else DrawRectangleRec(Player.Player, (Color){255, 215, 0, 255});

    // Enhanced obstacles with gradients
    for(int i = 0; i < MAX_OBS; i++) {
        // Shadow
        DrawRectangleRec((Rectangle){Obstackle[i].Obstackle.x + 3, Obstackle[i].Obstackle.y + 3, Obstackle[i].Obstackle.width, Obstackle[i].Obstackle.height}, Fade(BLACK, 0.2f));
        // Main obstacle
        DrawRectangleRec(Obstackle[i].Obstackle, (Color){34, 139, 34, 255}); // Forest green
        // Highlight
        DrawRectangle(Obstackle[i].Obstackle.x, Obstackle[i].Obstackle.y, 8, Obstackle[i].Obstackle.height, (Color){50, 205, 50, 255}); // Lime green highlight
        // Border
        DrawRectangleLines(Obstackle[i].Obstackle.x, Obstackle[i].Obstackle.y, Obstackle[i].Obstackle.width, Obstackle[i].Obstackle.height, (Color){0, 100, 0, 255});
    }
    
    // Enhanced score display
    std::string scoreText = "Score: " + std::to_string(Player.score);
    DrawText(scoreText.c_str(), 22, 22, 50, BLACK); // Shadow
    DrawText(scoreText.c_str(), 20, 20, 50, (Color){255, 215, 0, 255}); // Gold text
    
    // Lives display
    for(int i = 0; i < Player.life; i++) {
        DrawCircle(SCREEN_W - 50 - (i * 40), 40, 15, (Color){220, 20, 60, 255}); // Red hearts
        // DrawText("♥", SCREEN_W - 60 - (i * 40), 25, 30, WHITE);
    }

    EndDrawing();
}