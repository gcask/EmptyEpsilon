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

    HotkeyConfigItem(const string& key, const std::tuple<string, string>&);

    void load(const string& key_config);
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
    static HotkeyConfig& get();

    void load();
    std::vector<string> getCategories() const;
    std::vector<std::pair<string, string>> listHotkeysByCategory(const string& hotkey_category) const;
    std::vector<std::pair<string, string>> listAllHotkeysByCategory(const string& hotkey_category) const;

    std::vector<HotkeyResult> getHotkey(const SDL_Keysym& key) const;
    bool setHotkey(const std::string& work_cat, const std::pair<string,string>& key, const string& new_value);
    string getStringForKey(SDL_Scancode key) const;
    SDL_Scancode getKeyByHotkey(const string& hotkey_category, const string& hotkey_name) const;
private:
    HotkeyConfig();
    std::vector<HotkeyConfigCategory> categories;

    void newCategory(const string& key, const string& name);
    void newKey(const string& key, const std::tuple<string, string>&);
friend class JoystickConfig;
};
#endif//HOTKEY_CONFIG_H
