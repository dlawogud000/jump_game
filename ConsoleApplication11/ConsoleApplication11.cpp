#include<stdio.h>
#include<bangtal.h>

ObjectID star, moon1, moon2, moon3, moon4, moon5;
ObjectID  b1_1, b1_2, b1_3, b1_4, b2_1, b2_2, b2_3, b2_4, b2_5;
ObjectID eb2_1, eb2_2, eb2_3, eb2_4, eb2_5, eb2_6, eb2_7, eb2_8;
ObjectID b3_1, b3_2, b3_3, mj3_1, mj3_2, eb3_1, eb3_2;
ObjectID b4_1, b4_2, b4_3, b4_4, b4_5, sw4_1, sw4_2;
ObjectID b5_1, b5_2, b5_3, b5_4, mj5_1, mj5_2, eb5_1, eb5_2, eb5_3, eb5_4, sw5_1, sw5_2, sw5_3, sw5_4;
SceneID map1, map2, map3, map4, map5, map6;
TimerID timer1, timer2;
float starX = 101, starY = 151;
int map_status = 1;
float a = 0, b = 0, c = 0, d = 0, e = 0;
bool l_move = false, r_move = false, jump = false, landed = true, morejump = false, sw_status = false;
int stariX[5] = { 101, 151, 201, 501, 201 }, stariY[5] = { 151, 701, 251, 201, 250 }; 
int moonX[5] = { 1190, 350, 1100, 900, 1000 }, moonY[5] = { 510, 150, 350, 650, 250 }; 
int b1X[4] = {100, 410, 720, 1030}, b1Y[4] = {100, 220, 340, 460};
int b2X[5] = { 100, 500, 900, 600, 200 }, b2Y[5] = {550, 450, 300, 200, 100};
int eb2X[8] = { 300, 350, 400, 450, 700, 1000, 700, 50 }, eb2Y[8] = {450, 450, 450, 450, 500, 350, 250, 550 };
int b3X[3] = { 100, 500, 1000 }, b3Y[3] = { 200, 440, 300 }, mj3X[2] = { 400, 850 }, mj3Y[2] = { 370, 220 }, eb3X[2] = { 900, 900 }, eb3Y[2] = { 450, 500 };
int b4X[5] = { 500, 200, 700, 900, 800 }, b4Y[5] = { 150, 300, 300, 450, 600 }, sw4X[2] = { 300, 300 }, sw4Y[2] = { 350, 350 };
int b5X[4] = { 100, 350, 800, 900 }, b5Y[4] = { 200, 550, 450, 200 }, mj5X[2] = { 350, 250 }, mj5Y[2] = { 370, 480 };
int eb5X[4] = { 900, 950, 1000, 1050 }, eb5Y[4] = { 300, 300, 300, 300 }, sw5X[2] = { 100, 950 }, sw5Y[2] = { 250, 500 };

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown)
{
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) showObject(object);
	return object;
}

