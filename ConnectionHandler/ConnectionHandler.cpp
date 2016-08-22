/**
 * @file    ConnectionHandler.cpp
 * @brief   mbed Endpoint ConnectionHandler
 * @author  Doug Anson
 * @version 1.0
 * @see
 *
 * Copyright (c) 2014
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Class
#include "ConnectionHandler.h"

// Forward declarations of public functions in mbedEndpointNetwork
#include "mbed-connector-interface/mbedEndpointNetworkImpl.h"

// Default constructor
ConnectionHandler::ConnectionHandler() : ConnectionStatusInterface() {
}

// Copy constructor
ConnectionHandler::ConnectionHandler(ConnectionHandler &ch) : ConnectionStatusInterface(ch) {
}

// Destructor
ConnectionHandler::~ConnectionHandler() {
}
