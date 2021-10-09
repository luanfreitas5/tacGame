/**
 * @file Component.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Component
 * @version 0.1
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
