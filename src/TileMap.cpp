/**
 * @file TileMap.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe TileMap
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/TileMap.h"

/**
 * @brief Construtor da Classe TileMap.
 *
 * @param associated objeto associado a classe GameObject
 * @param file nome do arquivo
 * @param tileSet Ponteiro do objeto tileSet
 */
TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) :
		Component(associated) {

	Load(file);
	this->tileSet = tileSet;
}

/**
 * @brief Carrega o arquivo de coordenadas tileMap
 *
 * @param file nome do arquivo texto .txt
 */
void TileMap::Load(string file) {

	ifstream arquivo(file, ifstream::in);
	if (!arquivo.is_open()) {
		cout << ERRO_LOAD_FILE << file << " " << SDL_GetError() << endl;
		exit(0);
	}

	string linha;
	int i, posicao = 0, mapValor = 0;
	int tamanhoLinha = 0, tileValor = 0;

	getline(arquivo, linha);
	tamanhoLinha = linha.size();

	for (int i = 0; i < tamanhoLinha; i++) {
		if (linha.at(i) == ',') {
			switch (posicao) {
			case 0:
				mapWidth = mapValor;
				break;
			case 1:
				mapHeight = mapValor;
				break;
			case 2:
				mapDepth = mapValor;
				break;
			}
			mapValor = 0;
			posicao++;
		} else {
			mapValor *= 10;
			mapValor += linha.at(i) - '0';
		}
	}

	while (getline(arquivo, linha)) {
		int tamanhoLinha = linha.size();

		for (i = 0; i < tamanhoLinha; i++) {

			if (linha.at(i) >= '0' && linha.at(i) <= '9') {
				tileValor *= 10;
				tileValor += linha.at(i) - '0';

			} else if (linha.at(i) == ',') {
				tileMatrix.push_back(tileValor - 1);
				tileValor = 0;

			} else {
				tileValor = 0;
			}
		}
	}

	arquivo.close();
}

/**
 * @brief Set um objeto tileSet
 *
 * @param tileSet Ponteiro do objeto tileSet
 */
void TileMap::SetTileSet(TileSet *tileSet) {
	this->tileSet = tileSet;
}

/**
 * @brief Metodo para procurar posicao do valor do tile no map
 * atraves das coordenadas x, y e z
 *
 * @param x Coordenada horizontal.
 * @param y Coordenada vertical.
 * @param z Coordenada de profundidade.
 * @return int&
 */
int& TileMap::At(int x, int y, int z) {
	return tileMatrix.at(x + (y * mapWidth) + (z * mapWidth * mapHeight));
}

/**
 * @brief Get mapWidth do tile
 *
 * @return int
 */
int TileMap::GetWidth() {
	return mapWidth;
}

/**
 * @brief Get mapHeight do tile
 *
 * @return int
 */
int TileMap::GetHeight() {
	return mapHeight;
}

/**
 * @brief Get mapDepth do tile
 *
 * @return int
 */
int TileMap::GetDepth() {
	return mapDepth;
}

/**
 * @brief Metodo para renderiza camada de profundidade do mapa.
 *
 * @param layer
 * @param cameraX
 * @param cameraY
 */
void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {

	int i, j;
	int index = 0, x = 0, y = 0;

	for (i = 0; i < mapHeight; i++) {
		for (j = 0; j < mapWidth; j++) {
			index = At(j, i, layer);
			x = j * tileSet->GetTileWidth();
			y = i * tileSet->GetTileHeight();
			tileSet->RenderTile(index, x, y);
		}
	}
}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void TileMap::Render() {

	int i;

	for (i = mapDepth - 1; i >= 0; i--) {
		RenderLayer(i, tileSet->GetTileWidth(), tileSet->GetTileHeight());
	}
}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para atualizar o componente.
 *
 * @param dt entrada de botoes do jogador
 */
void TileMap::Update(float dt) {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para verificar o componente.
 *
 * @param type tipo de componente
 * @return true se o tipo componente for valido
 * @return false caso contrario
 */
bool TileMap::Is(string type) {

	if (type.compare("TileMap") == 0) {
		return true;
	}
	return false;
}
