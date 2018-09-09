/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file stock_exchange.h Definition of stock exchange related functionality */

#ifndef STOCK_EXCHANGE_H
#define STOCK_EXCHANGE_H

#include "stdafx.h"
#include <list>
#include "strings_type.h"

enum ShareOwnerType {
	SHAREOWNER_BEGIN = 0,      ///< Used for iterations
	SHAREOWNER_PUBLIC = 0,     ///< shares owned by the public - these can be bought by players or companies
	SHAREOWNER_PLAYER = 1,     ///< shares owned by a player
	SHAREOWNER_COMPANY = 2,    ///< shares owned by a company
	SHAREOWNER_END,            ///< Used for iterations
	INVALID_SHAREOWNER = 0xFF, ///< flag for invalid share owner type
};

struct ShareOwner {
	ShareOwnerType share_owner_type; ///< the type of share owner
	StringID share_owner_id;         ///< the ID of the share owner - can be a company or president name - only valid for SHAREOWNER_PLAYER and SHAREOWNER_COMPANY
	uint num_shares;               ///< the number of shares owned
};

struct CompanyShares {
	StringID company;
	std::list<ShareOwner> player_share_owners;
};

class StockExchange {
public:
	StockExchange();
	~StockExchange();

	// company actions
	void IssueStock();
	void BuyBackStock();

	// player actions
	void BuyStock();
	void SellStock();
};

static const uint NUM_SHARES_PER_TX = 1000; ///< Number of shares per transaction

#endif //STOCK_EXCHANGE_H
