# Build e Execução

Guia rápido para compilar e executar no Windows (PowerShell) com GCC/MinGW.

## Compilar executável
```
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude src/main.c src/salas.c src/pistas.c src/suspeitos.c -o detective-quest.exe
```

## Executar
- Menu principal (sem argumentos):
```
./detective-quest.exe
```
- Ajuda rápida:
```
./detective-quest.exe -h
./detective-quest.exe --help
```
- Salas (interativo):
```
./detective-quest.exe -salas
```
- Salas (demo):
```
./detective-quest.exe -salas-demo eed
# Alias compatível:
./detective-quest.exe -demo eed
```
- Pistas:
```
./detective-quest.exe -pistas-demo
./detective-quest.exe -pistas
```
- Suspeitos:
```
./detective-quest.exe -suspeitos-demo
./detective-quest.exe -suspeitos
```

## Testes automatizados (sem make)
```
# Pistas
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude tests/test_pistas.c src/pistas.c -o tests/test_pistas.exe
./tests/test_pistas.exe

# Suspeitos
gcc -Wall -Wextra -Wpedantic -std=c11 -Iinclude tests/test_suspeitos.c src/suspeitos.c -o tests/test_suspeitos.exe
./tests/test_suspeitos.exe
```