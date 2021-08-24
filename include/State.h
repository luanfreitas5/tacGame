/**
 * @file State.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe State com seus prototipos de funcoes e ponteiros.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef STATE_H_
#define STATE_H_

#define INCLUDE_SDL

#include "Messages.h"
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Game responsavel genereciar os estados do jogo (posicao, musica, etc.) e encerrar o jogo.
 * 
 */
class State {

public:
	/**
	 * @brief Construtor da Classe Sprite
	 * 
	 */
	State();

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
	 * @brief Metodo que atualiza o estado do jogo, de acordo com as entradas do jogador
	 * 
	 * @param dt entrada de botoes do jogador
	 */
	void Update(float dt);

	/**
	 * @brief Metodo para a renderização do estado do jogo.
	 * 
	 */
	void Render();

private:
	/**
	 * @brief Ponteiro para estado da imagem do jogo.
	 *
	 */
	Sprite bg;

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

};

#endif /* STATE_H_ */
