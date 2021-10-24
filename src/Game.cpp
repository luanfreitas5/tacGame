/**
 * @file Game.cpp
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Modulo dos metodos da classe Game
 * @version 0.5
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Game.h"
#include "../include/Resources.h"

/**
 * @brief Construtor da Classe Game.
 * Inicializa as funcionalidades basicas do SDL e seus auxiliares
 *
 * @param title Titulo do Jogo na tela de jogo (Nome - Matricula)
 * @param width Tamanho da largura da tela de jogo
 * @param height Tamanho da altura da tela de jogo
 */
Game::Game(string title, int width, int height) {

	if (instance != nullptr) {
		cout << ERRO_INSTANCIA << SDL_GetError() << endl;
		exit(0);

	} else {
		instance = this;

		int sdlInit = SDL_Init(
		SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);

		int imgInit = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

		int mixInit = Mix_Init(
				MIX_INIT_FLAC | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_MP3
						| MIX_INIT_MOD | MIX_INIT_OPUS);

		int mixOpenAudio = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
		MIX_DEFAULT_FORMAT,
		MIX_DEFAULT_CHANNELS, MIX_CHUNKSIZE);

		int mixAllocateChannels = Mix_AllocateChannels(MIX_CHANNEL);

		if (sdlInit != 0) {
			cout << ERRO_INIT_SDL << SDL_GetError() << endl;
			exit(0);

		} else if (imgInit == 0) {
			cout << ERRO_INIT_SDL_IMAGE << SDL_GetError() << endl;
			exit(0);

		} else if (mixInit == 0) {
			cout << ERRO_INIT_SDL_MIXER << SDL_GetError() << endl;
			exit(0);

		} else if (mixOpenAudio != 0) {
			cout << ERRO_INIT_MIX_OPEN_AUDIO << SDL_GetError() << endl;
			exit(0);

		} else if (mixAllocateChannels == 0) {
			cout << ERRO_INIT_MIX_ALLOCATE_CHANNELS << SDL_GetError() << endl;
			exit(0);

		} else {
			window = SDL_CreateWindow(title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, width, height, 0);

			renderer = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE
							| SDL_RENDERER_PRESENTVSYNC);

			if (window == nullptr) {
				cout << ERRO_INIT_WINDOW << SDL_GetError() << endl;
				exit(0);

			} else if (renderer == nullptr) {
				cout << ERRO_INIT_RENDERER << SDL_GetError() << endl;
				exit(0);

			} else {
				state = new State();
				frameStart = 0;
				dt = 0;
			}
		}
	}
}

/**
 * @brief Destrutor da Classe Game
 *
 */
Game::~Game() {
	delete state;

	Resources::ClearImages();
	Resources::ClearMusics();
	Resources::ClearSounds();

	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

/**
 * @brief Obtem um objeto Instance
 *
 * @return Game& um ponteiro para a inst�ncia �nica da classe Game
 */
Game& Game::GetInstance() {
	if (instance != nullptr) {
		return *instance;
	} else {
		instance = new Game(TITLE, WIDTH, HEIGHT);
		return *instance;
	}
}

/**
 * @brief Obtem um objeto Renderer
 *
 * @return SDL_Renderer* ponteiro para o renderizador SDL do jogo
 */
SDL_Renderer* Game::GetRenderer() {
	return renderer;
}

/**
 * @brief Obtem um objeto State
 *
 * @return State& uma referencia ao estado atual do jogo
 */
State& Game::GetState() {
	return *state;
}

/**
 * @brief Metodo para calcular intervalos de tempo
 *
 */
void Game::CalculateDeltaTime() {

	dt = SDL_GetTicks() - frameStart;
	frameStart = frameStart + dt;

}

/**
 * @brief Get um valor Delta Time
 *
 * @return float valor Delta Time
 */
float Game::GetDeltaTime() {

	return dt / 1000;

}

/**
 * @brief Metodo que inicia o loop do jogo,
 * controlando a tela, recebendo dados de entrada, atualizando estados e
 * desenhando objeto na tela.
 *
 */
void Game::Run() {

	state->Start();

	InputManager &inputManager = InputManager::GetInstance();

	/** Inicando o loop do jogo com suas funcionalidades */
	while (state->QuitRequested() == false) {
		GetInstance().state->Update(0);

		CalculateDeltaTime();
		inputManager.Update();

		if (SDL_RenderClear(renderer) != 0) {
			cout << ERRO_CLEAR_RENDERER << SDL_GetError() << endl;
			exit(0);
		}

		GetInstance().state->Update(GetDeltaTime());

		GetInstance().state->Render();
		SDL_RenderPresent(GetInstance().renderer);
		SDL_Delay(33);
	}

}
