/**
 * @file InputManager.cpp
 * @author Luan Mendes Gon√ßalves Freitas - 150015585
 * @brief Modulo dos metodos da classe InputManager
 * @version 0.2
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../include/InputManager.h"

/**
 * @brief Construtor da Classe InputManager
 *
 */
InputManager::InputManager() {

	for (int i = 0; i < 6; i++) {
		mouseState[i] = false;
		mouseUpdate[i] = 0;
	}

	keyState = { { 0, false } };
	keyUpdate = { { 0, false } };

	updateCounter = 0;
	quitRequested = false;

	mouseX = 0;
	mouseY = 0;

}

/**
 * @brief Destrutor da Classe InputManager
 *
 */
InputManager::~InputManager() {
	keyState.clear();
	keyUpdate.clear();
}

/**
 * @brief Atualiza e processa a entrada SDL do teclado e mouse.
 *
 */
void InputManager::Update() {

	SDL_Event sdlEvent;
	SDL_GetMouseState(&mouseX, &mouseY);
	mouseX += Camera::pos.x;
	mouseY += Camera::pos.y;
	quitRequested = false;

	if (updateCounter < 100) {
		updateCounter++;
	} else {
		updateCounter = 0;
	}

	while (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.key.repeat != 1) {

			switch (sdlEvent.type) {
			case SDL_QUIT:
				quitRequested = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mouseState[sdlEvent.button.button] = true;
				mouseUpdate[sdlEvent.button.button] = updateCounter;
				break;
			case SDL_MOUSEBUTTONUP:
				mouseState[sdlEvent.button.button] = false;
				mouseUpdate[sdlEvent.button.button] = updateCounter;
				break;
			case SDL_KEYDOWN:
				keyState[sdlEvent.key.keysym.sym] = true;
				keyUpdate[sdlEvent.key.keysym.sym] = updateCounter;
				break;
			case SDL_KEYUP:
				keyState[sdlEvent.key.keysym.sym] = false;
				keyUpdate[sdlEvent.key.keysym.sym] = updateCounter;
				break;
			default:
				break;
			}
		}
	}

}

/**
 * @brief Verifica se uma tecla foi pressionada.
 *
 * @param key valor da chave
 * @return true se a tecla foi pressionada
 * @return false caso contrario
 */
bool InputManager::KeyPress(int key) {

	if (keyUpdate[key] == updateCounter) {
		return keyState[key];
	} else {
		return false;
	}

}

/**
 * @brief Verifica se uma tecla foi liberada.
 *
 * @param key valor da chave
 * @return true se a tecla foi liberada
 * @return false caso contrario
 */
bool InputManager::KeyRelease(int key) {

	if (keyUpdate[key] == updateCounter) {
		return !(keyState[key]);
	} else {
		return false;
	}

}

/**
 * @brief Verifica se uma tecla continua sendo pressionada.
 *
 * @param key valor da chave
 * @return true se a tecla continua sendo pressionada
 * @return false caso contrario
 */
bool InputManager::IsKeyDown(int key) {

	return keyState[key];

}

/**
 * @brief Verifica se um botao mouse foi pressionado.
 *
 * @param key valor da chave
 * @return true se o botao do mouse foi pressionado
 * @return false caso contrario
 */
bool InputManager::MousePress(int button) {

	if (mouseUpdate[button] == updateCounter) {
		return mouseState[button];
	} else {
		return false;
	}

}

/**
 * @brief Verifica se botao do mouse continua sendo pressionado.
 *
 * @param key valor da chave
 * @return true se o botao do mouse continua sendo pressionaoa
 * @return false caso contrario
 */
bool InputManager::MouseRelease(int button) {

	if (mouseUpdate[button] == updateCounter) {
		return !(mouseState[button]);
	} else {
		return false;
	}

}

/**
 * @brief Verifica se um botao continua sendo pressionado.
 *
 * @param key valor da chave
 * @return true se um botao do mouse continua sendo pressionado
 * @return false caso contrario
 */
bool InputManager::IsMouseDown(int button) {

	return mouseState[button];

}

/**
 * @brief Get um objeto mouseX
 *
 * @return int mouseX
 */
int InputManager::GetMouseX() {

	return mouseX;

}

/**
 * @brief Get um objeto mouseY
 *
 * @return int mouseY
 */
int InputManager::GetMouseY() {

	return mouseY;

}

/**
 * @brief Verifica se a entrada SDL recebeu um sinal de encerramento.
 *
 * @return true se a entrada solicitada sair
 * @return false caso contrario
 */
bool InputManager::QuitRequested() {

	return quitRequested;

}

/**
 * @brief Get um objeto InputManager
 *
 * @return InputManager& um ponteiro para a inst‚ncia ˙nica da classe Input Manager
 */
InputManager& InputManager::GetInstance() {

	static InputManager inputManager;
	return inputManager;

}
