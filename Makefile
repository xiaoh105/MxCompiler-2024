# 定义变量
BUILD_DIR := makebuild
CMAKE_BUILD_TYPE := Release

# 默认目标
all: build

build:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) -Wno-dev ..
	@cd $(BUILD_DIR) && $(MAKE) -j$(nproc)

run:
	@cd $(BUILD_DIR) && ./MxCompiler

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all build run clean
