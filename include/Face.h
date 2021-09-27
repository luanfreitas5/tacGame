/**
 * @file Face.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Face com seus prototipos de metodo e ponteiros.
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FACE_H_
#define FACE_H_

#include "Messages.h"
#include "Component.h"
#include "GameObject.h"
#include "Sound.h"
#include "Sprite.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Face representa um componente de um objeto de jogo,
 * como um personagem de jogo.
 * Herda metodos da classe Component
 * 
 */
class Face: public Component {

public:

	/**
	 * @brief Construtor da Classe Face
	 * Inicializa o hitpoints (pontos de vida) objeto do jogo.
	 * 
	 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
	 */
	Face(GameObject &associated);

	/**
	 * @brief Metodo para diminuir os hitpoints do objeto de jogo.
	 * Quando os hitpoints ficam menores ou igual a zero o objeto de jogo é removido,
	 * reproduzindo um som de morte e esconde sua textura.
	 * 
	 * @param damage valor a ser substraindo no hitpointss
	 */
	void Damage(int damage);

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
	 * @param dt entrada de botoes do jogador
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

	/**
	 * @brief Metodo para verificar se objeto de jogo esta dead,
	 * isto e, hitpoints menor ou igual a zero.
	 * 
	 * @return true objeto de jogo esta dead
	 * @return false caso contrario
	 */
	bool IsDead();

private:

	/**
	 * @brief Pontos de vida do objeto de jogo.
	 * 
	 */
	int hitpoints;
};

#endif /* FACE_H_ */
