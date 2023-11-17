#pragma once

#include <string>

//selector configuration
#define HUE 240
#define DEFAULT 1 // Red Alliance Side
#define AUTONS "Alliance Side", "Opponent Side", "Skills"

namespace selector{

extern int auton;
const char *b[] = {AUTONS, ""};
void init(int hue = HUE, int default_auton = DEFAULT, const char **autons = b);

}
