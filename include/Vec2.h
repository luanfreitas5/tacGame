/**
 * @file Vec2.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Vec2 com seus prototipos de metodo e ponteiros.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef VEC2_H_
#define VEC2_H_

#define PI 3.14159265359

#include "Messages.h"
#include <iostream>
#include <math.h>
#include <random>

using namespace std;

/**
 * @brief Classe Vec2 responsavel por operacoes de vetor no jogo.
 * 
 */
class Vec2 {

public:

	/**
	 * @brief Construtor da Classe Vec2
	 * Inicializa as coordenadas com zero
	 * 
	 */
	Vec2();

	/**
	 * @brief Construtor da Classe Vec2
	 * Inicializa as coordenadas com parametros de entrada
	 * 
	 * @param x coordenada horizontal do retangulo
	 * @param y coordenada vertical do retangulo
	 */
	Vec2(float x, float y);

	/**
	 * @brief Metodo calcular um ponto aleatorio para preencher o objeto de jogo na tela
	 * 
	 * @param distancia valor da distancia entre o primeiro valor Vec2 e o segundo 2 Vec2 aleatorio.
	 */
	void CalcularRotacaoAngulo(float distancia);

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

private:
};

#endif /* VEC2_H_ */
