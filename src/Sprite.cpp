/**
 * @file Sprite.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Sprite
 * @version 0.5
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Sprite.h"
#include "../include/Game.h"
#include "../include/Resources.h"

/**
 * @brief Construtor da Classe Sprite
 *
 * @param associated objeto associado a classe GameObject
 *
 */
Sprite::Sprite(GameObject &associated) :
		Component(associated) {
	texture = nullptr;
	width = 0;
	height = 0;
}

/**
 * @brief Construtor da Classe Sprite recebendo com entrada um arquivo de imagem
 *
 * @param associated objeto associado a classe GameObject
 * @param file nome do arquivo de imagem de entrada.
 */
Sprite::Sprite(GameObject &associated, string file) :
		Component(associated) {

	texture = nullptr;
	Open(file);

	associated.box.w = width;
	associated.box.h = height;

}

/**
 * @brief Destrutor da Classe Sprite
 *
 */
Sprite::~Sprite() {
	texture = nullptr;
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

	texture = Resources::GetImage(file);

	if (texture == nullptr) {
		cout << ERRO_OPEN_FILE_IMAGE << file << " " << SDL_GetError() << endl;
		exit(0);
	}

	int queryTexture = SDL_QueryTexture(texture, nullptr, nullptr, &width,
			&height);

	if (queryTexture != 0) {
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
 * @brief Metodo renderizador da textura imagem
 *
 */
void Sprite::Render() {

	Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y);
}

/**
 * @brief Metodo renderizador da textura imagem
 * 
 * @param x posicao x na textura imagem
 * @param y posicao y na textura imagem
 */
void Sprite::Render(int x, int y) {

	SDL_Rect sdlReact;
	sdlReact.x = x;
	sdlReact.y = y;
	sdlReact.w = clipRect.w;
	sdlReact.h = clipRect.h;

	SDL_Renderer *sdlRenderer = Game::GetInstance().GetRenderer();

	int renderCopy = SDL_RenderCopy(sdlRenderer, texture, &clipRect, &sdlReact);

	if (renderCopy != 0) {
		cout << ERRO_INIT_RENDER << SDL_GetError() << endl;
		exit(0);
	}
}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para atualizar o componente.
 *
 * @param dt valor Delta Time
 */
void Sprite::Update(float dt) {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para verificar o componente.
 *
 * @param type tipo de componente
 * @return true se o tipo componente for valido
 * @return false caso contrario
 */
bool Sprite::Is(string type) {

	if (type.compare("Sprite") == 0) {
		return true;
	}
	return false;
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

/**
 * @brief Set um objeto vec2 de escala
 *
 * @param scaleX valor de escala x
 * @param scaleY valor de escala y
 */
void Sprite::SetScale(float scaleX, float scaleY) {

	if (scaleX > 0 && scaleY > 0) {
		scale.x = scaleX;
		scale.y = scaleY;
		associated.box.w = GetWidth();
		associated.box.h = GetHeight();
	}

}

/**
 * @brief Get um objeto vec2 de escala
 *
 * @return Vec2 objeto Vec2
 */
Vec2 Sprite::GetScale() {
	return scale;
}

