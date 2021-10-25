/**
 * @file Alien.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho da classe Alien com seus prototipos de metodo e ponteiros.
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef ALIEN_H_
#define ALIEN_H_

#define FILE_ALIEN "assets/img/alien.png"
#define ALIEN_HP 1500

#include "Messages.h"
#include "Component.h"
#include "GameObject.h"
#include "Minion.h"
#include "Rect.h"
#include "Sprite.h"
#include "Vec2.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * @brief Classe Sprite responsavel genereciar o alien jogo.
 * Herda metodos da classe Component
 *
 */
class Alien: public Component {

public:

	/**
	 * @brief Construtor da Classe Alien
	 * 
	 * @param associated objeto associado a classe GameObject
	 * @param nMinions numero de minions do alien
	 */
	Alien(GameObject &associated, int nMinions);

	/**
	 * @brief Destrutor da Classe Alien
	 * 
	 */
	~Alien();

	/**
	 * @brief Sobreposicao do metodo da classe Component
	 * Metodo para inicializa o alien e o array de minions do jogo.
	 * 
	 */
	void Start();

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
	 * @brief Classe Privada Action responsavel genereciar as acoes do alien de jogo.
	 * 
	 */
	class Action {
	public:
		
		/**
		 * @brief Enum das acoes do alien mover 0 e atirar 1
		 * 
		 */
		enum ActionType {
			MOVE, SHOOT
		};

		/**
		 * @brief Construct a new Action object
		 * 
		 * @param type tipo de acao MOVE ou SHOOT
		 * @param x coordenada horizontal
		 * @param y coordenada vertical
		 */
		Action(ActionType type, float x, float y);

		/**
		 * @brief tipo de acao MOVE ou SHOOT
		 * 
		 */
		ActionType type;
		
		/**
		 * @brief posicao da acao
		 * 
		 */
		Vec2 pos;

	private:
	};

	/**
	 * @brief Velocidade do alien no jogo
	 * 
	 */
	Vec2 speed;

	/**
	 * @brief Pontos de Vida do alien no jogo
	 * 
	 */
	int hp;

	/**
	 * @brief numero de minions do alien
	 * 
	 */
	int nMinions;

	/**
	 * @brief Fila de acoes
	 * 
	 */
	queue<Action> taskQueue;

	/**
	 * @brief Array que armazenha os minions exitentes no jogo
	 * 
	 */
	vector<weak_ptr<GameObject>> minionArray;

};

#endif /* ALIEN_H_ */
