/**
 * @file State.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe State com seus prototipos de funcoes e ponteiros.
 * @version 0.4
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef STATE_H_
#define STATE_H_

#define INCLUDE_SDL

#define FILE_OCEAN "assets/img/ocean.jpg"
#define FILE_TILE_SET "assets/img/tileset.png"
#define FILE_TILE_MAP "assets/map/tileMap.txt"
#define FILE_STAGE_STATE "assets/audio/stageState.ogg"
#define FILE_PENGUIN_FACE "assets/img/penguinface.png"
#define FILE_BOOM "assets/audio/boom.wav"

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

#include "Messages.h"
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include "Face.h"
#include "Vec2.h"
#include "TileMap.h"
#include "TileSet.h"
#include "CameraFollower.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe State responsavel genereciar os estados do
 * jogo (posicao, musica, etc.) e encerrar o jogo.
 * 
 */
class State {

public:
	/**
	 * @brief Construtor da Classe State
	 * 
	 */
	State();

	/**
	 * @brief Destrutor da Classe State
	 *
	 */
	~State();

	/**
	 * @brief Metodo para acessar o membro quitRequested
	 * 
	 * @return true 
	 * @return false 
	 */
	bool QuitRequested();

	/**
	 * @brief Metodo para pre-carregar os assets do state do jogo
	 * 
	 */
	void LoadAssets();

	/**
	 * @brief Metodo que atualiza o estado do jogo, atualizando o estado dos objetos de jogo na tela
	 * 
	 * @param dt valor Delta Time
	 */
	void Update(float dt);

	/**
	 * @brief Metodo para a renderização do estado no canto superior esquerdo do jogo.
	 * 
	 */
	void Render();

private:

	/**
	 * @brief Metodo detectar entradas de teclas do usuario e trata acoes de acordo
	 * 
	 */
	void Input();

	/**
	 * @brief Metodo para adicionar objeto de jogo (pinguim) na tela de Jogo.
	 * 
	 * @param mouseX coordenada horizontal do retangulo
	 * @param mouseY coordenada vertical do retangulo
	 */
	void AddObject(int mouseX, int mouseY);

	/**
	 * @brief Ponteiro para estado da music do jogo.
	 *
	 */
	Music music;

	/**
	 * @brief Indicador sair do jogo.
	 *
	 */
	bool quitRequested;

	/**
	 * @brief Indicador sair do jogo.
	 *
	 */
	vector<unique_ptr<GameObject>> objectArray;

};

#endif /* STATE_H_ */
