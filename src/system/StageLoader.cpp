#include "system/StageLoader.hpp"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::vector<EnemySpawnData> StageLoader::loadFromJson(const std::string &filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open stage file: " + filepath);
    }

    json j;
    file >> j;

    std::vector<EnemySpawnData> result;
    for (const auto &item : j)
    {
        result.emplace_back(
            item["time"],
            item["x"],
            item["y"],
            item["type"],
            item["hp"]);
    }

    return result;
}