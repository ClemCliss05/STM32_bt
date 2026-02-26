cmake_minimum_required(VERSION 3.22)

# Indique que ce n’est pas un projet PC
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-m0)

project(STM32_bt C CXX ASM)

# Standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# Désactivation features inutiles
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Flags CPU STM32F072
set(MCU_FLAGS
    -mcpu=cortex-m0
    -mthumb
)

add_executable(${PROJECT_NAME}
    app/main.cpp
)

# Linker script: Empêcher la libc de s’initialiser inutilement
target_link_options(${PROJECT_NAME} PRIVATE
    -nostartfiles
    -nostdlib
)

# Include directories
target_compile_options(${PROJECT_NAME} PRIVATE
    ${MCU_FLAGS}
    -Wall
    -Wextra
    -Wpedantic
    -Os
    -ffunction-sections
    -fdata-sections
    -fno-exceptions
    -fno-rtti
)

# Linker options
target_link_options(${PROJECT_NAME} PRIVATE
    ${MCU_FLAGS}
    -Wl,--gc-sections
)