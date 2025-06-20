cmake_minimum_required(VERSION 3.10)
project(STG)

set(CMAKE_CXX_STANDARD 17)

# SDL2 を探す
find_package(SDL2 REQUIRED)

# ソースコードをすべて収集
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 実行ファイルターゲットを作成
add_executable(${PROJECT_NAME} ${SOURCES})

# インクルードパスの設定
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/third_party/json
)

# SDL2ライブラリをリンク
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${SDL2_LIBRARIES}
)
