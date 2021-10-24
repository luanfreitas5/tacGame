/**
 * @file Component.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Component
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Component.h"

/**
 * @brief Construtor da Classe Component
 *
 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
 */
Component::Component(GameObject &associated) :
		associated(associated) {

}

/**
 * @brief Destrutor da Classe Component
 *
 */
Component::~Component() {

}

/**
 * @brief Metodo Virtual.
 * Metodo para inicializa o alien e o array de minions do jogo
 *
 */
void Component::Start() {
}
