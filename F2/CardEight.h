#pragma once
#include "Card.h"
class CardEight :
	public Card
{
	bool AbleToMove[4];
public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	void Convert(int index);

	bool GetStatues(int index);

	virtual ~CardEight(); // A Virtual Destructor

	virtual Card* CopyParameters(CellPosition position);

	virtual void Save(ofstream& OutFile, int type);
};

