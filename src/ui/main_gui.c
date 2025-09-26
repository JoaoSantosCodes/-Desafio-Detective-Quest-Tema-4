#include <raylib.h>
#include <stdbool.h>

// Helper para desenhar texto com Font customizado
static inline void DrawTextUI(Font font, const char *text, int x, int y, int size, Color color) {
    DrawTextEx(font, (Vector2){(float)x, (float)y}, (float)size, 1.0f, color);
}

int main(void) {
    const int screenWidth = 960;
    const int screenHeight = 600;
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Detective Quest — GUI");

    SetTargetFPS(60);

    // Carregar fonte Inter se disponível, senão usar default
    bool interLoaded = false;
    Font uiFont = GetFontDefault();
    if (FileExists("assets/fonts/Inter-Regular.ttf")) {
        uiFont = LoadFontEx("assets/fonts/Inter-Regular.ttf", 20, NULL, 0);
        interLoaded = true;
    }

    // Tema escuro básico
    Color bg = (Color){15, 17, 21, 255};      // #0F1115
    Color surface = (Color){21, 25, 34, 255}; // #151922
    Color text = (Color){230, 232, 238, 255}; // #E6E8EE
    Color accent = (Color){59, 130, 246, 255}; // #3B82F6

    // Estado inicial: Menu
    int currentScreen = 0; // 0 Menu, 1 Salas, 2 Pistas, 3 Suspeitos, 4 Ajuda

    while (!WindowShouldClose()) {
        // Input básico (atalhos do menu)
        if (IsKeyPressed(KEY_S)) currentScreen = 1;      // Salas
        if (IsKeyPressed(KEY_P)) currentScreen = 2;      // Pistas
        if (IsKeyPressed(KEY_U)) currentScreen = 3;      // Suspeitos
        if (IsKeyPressed(KEY_H) || IsKeyPressed(KEY_F1)) currentScreen = 4; // Ajuda

        BeginDrawing();
            ClearBackground(bg);

            // Header
            DrawRectangle(0, 0, screenWidth, 56, surface);
            DrawTextUI(uiFont, "Detective Quest", 16, 16, 24, text);

            // Navegação atual
            const char* tabs[5] = {"Menu", "Salas", "Pistas", "Suspeitos", "Ajuda"};
            for (int i = 0; i < 5; i++) {
                int x = 160 + i * 100;
                Color c = (i == currentScreen) ? accent : text;
                DrawTextUI(uiFont, tabs[i], x, 20, 20, c);
            }

            // Conteúdo por tela (placeholder)
            if (currentScreen == 0) {
                DrawTextUI(uiFont, "Pressione S: Salas | P: Pistas | U: Suspeitos | H/F1: Ajuda", 16, 100, 20, text);
            } else if (currentScreen == 1) {
                DrawTextUI(uiFont, "Tela de Salas — árvore e navegação (e/d/s/r)", 16, 100, 20, text);
            } else if (currentScreen == 2) {
                DrawTextUI(uiFont, "Tela de Pistas — lista, busca, adicionar/atualizar", 16, 100, 20, text);
            } else if (currentScreen == 3) {
                DrawTextUI(uiFont, "Tela de Suspeitos — listagem, buscar, adicionar/atualizar, remover", 16, 100, 20, text);
            } else if (currentScreen == 4) {
                DrawTextUI(uiFont, "Ajuda — atalhos e instruções", 16, 100, 20, text);
            }
        EndDrawing();
    }

    if (interLoaded) UnloadFont(uiFont);
    CloseWindow();
    return 0;
}