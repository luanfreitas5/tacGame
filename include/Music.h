/**
 * @file Music.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Music com seus prototipos de metodos e ponteiros.
 * @version 0.3
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#define INCLUDE_SDL_MIXER

#include "Messages.h"
#include "SDL_include.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Music responsavel genereciar as musicas do jogo.
 * 
 */
class Music {

public:
	/**
	 * @brief Construtor da Classe Music
	 * 
	 */
	Music();

	/**
	 * @brief Construtor da Classe Music recebendo com entrada um arquivo de audio (.wav/.ogg)
	 * 
	 * @param file nome do arquivo de audio (.wav/.ogg) de entrada.
	 */
	Music(string file);

	/**
	 * @brief Destrutor da Classe Music
	 *
	 */
	~Music();

	/**
	 * @brief Metodo para executar a musica de entrada.
	 * 
	 * @param times Determina quantas vezes musica é executada no jogo.
	 * Se valor de entrada for -1 significa loop infinito e 0 a musica não é executada.
	 */
	void Play(int times = -1);

	/**
	 * @brief Metodo para parar a musica de entrada.
	 * 
	 * @param msToStop Determina o tempo em milissegundos de quando a musica irá diminuir o volume até 0,
	 * ou seja, parar a musica.
	 */
	void Stop(int msToStop = 1500);

	/**
	 * @brief Metodo para carregar o arquivo de audio de entrada.
	 * 
	 * @param file nome do arquivo de audio (.wav/.ogg) de entrada.
	 */
	void Open(string file);

	/**
	 * @brief Verifica se arquivo de audio (.wav/.ogg) de entrada for carregado com sucesso.
	 * 
	 * @return true se o objeto existe
	 * @return false se o objeto é null
	 */
	bool IsOpen();

private:
	/**
	 * @brief Ponteiro da musica do jogo.
	 *
	 */
	Mix_Music *music;

};

#endif /* MUSIC_H_ */
