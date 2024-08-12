# 定义变量
BUILD_DIR := makebuild # 构建目录
CMAKE_BUILD_TYPE := Release # 构建类型，可以是 Release 或 Debug

# 默认目标
all: build

# 构建目标，调用CMake进行构建
build:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) -Wno-dev ..
	@cd $(BUILD_DIR) && $(MAKE) -j($nproc)

# 运行目标，运行生成的可执行文件
run:
	@cd $(BUILD_DIR) && ./zmxcc /dev/stdin -o /dev/null

# 清理目标
clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all build run clean
