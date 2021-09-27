/**
 * @file TileSet.h
 * @author Luan Mendes GonÃ§alves Freitas - 150015585
 * @brief Cabecalho da classe TileSet com seus prototipos de metodo e ponteiros.
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef TILESET_H_
#define TILESET_H_

#include "Messages.h"
#include "GameObject.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe TileSet responsavel por armazenar os tiles
 * utilizados na renderização do TileMap
 * 
 */
class TileSet {

public:

	/**
	 * @brief Construtor da Classe TileSet
	 * 
	 * @param associated objeto associado a classe GameObject
	 * @param tileWidth largura do Tile
	 * @param tileHeight altura do Tile
	 * @param file nome do arquivo
	 */
	TileSet(GameObject &associated, int tileWidth, int tileHeight, string file);

	/**
	 * @brief Construtor da Classe TileSet
	 * 
	 * @param associated objeto associado a classe GameObject
	 * @param file nome do arquivo
	 */
	TileSet(GameObject &associated, string file);

	/**
	 * @brief Metodo para renderiza um tile
	 * 
	 * @param index valor do indice do tile
	 * @param x posicao horizontal do tile
	 * @param y posicao vertical do tile
	 */
	void RenderTile(int index, float x, float y);

	/**
	 * @brief Get o tileWidth do tile
	 * 
	 * @return int 
	 */
	int GetTileWidth();

	/**
	 * @brief Get o tileHeight do tile
	 * 
	 * @return int 
	 */
	int GetTileHeight();

private:

	/**
	 * @brief Textura do tileSet.
	 * 
	 */
	Sprite tileSet;

	/**
	 * @brief Numero de tiles na horizontal
	 * 
	 */
	int rows;

	/**
	 * @brief Numero de tiles na vertical
	 * 
	 */
	int columns;

	/**
	 * @brief Largura do tile
	 * 
	 */
	int tileWidth;

	/**
	 * @brief Altura do tile
	 * 
	 */
	int tileHeight;
};

#endif /* TILESET_H_ */
