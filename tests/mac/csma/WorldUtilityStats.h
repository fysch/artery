//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __WORLDUTILITYSTATS_H__
#define __WORLDUTILITYSTATS_H__

#include <omnetpp.h>
#include <BaseWorldUtility.h>

/**
 * TODO - Generated class
 */
class WorldUtilityStats : public BaseWorldUtility,
						  public ImNotifiable
{
protected:
	/** @brief BBItem category for Packets*/
	int catPacket;

	/** @brief Stores the number of bits sent */
	long bitsSent;
	/** @brief Stores the number of bits received */
	long bitsReceived;

protected:
    virtual void initialize(int stage);

public:
	virtual void receiveBBItem(int category, const BBItem *details, int scopeModuleId);

	virtual void finish();
};

#endif