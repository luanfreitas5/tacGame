/**
 * @file Music.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Music
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Music.h"

/**
 * @brief Construtor da Classe Music
 * 
 */
Music::Music() {
	music = nullptr;
}

/**
 * @brief Construtor da Classe Music recebendo com entrada um arquivo de audio (.wav/.ogg)
 * 
 * @param file nome do arquivo de audio (.wav/.ogg) de entrada.
 */
Music::Music(string file) {
	Open(file);
}

/**
 * @brief Metodo para executar a musica de entrada.
 * 
 * @param times Determina quantas vezes musica é executada no jogo.
 * Se valor de entrada for -1 significa loop infinito e 0 a musica não é executada.
 */
void Music::Play(int times) {
	Mix_PlayMusic(music, times);
}

/**
 * @brief Metodo para parar a musica de entrada.
 * 
 * @param msToStop Determina o tempo em milissegundos de quando a musica irá diminuir o volume até 0,
 * ou seja, parar a musica.
 */
void Music::Stop(int msToStop) {
	Mix_FadeOutMusic(msToStop);
}

/**
 * @brief Metodo para carregar o arquivo de audio de entrada.
 * 
 * @param file nome do arquivo de audio (.wav/.ogg) de entrada.
 */
void Music::Open(string file) {
	music = Mix_LoadMUS(file.c_str());

	if (music == nullptr) {
		cout << ERRO_INIT_MUSIC << SDL_GetError() << endl;
		exit(0);
	}
}

/**
 * @brief Verifica se arquivo de audio (.wav/.ogg) de entrada for carregado com sucesso.
 * 
 * @return true se o objeto existe
 * @return false se o objeto é null
 */
bool Music::IsOpen() {

	if (music != nullptr) {
		return true;
	}
	return false;
}
