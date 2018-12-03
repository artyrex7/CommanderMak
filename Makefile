CC = g++
CFLAGS = -std=c++11
OBJ_DIR = obj
OBJS = $(OBJ_DIR)/GameClient.o $(OBJ_DIR)/GameState.o $(OBJ_DIR)/Player.o $(OBJ_DIR)/Enemy.o $(OBJ_DIR)/EnemyEasy.o $(OBJ_DIR)/EnemyMedium.o $(OBJ_DIR)/EnemyHard.o

build: main.o

main.o: main.cpp $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.cpp -o a.o

$(OBJ_DIR)/GameClient.o: GameClient.cpp GameClient.h
	$(CC) $(CFLAGS) -c GameClient.cpp -o $@

$(OBJ_DIR)/GameState.o: GameState.cpp GameState.h
	$(CC) $(CFLAGS) -c GameState.cpp -o $@

$(OBJ_DIR)/Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp -o $@

$(OBJ_DIR)/Enemy.o: Enemy.cpp Enemy.h
	$(CC) $(CFLAGS) -c EnemyHard.cpp -o $@

$(OBJ_DIR)/EnemyEasy.o: EnemyEasy.cpp EnemyEasy.h
	$(CC) $(CFLAGS) -c EnemyEasy.cpp -o $@

$(OBJ_DIR)/EnemyMedium.o: EnemyMedium.cpp EnemyMedium.h
	$(CC) $(CFLAGS) -c EnemyMedium.cpp -o $@

$(OBJ_DIR)/EnemyHard.o: EnemyHard.cpp EnemyHard.h
	$(CC) $(CFLAGS) -c EnemyHard.cpp -o $@

clean:
	rm obj/*

# %.o: %.c %.h
# 	gcc -c $< -o $@


