cmake_minimum_required(VERSION 3.10)
project(STG)

# C++のバージョン設定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# インクルードディレクトリ（-Iで追加される）
include_directories(include)

# SDL2を探してリンク
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# ソースファイルを再帰的に集める
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)


# 実行ファイル生成
add_executable(STG ${SOURCES})

# SDL2をリンク
target_link_libraries(STG ${SDL2_LIBRARIES})
