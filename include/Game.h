/**
 * @file Game.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Game com seus prototipos de metodo e ponteiros.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GAME_H_
#define GAME_H_

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#define TITLE "Luan Mendes Gonçalves Freitas - 150015585"
#define WIDTH 1024
#define HEIGHT 600

#define MIX_CHUNKSIZE 1024
#define MIX_CHANNELS 32

#include "Messages.h"
#include "SDL_include.h"
#include "State.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Game responsavel por inicializar recursos do jogo,
 * executar o loop principal do jogo e
 * liberar os recursos na memoria quando o jogo encerrar.
 * 
 */
class Game {

public:
	/**
	 * @brief Destrutor da Classe Game
	 * 
	 */
	~Game();

	/**
	 * @brief Metodo que inicia o loop do jogo,
	 * controlando a tela, recebendo dados de entrada, atualizando estados e desenhando objeto na tela.
	 * 
	 */
	void Run();

	/**
	 * @brief Obtem um objeto Renderer
	 * 
	 * @return SDL_Renderer* 
	 */
	SDL_Renderer* GetRenderer();

	/**
	 * @brief Obtem um objeto State
	 * 
	 * @return State& 
	 */
	State& GetState();

	/**
	 * @brief Obtem um objeto Instance
	 * 
	 * @return Game& 
	 */
	static Game& GetInstance();

private:

	/**
	 * @brief Construtor da Classe Game.
	 * Inicializa as funcionalidades basicas do SDL e seus auxiliares
	 * 
	 * @param title Titulo do Jogo na tela de jogo (Nome - Matricula)
	 * @param width Tamanho da largura da tela de jogo
	 * @param height Tamanho da altura da tela de jogo
	 */
	Game(string title, int width, int height);

	/**
	 * @brief Ponteiro da instancia unica do jogo.
	 *
	 */
	static Game *instance;

	/**
	 * @brief Ponteiro da janela de jogo.
	 *
	 */
	SDL_Window *window;

	/**
	 * @brief Ponteiro do desenho da tela de jogo.
	 *
	 */
	SDL_Renderer *renderer;

	/**
	 * @brief Ponteiro do estado da tela de jogo.
	 *
	 */
	State *state;

};

#endif /* GAME_H_ */
