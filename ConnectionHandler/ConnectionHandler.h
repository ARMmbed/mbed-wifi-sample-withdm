/**
 * @file    ConnectionHandler.h
 * @brief   mbed Endpoint Connection Handler (header)
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
 
 #ifndef __CONNECTION_HANDLER_H__
 #define __CONNECTION_HANDLER_H__
 
 // mbed API
 #include "mbed.h"
 
 // ConnectionStatusInterface 
 #include "mbed-connector-interface/ConnectionStatusInterface.h"
 
 class ConnectionHandler : public Connector::ConnectionStatusInterface {
    public:
        // Default constructor
        ConnectionHandler();
        
        // Copy constructor
        ConnectionHandler(ConnectionHandler &ch);
        
        // Destructor
        virtual ~ConnectionHandler();
 };
 
 #endif // __CONNECTION_HANDLER_H__