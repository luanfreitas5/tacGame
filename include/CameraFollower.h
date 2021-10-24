/**
 * @file CameraFollower.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe CameraFollower com seus prototipos de metodo e ponteiros.
 * @version 0.2
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef CAMERAFOLLOWER_H_
#define CAMERAFOLLOWER_H_

#include "Messages.h"
#include "Camera.h"
#include "GameObject.h"
#include "Vec2.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe CameraFollower que armazenha um conjunto de blocos recortado de uma imagem para ser mostrado em um mapa de blocos.
 * Herda metodos da classe Component
 * 
 */
class CameraFollower: public Component {

public:

	/**
	 * @brief Construtor da Classe CameraFollower
	 * 
	 * @param associated endereco do objeto de jogo ao qual o componente esta associado.
	 */
	CameraFollower(GameObject &associated);

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
	 * @param dt valor Delta Time
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

private:
};

#endif /* CAMERAFOLLOWER_H_ */
