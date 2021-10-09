/**
 * @file Face.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Face
 * @version 0.3
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Face.h"

/**
 * @brief Construtor da Classe Face
 * Inicializa o hitpoints (pontos de vida) objeto do jogo.
 *
 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
 */
Face::Face(GameObject &associated) :
		Component(associated) {

	hitpoints = 30;

}

/**
 * @brief Metodo para diminuir os hitpoints do objeto de jogo.
 * Quando os hitpoints ficam menores ou igual a zero o objeto de jogo é removido,
 * reproduzindo um som de morte e esconde sua textura.
 *
 * @param damage valor a ser substraindo no hitpointss
 */
void Face::Damage(int damage) {

	hitpoints -= damage;

	if (hitpoints <= 0) {

		static_cast<Sound*>(associated.GetComponent("Sound"))->Play(1);
		Sprite *sprite = static_cast<Sprite*>(associated.GetComponent("Sprite"));

		if (sprite != nullptr) {
			associated.RemoveComponent(sprite);
		}
	}

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void Face::Render() {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para atualizar o componente.
 *
 * @param dt valor Delta Time
 */
void Face::Update(float dt) {

	if (hitpoints <= 0) {
		if (!(static_cast<Sound*>(associated.GetComponent("Sound"))->GetIsPlaying())) {
			associated.RequestDelete();
		}
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
bool Face::Is(string type) {

	if (type.compare("Face") == 0) {
		return true;
	}
	return false;

}

/**
 * @brief Metodo para verificar se objeto de jogo esta dead,
 * isto e, hitpoints menor ou igual a zero.
 *
 * @return true objeto de jogo esta dead
 * @return false caso contrario
 */
bool Face::IsDead() {

	if (hitpoints <= 0) {
		return true;
	}

	return false;

}