void sw_action()
{
	if (map_status == 4)
	{
		if (c == 0)
		{
			if (sw4X[0] - 60 < starX && starX < sw4X[0] + 50 && sw4Y[0] - 50 < starY && starY < sw4Y[0] + 50)
			{
				if (sw_status == false)
				{
					setSceneLight(map4, 0.5f);
					showObject(b4_4);
					showObject(sw4_2);
					hideObject(sw4_1);
					sw_status = true;
					c = 1;
				}
			    else if (sw_status == true)
				{
					setSceneLight(map4, 1.0f);
					hideObject(b4_4);
					showObject(sw4_1);
					hideObject(sw4_2);
					sw_status = false;
					c = 1;
				}
			}
		}
	}
	if (map_status == 5)
	{
		if (d == 0)
		{
			if (sw5X[0] - 60 < starX && starX < sw5X[0] + 50 && sw5Y[0] - 50 < starY && starY < sw5Y[0] + 50)
			{
				if (sw_status == false)
				{
					setSceneLight(map5, 0.5f);
					hideObject(mj5_2);
					hideObject(eb5_1);
					hideObject(eb5_2);
					hideObject(eb5_3);
					hideObject(eb5_4);
					showObject(sw5_2);
					hideObject(sw5_1);
					showObject(sw5_3);
					hideObject(sw5_4);
					sw_status = true;
					d = 1;
				}
				else if (sw_status == true)
				{
					setSceneLight(map5, 1.0f);
					showObject(mj5_2);
					showObject(eb5_1);
					showObject(eb5_2);
					showObject(eb5_3);
					showObject(eb5_4);
					showObject(sw5_1);
					hideObject(sw5_2);
					showObject(sw5_3);
					hideObject(sw5_4);
					sw_status = false;
					d = 1;
				}
			}
			else if (sw5X[1] - 60 < starX && starX < sw5X[1] + 50 && sw5Y[1] - 50 < starY && starY < sw5Y[1] + 50)
			{
				if (sw_status == false)
				{
					setSceneLight(map5, 0.5f);
					hideObject(mj5_2);
					hideObject(eb5_1);
					hideObject(eb5_2);
					hideObject(eb5_3);
					hideObject(eb5_4);
					showObject(sw5_2);
					hideObject(sw5_1);
					showObject(sw5_3);
					hideObject(sw5_4);
					sw_status = true;
					d = 1;
				}
				else if (sw_status == true)
				{
					setSceneLight(map5, 1.0f);
					showObject(mj5_2);
					showObject(eb5_1);
					showObject(eb5_2);
					showObject(eb5_3);
					showObject(eb5_4);
					showObject(sw5_1);
					hideObject(sw5_2);
					showObject(sw5_3);
					hideObject(sw5_4);
					sw_status = false;
					d = 1;
				}
			}
		}	
	}
}

void morejumping()
{
	if (map_status == 3)
	{
		if (mj3X[0] - 60 < starX && starX < mj3X[0] + 50 && mj3Y[0] < starY && starY < mj3Y[0] + 50)
		{
			morejump = true;
		}
		else if (mj3X[1] - 60 < starX && starX < mj3X[1] + 50 && mj3Y[1] < starY && starY < mj3Y[1] + 50)
		{
			morejump = true;
		}
	}
	else if (map_status == 5)
	{
		if (mj5X[0] - 60 < starX && starX < mj5X[0] + 50 && mj5Y[0] < starY && starY < mj5Y[0] + 50)
		{
			morejump = true;
		}
		else if (mj5X[1] - 60 < starX && starX < mj5X[1] + 50 && mj5Y[1] < starY && starY < mj5Y[1] + 50)
		{
			morejump = true;
		}
	}
}

void gameover()
{
	if (map_status == 1)
	{
		starX = stariX[0], starY = stariY[0];
		locateObject(star, map1, starX, starY);
	}
	else if (map_status == 2)
	{
		starX = stariX[1], starY = stariY[1];
		locateObject(star, map2, starX, starY);
	}
	else if (map_status == 3)
	{
		starX = stariX[2], starY = stariY[2];
		locateObject(star, map3, starX, starY);
	}
	else if (map_status == 4)
	{
		starX = stariX[3], starY = stariY[3];
		locateObject(star, map4, starX, starY);
		setSceneLight(map4, 1.0f);
		showObject(sw4_1);
		hideObject(sw4_2);
		sw_status = false;
	}
	else if (map_status == 5)
	{
		starX = stariX[4], starY = stariY[4];
		locateObject(star, map5, starX, starY);
		setSceneLight(map5, 0.5f);
		showObject(sw5_2);
		hideObject(sw5_1);
		showObject(sw5_4);
		hideObject(sw5_3);
		hideObject(mj5_2);
		sw_status = true;
	}
}

void fallen()
{
	if (starY < 0)
	{
		gameover();
		b = 0;
	}
}

