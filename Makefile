# Usar MinGW (GCC) no Windows
CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -O2
INCLUDES=-Iinclude
SRC = src/main.c src/salas.c src/pistas.c src/suspeitos.c
OBJ=$(SRC:.c=.o)
TARGET=detective-quest

# Testes
TEST_DIR=tests
TESTS=$(TEST_DIR)/test_pistas.exe $(TEST_DIR)/test_suspeitos.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Build de testes
$(TEST_DIR)/test_pistas.exe: $(TEST_DIR)/test_pistas.c include/pistas.h src/pistas.c
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_DIR)/test_pistas.c src/pistas.c -o $(TEST_DIR)/test_pistas.exe

$(TEST_DIR)/test_suspeitos.exe: $(TEST_DIR)/test_suspeitos.c include/suspeitos.h src/suspeitos.c
	$(CC) $(CFLAGS) $(INCLUDES) $(TEST_DIR)/test_suspeitos.c src/suspeitos.c -o $(TEST_DIR)/test_suspeitos.exe

# Alvo para compilar todos os testes
 tests: $(TESTS)

# Alvo para rodar todos os testes
 test: tests
	@echo Executando testes...
	@$(TEST_DIR)/test_pistas.exe
	@$(TEST_DIR)/test_suspeitos.exe

# ---------------- GUI (Raylib) ----------------
GUI_DIR=src/ui
GUI_SRC=$(GUI_DIR)/main_gui.c
GUI_BIN=build/detective-quest-gui.exe
RAYLIB_LIBS=-lraylib -lopengl32 -lgdi32 -lwinmm
# Versão e pasta de distribuição da GUI
GUI_VERSION=1.1.0
DIST_DIR=dist/detective-quest-gui-v$(GUI_VERSION)

# Compila o binário GUI (requer Raylib instalado)
 gui: $(GUI_BIN)

$(GUI_BIN): $(GUI_SRC)
	@if not exist build mkdir build
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(RAYLIB_LIBS)

# Executa o binário GUI
 run-gui: $(GUI_BIN)
	./$(GUI_BIN)

# Empacota binário + assets em um .zip versionado em dist/
 package-gui: $(GUI_BIN)
	@if not exist dist mkdir dist
	@if exist $(DIST_DIR) rmdir /S /Q $(DIST_DIR)
	@mkdir $(DIST_DIR)
	@mkdir $(DIST_DIR)\assets
	@if exist assets\fonts mkdir $(DIST_DIR)\assets\fonts
	@if exist assets\fonts copy assets\fonts\* $(DIST_DIR)\assets\fonts\ > NUL
	@if exist assets\svg mkdir $(DIST_DIR)\assets\svg
	@if exist assets\svg copy assets\svg\*.svg $(DIST_DIR)\assets\svg\ > NUL
	@copy $(GUI_BIN) $(DIST_DIR)\ > NUL
	@powershell -NoProfile -Command "Compress-Archive -Path '$(DIST_DIR)\*' -DestinationPath 'dist\detective-quest-gui-v$(GUI_VERSION).zip' -Force"

clean:
	del /Q src\*.o 2> NUL || true
	del /Q $(TARGET).exe 2> NUL || true
	del /Q $(TEST_DIR)\*.exe 2> NUL || true
	del /Q build\*.exe 2> NUL || true

.PHONY: all clean run tests test gui run-gui package-gui