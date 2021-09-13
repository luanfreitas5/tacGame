/**
 * @file Sound.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Sound com seus prototipos de metodo e ponteiros.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SOUND_H_
#define SOUND_H_

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "Messages.h"
#include "SDL_include.h"
#include "Component.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Sound responsavel por genereciar os sons do jogo.
 * 
 */
class Sound: public Component {

public:

	/**
	 * @brief Construtor da Classe Sound
	 * Inicializa sons chunk e channel
	 * 
	 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
	 */
	Sound(GameObject &associated);

	/**
	 * @brief Construtor da Classe Sound
	 * Abre o arquivo de entrada
	 * 
	 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
	 * @param file nome do arquivo de entrada
	 */
	Sound(GameObject &associated, string file);

	/**
	 * @brief Destrutor da Classe Sound
	 *
	 */
	~Sound();

	/**
	 * @brief Metodo para executar som.
	 * 
	 * @param times Determina quantas vezes som é executada no jogo.
	 */
	void Play(int times = 1);

	/**
	 * @brief Metodo para parar som.
	 * 
	 */
	void Stop();

	/**
	 * @brief Metodo para carregar o arquivo de audio de entrada.
	 * 
	 * @param file 
	 */
	void Open(string file);

	/**
	 * @brief Verifica se arquivo de audio (.wav/.ogg) de entrada for carregado com sucesso.
	 * 
	 * @return true se o objeto existe
	 * @return false se o objeto é null
	 */
	bool IsOpen();

	/**
	 * @brief Sobreposicao do metodo da classe Component.
	 * Metodo para atualizar o componente.
	 *
	 * @param dt entrada de botoes do jogador
	 */
	void Update(float dt);

	/**
	 * @brief Sobreposicao do metodo da classe Component.
	 * Metodo para renderizar o componente.
	 *
	 */
	void Render();

	/**
	 * @brief Sobreposicao do metodo da classe Component.
	 * Metodo para verificar o componente.
	 *
	 * @param type tipo de componente
	 * @return true se o tipo componente for valido
	 * @return false caso contrario
	 */
	bool Is(string type);

	/**
	 * @brief Metodo para verifica se o som esta sendo reproduzido.
	 *
	 */
	bool GetIsPlaying();

private:

	/**
	 * @brief Ponteiro de Mix_Chunk para reproduzir o som
	 * 
	 */
	Mix_Chunk *chunk;

	/**
	 * @brief Canal do som.
	 * 
	 */
	int channel;
};

#endif /* SOUND_H_ */
