#pragma once
#include <general.hpp>

class UI {
    public:
        static std::unordered_map<std::string, std::vector<float>> UITitle;
        static std::unordered_map<std::string, std::vector<float>> UIField;
        static std::unordered_map<std::string, std::vector<float>> UIBattle;
        static std::unordered_map<std::string, std::vector<float>> UIMenuField;
        static std::unordered_map<std::string, std::vector<float>> UIMenuBattle;
};
