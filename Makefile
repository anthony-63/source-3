OUT = bin\a_game_thing.exe
SRC = src/*.c

$(OUT): $(SRC)
	gcc $(SRC) -o $(OUT) -lSDL2 -lSDL2_ttf
run: $(OUT)
	.\$(OUT)
	del .\$(OUT)