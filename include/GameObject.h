/**
 * @file GameObject.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Messages.h"
#include "Component.h"
#include "Rect.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/**
 * @brief Declaracao de encaminhamento da classe Component.
 *
 */
class Component;

/**
 * @brief Classe GameObject representa um objeto no jogo,
 * contendo componentes (caracteristicas) de jogo
 * 
 */
class GameObject {

public:

	/**
	 * @brief Construtor da Classe GameObject
	 * 
	 */
	GameObject();

	/**
	 * @brief Destrutor da Classe GameObject
	 * 
	 */
	~GameObject();

	/**
	 * @brief Metodo para atualizar o componente.
	 * 
	 * @param dt entrada de botoes do jogador
	 */
	void Update(float dt);

	/**
	 * @brief Metodo para renderizar o componente.
	 * 
	 */
	void Render();

	/**
	 * @brief Metodo para verificar se objeto de jogo esta dead,
	 * isto e, hitpoints menor ou igual a zero.
	 * 
	 * @return true objeto de jogo esta dead
	 * @return false caso contrario
	 */
	bool IsDead();

	/**
	 * @brief Metodo para deletar objeto de jogo
	 * 
	 */
	void RequestDelete();

	/**
	 * @brief Metodo para adicionar componente
	 * 
	 * @param cpt ponteiro do componente
	 */
	void AddComponent(Component *cpt);

	/**
	 * @brief Metodo para remover componente
	 * 
	 * @param cpt ponteiro do componente
	 */
	void RemoveComponent(Component *cpt);

	/**
	 * @brief Get um objeto Component
	 * 
	 * @param type tipo do componente a ser retornado
	 * @return Component* ponteiro do componente de jogo correspondente ao parametro
	 */
	Component* GetComponent(string type);

	/**
	 * @brief Posisao na qual o objeto é inserido no jogo, com informacoes
	 * de posicoes x, y, largura e altura.
	 * 
	 */
	Rect box;

private:

	/**
	 * @brief Vetor de ponteiros unicos de componentes de objetos.
	 * 
	 */
	vector<unique_ptr<Component>> components;

	/**
	 * @brief Flag que determina se o objeto esta vivo ou nao.
	 * 
	 */
	bool isDead;
};

#endif /* GAMEOBJECT_H_ */
