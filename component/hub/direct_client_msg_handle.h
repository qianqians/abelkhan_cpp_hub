/*
 * gate_msg_handle.h
 *
 *  Created on: 2020-1-10
 *      Author: qianqians
 */
#ifndef _client_msg_handle_h
#define _client_msg_handle_h

#include <iostream>
#include <string>

#include <Imodule.h>

#include "hub.h"
#include "gatemanager.h"

namespace client_msg{

void client_connect(std::shared_ptr<hub::gatemanager> gates, std::string uuid) {
	gates->client_direct_connect(uuid, juggle::current_ch);
}

void call_hub(std::shared_ptr<hub::hub_service> _hub, std::string uuid, std::string _module, std::string func, Fossilizid::JsonParse::JsonArray argv) {
	hub::current_client_uuid = uuid;
	_hub->modules.process_module_mothed(_module, func, argv);
	hub::current_client_uuid = "";
}

}

#endif //_client_msg_handle_h
