#ifndef _SCREEN_HPP
#define _SCREEN_HPP

#include <sstream>
#include <string>
#include <iostream>

#define BTN_DOWN 2
#define BTN_UP 3

#define BTN_LEFT 4
#define BTN_RIGHT 5

#ifndef LINUX
#define BTN_RETURN 13
#else
#define BTN_RETURN 10
#endif

#define _CRT_SECURE_NO_WARNINGS


#ifndef LINUX
// Windows Borders
#define TL_CORNER 201
#define TR_CORNER 187
#define BL_CORNER 200
#define BR_CORNER 188
#define D_TTHINGY 203
#define U_TTHINGY 202
#define R_TTHINGY 204
#define L_TTHINGY 185
#define H_DOUBLEL 205
#define V_DOUBLEL 186
#define D_CROSS   206
#else
// Linux Borders
#define TL_CORNER '+'
#define TR_CORNER '+'
#define BL_CORNER '+'
#define BR_CORNER '+'
#define D_TTHINGY '+'
#define U_TTHINGY '+'
#define R_TTHINGY '+'
#define L_TTHINGY '+'
#define H_DOUBLEL '-'
#define V_DOUBLEL '|'
#define D_CROSS   '+'
#endif

using namespace std;

class GameSymbol {
private:
   int val;

public:
   GameSymbol(float val);
   operator char();
};

class Screen {
protected:
   void* _this_window;
   Screen(void);
   ~Screen(void);
   void printw(string val, bool refresh);

public:
   Screen(int height, int width, int x, int y);

   char handle_input(void);

   Screen& operator<<(string val);
   Screen& operator<<(int val);

   void Refresh(void);
   void Clear(void);
};


class BattleScreen: public Screen {
private:
   static const int offset_x;
   static const int offset_y;
   void DrawTable(void);
   void put_game_symbol(char val);
public:
   BattleScreen(int x, int y);
   void Init(void);
   void PutC(char val, int x, int y);
};

class MainScreen: public Screen {
private:
   BattleScreen *mytable;
   BattleScreen *enemytable;
   Screen *statusscreen;

   static MainScreen* INSTANCE;
   MainScreen();
public:

   BattleScreen& GetMyTable(void);
   BattleScreen& GetEnemyTable(void);
   Screen& GetStatusScreen(void);

   static MainScreen& GetInstance(void);

   ~MainScreen();
};


#endif