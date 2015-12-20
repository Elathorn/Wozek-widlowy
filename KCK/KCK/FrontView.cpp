#include "FrontView.h"





FrontView::FrontView(TextureManager* TM,RenderWindow & window, Mechanic * mech, int borderXAxis, int borderYAxis) : _window(window)
{
	_actShelf = NULL;
	_mech = mech;
	_borderXAxis = borderXAxis;
	_borderYAxis = borderYAxis;
	_background = new Sprite(*TM->getTexture("shelfFront"));
	_background->setPosition(borderXAxis, 0);
	_background->setScale(0.55, 0.55);
}

FrontView::~FrontView()
{
}

void FrontView::drawAllContent()
{
	_window.draw(*_background);
	_drawMovableObjects();
}

void FrontView::executeEvent(Vector2f & mouse, Event & event)
{

}

void FrontView::_drawMovableObjects()
{
	char levels[3] = { Shelf::TOP_SHELF, Shelf::MID_SHELF, Shelf::BOT_SHELF};

	if (_actShelf == NULL)
		return;

	for (int i = 0; i < 3; i++)
	{
		if (_actShelf->getShelf(levels[i]))
		{
			Sprite * spr = _actShelf->getShelf(levels[i])->getSprite();
			spr->setPosition(50 + 100 * i, 50 + 100 * i);
			if (spr != NULL)
				_window.draw(*spr);
		}
	}

}