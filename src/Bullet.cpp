/**
 * @file Bullet.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Bullet
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Bullet.h"

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
Bullet::Bullet(GameObject &associated, float angle, float speed, int damage,
		float maxDistance, string sprite) :
		Component(associated) {

	Sprite *spriteBullet = new Sprite(associated, sprite);

	this->speed = Vec2(speed * Vec2::Cos(angle), speed * Vec2::Sin(angle));
	this->damage = damage;
	this->distanceLeft = maxDistance;
	associated.angleDeg = angle;

	associated.AddComponent(spriteBullet);

}

/**
 * @brief Get o valor damage
 *
 * @return int valor damage
 */
int Bullet::GetDamage() {

	return damage;

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void Bullet::Render() {

}

void Bullet::Update(float dt) {

	if (distanceLeft > 0) {
		float x = speed.x * dt;
		float y = speed.y * dt;
		Vec2 vec2 = Vec2(x, y);

		associated.box.x += x;
		associated.box.y += y;
		distanceLeft -= Vec2().GetDistance(vec2);
	} else {
		associated.RequestDelete();
	}

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para verificar o componente.
 *
 * @param type tipo de componente
 * @return true se o tipo componente for valido
 * @return false caso contrario
 */
bool Bullet::Is(string type) {

	if (type.compare("Bullet") == 0) {
		return true;
	}
	return false;

}
