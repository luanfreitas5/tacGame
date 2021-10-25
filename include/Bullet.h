/**
 * @file Bullet.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Bullet com seus prototipos de metodo e ponteiros.
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "Messages.h"
#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Vec2.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Bullet responsavel genereciar os tiros no jogo.
 * Herda metodos da classe Component
 *
 */
class Bullet: public Component {

public:

	/**
	 * @brief Construtor da Classe Alien
	 * 
	 * @param associated objeto associado a classe GameObject
	 * @param angle angulo do bullet na tela
	 * @param speed velocidade do bullet na tela
	 * @param damage valor do dano do bullet
	 * @param maxDistance distancia do bullet na tela
	 * @param sprite no arquivo do bullet
	 */
	Bullet(GameObject &associated, float angle, float speed, int damage,
			float maxDistance, string sprite);

	/**
	 * @brief Get o valor damage
	 * 
	 * @return int valor damage
	 */
	int GetDamage();

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
	 * @param dt valor Delta Time
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
	 * @brief Velocidade do bullet
	 * 
	 */
	Vec2 speed;

	/**
	 * @brief Distancia do bullet
	 * 
	 */
	float distanceLeft;

	/**
	 * @brief valor damage do bullet
	 * 
	 */
	int damage;
};

#endif /* BULLET_H_ */
