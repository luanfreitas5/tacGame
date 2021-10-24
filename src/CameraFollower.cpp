/**
 * @file CameraFollower.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe CameraFollower
 * @version 0.2
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/CameraFollower.h"

/**
 * @brief Construtor da Classe CameraFollower
 *
 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
 */
CameraFollower::CameraFollower(GameObject &associated) :
		Component(associated) {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void CameraFollower::Render() {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para atualizar o componente.
 *
 * @param dt entrada de botoes do jogador
 */
void CameraFollower::Update(float dt) {

	associated.box.x = Camera::pos.x;
	associated.box.y = Camera::pos.y;

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para verificar o componente.
 *
 * @param type tipo de componente
 * @return true se o tipo componente for valido
 * @return false caso contrario
 */
bool CameraFollower::Is(string type) {

	if (type.compare("CameraFollower") == 0) {
		return true;
	}
	return false;

}
