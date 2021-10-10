/**
 * @file State.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe State
 * @version 0.4
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/State.h"

/**
 * @brief Construtor da Classe State
 *
 */
State::State() :
		music(Music()) {

	GameObject *gameObject_sprite = new GameObject();
	Sprite *sprite = new Sprite(*gameObject_sprite, FILE_OCEAN);
	CameraFollower *cameraFollower = new CameraFollower(*gameObject_sprite);
	gameObject_sprite->box.x = 0;
	gameObject_sprite->box.y = 0;
	gameObject_sprite->AddComponent(sprite);
	gameObject_sprite->AddComponent(cameraFollower);
	objectArray.emplace_back(gameObject_sprite);

	GameObject *gameObject_tileMap = new GameObject();
	TileSet *tileSet = new TileSet(*gameObject_tileMap, TILE_WIDTH, TILE_HEIGHT,
	FILE_TILE_SET);
	TileMap *tileMap = new TileMap(*gameObject_tileMap, FILE_TILE_MAP, tileSet);
	gameObject_tileMap->box.x = 0;
	gameObject_tileMap->box.y = 0;
	gameObject_tileMap->AddComponent(tileMap);
	objectArray.emplace_back(gameObject_tileMap);

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
	music.Open(FILE_STAGE_STATE);
	music.Play();
}

/**
 * @brief Metodo que atualiza o estado do jogo, atualizando o estado dos objetos de jogo na tela
 *
 * @param dt valor Delta Time
 */
void State::Update(float dt) {

	int i, tamanhoObjectArray = objectArray.size() - 1;

	InputManager &inputManager = InputManager::GetInstance();
	quitRequested = inputManager.QuitRequested();

	Camera::Update(dt);

	Input();

	for (i = tamanhoObjectArray; i >= 0; i--) {
		objectArray[i]->Update(dt);
	}

	/** Verificando objetos de jogo no estado dead */
	for (i = tamanhoObjectArray; i >= 0; i--) {
		if (objectArray[i]->IsDead()) {
			Camera::Unfollow();
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
		objectArray[i]->Render();
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
	int i, tamanhoObjectArray = objectArray.size() - 1;
	InputManager &inputManager = InputManager::GetInstance();

	if (inputManager.KeyPress(LEFT_ARROW_KEY)
			|| inputManager.KeyPress(RIGHT_ARROW_KEY)
			|| inputManager.KeyPress(UP_ARROW_KEY)
			|| inputManager.KeyPress(DOWN_ARROW_KEY)) {
		Camera::Unfollow();
	}

	/** crie um objeto */
	if (inputManager.KeyPress(SPACE_KEY)) {
		Vec2 objPos = Vec2(inputManager.GetMouseX(), inputManager.GetMouseY());
		float distancia = 200;
		objPos.CalcularRotacaoAngulo(distancia);
		AddObject((int) objPos.x, (int) objPos.y);
	}

	if (inputManager.MousePress(LEFT_MOUSE_BUTTON)) {

		/** Percorrer de trás pra frente pra sempre clicar no objeto mais de cima */
		for (i = tamanhoObjectArray; i >= 0; i--) {

			int mouseX = inputManager.GetMouseX();
			int mouseY = inputManager.GetMouseY();

			if (objectArray[i]->box.Contains(mouseX, mouseY)) {

				Face *face = static_cast<Face*>(objectArray[i]->GetComponent(
						"Face"));
				if (face != nullptr) {
					if (!face->IsDead()) {
						/** Aplica dano */
						face->Damage(rand() % 10 + 10);
						Camera::Follow(objectArray[i].get());
						/** Sai do loop (só queremos acertar um) */
						break;
					}
				}

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
	Sprite *sprite = new Sprite(*gameObject, FILE_PENGUIN_FACE);
	Sound *sound = new Sound(*gameObject, FILE_BOOM);
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
