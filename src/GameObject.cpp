/**
 * @file GameObject.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/GameObject.h"

/**
 * @brief Construtor da Classe GameObject
 *
 */
GameObject::GameObject() :
		box(Rect()) {

	isDead = false;

}

/**
 * @brief Destrutor da Classe GameObject
 *
 */
GameObject::~GameObject() {

	components.clear();

}

/**
 * @brief Metodo para atualizar o componente.
 *
 * @param dt entrada de botoes do jogador
 */
void GameObject::Update(float dt) {

	int i, tamanhoComponents = components.size() - 1;

	for (i = tamanhoComponents; i >= 0; i--) {
		components.at(i)->Update(dt);
	}

}

/**
 * @brief Metodo para renderizar o componente.
 *
 */
void GameObject::Render() {

	int i, tamanhoComponents = components.size();

	for (i = 0; i < tamanhoComponents; i++) {
		components.at(i)->Render();
	}

}

/**
 * @brief Metodo para verificar se objeto de jogo esta dead,
 * isto e, hitpoints menor ou igual a zero.
 *
 * @return true objeto de jogo esta dead
 * @return false caso contrario
 */
bool GameObject::IsDead() {

	return isDead;

}

/**
 * @brief Metodo para deletar objeto de jogo
 *
 */
void GameObject::RequestDelete() {

	isDead = true;

}

/**
 * @brief Metodo para adicionar componente
 *
 * @param cpt ponteiro do componente
 */
void GameObject::AddComponent(Component *cpt) {

	components.emplace_back(cpt);

}

/**
 * @brief Metodo para remover componente
 *
 * @param cpt ponteiro do componente
 */
void GameObject::RemoveComponent(Component *cpt) {

	int i, tamanhoComponents = components.size();

	for (i = 0; i < tamanhoComponents; i++) {

		if (components.at(i).get() == cpt) {
			components.erase(components.begin() + i);
			break;
		}
	}
}

/**
 * @brief Get um objeto Component
 *
 * @param type tipo do componente a ser retornado
 * @return Component* ponteiro do componente de jogo correspondente ao parametro
 */
Component* GameObject::GetComponent(string type) {

	int i, tamanhoComponents = components.size() - 1;

	for (i = tamanhoComponents; i >= 0; i--) {

		if (components.at(i)->Is(type)) {
			return components.at(i).get();
		}
	}
	return nullptr;

}
