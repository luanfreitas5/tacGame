/**
 * @file State.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe State
 * @version 0.5
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

	GameObject *gameObject_alien = new GameObject();
	Alien *alien = new Alien(*gameObject_alien, 8);
	gameObject_alien->AddComponent(alien);
	gameObject_alien->box.x = 512 - gameObject_alien->box.w / 2;
	gameObject_alien->box.y = 300 - gameObject_alien->box.h / 2;
	AddObject(gameObject_alien);

	quitRequested = false;
	started = false;
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

	//Input();

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
 * @brief Metodo para adicionar objeto de jogo (pinguim) na tela de Jogo.
 *
 * @param mouseX coordenada horizontal do retangulo
 * @param mouseY coordenada vertical do retangulo
 */
weak_ptr<GameObject> State::AddObject(GameObject *go) {

	/* Instantiates the object. */
	shared_ptr<GameObject> pointer = shared_ptr<GameObject>(go);

	/* Placing this new object in the object vector. */
	objectArray.push_back(pointer);

	if (started) {
		pointer->Start();
	}

	return pointer;

}

weak_ptr<GameObject> State::GetObjectPtr(GameObject *go) {

	int i, tamanhoObjectArray = objectArray.size();
	for (i = 0; i < tamanhoObjectArray; i++) {
		if (objectArray[i].get() == go) {
			return objectArray[i];
		}
	}
	return weak_ptr<GameObject>();

}

void State::Start() {

	/** Carregando os assests */
	LoadAssets();

	int i, tamanhoObjectArray = objectArray.size();
	for (i = 0; i < tamanhoObjectArray; i++) {
		objectArray[i]->Start();
	}
	started = true;

}
