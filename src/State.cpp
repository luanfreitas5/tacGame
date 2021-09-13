/**
 * @file State.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe State
 * @version 0.2
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/State.h"

/**
 * @brief Construtor da Classe Sprite
 *
 */
State::State() :
		music(Music()) {

	GameObject *gameObject = new GameObject();
	Sprite *sprite = new Sprite(*gameObject, "assets/img/ocean.jpg");
	gameObject->box.x = 0;
	gameObject->box.y = 0;
	gameObject->AddComponent(sprite);
	objectArray.emplace_back(gameObject);

	quitRequested = false;
}

/**
 * @brief Destrutor da Classe State
 *
 */
State::~State() {
	objectArray.clear();
}

/**
 * @brief Metodo para pre-carregar os assets do state do jogo
 *
 */
void State::LoadAssets() {
	music.Open("assets/audio/stageState.ogg");
	music.Play();
}

/**
 * @brief Metodo que atualiza o estado do jogo, atualizando o estado dos objetos de jogo na tela
 *
 * @param dt entrada de botoes do usuario
 */
void State::Update(float dt) {

	Input();

	int i, tamanhoObjectArray = objectArray.size() - 1;

	for (i = tamanhoObjectArray; i >= 0; i--) {
		objectArray.at(i)->Update(dt);
	}

	/** Verificando objetos de jogo no estado dead */
	for (i = tamanhoObjectArray; i >= 0; i--) {
		if (objectArray.at(i)->IsDead()) {
			objectArray.erase(objectArray.begin() + i);
		}
	}
}

/**
 * @brief Metodo para a renderização do estado no canto superior esquerdo do jogo.
 *
 */
void State::Render() {

	int i, tamanhoObjectArray = objectArray.size();

	for (i = 0; i < tamanhoObjectArray; i++) {
		objectArray.at(i).get()->Render();
	}
}

/**
 * @brief Metodo para acessar o membro quitRequested
 *
 * @return true
 * @return false
 */
bool State::QuitRequested() {

	return quitRequested;
}

/**
 * @brief Metodo detectar entradas de teclas do usuario e trata acoes de acordo
 *
 */
void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	/** Obtenha as coordenadas do mouse */
	SDL_GetMouseState(&mouseX, &mouseY);

	/** SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário */
	while (SDL_PollEvent(&event)) {

		/** Se o evento for quit, setar a flag para terminação */
		if (event.type == SDL_QUIT) {
			quitRequested = true;
		}

		/** Se o evento for clique... */
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			/** Percorrer de trás pra frente pra sempre clicar no objeto mais de cima */
			for (int i = objectArray.size() - 1; i >= 0; --i) {

				/** Obtem o ponteiro e casta pra Face. */
				GameObject *go = (GameObject*) objectArray[i].get();

				/** Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				 * O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				 * ao usar get(), violamos esse princípio e estamos menos seguros.
				 * Esse código, assim como a classe Face, é provisório. Futuramente, para
				 * chamar funções de GameObjects, use objectArray[i]->função() direto. */

				if (go->box.Contains((float) mouseX, (float) mouseY)) {

					Face *face = (Face*) go->GetComponent("Face");
					if (face != nullptr) {
						if (!(face->IsDead())) {

							/** Aplica dano */
							face->Damage(rand() % 10 + 10);

							/** Sai do loop (só queremos acertar um) */
							break;
						}
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {

			/** Se a tecla for ESC, setar a flag de quit */
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}

			/** Se não, crie um objeto */
			else {
				Vec2 objPos = Vec2(mouseX, mouseY);
				float distancia = 200;
				objPos.CalcularRotacaoAngulo(distancia);
				AddObject((int) objPos.x, (int) objPos.y);
			}
		}
	}
}

/**
 * @brief Metodo para adicionar objeto de jogo (pinguim) na tela de Jogo.
 *
 * @param mouseX coordenada horizontal do retangulo
 * @param mouseY coordenada vertical do retangulo
 */
void State::AddObject(int x, int y) {

	GameObject *gameObject = new GameObject();
	Sprite *sprite = new Sprite(*gameObject, "assets/img/penguinface.png");
	Sound *sound = new Sound(*gameObject, "assets/audio/boom.wav");
	Face *face = new Face(*gameObject);

	gameObject->box.x = x;
	gameObject->box.y = y;

	gameObject->AddComponent(sprite);
	gameObject->AddComponent(sound);
	gameObject->AddComponent(face);

	gameObject->box.x -=
			static_cast<Sprite*>(gameObject->GetComponent("Sprite"))->GetWidth();

	gameObject->box.x /= 2;

	gameObject->box.y -=
			static_cast<Sprite*>(gameObject->GetComponent("Sprite"))->GetHeight();

	gameObject->box.y /= 2;

	objectArray.emplace_back(gameObject);

}
