/**
 * @file Component.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Component com seus prototipos de metodo e ponteiros.
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Messages.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

/**
 * @brief Declaracao de encaminhamento da classe GameObject.
 *
 */
class GameObject;

/**
 * @brief Classe Abstrata Component.
 * Representa um objeto de jogo, como face, som ou estado.
 * 
 */
class Component {

public:

	/**
	 * @brief Construtor da Classe Component
	 * 
	 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
	 */
	Component(GameObject &associated);

	/**
	 * @brief Destrutor da Classe Component
	 * 
	 */
	virtual ~Component();

	/**
	 * @brief Metodo Virtual.
	 * Metodo para atualizar o componente.
	 *
	 * @param dt valor Delta Time
	 */
	virtual void Update(float dt) = 0;

	/**
	 * @brief Metodo Virtual.
	 * Metodo para renderizar o componente.
	 *
	 */
	virtual void Render() = 0;

	/**
	 * @brief Metodo Virtual.
	 * Metodo para verificar o componente.
	 *
	 * @param type tipo de componente
	 * @return true se o tipo componente for valido
	 * @return false caso contrario
	 */
	virtual bool Is(string type) = 0;

	/**
	 * @brief Metodo Virtual.
	 * Metodo para inicializa o alien e o array de minions do jogo
	 * 
	 */
	virtual void Start();

private:

protected:

	/**
	 * @brief Endereco do objeto de jogo ao qual o componente esta associado.
	 * 
	 */
	GameObject &associated;
};

#endif /* COMPONENT_H_ */
