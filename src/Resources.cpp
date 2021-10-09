/**
 * @file Resources.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Resources
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Resources.h"

/**
 * @brief Get objeto imagem SDL_Texture
 *
 * @param file nome do arquivo de imagem
 * @return SDL_Texture*
 */
SDL_Texture* Resources::GetImage(string file) {

	unordered_map<string, SDL_Texture*>::const_iterator imageIterator;

	/** Procura objeto imagem na tabela hash */
	imageIterator = imageTable.find(file);

	/** Se encontrou objeto imagem retorna, se nao cria */
	if (imageIterator != imageTable.end()) {
		return imageIterator->second;

	} else {
		SDL_Renderer *sdlRenderer = Game::GetInstance().GetRenderer();
		SDL_Texture *sdlTexture = IMG_LoadTexture(sdlRenderer, file.c_str());

		if (sdlTexture == nullptr) {
			cout << ERRO_OPEN_FILE_IMAGE << file << " " << SDL_GetError()
					<< endl;
			exit(0);
		}

		imageTable.insert( { file, sdlTexture });
		return sdlTexture;
	}

}

/**
 * @brief Destroi objeto imagem SDL_Texture
 *
 */
void Resources::ClearImages() {

	unordered_map<string, SDL_Texture*>::const_iterator imageIterator;

	imageIterator = imageTable.begin();

	while (imageIterator != imageTable.end()) {
		SDL_DestroyTexture(imageIterator->second);
		imageIterator = imageTable.erase(imageIterator);
	}
	imageTable.clear();

}

/**
 * @brief Get objeto musica Mix_Music
 *
 * @param file nome do arquivo de audio
 * @return Mix_Music*
 */
Mix_Music* Resources::GetMusic(string file) {

	unordered_map<string, Mix_Music*>::const_iterator musicIterator;

	/** Procura objeto musica na tabela hash */
	musicIterator = musicTable.find(file);

	/** Se encontrou objeto musica retorna, se nao cria */
	if (musicIterator != musicTable.end()) {
		return musicIterator->second;

	} else {
		Mix_Music *mixMusic = Mix_LoadMUS(file.c_str());

		if (mixMusic == nullptr) {
			cout << ERRO_OPEN_FILE_MUSIC << file << " " << SDL_GetError()
					<< endl;
			exit(0);
		}

		musicTable.insert( { file, mixMusic });
		return mixMusic;
	}

}

/**
 * @brief Destroi objeto musica Mix_Music
 *
 */
void Resources::ClearMusics() {

	unordered_map<string, Mix_Music*>::const_iterator musicIterator;

	musicIterator = musicTable.begin();

	while (musicIterator != musicTable.end()) {
		Mix_FreeMusic(musicIterator->second);
		musicIterator = musicTable.erase(musicIterator);
	}
	musicTable.clear();

}

/**
 * @brief Get objeto som Mix_Chunk
 *
 * @param file nome do arquivo de audio
 * @return Mix_Chunk*
 */
Mix_Chunk* Resources::GetSound(string file) {

	unordered_map<string, Mix_Chunk*>::const_iterator soundIterator;

	/** Procura objeto som na tabela hash */
	soundIterator = soundTable.find(file);

	/** Se encontrou objeto som retorna, se nao cria */
	if (soundIterator != soundTable.end()) {
		return soundIterator->second;

	} else {
		Mix_Chunk *mixChunk = Mix_LoadWAV(file.c_str());

		if (mixChunk == nullptr) {
			cout << ERRO_OPEN_FILE_SOUND << file << " " << SDL_GetError()
					<< endl;
			exit(0);
		}

		soundTable.insert( { file, mixChunk });
		return mixChunk;
	}

}

/**
 * @brief Destroi objeto som Mix_Chunk
 *
 */
void Resources::ClearSounds() {

	unordered_map<string, Mix_Chunk*>::const_iterator soundIterator;

	soundIterator = soundTable.begin();

	while (soundIterator != soundTable.end()) {
		Mix_FreeChunk(soundIterator->second);
		soundIterator = soundTable.erase(soundIterator);
	}
	soundTable.clear();

}
