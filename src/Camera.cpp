/**
 * @file Camera.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Camera
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/Camera.h"
#include "../include/Game.h"

/**
 * @brief Faz com que a camera siga um determinado objeto.
 *
 * @param newFocus um ponteiro GameObject para o objeto a ser seguido
 */
void Camera::Follow(GameObject *newFocus) {
	focus = newFocus;
}

/**
 * @brief Faz com que a camera pare de seguir seu objeto-alvo.
 *
 */
void Camera::Unfollow() {
	focus = nullptr;
}

/**
 * @brief Atualiza a camera.
 * Isso pode ser feito seguindo um objeto visado ou movendo-se de
 * acordo com as entradas e considerando os limites do mapa.
 *
 * @param dt valor Delta Time
 */
void Camera::Update(float dt) {

	InputManager &inputManager = InputManager::GetInstance();

	if (focus != nullptr) {
		pos.x = (focus->box.x + (focus->box.w / 2)) - (WIDTH / 2);
		pos.y = (focus->box.y + (focus->box.h / 2)) - (HEIGHT / 2);

		if (inputManager.IsKeyDown(LEFT_ARROW_KEY)) {
			focus->box.x -= speed.x * dt;
		}

		if (inputManager.IsKeyDown(RIGHT_ARROW_KEY)) {
			focus->box.x += speed.x * dt;
		}

		if (inputManager.IsKeyDown(UP_ARROW_KEY)) {
			focus->box.y -= speed.y * dt;
		}

		if (inputManager.IsKeyDown(DOWN_ARROW_KEY)) {
			focus->box.y += speed.y * dt;
		}

	} else {

		if (inputManager.IsKeyDown(LEFT_ARROW_KEY)) {
			pos.x -= speed.x * dt;
		}

		if (inputManager.IsKeyDown(RIGHT_ARROW_KEY)) {
			pos.x += speed.x * dt;
		}

		if (inputManager.IsKeyDown(UP_ARROW_KEY)) {
			pos.y -= speed.y * dt;
		}

		if (inputManager.IsKeyDown(DOWN_ARROW_KEY)) {
			pos.y += speed.y * dt;
		}
	}
}
