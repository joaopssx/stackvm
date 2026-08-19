CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -MMD -MP
LDFLAGS :=

BUILD := build
TARGET := $(BUILD)/stackvm.exe

SRCS := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)
OBJS := $(SRCS:src/%.cpp=$(BUILD)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

$(BUILD)/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

release: CXXFLAGS += -O2 -DNDEBUG
release: all

debug: CXXFLAGS += -O0 -g
debug: all

clean:
	rm -rf $(BUILD)

-include $(DEPS)

.PHONY: all release debug clean
