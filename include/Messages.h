/**
 * @file Messages.h
 * @author Luan Mendes Gonçalves Freitas - 150015585
 * @brief Cabecalho de mensagens de textos
 * @version 0.2
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

#define ERRO_INSTANCIA RED "Erro Instance nao instanciada" RESET

#define ERRO_INIT_SDL RED "Erro SDL nao inicializada: " RESET

#define ERRO_INIT_SDL_IMAGE RED "Erro SDL_Image nao inicializada: " RESET

#define ERRO_INIT_SDL_MIXER RED "Erro SDL_mixer nao inicializada: " RESET

#define ERRO_INIT_MIX_OPEN_AUDIO RED "Erro Mix_OpenAudio nao inicializada: " RESET

#define ERRO_INIT_MIX_ALLOCATE_CHANNELS RED "Erro Mix_AllocateChannels nao inicializada: " RESET

#define ERRO_INIT_WINDOW RED "Erro Window nao inicializada: " RESET

#define ERRO_INIT_RENDERER RED "Erro Renderer nao inicializada: " RESET

#define ERRO_INIT_TEXTURE RED "Erro Texture nao inicializada: " RESET

#define ERRO_INIT_QUERY_TEXTURE RED "Erro Query Texture nao inicializada: " RESET

#define ERRO_INIT_RENDER RED "Erro Render nao inicializada: " RESET

#define ERRO_INIT_MUSIC RED "Erro Music nao carregada: " RESET

#define ERRO_PLAY_MIX_PLAYCHANNEL RED "Erro de play som no Mix_PlayChannel: " RESET

#define ERRO_STOP_MIX_HALTCHANNEL RED "Erro de stop som no Mix_HaltChannel: " RESET

#define ERRO_OPEN_SOUND RED "Erro nao foi possivel abrir arquivo sound Mix_LoadWAV: " RESET


#endif /* MESSAGES_H_ */
