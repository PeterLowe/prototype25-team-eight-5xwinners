//author team_8 - [5xWinners]

#pragma once


// MAXIMUM VALUES
static const int MAX_RICHES = 9;
static const int MAX_TOOLS = 4;
static const int MAX_COVERS = 4;
static const int MAX_ROOMS = 6;
static const int MAX_METERS = 11;

//directions for sprite movement 
const int static LEFT = 1;
const int static RIGHT = 2;
const int static UP = 3;
const int static DOWN = 4;

//screen size
const int SCREEN_WIDTH = 1000U;
const int SCREEN_HEIGHT = 800U;


//METER CONSTS
const int SCARE = 0;

// Screens
static const int MAIN = 1;
static const int GAMEPLAY = 2;
static const int INVENTORY = 3;
static const int HELP = 4;
static const int SOUND = 5;
static const int CREDITS = 6;
static const int LOSING = 7;
static const int WINNING = 8;

#include <SFML/WINDOW.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/event.hpp>
// for uni library ^