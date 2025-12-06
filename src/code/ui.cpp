#include <ui.hpp>

std::unordered_map<std::string, std::vector<float>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"text_start", {180, 180}},
    {"button_collection", {160, 240, 960, 80}},
    {"text_collection", {180, 260}},
    {"button_erase", {160, 320, 960, 80}},
    {"text_erase", {180, 340}},
    {"button_quit", {160, 400, 960, 80}},
    {"text_quit", {180, 420}},
    {"arrow", {80, 160, 80, 240, 80, 320, 80, 400}}
};

std::unordered_map<std::string, std::vector<float>> UI::UIField = {
    {"button_menu", {1180, 20, 80, 80}},
};

std::unordered_map<std::string, std::vector<float>> UI::UIBattle = {

};

std::unordered_map<std::string, std::vector<float>> UI::UIMenuField = {
    {"rect", {320, 200, 640, 320}},
    {"text_paused", {340, 220}},
    {"button_resume", {320, 280, 640, 80}},
    {"text_resume", {340, 300}},
    {"button_exit", {320, 360, 640, 80}},
    {"text_exit", {340, 380}},
    {"button_quit", {320, 440, 640, 80}},
    {"text_quit", {340, 460}},
    {"arrow", {240, 280, 240, 360, 240, 440}}
};

std::unordered_map<std::string, std::vector<float>> UI::UIMenuBattle = {

};