void elecbox()
{
	if (map_status == 2)
	{
		if (eb2X[0] - 60 < starX && starX < eb2X[3] + 50 && eb2Y[0] - 30 < starY && starY < eb2Y[3] + 50)
		{
			gameover();
		}
		else if (eb2X[4] - 60 < starX && starX < eb2X[4] + 50 && eb2Y[4] < starY && starY < eb2Y[4] + 50)
		{
			gameover();
		}
		else if (eb2X[5] - 60 < starX && starX < eb2X[5] + 50 && eb2Y[5] - 10 < starY && starY < eb2Y[5] + 50)
		{
			gameover();
		}
		else if (eb2X[6] - 60 < starX && starX < eb2X[6] + 50 && eb2Y[6] - 10 < starY && starY < eb2Y[6] + 50)
		{
			gameover();
		}
		else if (eb2X[7] - 60 < starX && starX < eb2X[7] + 50 && eb2Y[7] - 10 < starY && starY < eb2Y[7] + 50)
		{
			gameover();
		}
	}
	else if (map_status == 3)
	{
		if (eb3X[0] - 60 < starX && starX < eb3X[0] + 50 && eb3Y[0] - 50 < starY && starY < eb3Y[0] + 50)
		{
			gameover();
		}
		else if (eb3X[1] - 60 < starX && starX < eb3X[1] + 50 && eb3Y[1] - 50 < starY && starY < eb3Y[1] + 50)
		{
			gameover();
		}
	}
	else if (map_status == 5)
	{
		if (eb5X[0] - 60 < starX && starX < eb5X[3] + 50 && eb5Y[0] - 50 < starY && starY < eb5Y[3] + 50)
		{
			if (sw_status == false) gameover();
		}
	}
}

void moon_event()
{
	if (map_status == 1)
	{
		if (moonX[0] - 60 < starX && starX < moonX[0] + 50 && moonY[0] - 10 < starY && starY < moonY[0] + 50)
		{
			enterScene(map2);
			map_status = 2;
			starX = stariX[1], starY = stariY[1];
			locateObject(star, map2, starX, starY);
		}
	}
	else if (map_status == 2)
	{
		if (moonX[1] - 60 < starX && starX < moonX[1] + 50 && moonY[1] - 10 < starY && starY < moonY[1] + 50)
		{
			enterScene(map3);
			map_status = 3;
			starX = stariX[2], starY = stariY[2];
			locateObject(star, map3, starX, starY);
			showMessage("초록색 화살표에서는 여러번 점프할 수 있습니다");
		}
	}
	else if (map_status == 3)
	{
		if (moonX[2] - 60 < starX && starX < moonX[2] + 50 && moonY[2] - 20 < starY && starY < moonY[2] + 50)
		{
			enterScene(map4);
			map_status = 4;
			starX = stariX[3], starY = stariY[3];
			locateObject(star, map4, starX, starY);
		}
	}
	else if (map_status == 4)
	{
		if (moonX[3] - 60 < starX && starX < moonX[3] + 50 && moonY[3] - 50 < starY && starY < moonY[3] + 50)
		{
			enterScene(map5);
			map_status = 5;
			starX = stariX[4], starY = stariY[4];
			locateObject(star, map5, starX, starY);
			setSceneLight(map5, 0.5f);
			morejump = false;
		}
	}
	else if (map_status == 5)
	{
		if (moonX[4] - 60 < starX && starX < moonX[4] + 50 && moonY[4] - 50 < starY && starY < moonY[4] + 50)
		{
			setSceneLight(map6, 1.0f);
			enterScene(map6);
			landed = true;
			map_status = 6;
			hideObject(star);
			showMessage("플레이 해주셔서 감사합니다");
		}
	}
}

