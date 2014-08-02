/*	EQEMu: Everquest Server Emulator
	Copyright (C) 2001-2014 EQEMu Development Team (http://eqemulator.net)

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; version 2 of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY except by those people which sell it, which
	are required to give you total support for your newly bought product;
	without even the implied warranty of MERCHANTABILITY or FITNESS FOR
	A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#ifndef ZONE_REMOTE_CALL_SUBSCRIBE_H
#define ZONE_REMOTE_CALL_SUBSCRIBE_H

#include <map>
#include <string>
#include <vector>

class RemoteCallSubscriptionHandler
{
public:
	~RemoteCallSubscriptionHandler();
	
	static RemoteCallSubscriptionHandler *Instance();
	bool Subscribe(std::string connection_id, std::string event_name);
	bool Unsubscribe(std::string connection_id, std::string event_name);
	const std::vector<std::string> &GetSubscribers(std::string event_name);

	void Process();
	void ClearConnection(std::string connection_id);
	void ClearAllConnections();

private:
	RemoteCallSubscriptionHandler();
	RemoteCallSubscriptionHandler(RemoteCallSubscriptionHandler const&);
	RemoteCallSubscriptionHandler& operator=(RemoteCallSubscriptionHandler const&);
	
	static RemoteCallSubscriptionHandler *_instance;

	std::map<std::string, std::vector<std::string>> registered_events;
	std::map<std::string, int> connection_ids;
};

#endif
