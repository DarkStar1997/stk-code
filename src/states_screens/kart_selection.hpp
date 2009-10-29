//  $Id: font.cpp 3625 2009-06-21 01:10:43Z auria $
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include <string>
#include "guiengine/screen.hpp"

namespace GUIEngine
{
    class Widget;
}
class InputDevice;
class ActivePlayer;

class KartSelectionScreen : public GUIEngine::Screen, public GUIEngine::ScreenSingleton<KartSelectionScreen>
{
    friend class GUIEngine::ScreenSingleton<KartSelectionScreen>;
    KartSelectionScreen();
    
    /** Called when all players selected their kart */
    void allPlayersDone();
    
    /** Called when number/order of karts changed, so that all will keep an up-to-date ID */
    void renumberKarts();

    /** Checks identities chosen by players, making sure no duplicates are used.
        \return Whether all choices are ok */
    bool validateIdentChoices();
    
public:
    
    /** Called when a player hits 'fire' on his device to join the game */
    bool playerJoin(InputDevice* device, bool firstPlayer);
    
    /** Called when a player hits 'rescue' on his device to leave the game */
    bool playerQuit(ActivePlayer* player);
    
    /** Standard 'Screen' callback before screen is entered */
    void init();
    
    /** Standard 'Screen' callback before screen is left */
    void tearDown();
    
    /** Standard 'Screen' callback when an event occurs*/
    void eventCallback(GUIEngine::Widget* widget, const std::string& name, const int playerID);
    
    /** Standard 'Screen' callback every frame */
    void onUpdate(float dt, irr::video::IVideoDriver*);
};
