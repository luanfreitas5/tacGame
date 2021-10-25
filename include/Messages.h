/**
 * @file Messages.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho de mensagens de textos
 * @version 0.4
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MESSAGES_H_
#define MESSAGES_H_

#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define MAGENTA	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define WHITE	"\x1B[37m"
#define RESET	"\x1B[0m"

/** Game **/

#define ERRO_INSTANCIA RED "Erro Instance nao instanciada" RESET

#define ERRO_INIT_SDL RED "Erro SDL nao inicializada: " RESET

#define ERRO_INIT_SDL_IMAGE RED "Erro SDL_Image nao inicializada: " RESET

#define ERRO_INIT_SDL_MIXER RED "Erro SDL_mixer nao inicializada: " RESET

#define ERRO_INIT_MIX_OPEN_AUDIO RED "Erro Mix_OpenAudio nao inicializada: " RESET

#define ERRO_INIT_MIX_ALLOCATE_CHANNELS RED "Erro Mix_AllocateChannels nao inicializada: " RESET

#define ERRO_INIT_WINDOW RED "Erro Window nao inicializada: " RESET

#define ERRO_INIT_RENDERER RED "Erro Renderer nao inicializada: " RESET

#define ERRO_CLEAR_RENDERER RED "Erro Renderer nao limpa: " RESET

/** Sprite **/

#define ERRO_INIT_TEXTURE RED "Erro Texture nao inicializada: " RESET

#define ERRO_INIT_QUERY_TEXTURE RED "Erro Query Texture nao inicializada: " RESET

#define ERRO_INIT_RENDER RED "Erro Render nao inicializada: " RESET

/** Resources **/

#define ERRO_OPEN_FILE_MUSIC RED "Erro nao foi possivel abrir arquivo music Mix_LoadMUS: " RESET

#define ERRO_OPEN_FILE_SOUND RED "Erro nao foi possivel abrir arquivo sound Mix_LoadWAV: " RESET

#define ERRO_OPEN_FILE_IMAGE RED "Erro nao foi possivel abrir arquivo image IMG_LoadTexture: " RESET

#define ERRO_LOAD_FILE_TILEMAP RED "Erro nao foi possivel abrir arquivo tileMap IMG_LoadTexture: " RESET

/** Music **/

#define ERRO_PLAY_MUSIC RED "Erro de play musica music NULL: " RESET

#define ERRO_STOP_MUSIC RED "Erro de stop musica music NULL: " RESET

#define ERRO_PLAY_MIX_PLAYMUSIC RED "Erro de play musica no Mix_FadeOutMusic: " RESET

#define ERRO_STOP_MIX_FADEOUTMUSIC RED "Erro de stop musica no Mix_FadeOutMusic: " RESET

/** Sound **/

#define ERRO_PLAY_SOUND RED "Erro de play som chunk NULL: " RESET

#define ERRO_STOP_SOUND RED "Erro de stop som chunk NULL: " RESET

#define ERRO_PLAY_MIX_PLAYCHANNEL RED "Erro de play som no Mix_PlayChannel: " RESET

#define ERRO_STOP_MIX_HALTCHANNEL RED "Erro de stop som no Mix_HaltChannel: " RESET

/** Action **/

#define ERRO_ACTION RED "Erro Action Invalido: " RESET

#endif /* MESSAGES_H_ */
