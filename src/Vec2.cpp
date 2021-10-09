/**
 * @file Vec2.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Vec2
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Vec2.h"

/**
 * @brief Construtor da Classe Vec2
 * Inicializa as coordenadas com zero
 *
 */
Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
}

/**
 * @brief Construtor da Classe Vec2
 * Inicializa as coordenadas com parametros de entrada
 *
 * @param x coordenada horizontal do retangulo
 * @param y coordenada vertical do retangulo
 */
Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

/**
 * @brief Metodo calcular um ponto aleatorio para preencher o objeto de jogo na tela
 *
 * @param distancia valor da distancia entre o primeiro valor Vec2 e o segundo 2 Vec2 aleatorio.
 */
void Vec2::CalcularRotacaoAngulo(float distancia) {

	double angulo;
	random_device numeroRand;

	angulo = (double) (2 * PI * ((double) numeroRand() / numeroRand.max()));

	x += (float) (cos(angulo) * distancia);
	y += (float) (sin(angulo) * distancia);
}
