#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32f429i_discovery_gyroscope.h"

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateGyroinfo()
{
	float valXYZ[3];
	BSP_GYRO_GetXYZ(valXYZ);
	Unicode::UnicodeChar tmp1[40];
	Unicode::snprintfFloat(tmp1, 40, "%f", valXYZ[0]);
	xAxysText.setWildcard(tmp1);
	xAxysText.invalidate();
	Unicode::UnicodeChar tmp2[40];
	Unicode::snprintfFloat(tmp2, 40, "%f", valXYZ[1]);
	yAxysText.setWildcard(tmp2);
	yAxysText.invalidate();
	Unicode::UnicodeChar tmp3[40];
	Unicode::snprintfFloat(tmp3, 40, "%f", valXYZ[2]);
	zAxysText.setWildcard(tmp3);
	zAxysText.invalidate();
}
