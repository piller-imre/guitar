#pragma once
class Menu_controller
{
private:
	bool m_isQuit;
	bool m_mainMenuVisible;
	bool m_helpVisible;
	bool m_quitVisible;
	bool m_isOpenable;
	bool m_isWaiting;
	bool m_menuLight;
	int m_lightSliderPos = 0;


public:
	Menu_controller();

	void wantToQuit();
	void notWantToQuit();
	bool needToQuit();

	void openMenu();
	void closeMenu();
	bool needInMenu();

	void openHelp();
	void closeHelp();
	bool needInHelp();

	void openQuitMenu();
	void closeQuitMenu();
	bool needInQuitM();

	void allowedToOpenDoor();
	void notAllowedToOpenDoor();
	bool needToAllowedOpenDoor();

	void openWaitingWindow();
	void closeWaitingWindow();
	bool needToOpenWaitingWindow();

	void turnOnMenuLight();
	void turnOffMenuLight();
	bool needToTurnOnMenuLi();

	void lightSliderMoveUp();
	void lightSliderMoveDown();
	int lightSliderActualPos();

};

