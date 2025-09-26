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

clean:
	del /Q src\*.o 2> NUL || true
	del /Q $(TARGET).exe 2> NUL || true
	del /Q $(TEST_DIR)\*.exe 2> NUL || true

.PHONY: all clean run tests test