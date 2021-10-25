/**
 * @file Rect.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Rect com seus prototipos de metodo e ponteiros.
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef RECT_H_
#define RECT_H_

#include "Messages.h"
#include "Vec2.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Rect contem coordenadas e tamanho (largura e altura)
 * para inserir um objeto do jogo na janela do jogo
 * 
 */
class Rect {

public:

	/**
	 * @brief Construtor da Classe Rect.
	 * Inicializa as coordenadas e tamanho (largura e altura) com zero
	 * 
	 */
	Rect();

	/**
	 * @brief Construtor da Classe Rect.
	 * Inicializa as coordenadas e tamanho (largura e altura) com parametros de entrada
	 * 
	 * @param x coordenada horizontal do retangulo
	 * @param y coordenada vertical do retangulo
	 * @param w tamanho da largura do retangulo
	 * @param h tamanho da altura do retangulo
	 */
	Rect(float x, float y, float w, float h);

	/**
	 * @brief Metodo para verificar se um determinado ponto esta dentro da area do retangulo.
	 * 
	 * @param mouseX coordenada horizontal do retangulo
	 * @param mouseY coordenada vertical do retangulo
	 * @return true se o ponto x e y estiver dentro da area do retangulo.
	 * @return false caso contrario
	 */
	bool Contains(float mouseX, float mouseY);

	/**
	 * @brief Get Pos
	 * 
	 * @return Vec2 
	 */
	Vec2 GetPos();

	/**
	 * @brief Get Center
	 * 
	 * @return Vec2 
	 */
	Vec2 GetCenter();

	/**
	 * @brief Set Pos
	 * 
	 * @param pos 
	 */
	void SetPos(Vec2 pos);

	/**
	 * @brief Get Vec2
	 * 
	 * @return Vec2 
	 */
	Vec2 GetVec2();

	/**
	 * @brief coordenada horizontal do retangulo
	 * 
	 */
	float x;

	/**
	 * @brief coordenada vertical do retangulo
	 * 
	 */
	float y;

	/**
	 * @brief tamanho da largura do retangulo
	 * 
	 */
	float w;

	/**
	 * @brief tamanho da altura do retangulo
	 * 
	 */
	float h;

private:

};

#endif /* RECT_H_ */
