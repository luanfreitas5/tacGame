/**
 * @file Rect.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Rect.h"

/**
 * @brief Construtor da Classe Rect.
 * Inicializa as coordenadas e tamanho (largura e altura) com zero
 *
 */
Rect::Rect() {
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

/**
 * @brief Construtor da Classe Rect.
 * Inicializa as coordenadas e tamanho (largura e altura) com parametros de entrada
 *
 * @param x coordenada horizontal do retangulo
 * @param y coordenada vertical do retangulo
 * @param w tamanho da largura do retangulo
 * @param h tamanho da altura do retangulo
 */
Rect::Rect(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

/**
 * @brief Metodo para verificar se um determinado ponto esta dentro da area do retangulo.
 *
 * @param mouseX coordenada horizontal do retangulo
 * @param mouseY coordenada vertical do retangulo
 * @return true se o ponto x e y estiver dentro da area do retangulo.
 * @return false caso contrario
 */
bool Rect::Contains(float mouseX, float mouseY) {
	if (mouseX >= x && mouseY >= y && mouseX <= x + w && mouseY <= y + h) {
		return true;
	}
	return false;

}