void land()
{
	if (map_status == 1)
	{
		if (b1X[0] - 60 < starX && starX < b1X[0] + 200 && b1Y[0] < starY && starY < b1Y[0] + 50)
		{
			landed = true;
		}
		else if (b1X[1] - 60 < starX && starX < b1X[1] + 200 && b1Y[1] < starY && starY < b1Y[1] + 50)
		{
			landed = true;
		}
		else if (b1X[2] - 60 < starX && starX < b1X[2] + 200 && b1Y[2] < starY && starY < b1Y[2] + 50)
		{
			landed = true;
		}
		else if (b1X[3] - 60 < starX && starX < b1X[3] + 200 && b1Y[3] < starY && starY < b1Y[3] + 50)
		{
			landed = true;
		}
		else 
		    if (jump == false) landed = false;
	}
	else if (map_status == 2)
	{
		if (b2X[0] - 60 < starX && starX < b2X[0] + 200 && b2Y[0] < starY && starY < b2Y[0] + 50)
		{
			landed = true;
		}
		else if (b2X[1] - 60 < starX && starX < b2X[1] + 200 && b2Y[1] < starY && starY < b2Y[1] + 50)
		{
			landed = true;
		}
		else if (b2X[2] - 60 < starX && starX < b2X[2] + 200 && b2Y[2] < starY && starY < b2Y[2] + 50)
		{
			landed = true;
		}
		else if (b2X[3] - 60 < starX && starX < b2X[3] + 200 && b2Y[3] < starY && starY < b2Y[3] + 50)
		{
			landed = true;
		}
		else if (b2X[4] - 60 < starX && starX < b2X[4] + 200 && b2Y[4] < starY && starY < b2Y[4] + 50)
		{
			landed = true;
		}
		else
			if (jump == false) landed = false;
	}
	else if (map_status == 3)
	{
		if (b3X[0] - 60 < starX && starX < b3X[0] + 200 && b3Y[0] < starY && starY < b3Y[0] + 50)
		{
			landed = true;
		}
		else if (b3X[1] - 60 < starX && starX < b3X[1] + 200 && b3Y[1] < starY && starY < b3Y[1] + 50)
		{
			landed = true;
		}
		else if (b3X[2] - 60 < starX && starX < b3X[2] + 200 && b3Y[2] < starY && starY < b3Y[2] + 50)
		{
			landed = true;
		}
		else
			if (jump == false) landed = false;
	}
	else if (map_status == 4)
	{
		if (b4X[0] - 60 < starX && starX < b4X[0] + 200 && b4Y[0] < starY && starY < b4Y[0] + 50)
		{
			landed = true;
		}
		else if (b4X[1] - 60 < starX && starX < b4X[1] + 200 && b4Y[1] < starY && starY < b4Y[1] + 50)
		{
			landed = true;
		}
		else if (b4X[2] - 60 < starX && starX < b4X[2] + 200 && b4Y[2] < starY && starY < b4Y[2] + 50)
		{
			landed = true;
		}
		else if (b4X[3] - 60 < starX && starX < b4X[3] + 200 && b4Y[3] < starY && starY < b4Y[3] + 50)
		{
			if (sw_status) landed = true;
		}
		else if (b4X[4] - 60 < starX && starX < b4X[4] + 200 && b4Y[4] < starY && starY < b4Y[4] + 50)
		{
			landed = true;
		}
		else
			if (jump == false) landed = false;
	}
	else if (map_status == 5)
	{
		if (b5X[0] - 60 < starX && starX < b5X[0] + 200 && b5Y[0] < starY && starY < b5Y[0] + 50)
		{
			landed = true;
		}
		else if (b5X[1] - 60 < starX && starX < b5X[1] + 200 && b5Y[1] < starY && starY < b5Y[1] + 50)
		{
			landed = true;
		}
		else if (b5X[2] - 60 < starX && starX < b5X[2] + 200 && b5Y[2] < starY && starY < b5Y[2] + 50)
		{
			landed = true;
		}
		else if (b5X[3] - 60 < starX && starX < b5X[3] + 200 && b5Y[3] < starY && starY < b5Y[3] + 50)
		{
			landed = true;
		}
		else
			if (jump == false) landed = false;
	}
}

