/**
 * @file TileMap.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe TileMap com seus prototipos de metodo e ponteiros.
 * @version 0.2
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "Messages.h"
#include "Component.h"
#include "GameObject.h"
#include "TileSet.h"
#include "Camera.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Classe TileMap responsavel por mapear as posicoes dos tile
 * Herda metodos da classe Component
 * 
 */
class TileMap: public Component {

public:

	/**
	 * @brief Construtor da Classe TileMap.
	 * 
	 * @param associated objeto associado a classe GameObject
	 * @param file nome do arquivo
	 * @param tileSet Ponteiro do objeto tileSet
	 */
	TileMap(GameObject &associated, string file, TileSet *tileSet);

	/**
	 * @brief Carrega o arquivo de coordenadas tileMap
	 * 
	 * @param file nome do arquivo texto .txt
	 */
	void Load(string file);

	/**
	 * @brief Set um objeto tileSet
	 * 
	 * @param tileSet Ponteiro do objeto tileSet
	 */
	void SetTileSet(TileSet *tileSet);

	/**
	 * @brief Metodo para procurar posicao do valor do tile no map
	 * atraves das coordenadas x, y e z
	 * 
	 * @param x Coordenada horizontal.
	 * @param y Coordenada vertical.
	 * @param z Coordenada de profundidade.
	 * @return int& 
	 */
	int& At(int x, int y, int z = 0);

	/**
	 * @brief Get mapWidth do tile
	 * 
	 * @return int 
	 */
	int GetWidth();

	/**
	 * @brief Get mapHeight do tile
	 * 
	 * @return int 
	 */
	int GetHeight();

	/**
	 * @brief Get mapDepth do tile
	 * 
	 * @return int 
	 */
	int GetDepth();

	/**
	 * @brief Metodo para renderiza camada de profundidade do mapa.
	 * 
	 * @param layer 
	 * @param cameraX 
	 * @param cameraY 
	 */
	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

	/**
	 * @brief Sobreposicao do metodo da classe Component.
	 * Metodo para renderizar o componente.
	 * 
	 */
	void Render();

	/**
	 * @brief Sobreposicao do metodo da classe Component.
	 * Metodo para atualizar o componente.
	 * 
	 * @param valor Delta Time
	 */
	void Update(float dt);

	/**
	 * @brief Sobreposicao do metodo da classe Component.
	 * Metodo para verificar o componente.
	 * 
	 * @param type tipo de componente
	 * @return true se o tipo componente for valido
	 * @return false caso contrario
	 */
	bool Is(string type);

private:

	/**
	 * @brief Vetor de valores tiles
	 * 
	 */
	vector<int> tileMatrix;

	/**
	 * @brief Ponteiro do TileSet
	 * 
	 */
	TileSet *tileSet;

	/**
	 * @brief Largura do tileMap
	 * 
	 */
	int mapWidth;

	/**
	 * @brief Altura do tileMap
	 * 
	 */
	int mapHeight;

	/**
	 * @brief Profundidade do tileMap
	 * 
	 */
	int mapDepth;
};

#endif /* TILEMAP_H_ */
