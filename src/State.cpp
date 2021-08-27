/**
 * @file State.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe State
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/State.h"

/**
 * @brief Construtor da Classe Sprite
 *
 */
State::State() :
		bg(), music() {

	quitRequested = false;
}

/**
 * @brief Metodo para pre-carregar os assets do state do jogo
 * 
 */
void State::LoadAssets() {
	bg.Open("assets/img/ocean.jpg");
	music.Open("assets/audio/stageState.ogg");
	music.Play();
}

/**
 * @brief Metodo que atualiza o estado do jogo, de acordo com as entradas do jogador
 * 
 * @param dt entrada de botoes do jogador
 */
void State::Update(float dt) {
	if (SDL_QuitRequested() != false) {
		quitRequested = true;
	}
}

/**
 * @brief Metodo para a renderização do estado do jogo.
 * 
 */
void State::Render() {
	bg.Render(0, 0);
}

/**
 * @brief Metodo para acessar o membro quitRequested
 * 
 * @return true 
 * @return false 
 */
bool State::QuitRequested() {

	return quitRequested;
}
