/**
 * @file Sound.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief 
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Sound.h"
#include "../include/Resources.h"

/**
 * @brief Construtor da Classe Sound
 * Inicializa sons chunk e channel
 *
 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
 */
Sound::Sound(GameObject &associated) :
		Component(associated) {

	chunk = nullptr;
	channel = -1;

}

/**
 * @brief Construtor da Classe Sound
 * Abre o arquivo de entrada
 *
 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
 * @param file nome do arquivo de som
 */
Sound::Sound(GameObject &associated, string file) :
		Sound(associated) {

	Open(file);

}

/**
 * @brief Metodo para executar som.
 *
 * @param times Determina quantas vezes som a ser executada no jogo.
 */
void Sound::Play(int times) {

	channel = Mix_PlayChannel(-1, chunk, times - 1);
	if (channel == -1) {
		cout << ERRO_PLAY_MIX_PLAYCHANNEL << SDL_GetError() << endl;
		exit(0);
	}

}

/**
 * @brief Metodo para parar som.
 *
 */
void Sound::Stop() {

	if (chunk != nullptr) {
		if (Mix_HaltChannel(channel) != 0) {
			cout << ERRO_STOP_MIX_HALTCHANNEL << SDL_GetError() << endl;
			exit(0);
		}
	}

}

/**
 * @brief Metodo para carregar o arquivo de audio de entrada.
 *
 * @param file nome do arquivo de som
 */
void Sound::Open(string file) {

	chunk = Resources::GetSound(file);

	if (chunk == nullptr) {
		cout << ERRO_OPEN_SOUND << file << " " << SDL_GetError() << endl;
		exit(0);
	}

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void Sound::Render() {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para atualizar o componente.
 *
 * @param dt entrada de botoes do jogador
 */
void Sound::Update(float dt) {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para verificar o componente.
 *
 * @param type tipo de componente
 * @return true se o tipo componente for valido
 * @return false caso contrario
 */
bool Sound::Is(string type) {

	if (type.compare("Sound") == 0) {
		return true;
	}
	return false;

}

/**
 * @brief Metodo para verifica se o som esta sendo reproduzido.
 *
 */
bool Sound::GetIsPlaying() {

	if (Mix_Playing(channel) > 0) {
		return true;
	}

	return false;

}
