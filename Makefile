#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# SO Linux Ubuntu
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Compilador
COMPILER = g++

# Comando para remover pastas
RMDIR = rm -rdf

# Comando para remover arquivos
RM = rm -f

# Flags para geração automática de dependências
DEP_FLAGS = -M -MT $@  -MT $(BIN_PATH)/$(*F).o -MP -MF $@

# Flags das bibliotecas SDL
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

# Paths includes
INC_PATHS = -I$(INC_PATH) $(addprefix -I,$(SDL_INC_PATHS))

# Diretivas de compilação
FLAGS = -std=c++11 -Wall -pedantic -Wextra -Wno-unused-parameter -Werror=init-self

# Diretivas extras para debug
DFLAGS = -ggdb -O0 -DDEBUG

# Diretivas extras para release
RFLAGS = -O3 -mtune=native

INC_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep

# Uma lista de arquivos por extensão:
CPP_FILES 	= $(wildcard $(SRC_PATH)/*.cpp)
INC_FILES 	= $(wildcard $(INC_PATH)/*.hpp)
FILE_NAMES 	= $(sort $(notdir $(CPP_FILES:.cpp=)) $(notdir $(INC_FILES:.hpp=)))
DEP_FILES	= $(addprefix $(DEP_PATH)/,$(addsufix	.d,$(FILE_NAMES)))
OBJ_FILES	= $(addprefix $(BIN_PATH)/,$(notdir	$(CPP_FILES:.cpp=.o)))

# Nome do executável
EXEC = game

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# SO Windows
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ifeq (($OS),Windows_NT)

# Comando para remover diretório
RMDIR = rd /s /q

# Ccomando para deletar arquivo
RM = del /q

#Possíveis paths da SDL. Caso seja possível ter mais de um local, adicione espaço entre eles
#Por exemplo.: SDL_PATHs = C:/SDL2 D:/Tools/SDL2 C:/dev-tools/SDL2s
SDL_PATH = C:/SDL2/x86_64-w64-mingw32 C:/msys64/mingw64

SDL_INC_PATH 	+= $(addsuffix /include,$(SDL_PATHS))
LINK_PATH 		= $(addprefix -L,$(addsufix /lib,$(SDL_PATHS)))
FLAGS 			+= -mwindows
DFLAGS 			+= -mconsole
LIBS 			:= -lmingw32 -lSDL2main $(LIBS)

#nome do executável
EXEC := $(EXEC).exe

else

UNAME_S := $(shell uname -s)

#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
# SO Mac
#-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ifeq ($(UNAME_S), Darwin)
LIBS = -lm -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf

endif
endif
################################################################################################################################################################################

.PRECIOUS: $(DEP_FILES)
.PHONY: release debug clean folders help

# Geral
all: $(EXEC)

# Gerar executável
$(EXEC):	$(OBJ_FILES)
	$(COMPILER) -o $@ $^ $(LINK_PATH) $(LIBS) $(FLAGS)

# Gerar arquivos objetos
$(BIN_PATH)/%.o:	$(DEP_PATH)/%.d	|	folders
	$(COMPILER) $(INC_PATHS) $(addprefix $(SRC_PATH)/,$(notdir $(<:.d=.cpp))) -c $(FLAGS) -o $@

# Gerar arquivos de dependência
$(DEP_PATH)/%.d: $(SRC_PATH)/%.cpp | folders
	$(COMPILER) $(INC_PATHS) $< $(DEP_FLAGS) $(FLAGS)

clean:
		-$(RMDIR) $(DEP_PATH)
		-$(RMDIR) $(BIN_PATH)
		-$(RM) $(EXEC)

release: FLAGS += $(RFLAFS)
release: $(EXEC)

debug: FLAGS += $(DFLAGS)
debug: $(EXEC)

folders:
ifeq ($(OS), Windows_NT)
	@if NOT exists $(DEP_PATH) (	mkdir $(DEP_PATH)	)
	@if NOT exists $(BIN_PATH) (	mkdir $(BIN_PATH)	)
	@if NOT exists $(INC_PATH) (	mkdir $(INC_PATH)	)
	@if NOT exists $(SRC_PATH) (	mkdir $(SRC_PATH)	)
else
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(INC_PATH) $(SRC_PATH)
endif

#Regra para debug
print-% : ; @echo $* = $($*)

help:
ifeq ($(OS), Windows_NT)
	@echo.
endif
	@echo Available targets:
	@echo - release:	Builds the release version
	@echo - debug:		Builds the debug version
	@echo - clean: 		Cleans the generated files
	@echo - folders:	Generates project directories
	@echo - help:			Shows this help
ifeq ($(OS), Windows_NT)
	@echo.
endif

.SECONDEXPANSION:
-include $$(DEP_FILES)
