#ifndef MINION_H_
#define MINION_H_

#define FILE_MINION "assets/img/minion.png"
#define FILE_MINION_BULLET1 "assets/img/minionbullet1.png"
#define FILE_MINION_BULLET2 "assets/img/minionbullet2.png"

#define FILE_MINION_BULLET2 "assets/img/minionbullet2.png"
#define FILE_MINION_BULLET2 "assets/img/minionbullet2.png"

#define SPEED 600
#define DAMEGE 5

#include "Messages.h"
#include "Bullet.h"
#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Vec2.h"
#include <iostream>

using namespace std;

class Minion: public Component {

public:

	/**
	 * @brief Construtor da Classe Minion
	 * 
	 * @param associated objeto associado a classe GameObject
	 * @param alienCenter Objeto alien no centro do jogo
	 * @param arcOffsetDeg Angulo do minion entre o alien no centro
	 */
	Minion(GameObject &associated, GameObject &alienCenter, float arcOffsetDeg =
			0);

	/**
	 * @brief Metodo para um minion disparar um bullet no alien
	 * 
	 * @param target Posicao do alvo
	 */
	void Shoot(Vec2 target);

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

	/**
	 * @brief Instancia do alien no centro do jogo
	 * 
	 */
	weak_ptr<GameObject> alienCenter;

	/**
	 * @brief Angulo do minion
	 * 
	 */
	float arc;
};

#endif /* MINION_H_ */
