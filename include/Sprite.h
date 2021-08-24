/**
 * @file Sprite.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Sprite com seus prototipos de funcoes e ponteiros.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "Messages.h"
#include "SDL_include.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Game responsavel genereciar as imagens e textura do jogo.
 * 
 */
class Sprite {

public:
	/**
	 * @brief Construtor da Classe Sprite
	 * 
	 */
	Sprite();

	/**
	 * @brief Construtor da Classe Music recebendo com entrada um arquivo de imagem
	 * 
	 * @param file nome do arquivo de imagem de entrada.
	 */
	Sprite(string file);

	/**
	 * @brief Destrutor da Classe Sprite
	 * 
	 */
	~Sprite();

	/**
	 * @brief Metodo para carregar o arquivo de imagem de entrada.
	 * 
	 * @param file nome do arquivo de imagem de entrada.
	 */
	void Open(string file);

	/**
	 * @brief Metodo para setar as dimensoes da imagem
	 * 
	 * @param x Posicao horizontal superior esquerda do recorte
	 * @param y Posicao vertical superior esquerda do recorte
	 * @param w Tamanho da largura do recorte
	 * @param h Tamanho da altura do recorte
	 */
	void SetClip(int x, int y, int w, int h);

	/**
	 * @brief Metodo renderizador da textura imagem
	 * 
	 * @param x Posicao horizontal superior esquerda no renderizador do jogo
	 * @param y Posicao horizontal superior esquerda no renderizador do jogo
	 */
	void Render(int x, int y);

	/**
	 * @brief Obtem o tamanho largura da imagem
	 * 
	 * @return int 
	 */
	int GetWidth();

	/**
	 * @brief Obtem o tamanho altura da imagem
	 * 
	 * @return int 
	 */
	int GetHeight();

	/**
	 * @brief Verifica se arquivo de imagem de entrada for carregado com sucesso.
	 * 
	 * @return true se o objeto existe
	 * @return false se o objeto é null
	 */
	bool IsOpen();

private:
	/**
	 * @brief Ponteiro da textura da imagem do jogo.
	 *
	 */
	SDL_Texture *texture;

	/**
	 * @brief Tamanho da largura da imagem do jogo.
	 *
	 */
	int width;

	/**
	 * @brief Tamanho da altura da imagem do jogo.
	 *
	 */
	int height;

	/**
	 * @brief Ponteiro da retangulo de textura recortada
	 *
	 */
	SDL_Rect clipRect;

};

#endif /* SPRITE_H_ */
