#include "Menu_controller.h"

Menu_controller::Menu_controller()
{
}

//want to quit
void Menu_controller::wantToQuit()
{
	m_isQuit = true;
}

void Menu_controller::notWantToQuit()
{
	m_isQuit = false;
}

bool Menu_controller::needToQuit()
{
	return m_isQuit;
}

//main menu
void Menu_controller::openMenu()
{
	m_mainMenuVisible = true;
}

void Menu_controller::closeMenu()
{
	m_mainMenuVisible = false;
}

bool Menu_controller::needInMenu()
{
	return m_mainMenuVisible;
}

//help menu
void Menu_controller::openHelp()
{
	m_helpVisible = true;
}

void Menu_controller::closeHelp()
{
	m_helpVisible = false;
}

bool Menu_controller::needInHelp()
{
	return m_helpVisible;
}

//quit menu
void Menu_controller::openQuitMenu()
{
	m_quitVisible = true;
}

void Menu_controller::closeQuitMenu()
{
	m_quitVisible = false;
}

bool Menu_controller::needInQuitM()
{
	return m_quitVisible;
}

//doors openable::
void Menu_controller::allowedToOpenDoor()
{
	m_isOpenable = true;
}

void Menu_controller::notAllowedToOpenDoor()
{
	m_isOpenable = false;
}

bool Menu_controller::needToAllowedOpenDoor()
{
	return m_isOpenable;
}

//waiting window // sand glass picture
void Menu_controller::openWaitingWindow()
{
	m_isWaiting = true;
}

void Menu_controller::closeWaitingWindow()
{
	m_isWaiting = false;
}

bool Menu_controller::needToOpenWaitingWindow()
{
	return m_isWaiting;
}

//menu light on or off
void Menu_controller::turnOnMenuLight()
{
	m_menuLight = true;
}

void Menu_controller::turnOffMenuLight()
{
	m_menuLight = false;
}

bool Menu_controller::needToTurnOnMenuLi()
{
	return m_menuLight;
}

//light slider moving
void Menu_controller::lightSliderMoveUp()
{
	m_lightSliderPos++;
}

void Menu_controller::lightSliderMoveDown()
{
	m_lightSliderPos--;
}

int Menu_controller::lightSliderActualPos()
{
	return m_lightSliderPos;
}
