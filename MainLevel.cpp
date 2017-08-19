#include "MainLevel.h"


float MainLevel::_time;
float MainLevel::_fuel;
int MainLevel::_score;

MainLevel::MainLevel()
{
}


MainLevel::~MainLevel()
{
}

void MainLevel::Load()
{
	_time = 0.;
	_fuel = 100.;
	playerBoat = new PlayerBoat;
	river = new River;
	fInd = new FuelIndicator;
	sInd = new ScoreIndicator;
	Fuel::tex = new Texture(L"fuel.png");
	PlayerBoat::tex = new Texture(L"pBoat.png");
	Torpedo::tex = new Texture(L"Torpedo.png");
	Boat::tex = new Texture(L"Boat.png");
}
void MainLevel::Unload() 
{
	delete playerBoat;
	delete river;
	delete fInd;
	delete sInd;
	switchTo = -1;
};


void MainLevel::Update(double time, double dtime)
{
	_time = time;
	_fuel += -10*dtime;


	river->Update(_time);

	/****DOTANKOWANIA****/
	_fuel += river->Refuel(playerBoat);

	/****AKTUALIZACJA WSKAZNIKA PALIWA****/
	if (_fuel > 100) _fuel = 100;
	fInd->Update(_fuel);

	/****PUNKTY ZA ZESTRZELENIA****/
	_score += river->GainScore();


	/****AKTUALIZACJA WSKAZNIKA PUNKTOW****/
	sInd->Update(_score);


	/*****SPRAWDZANIE ZAKONCZENIA****/
	if (river->IsHit(playerBoat) || _fuel < 0 ) switchTo = 1;
}
void MainLevel::Render()
{
	gfx->ClearScreen(0.0f, 0.7f, 0.0f);
	river->Render();
	playerBoat->Render();
	fInd->Render();
	sInd->Render();
}

void MainLevel::ProcessKey(int& h, int& v, int& s, double dtime)
{
	if (playerBoat->ProcessKey(h, v, s, dtime))
	{
		river->InsertTorpedo(playerBoat->getX(), playerBoat->getY(), _time);
		_score += -1;
	}
}
