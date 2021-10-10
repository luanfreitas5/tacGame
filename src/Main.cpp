/**
 * @file Main.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo de inicializacao do programa/jogo;
 * @version 0.3
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/Game.h"
#include "../include/Resources.h"
#include "../include/Camera.h"

Game *Game::instance = nullptr;
unordered_map<string, SDL_Texture*> Resources::imageTable = { { "", nullptr } };
unordered_map<string, Mix_Music*> Resources::musicTable = { { "", nullptr } };
unordered_map<string, Mix_Chunk*> Resources::soundTable = { { "", nullptr } };
GameObject *Camera::focus = nullptr;
Vec2 Camera::pos = Vec2();
Vec2 Camera::speed = Vec2(SPEED_X, SPEED_Y);

/**
 * @brief Metodo de inicializacao do programa/jogo
 * 
 * @param argc Uma contagem de argumentos inteiros dos argumentos da linha de comando
 * @param argv Um vetor de argumento dos argumentos da linha de comando
 * @return int 0 encerramento com sucesso
 */
int main(int argc, char **argv) {

	Game game = Game::GetInstance();
	game.Run();
	cout << "Fim" << endl;

	return 0;
}
