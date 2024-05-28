#ifndef ICON_H
#define ICON_H

#include"string"

class Icon
{
public:
    Icon();

    //
    int index;
    std::string iconPath = "";
    std::string exePath = "";
    std::string args = "";
};

#endif // ICON_H
