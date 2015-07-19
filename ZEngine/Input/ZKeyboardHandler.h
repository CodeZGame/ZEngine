//-----------------------------------------------------------
// ZKeyboardHandler.h
//-----------------------------------------------------------

#pragma once

#include <SFML\Window\Keyboard.hpp>

namespace ZEngine
{
	//Currently have to corresponds exactly to SFML enum sf::Keyboard::Key
	enum ZInputKey
	{
		e_InputKey_Unknown = -1, ///< Unhandled key
		e_InputKey_A = 0,        ///< The A key
		e_InputKey_B,            ///< The B key
		e_InputKey_C,            ///< The C key
		e_InputKey_D,            ///< The D key
		e_InputKey_E,            ///< The E key
		e_InputKey_F,            ///< The F key
		e_InputKey_G,            ///< The G key
		e_InputKey_H,            ///< The H key
		e_InputKey_I,            ///< The I key
		e_InputKey_J,            ///< The J key
		e_InputKey_K,            ///< The K key
		e_InputKey_L,            ///< The L key
		e_InputKey_M,            ///< The M key
		e_InputKey_N,            ///< The N key
		e_InputKey_O,            ///< The O key
		e_InputKey_P,            ///< The P key
		e_InputKey_Q,            ///< The Q key
		e_InputKey_R,            ///< The R key
		e_InputKey_S,            ///< The S key
		e_InputKey_T,            ///< The T key
		e_InputKey_U,            ///< The U key
		e_InputKey_V,            ///< The V key
		e_InputKey_W,            ///< The W key
		e_InputKey_X,            ///< The X key
		e_InputKey_Y,            ///< The Y key
		e_InputKey_Z,            ///< The Z key
		e_InputKey_Num0,         ///< The 0 key
		e_InputKey_Num1,         ///< The 1 key
		e_InputKey_Num2,         ///< The 2 key
		e_InputKey_Num3,         ///< The 3 key
		e_InputKey_Num4,         ///< The 4 key
		e_InputKey_Num5,         ///< The 5 key
		e_InputKey_Num6,         ///< The 6 key
		e_InputKey_Num7,         ///< The 7 key
		e_InputKey_Num8,         ///< The 8 key
		e_InputKey_Num9,         ///< The 9 key
		e_InputKey_Escape,       ///< The Escape key
		e_InputKey_LControl,     ///< The left Control key
		e_InputKey_LShift,       ///< The left Shift key
		e_InputKey_LAlt,         ///< The left Alt key
		e_InputKey_LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
		e_InputKey_RControl,     ///< The right Control key
		e_InputKey_RShift,       ///< The right Shift key
		e_InputKey_RAlt,         ///< The right Alt key
		e_InputKey_RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
		e_InputKey_Menu,         ///< The Menu key
		e_InputKey_LBracket,     ///< The [ key
		e_InputKey_RBracket,     ///< The ] key
		e_InputKey_SemiColon,    ///< The ; key
		e_InputKey_Comma,        ///< The , key
		e_InputKey_Period,       ///< The . key
		e_InputKey_Quote,        ///< The ' key
		e_InputKey_Slash,        ///< The / key
		e_InputKey_BackSlash,    ///< The \ key
		e_InputKey_Tilde,        ///< The ~ key
		e_InputKey_Equal,        ///< The = key
		e_InputKey_Dash,         ///< The - key
		e_InputKey_Space,        ///< The Space key
		e_InputKey_Return,       ///< The Return key
		e_InputKey_BackSpace,    ///< The Backspace key
		e_InputKey_Tab,          ///< The Tabulation key
		e_InputKey_PageUp,       ///< The Page up key
		e_InputKey_PageDown,     ///< The Page down key
		e_InputKey_End,          ///< The End key
		e_InputKey_Home,         ///< The Home key
		e_InputKey_Insert,       ///< The Insert key
		e_InputKey_Delete,       ///< The Delete key
		e_InputKey_Add,          ///< The + key
		e_InputKey_Subtract,     ///< The - key
		e_InputKey_Multiply,     ///< The * key
		e_InputKey_Divide,       ///< The / key
		e_InputKey_Left,         ///< Left arrow
		e_InputKey_Right,        ///< Right arrow
		e_InputKey_Up,           ///< Up arrow
		e_InputKey_Down,         ///< Down arrow
		e_InputKey_Numpad0,      ///< The numpad 0 key
		e_InputKey_Numpad1,      ///< The numpad 1 key
		e_InputKey_Numpad2,      ///< The numpad 2 key
		e_InputKey_Numpad3,      ///< The numpad 3 key
		e_InputKey_Numpad4,      ///< The numpad 4 key
		e_InputKey_Numpad5,      ///< The numpad 5 key
		e_InputKey_Numpad6,      ///< The numpad 6 key
		e_InputKey_Numpad7,      ///< The numpad 7 key
		e_InputKey_Numpad8,      ///< The numpad 8 key
		e_InputKey_Numpad9,      ///< The numpad 9 key
		e_InputKey_F1,           ///< The F1 key
		e_InputKey_F2,           ///< The F2 key
		e_InputKey_F3,           ///< The F3 key
		e_InputKey_F4,           ///< The F4 key
		e_InputKey_F5,           ///< The F5 key
		e_InputKey_F6,           ///< The F6 key
		e_InputKey_F7,           ///< The F7 key
		e_InputKey_F8,           ///< The F8 key
		e_InputKey_F9,           ///< The F9 key
		e_InputKey_F10,          ///< The F10 key
		e_InputKey_F11,          ///< The F11 key
		e_InputKey_F12,          ///< The F12 key
		e_InputKey_F13,          ///< The F13 key
		e_InputKey_F14,          ///< The F14 key
		e_InputKey_F15,          ///< The F15 key
		e_InputKey_Pause,        ///< The Pause key

		e_InputKey_KeyCount      ///< Keep last -- the total number of keyboard keys
	};

	class CZKeyboardHandler
	{
	protected:
		static bool ms_bKeyCurrentStates[e_InputKey_KeyCount];			//Is button pressed ?
		static bool ms_bKeyFirstStates[e_InputKey_KeyCount];			//Is first press on button ?
		static bool ms_bKeyReleasedStates[e_InputKey_KeyCount];			// Has button been released after being pressed ?

		CZKeyboardHandler();

		static void UpdateKeyboardInput();

	public:
		~CZKeyboardHandler();

		static bool IsKeyPressed(ZInputKey p_eKey);
		static bool IsKeyFirstPressed(ZInputKey p_eKey);
		static bool IsKeyReleased(ZInputKey p_eKey);

		//ONLY CALL THIS WHEN OVERRIDING THE MAIN LOOP
		//CALL THIS ON THE MAIN LOOP BEFORE THE GENERAL UPDATE
		static void UpdateKeyboardInputOnExternalLoop();
		
		friend class CZStarter;
	};
}