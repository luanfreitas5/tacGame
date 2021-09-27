/**
 * @file Resources.h
 * @author Luan Mendes GonÃ§alves Freitas - 150015585
 * @brief Cabecalho da classe Resources com seus prototipos de metodo e ponteiros.
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef RESOURCES_H_
#define RESOURCES_H_

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "Messages.h"
#include "SDL_include.h"
#include "Game.h"
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @brief Classe Resources responsavel por contém os asserts do jogo.
 * Essa classe tem o proposito de evita que o jogo carregue algo repetidas vezes, usando muito processamento.
 * Os recursos criados sao mantidos em um tabela hash.
 * 
 */
class Resources {
public:

	/**
	 * @brief Get objeto imagem SDL_Texture
	 * 
	 * @param file nome do arquivo de imagem
	 * @return SDL_Texture* 
	 */
	static SDL_Texture* GetImage(string file);

	/**
	 * @brief Destroi objeto imagem SDL_Texture
	 * 
	 */
	static void ClearImages();

	/**
	 * @brief Get objeto musica Mix_Music
	 * 
	 * @param file nome do arquivo de audio
	 * @return Mix_Music* 
	 */
	static Mix_Music* GetMusic(string file);

	/**
	 * @brief Destroi objeto musica Mix_Music
	 * 
	 */
	static void ClearMusics();

	/**
	 * @brief Get objeto som Mix_Chunk
	 * 
	 * @param file nome do arquivo de audio
	 * @return Mix_Chunk* 
	 */
	static Mix_Chunk* GetSound(string file);

	/**
	 * @brief Destroi objeto som Mix_Chunk
	 * 
	 */
	static void ClearSounds();

private:

	/**
	 * @brief Tabela Hash para imagens
	 * 
	 */
	static unordered_map<string, SDL_Texture*> imageTable;

	/**
	 * @brief Tabela Hash para musicas
	 * 
	 */
	static unordered_map<string, Mix_Music*> musicTable;

	/**
	 * @brief Tabela Hash para sons
	 * 
	 */
	static unordered_map<string, Mix_Chunk*> soundTable;
};

#endif /* RESOURCES_H_ */
