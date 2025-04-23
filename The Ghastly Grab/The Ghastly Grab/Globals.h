//author team_8 - [5xWinners]

#pragma once


// MAXIMUM VALUES
static const int MAX_RICHES = 9;
static const int MAX_TOOLS = 4;
static const int MAX_COVERS = 4;
//static const int MAX_ROOMS = 9;
static const int MAX_METERS = 11;

//directions for sprite movement 
const int static LEFT = 1;
const int static RIGHT = 2;
const int static UP = 3;
const int static DOWN = 4;

//screen size
const int SCREEN_WIDTH = 1000U;
const int SCREEN_HEIGHT = 800U;


// Value for player sprite movement calculation
const int PLAYER_WIDTH = 84;	// Width of player sprite
const int PLAYER_HEIGHT = 217;	// Height of player sprite

const int LEFT_TO_LEG = 19.6f;	// Distance of leg from left boundary of sprite
const int UP_TO_LEG = 205.1f;	// Distance of Leg from up boundary of sprite

const float LEG_WIDTH = 44.8;		// Width of leg of sprite
const float LEG_HEIGHT = 11.9f;		// Height of Leg of sprite
// *Current values are based on temp sprite*

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


// Static for gameplay rooms
static const int OUTSIDE = 0;
static const int HALLWAY_LEFT = 1;
static const int HALLWAY_RIGHT = 2;
static const int KITCHEN = 3;
static const int BEDROOM_LEFT = 4;
static const int BEDROOM_RIGHT = 5;
static const int BATHROOM = 6;
static const int GREENHOUSE = 7;
static const int LIVING = 8;



#include <SFML/WINDOW.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/event.hpp>
// for uni library ^