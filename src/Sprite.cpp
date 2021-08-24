/**
 * @file Sprite.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Sprite
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Sprite.h"
#include "../include/Game.h"

/**
 * @brief Construtor da Classe Sprite
 * 
 */
Sprite::Sprite() {
	texture = nullptr;
	width = 0;
	height = 0;
}

/**
 * @brief Construtor da Classe Music recebendo com entrada um arquivo de imagem
 * 
 * @param file nome do arquivo de imagem de entrada.
 */
Sprite::Sprite(string file) {
	texture = nullptr;
	Open(file);
}

/**
 * @brief Destrutor da Classe Sprite
 * 
 */
Sprite::~Sprite() {

	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

/**
 * @brief Metodo para carregar o arquivo de imagem de entrada.
 * 
 * @param file nome do arquivo de imagem de entrada.
 */
void Sprite::Open(string file) {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}

	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

	int queryTexture = SDL_QueryTexture(texture, nullptr, nullptr, &width,
			&height);

	if (texture == nullptr) {
		cout << ERRO_INIT_TEXTURE << SDL_GetError() << endl;
		exit(0);

	} else if (queryTexture != 0) {
		cout << ERRO_INIT_QUERY_TEXTURE << SDL_GetError() << endl;
		exit(0);

	} else {
		SetClip(0, 0, width, height);
	}
}

/**
 * @brief Metodo para setar as dimensoes da imagem
 * 
 * @param x Posicao horizontal superior esquerda do recorte
 * @param y Posicao vertical superior esquerda do recorte
 * @param w Tamanho da largura do recorte
 * @param h Tamanho da altura do recorte
 */
void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

/**
 * @brief Metodo renderizador da textura imagem
 * 
 * @param x Posicao horizontal superior esquerda no renderizador do jogo
 * @param y Posicao horizontal superior esquerda no renderizador do jogo
 */
void Sprite::Render(int x, int y) {

	SDL_Rect sdlReact;
	sdlReact.x = x;
	sdlReact.y = y;
	sdlReact.w = GetWidth();
	sdlReact.h = GetHeight();

	int renderCopy = SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture,
			&clipRect, &sdlReact);

	if (renderCopy != 0) {
		cout << ERRO_INIT_RENDER << SDL_GetError() << endl;
		exit(0);
	}
}

/**
 * @brief Obtem o tamanho largura da imagem
 * 
 * @return int 
 */
int Sprite::GetWidth() {
	return width;
}

/**
 * @brief Obtem o tamanho altura da imagem
 * 
 * @return int 
 */
int Sprite::GetHeight() {
	return height;
}

/**
 * @brief Verifica se arquivo de imagem de entrada for carregado com sucesso.
 * 
 * @return true se o objeto existe
 * @return false se o objeto é null
 */
bool Sprite::IsOpen() {

	if (texture != nullptr) {
		return true;
	}

	return false;
}
