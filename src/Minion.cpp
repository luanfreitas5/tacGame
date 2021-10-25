/**
 * @file Minion.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Minion
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Minion.h"
#include "../include/Game.h"

/**
 * @brief Construtor da Classe Minion
 *
 * @param associated objeto associado a classe GameObject
 * @param alienCenter Objeto alien no centro do jogo
 * @param arcOffsetDeg Angulo do minion entre o alien no centro
 */
Minion::Minion(GameObject &associated, GameObject &alienCenter,
		float arcOffsetDeg) :
		Component(associated) {

	State &state = Game::GetInstance().GetState();
	Sprite *sprite = new Sprite(associated, FILE_MINION);
	float scale = 1 + (float) (rand() % 501) / 1000;

	this->alienCenter = state.GetObjectPtr(&alienCenter);
	this->arc = arcOffsetDeg;

	sprite->SetScale(scale, scale);
	associated.AddComponent(sprite);

}

/**
 * @brief Metodo para um minion disparar um bullet no alien
 *
 * @param target Posicao do alvo
 */
void Minion::Shoot(Vec2 target) {

	float distance = associated.box.GetCenter().GetDistance(target);
	float angle = associated.box.GetCenter().GetAngle(target);

	GameObject *gameObject = new GameObject();
	Bullet *buller = new Bullet(*gameObject, angle, SPEED, DAMEGE, distance,
	FILE_MINION_BULLET1);

	Vec2 vec2 = Vec2(gameObject->box.w / 2, gameObject->box.h / 2);
	Vec2 center = associated.box.GetCenter();
	State &state = Game::GetInstance().GetState();

	gameObject->AddComponent(buller);
	gameObject->box.SetPos(center - vec2);
	state.AddObject(gameObject);

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void Minion::Render() {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para atualizar o componente.
 *
 * @param dt valor Delta Time
 */
void Minion::Update(float dt) {

	if (alienCenter.expired()) {
		associated.RequestDelete();
	} else {
		arc += 60 * dt;
		associated.angleDeg = arc - 90;

		associated.box.x = alienCenter.lock()->box.GetCenter().x
				+ (200 * Vec2::Cos(arc)) - (associated.box.w / 2);

		associated.box.y = alienCenter.lock()->box.GetCenter().y
				+ (200 * Vec2::Sin(arc)) - (associated.box.h / 2);
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
bool Minion::Is(string type) {

	if (type.compare("Minion") == 0) {
		return true;
	}
	return false;

}
