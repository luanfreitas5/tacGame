/**
 * @file Alien.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Alien
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Alien.h"
#include "../include/Game.h"

/**
 * @brief Construtor da Classe Alien
 *
 * @param associated objeto associado a classe GameObject
 * @param nMinions numero de minions do alien
 */
Alien::Alien(GameObject &associated, int nMinions) :
		Component(associated) {

	this->hp = 10;
	this->speed = Vec2();
	this->nMinions = nMinions;

	Sprite *sprite = new Sprite(associated, FILE_ALIEN);

	associated.AddComponent(sprite);

}

/**
 * @brief Destrutor da Classe Alien
 *
 */
Alien::~Alien() {

	minionArray.clear();

}

Alien::Action::Action(ActionType type, float x, float y) {

	Action::type = type;
	pos = Vec2(x, y);

}

/**
 * @brief Sobreposicao do metodo da classe Component
 * Metodo para inicializa o alien e o array de minions do jogo.
 *
 */
void Alien::Start() {

	int i;

	for (i = 0; i < nMinions; i++) {

		float arcOffsetDeg = i * (360 / nMinions);

		GameObject *gameObject = new GameObject();
		Minion *minion = new Minion(*gameObject, associated, arcOffsetDeg);
		State &state = Game::GetInstance().GetState();

		gameObject->AddComponent(minion);
		minionArray.push_back(state.AddObject(gameObject));
	}

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void Alien::Update(float dt) {

	InputManager &inputManager = InputManager::GetInstance();

	float x = inputManager.GetInstance().GetMouseX();
	float y = inputManager.GetInstance().GetMouseY();
	Rect box = associated.box;
	Vec2 vec2 = Vec2(x, y);
	int tamanhoTaskQueue = taskQueue.size();

	if (inputManager.MousePress(LEFT_MOUSE_BUTTON)) {
		float x = vec2.x;
		float y = vec2.y;
		Action action = Action(Action::SHOOT, x, y);
		taskQueue.push(action);
	}
	if (inputManager.MousePress(RIGHT_MOUSE_BUTTON)) {
		float x = vec2.x - box.w / 2;
		float y = vec2.y - box.h / 2;
		Action action = Action(Action::MOVE, x, y);
		taskQueue.push(action);
	}

	if (tamanhoTaskQueue > 0) {
		Vec2 pos = taskQueue.front().pos;

		int posicao = 0, i;
		float distance = minionArray[0].lock()->box.GetCenter().GetDistance(
				pos);
		int tamanhoMinion = minionArray.size();

		float cos = box.GetPos().GetCos(pos);
		float sin = box.GetPos().GetSin(pos);
		Minion *minion;

		switch (taskQueue.front().type) {

		case Action::SHOOT:

			for (i = 1; i < tamanhoMinion; i++) {
				float distanceNova =
						minionArray[i].lock()->box.GetCenter().GetDistance(pos);
				if (distanceNova < distance) {
					posicao = i;
					distance = distanceNova;
				}
			}
			minion = (Minion*) minionArray[posicao].lock()->GetComponent(
					"Minion");

			minion->Shoot(pos);
			taskQueue.pop();
			break;

		case Action::MOVE:

			speed = Vec2(500 * cos, 500 * sin);

			if ((box.x + speed.x * dt > pos.x && pos.x > box.x)
					|| (box.x + speed.x * dt < pos.x && pos.x < box.x)) {
				box.x = pos.x;
			} else {
				box.x += speed.x * dt;
			}

			if ((box.y + speed.y * dt > pos.y && pos.y > box.y)
					|| (box.y + speed.y * dt < pos.y && pos.y < box.y)) {
				box.y = pos.y;
			} else {
				box.y += speed.y * dt;
			}

			if (box.x == pos.x && box.y == pos.y) {
				taskQueue.pop();
			}

			associated.box = box;
			break;

		default:
			cout << ERRO_ACTION << endl;
			break;
		}

	}

	if (hp < 1) {
		associated.RequestDelete();
	}

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para renderizar o componente.
 *
 */
void Alien::Render() {

}

/**
 * @brief Sobreposicao do metodo da classe Component.
 * Metodo para verificar o componente.
 *
 * @param type tipo de componente
 * @return true se o tipo componente for valido
 * @return false caso contrario
 */
bool Alien::Is(string type) {

	if (type.compare("Alien") == 0) {
		return true;
	}
	return false;

}

