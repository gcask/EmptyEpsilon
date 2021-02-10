#ifndef HOTKEY_CONFIG_H
#define HOTKEY_CONFIG_H

#include <tuple>
#include "SDL_events.h"
#include "stringImproved.h"

class JoystickConfig;

class HotkeyConfigItem
{
public:
    string key;
    std::tuple<string, string> value;
    SDL_Keysym hotkey;

    HotkeyConfigItem(string key, std::tuple<string, string>);

    void load(string key_config);
};

class HotkeyConfigCategory
{
public:
    string key;
    string name;
    std::vector<HotkeyConfigItem> hotkeys;
};

class HotkeyResult
{
public:
    HotkeyResult(string category, string hotkey) : category(category), hotkey(hotkey) {}

    string category;
    string hotkey;
};

class HotkeyConfig
{
public:
    HotkeyConfig();

    void load();
    std::vector<string> getCategories();
    std::vector<std::pair<string, string>> listHotkeysByCategory(string hotkey_category);
    std::vector<std::pair<string, string>> listAllHotkeysByCategory(string hotkey_category);

    std::vector<HotkeyResult> getHotkey(const SDL_Keysym& key);
    bool setHotkey(std::string work_cat, std::pair<string,string> key, string new_value);
    string getStringForKey(SDL_Scancode key);
    SDL_Scancode getKeyByHotkey(string hotkey_category, string hotkey_name);
private:
    std::vector<HotkeyConfigCategory> categories;

    void newCategory(string key, string name);
    void newKey(string key, std::tuple<string, string>);
friend class JoystickConfig;
};

extern HotkeyConfig hotkeys;

#endif//HOTKEY_CONFIG_H
