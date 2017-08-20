#include "MainLevel.h"

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
	_river.Reset();
	_playerBoat.Reset();

	PlayerBoat::LoadTexture();
	Torpedo::LoadTexture();
	Fuel::LoadTexture();
	Boat::LoadTexture();

}

void MainLevel::Unload() 
{
	switchTo = -1;

	PlayerBoat::UnloadTexture();
	Torpedo::UnloadTexture();
	Fuel::UnloadTexture();
	Boat::UnloadTexture();



};


void MainLevel::Update(const float& time, const float& dtime)
{
	_time = time;
	_fuel -= FUEL_USAGE*dtime;



	_river.CheckHits(_playerBoat);

	/****DOTANKOWANIA****/
	_fuel += _river.Refuel(_playerBoat);

	/****AKTUALIZACJA WSKAZNIKA PALIWA****/
	if (_fuel > 100) _fuel = 100;
	_fInd.Update(_fuel);

	/****PUNKTY ZA ZESTRZELENIA****/
	_score += _river.GainScore();


	/****AKTUALIZACJA WSKAZNIKA PUNKTOW****/
	_sInd.Update(_score);

	_river.Update(_time);
	/*****SPRAWDZANIE ZAKONCZENIA****/
	if (_river.IsHit() || _fuel < 0 ) switchTo = 1;


}
void MainLevel::Render()
{
	gfx->ClearScreen(0.0f, 0.7f, 0.0f);
	_river.Render();
	_playerBoat.Render();
	_fInd.Render();
	_sInd.Render();
}

void MainLevel::ProcessKey(int& h, int& v, int& s, double dtime)
{
	if (_playerBoat.ProcessKey(h, v, s, dtime))
	{
		_river.InsertTorpedo(_playerBoat.getX(), _playerBoat.getY(), _time);
		_score += -1;
	}
}
