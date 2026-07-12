CXX ?= g++
TARGET := gameDev

SRCS := main.cpp \
        includes/game.render.cpp \
        includes/game.logic.cpp \
        includes/game.structures.cpp

BUILD_DIR := build
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.cpp=.o))

RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib 2>/dev/null)
RAYLIB_LIBS := $(shell pkg-config --libs raylib 2>/dev/null)

ifeq ($(strip $(RAYLIB_LIBS)),)
RAYLIB_LIBS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2 $(RAYLIB_CFLAGS)
LDLIBS ?= $(RAYLIB_LIBS)

.PHONY: all clean run
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)
