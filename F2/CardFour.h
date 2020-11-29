#pragma once
#include "Card.h"
class CardFour :
	public Card
{
public:
	CardFour(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardFour(); // A Virtual Destructor

	virtual void Save(ofstream& OutFile, int type);

	virtual Card* CopyParameters(CellPosition position);
};

