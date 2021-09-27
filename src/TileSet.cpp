/**
 * @file TileSet.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe TileSet
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/TileSet.h"

/**
 * @brief Construtor da Classe TileSet
 *
 * @param associated objeto associado a classe GameObject
 * @param tileWidth largura do Tile
 * @param tileHeight altura do Tile
 * @param file nome do arquivo
 */
TileSet::TileSet(GameObject &associated, int tileWidth, int tileHeight,
		string file) :
		tileSet(Sprite(associated, file)) {

	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;

	this->rows = tileSet.GetHeight() / this->tileHeight;
	this->columns = tileSet.GetWidth() / this->tileWidth;
}

/**
 * @brief Construtor da Classe TileSet
 *
 * @param associated objeto associado a classe GameObject
 * @param file nome do arquivo
 */
TileSet::TileSet(GameObject &associated, string file) :
		tileSet(Sprite(associated, file)) {

	this->tileWidth = 0;
	this->tileHeight = 0;

	this->rows = 0;
	this->columns = 0;
}

/**
 * @brief Metodo para renderiza um tile
 *
 * @param index valor do indice do tile
 * @param x posicao horizontal do tile
 * @param y posicao vertical do tile
 */
void TileSet::RenderTile(int index, float x, float y) {

	bool indexValido = index < rows * columns;

	if (indexValido) {
		int clipX = tileWidth * (index % columns);
		int clipY = tileHeight * (index / columns);
		tileSet.SetClip(clipX, clipY, tileWidth, tileHeight);

		tileSet.Render(x, y);
	}
}

/**
 * @brief Get o tileWidth do tile
 *
 * @return int
 */
int TileSet::GetTileWidth() {
	return tileWidth;
}

/**
 * @brief Get o tileHeight do tile
 *
 * @return int
 */
int TileSet::GetTileHeight() {
	return tileHeight;
}
