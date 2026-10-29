# Um arquivo que compila o codigo C.
# Segue o padrao da linguage
TARGET   	:= programa
CC 		 	:= gcc
PROJDIRS    := src
INCLUDEDIR  := include # inclui o diretorio dos headers
CFLAGS 	 	:= -std=c23 -g $(WARNINGS) -MMD -MP -I $(INCLUDEDIR)
SRCFILES 	:= $(shell find $(PROJDIRS) -type f -name "*.c") # encontra todo o codigo c
OBJFILES 	:= $(patsubst %.c,%.o,$(SRCFILES))

all: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBS) -o $(TARGET)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

compdb: # regra pra o editor de codigo poder ajudar
	bear --output compile_commands.json -- $(MAKE) clean all

clean:
	-@$(RM) $(wildcard $(OBJFILES) $(TARGET) compile_commands.json)

.PHONY: all clean compdb
