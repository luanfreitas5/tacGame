/**
 * @file Camera.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Camera com seus prototipos de metodo e ponteiros.
 * @version 0.2
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#define SPEED_X 300
#define SPEED_Y 300

#define WIDTH 1024
#define HEIGHT 600

#include "Messages.h"
#include "GameObject.h"
#include "InputManager.h"
#include "Vec2.h"
#include <iostream>

using namespace std;

/**
 * @brief Classe Camera que armazenha um conjunto de blocos
 * recortado de uma imagem para ser mostrado em um mapa de blocos.
 * 
 */
class Camera {

public:

	/**
	 * @brief Faz com que a camera siga um determinado objeto.
	 * 
	 * @param newFocus um ponteiro GameObject para o objeto a ser seguido
	 */
	static void Follow(GameObject *newFocus);

	/**
	 * @brief Faz com que a camera pare de seguir seu objeto-alvo.
	 * 
	 */
	static void Unfollow();

	/**
	 * @brief Atualiza a camera.
	 * Isso pode ser feito seguindo um objeto visado ou movendo-se de
	 * acordo com as entradas e considerando os limites do mapa.
	 * 
	 * @param dt valor Delta Time
	 */
	static void Update(float dt);

	/**
	 * @brief Posicao da camera.
	 * 
	 */
	static Vec2 pos;

	/**
	 * @brief Velocidade de movimento da camera.
	 * 
	 */
	static Vec2 speed;

private:

	/**
	 * @brief Foco do objeto de jogo na camera
	 * 
	 */
	static GameObject *focus;
};

#endif /* CAMERA_H_ */
