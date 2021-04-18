#include<stdio.h>
#include<bangtal.h>

ObjectID star, moon1, moon2, moon3, moon4, moon5, moon6;
ObjectID  b1_1, b1_2, b1_3, b1_4, b2_1, b2_2, b2_3, b2_4, b2_5;
ObjectID eb2_1, eb2_2, eb2_3, eb2_4, eb2_5, eb2_6, eb2_7, eb2_8;
ObjectID b3_1, b3_2, b3_3, mj3_1, mj3_2, eb3_1, eb3_2;
SceneID map1, map2, map3, map4, map5, map6;
TimerID timer1, timer2;
int starX = 101, starY = 151, map_status = 1;
float a = 0, b = 0;
bool l_move = false, r_move = false, jump = false, landed = true, morejump = false;
int stariX[4] = { 101, 151, 201, 0 }, stariY[4] = { 151, 701, 251, 0 }; 
int moonX[3] = { 1190, 350, 1100 }, moonY[3] = { 510, 150, 350 }; 
int b1X[4] = {100, 410, 720, 1030}, b1Y[4] = {100, 220, 340, 460};
int b2X[5] = { 100, 500, 900, 600, 200 }, b2Y[5] = {550, 450, 300, 200, 100};
int eb2X[8] = { 300, 350, 400, 450, 700, 1000, 700, 50 }, eb2Y[8] = {450, 450, 450, 450, 500, 350, 250, 550 };
int b3X[3] = { 100, 500, 1000 }, b3Y[3] = { 200, 440, 300 }, mj3X[2] = { 400, 850 }, mj3Y[2] = { 370, 220 }, eb3X[2] = { 900, 900 }, eb3Y[2] = { 450, 500 };

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown)
{
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown) showObject(object);
	return object;
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
		if (eb2X[0] - 60 < starX && starX < eb2X[3] + 50 && eb2Y[0] < starY && starY < eb2Y[3] + 50)
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
			locateObject(star, map2, starX, starY);
			showMessage("초록색 화살표에서는 여러번 점프할 수 있습니다");
		}
	}
	else if (map_status == 3)
	{
		if (moonX[2] - 60 < starX && starX < moonX[2] + 50 && moonY[2] - 10 < starY && starY < moonY[2] + 50)
		{
			enterScene(map6);
			map_status = 6;
			starX = stariX[3], starY = stariY[3];
			locateObject(star, map3, starX, starY);
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
				if (a > 13)
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
			if (a > 13)
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
			if (a > 13)
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
				if (a > 13)
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
			if (a > 13)
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
			if (a > 13)
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
					if (a > 13)
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
					if (a > 13)
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
					if (a > 13)
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
			if (a > 14)
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
			if (a > 14)
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
			if (a > 14)
			{
				morejump = false;
				jump = false;
				a = 0;
			}
		}
	}
	land();
	gravity();
	moon_event();
	elecbox();
	fallen();
	morejumping();
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
		timerCallback(timer2);
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
	map5 = createScene("5번맵", "white.png");
	map6 = createScene("6번맵", "white.png");
	star = createObject("star.png", map1, starX, starY, true);
	timer1 = createTimer(0.01f);
	startTimer(timer1);
	showMessage("a로 왼쪽, d로 오른쪽으로 움직이고 w로 점프합니다.\n다시시작은 r키 입니다");
	startGame(map1);
	return 0;
}