void gravity()
{
	if (landed == false)
	{
		if (map_status == 1)
		{
			//starY -= 5;
			//locateObject(star, map1, starX, starY);
			starY = starY + b;
			locateObject(star, map1, starX, starY);
			b -= 0.4;
		}
		else if (map_status == 2)
		{
			//starY -= 5;
			//locateObject(star, map2, starX, starY);
			starY = starY + b;
			locateObject(star, map2, starX, starY);
			b -= 0.4;
		}
		else if (map_status == 3)
		{
			//starY -= 5;
			//locateObject(star, map3, starX, starY);
			starY = starY + b;
			locateObject(star, map3, starX, starY);
			b -= 0.4;
		}
		else if (map_status == 4)
		{
			starY = starY + b;
			locateObject(star, map4, starX, starY);
			b -= 0.4;
		}
		else if (map_status == 5)
		{
			starY = starY + b;
			locateObject(star, map5, starX, starY);
			b -= 0.4;
		}
	}
	else b = 0;
}

void timerCallback(TimerID timer)
{
	if (map_status == 1)
	{
		if (r_move && jump == false)
		{
			starX = starX + 4;
			locateObject(star, map1, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (l_move && jump == false)
		{
			starX = starX - 4;
			locateObject(star, map1, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (jump && r_move == false && l_move == false)
		{
			if (landed)
			{
				starY = starY + a;
				locateObject(star, map1, starX, starY);
				setTimer(timer1, 0.01f);
				startTimer(timer1);
				a += 0.4 ;
				if (a > 12)
				{
					jump = false;
					a = 0;
					landed = false;
				}
			}
		}
		else if (r_move && jump)
		{
			starX = starX + 4;
			starY = starY + a;
			locateObject(star, map1, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 0.4;
			if (a > 12)
			{
				jump = false;
				a = 0;
				landed = false;
			}
		}
		else if (l_move && jump)
		{
			starX = starX - 4;
			starY = starY + a;
			locateObject(star, map1, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 0.4;
			if (a > 12)
			{
				jump = false;
				a = 0;
				landed = false;
			}
		}
	}
	else if (map_status == 2)
	{
		if (r_move && jump == false)
		{
			starX = starX + 4;
			locateObject(star, map2, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (l_move && jump == false)
		{
			starX = starX - 4;
			locateObject(star, map2, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (jump && r_move == false && l_move == false)
		{
			if (landed)
			{
				starY = starY + a;
				locateObject(star, map2, starX, starY);
				setTimer(timer1, 0.01f);
				startTimer(timer1);
				a += 0.4;
				if (a > 12)
				{
					jump = false;
					a = 0;
					landed = false;
				}
			}
		}
		else if (r_move && jump)
		{
			starX = starX + 4;
			starY = starY + a;
			locateObject(star, map2, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 0.4;
			if (a > 12)
			{
				jump = false;
				a = 0;
				landed = false;
			}
		}
		else if (l_move && jump)
		{
			starX = starX - 4;
			starY = starY + a;
			locateObject(star, map2, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 0.4;
			if (a > 12)
			{
				jump = false;
				a = 0;
				landed = false;
			}
		}
	}
	else if (map_status == 3)
	{
		if (r_move && jump == false)
		{
			starX = starX + 4;
			locateObject(star, map3, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (l_move && jump == false)
		{
			starX = starX - 4;
			locateObject(star, map3, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (landed)
		{
			if (jump && r_move == false && l_move == false)
			{
				if (landed)
				{
					starY = starY + a;
					locateObject(star, map3, starX, starY);
					setTimer(timer1, 0.01f);
					startTimer(timer1);
					a += 0.4;
					if (a > 12)
					{
						jump = false;
						a = 0;
						landed = false;
					}
				}
			}
			else if (r_move && jump)
			{
				if (landed)
				{
					starX = starX + 4;
					starY = starY + a;
					locateObject(star, map3, starX, starY);
					setTimer(timer1, 0.01f);
					startTimer(timer1);
					a += 0.4;
					if (a > 12)
					{
						jump = false;
						a = 0;
						landed = false;
					}
				}
			}
			else if (l_move && jump)
			{
				if (landed)
				{
					starX = starX - 4;
					starY = starY + a;
					locateObject(star, map3, starX, starY);
					setTimer(timer1, 0.01f);
					startTimer(timer1);
					a += 0.4;
					if (a > 12)
					{
						jump = false;
						a = 0;
						landed = false;
					}
				}
			}
		}
		else if (jump && morejump && r_move == false && l_move == false)
		{
			b = 0;
			starY = starY + a;
			locateObject(star, map3, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 1;
			if (a > 12)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
		else if (jump && morejump && r_move)
		{
			b = 0;
			starX = starX + 4;
			starY = starY + a;
			locateObject(star, map3, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 1;
			if (a > 12)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
		else if (jump && morejump && l_move)
		{
		    b = 0;
			starX = starX - 4;
			starY = starY + a;
			locateObject(star, map3, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 1;
			if (a > 12)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
	}
	else if (map_status == 4)
	{
		if (r_move && jump == false)
		{
			starX = starX + 4;
			locateObject(star, map4, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (l_move && jump == false)
		{
			starX = starX - 4;
			locateObject(star, map4, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (jump && r_move == false && l_move == false)
		{
			if (landed)
			{
				starY = starY + a;
				locateObject(star, map4, starX, starY);
				setTimer(timer1, 0.01f);
				startTimer(timer1);
				a += 0.4;
				if (a > 12)
				{
					jump = false;
					a = 0;
					landed = false;
				}
			}
		}
		else if (r_move && jump)
		{
			starX = starX + 4;
			starY = starY + a;
			locateObject(star, map4, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 0.4;
			if (a > 12)
			{
				jump = false;
				a = 0;
				landed = false;
			}
		}
		else if (l_move && jump)
		{
			starX = starX - 4;
			starY = starY + a;
			locateObject(star, map4, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 0.4;
			if (a > 12)
			{
				jump = false;
				a = 0;
				landed = false;
			}
		}
	}
	else if (map_status == 5)
	{
		if (r_move && jump == false)
		{
			starX = starX + 4;
			locateObject(star, map5, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (l_move && jump == false)
		{
			starX = starX - 4;
			locateObject(star, map5, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
		}
		else if (landed)

		{
			if (jump && r_move == false && l_move == false)
			{
				if (landed)
				{
					starY = starY + a;
					locateObject(star, map5, starX, starY);
					setTimer(timer1, 0.01f);
					startTimer(timer1);
					a += 0.4;
					if (a > 12)
					{
						jump = false;
						a = 0;
						landed = false;
					}
				}
			}
			else if (r_move && jump)
			{
				starX = starX + 4;
				starY = starY + a;
				locateObject(star, map5, starX, starY);
				setTimer(timer1, 0.01f);
				startTimer(timer1);
				a += 0.4;
				if (a > 12)
				{
					jump = false;
					a = 0;
					landed = false;
				}
			}
			else if (l_move && jump)
			{
				starX = starX - 4;
				starY = starY + a;
				locateObject(star, map5, starX, starY);
				setTimer(timer1, 0.01f);
				startTimer(timer1);
				a += 0.4;
				if (a > 12)
				{
					jump = false;
					a = 0;
					landed = false;
				}
			}
		}
		else if (jump && morejump && r_move == false && l_move == false)
		{
			b = 0;
			starY = starY + a;
			locateObject(star, map5, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 1;
			if (a > 12)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
		else if (jump && morejump && r_move)
		{
			b = 0;
			starX = starX + 4;
			starY = starY + a;
			locateObject(star, map5, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 1;
			if (a > 12)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
		else if (jump && morejump && l_move)
		{
			b = 0;
			starX = starX - 4;
			starY = starY + a;
			locateObject(star, map5, starX, starY);
			setTimer(timer1, 0.01f);
			startTimer(timer1);
			a += 1;
			if (a > 12)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
		
	}
	land();
	gravity();
	elecbox();
	if (map_status == 4)
	{
		if (sw4X[0] - 60 > starX || starX > sw4X[0] + 50) c = 0;
		else if (sw4Y[0] - 50 > starY || starY > sw4Y[0] + 50) c = 0;
	}
	if (map_status == 5)
	{
		if (starY < 450)
		{
			if (sw5X[0] - 60 > starX || starX > sw5X[0] + 50) d = 0;
			else if (sw5Y[0] - 50 > starY || starY > sw5Y[0] + 50) d = 0;
		}
		else if (starY > 450)
		{
			if (sw5X[1] - 60 > starX || starX > sw5X[1] + 50) d = 0;
			else if (sw5Y[1] - 50 > starY || starY > sw5Y[1] + 50) d = 0;
		}
	}
	sw_action();
	fallen();
	morejumping();
	moon_event();
	setTimer(timer1, 0.01f);
	startTimer(timer1);
}

void keyboardCallback(KeyCode key, KeyState state)
{
	if (key == KeyCode::KEY_D && state == KeyState::KEY_PRESSED)
	{
		r_move = true;
		timerCallback(timer1);
	}
	else if (key == KeyCode::KEY_D && state == KeyState::KEY_RELEASED)
	{
		r_move = false;
	}
	else if (key == KeyCode::KEY_A && state == KeyState::KEY_PRESSED)
	{
		l_move = true;
		timerCallback(timer1);
	}
	else if (key == KeyCode::KEY_A && state == KeyState::KEY_RELEASED)
	{
		l_move = false;
	}
	else if (key == KeyCode::KEY_W && state == KeyState::KEY_PRESSED)
	{
		jump = true;
	}
	else if (key == KeyCode::KEY_R && state == KeyState::KEY_PRESSED)
	{
		if (map_status == 1)
		{
			starX = stariX[0], starY = stariY[0];
			locateObject(star, map1, starX, starY);
		}
		else if (map_status == 2)
		{
			starX = stariX[1], starY = stariY[1];
			locateObject(star, map2, starX, starY);
		}
		else if (map_status == 3)
		{
			starX = stariX[2], starY = stariY[2];
			locateObject(star, map2, starX, starY);
		}
		else if (map_status == 4)
		{
			starX = stariX[3], starY = stariY[3];
			locateObject(star, map4, starX, starY);
			setSceneLight(map4, 1.0f);
			showObject(sw4_1);
			hideObject(sw4_2);
			sw_status = false;
		}
		else if (map_status == 5)
		{
			starX = stariX[4], starY = stariY[4];
			locateObject(star, map5, starX, starY);
			setSceneLight(map5, 0.5f);
			showObject(sw5_2);
			hideObject(sw5_1);
			showObject(sw5_4);
			hideObject(sw5_3);
			hideObject(mj5_2);
			sw_status = true;
		}
	}
}

int main()
{
	setKeyboardCallback(keyboardCallback);
	setTimerCallback(timerCallback);
	map1 = createScene("1번맵", "white.png");
	b1_1 = createObject("land1.png", map1, b1X[0], b1Y[0], true);
	b1_2 = createObject("land1.png", map1, b1X[1], b1Y[1], true);
	b1_3 = createObject("land1.png", map1, b1X[2], b1Y[2], true);
	b1_4 = createObject("land1.png", map1, b1X[3], b1Y[3], true);
	moon1 = createObject("moon.png", map1, moonX[0], moonY[0], true);
	map2 = createScene("2번맵", "white.png");
	b2_1 = createObject("land1.png", map2, b2X[0], b2Y[0], true);
	b2_2 = createObject("land1.png", map2, b2X[1], b2Y[1], true);
	b2_3 = createObject("land1.png", map2, b2X[2], b2Y[2], true);
	b2_4 = createObject("land1.png", map2, b2X[3], b2Y[3], true);
	b2_5 = createObject("land1.png", map2, b2X[4], b2Y[4], true);
	eb2_1 = createObject("elecbox.png", map2, eb2X[0], eb2Y[0], true);
	eb2_2 = createObject("elecbox.png", map2, eb2X[1], eb2Y[1], true);
	eb2_3 = createObject("elecbox.png", map2, eb2X[2], eb2Y[2], true);
	eb2_4 = createObject("elecbox.png", map2, eb2X[3], eb2Y[3], true);
	eb2_5 = createObject("elecbox.png", map2, eb2X[4], eb2Y[4], true);
	eb2_6 = createObject("elecbox.png", map2, eb2X[5], eb2Y[5], true);
	eb2_7 = createObject("elecbox.png", map2, eb2X[6], eb2Y[6], true);
	eb2_8 = createObject("elecbox.png", map2, eb2X[7], eb2Y[7], true);
	moon2 = createObject("moon.png", map2, moonX[1], moonY[1], true);
	map3 = createScene("3번맵", "white.png");
	b3_1 = createObject("land1.png", map3, b3X[0], b3Y[0], true);
	b3_2 = createObject("land1.png", map3, b3X[1], b3Y[1], true);
	b3_3 = createObject("land1.png", map3, b3X[2], b3Y[2], true);
	eb3_1 = createObject("elecbox.png", map3, eb3X[0], eb3Y[0], true);
	eb3_2 = createObject("elecbox.png", map3, eb3X[1], eb3Y[1], true);
	mj3_1 = createObject("more_jump.png", map3, mj3X[0], mj3Y[0], true);
	mj3_2 = createObject("more_jump.png", map3, mj3X[1], mj3Y[1], true);
	moon3 = createObject("moon.png", map3, moonX[2], moonY[2], true);
	map4 = createScene("4번맵", "white.png");
	b4_1 = createObject("land1.png", map4, b4X[0], b4Y[0], true);
	b4_2 = createObject("land1.png", map4, b4X[1], b4Y[1], true);
	b4_3 = createObject("land1.png", map4, b4X[2], b4Y[2], true);
	b4_4 = createObject("land1.png", map4, b4X[3], b4Y[3], false);
	b4_5 = createObject("land1.png", map4, b4X[4], b4Y[4], true);
	moon4 = createObject("moon.png", map4, moonX[3], moonY[3], true);
	sw4_1 = createObject("switch_closed.png", map4, sw4X[0], sw4Y[0], true);
	sw4_2 = createObject("switch_opened.png", map4, sw4X[1], sw4Y[1], false);
	map5 = createScene("5번맵", "white.png");
	b5_1 = createObject("land1.png", map5, b5X[0], b5Y[0], true);
	b5_2 = createObject("land1.png", map5, b5X[1], b5Y[1], true);
	b5_3 = createObject("land1.png", map5, b5X[2], b5Y[2], true);
	b5_4 = createObject("land1.png", map5, b5X[3], b5Y[3], true);
	eb5_1 = createObject("elecbox.png", map5, eb5X[0], eb5Y[0], false);
	eb5_2 = createObject("elecbox.png", map5, eb5X[1], eb5Y[1], false);
	eb5_3 = createObject("elecbox.png", map5, eb5X[2], eb5Y[2], false);
	eb5_4 = createObject("elecbox.png", map5, eb5X[3], eb5Y[3], false);
	mj5_1 = createObject("more_jump.png", map5, mj5X[0], mj5Y[0], true);
	mj5_2 = createObject("more_jump.png", map5, mj5X[1], mj5Y[1], false);
	sw5_1 = createObject("switch_closed.png", map5, sw5X[0], sw5Y[0], false);
	sw5_2 = createObject("switch_opened.png", map5, sw5X[0], sw5Y[0], true);
	sw5_3 = createObject("switch_closed.png", map5, sw5X[1], sw5Y[1], false);
	sw5_4 = createObject("switch_opened.png", map5, sw5X[1], sw5Y[1], true);
	moon5 = createObject("moon.png", map5, moonX[4], moonY[4], true);
	map6 = createScene("6번맵", "white.png");
	star = createObject("star.png", map1, starX, starY, true);
	timer1 = createTimer(0.01f);
	startTimer(timer1);
	showMessage("a로 왼쪽, d로 오른쪽으로 움직이고 w로 점프합니다.\n다시시작은 r키 입니다");
	startGame(map1);
	return 0;
}