# Compiler
CC = gcc

# Directories
INCLUDE_DIR = src/Include
LIB_DIR = src/lib

# Output
TARGET = 2048

# Source files
SRC_FILES = $(LIB_DIR)/main.c \
            $(LIB_DIR)/global.c \
            $(LIB_DIR)/logic.c \
            $(LIB_DIR)/draw.c \
            $(LIB_DIR)/mods.c \
            $(LIB_DIR)/init.c

# Compiler flags
CFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR)
LIBS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

# Build target
all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRC_FILES) $(LIBS)

# Clean target
clean:
	rm -f $(TARGET)