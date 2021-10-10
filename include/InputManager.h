/**
 * @file InputManager.h
 * @author Luan Mendes GonÃ§alves Freitas - 150015585
 * @brief Cabecalho da classe InputManager com seus prototipos de metodo e ponteiros.
 * @version 0.1
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#define INCLUDE_SDL

/** Botoes de Setas de Teclado */
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN

/** Botao do ESC */
#define ESCAPE_KEY SDLK_ESCAPE

/** Botao Espaco */
#define SPACE_KEY SDLK_SPACE

/** Botoes do Mouse */
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

#include "Messages.h"
#include "SDL_include.h"
#include "Camera.h"
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * @brief Classe GameObject representa um objeto no jogo,
 * contendo componentes (caracteristicas) de jogo
 * 
 */
class InputManager {

public:

	/**
	 * @brief Atualiza e processa a entrada SDL do teclado e mouse.
	 * 
	 */
	void Update();

	/**
	 * @brief Verifica se uma tecla foi pressionada.
	 * 
	 * @param key valor da chave
	 * @return true se a tecla foi pressionada
	 * @return false caso contrario
	 */
	bool KeyPress(int key);

	/**
	 * @brief Verifica se uma tecla foi liberada.
	 * 
	 * @param key valor da chave
	 * @return true se a tecla foi liberada
	 * @return false caso contrario
	 */
	bool KeyRelease(int key);

	/**
	 * @brief Verifica se uma tecla continua sendo pressionada.
	 * 
	 * @param key valor da chave
	 * @return true se a tecla continua sendo pressionada
	 * @return false caso contrario
	 */
	bool IsKeyDown(int key);

	/**
	 * @brief Verifica se um botao mouse foi pressionado.
	 * 
	 * @param key valor da chave
	 * @return true se o botao do mouse foi pressionado
	 * @return false caso contrario
	 */
	bool MousePress(int button);

	/**
	 * @brief Verifica se botao do mouse continua sendo pressionado.
	 * 
	 * @param key valor da chave
	 * @return true se o botao do mouse continua sendo pressionaoa
	 * @return false caso contrario
	 */
	bool MouseRelease(int button);

	/**
	 * @brief Verifica se um botao continua sendo pressionado.
	 * 
	 * @param key valor da chave
	 * @return true se um botao do mouse continua sendo pressionado
	 * @return false caso contrario
	 */
	bool IsMouseDown(int button);

	/**
	 * @brief Get um objeto mouseX
	 * 
	 * @return int mouseX
	 */
	int GetMouseX();

	/**
	 * @brief Get um objeto mouseY
	 * 
	 * @return int mouseY
	 */
	int GetMouseY();

	/**
	 * @brief Verifica se a entrada SDL recebeu um sinal de encerramento.
	 * 
	 * @return true se a entrada solicitada sair
	 * @return false caso contrario
	 */
	bool QuitRequested();

	/**
	 * @brief Get um objeto InputManager
	 * 
	 * @return InputManager& um ponteiro para a instância única da classe Input Manager
	 */
	static InputManager& GetInstance();

private:

	/**
	 * @brief Construtor da Classe InputManager
	 * 
	 */
	InputManager();

	/**
	 * @brief Destrutor da Classe InputManager
	 * 
	 */
	~InputManager();

	/**
	 * @brief Vetor de estados do mouse
	 * 
	 */
	bool mouseState[6];

	/**
	 * @brief Vetor de atualizacoes do mouse
	 * 
	 */
	int mouseUpdate[6];

	/**
	 * @brief Conteiner de estados do mouse
	 * 
	 */
	unordered_map<int, bool> keyState;

	/**
	 * @brief Conteiner de atualizacoes do mouse
	 * 
	 */
	unordered_map<int, int> keyUpdate;

	/**
	 * @brief Indicador sair do jogo.
	 * 
	 */
	bool quitRequested;

	/**
	 * @brief Indicador atualizar posicoes de jogo.
	 * 
	 */
	int updateCounter;

	/**
	 * @brief Botao esquerda do mouse
	 * 
	 */
	int mouseX;

	/**
	 * @brief Botao direita do mouse
	 * 
	 */
	int mouseY;
};

#endif /* INPUTMANAGER_H_ */
