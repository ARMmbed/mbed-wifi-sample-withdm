/**
 * @file    LightResource.h
 * @brief   mbed CoAP Endpoint Light resource supporting CoAP GET and PUT
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

#ifndef __LIGHT_RESOURCE_H__
#define __LIGHT_RESOURCE_H__

// Base class
#include "mbed-connector-interface/DynamicResource.h"

// our Light sensor
DigitalOut  __light(LED3);

// possible Light states
#define OFF             "1"
#define ON              "0"

/** LightResource class
 */
class LightResource : public DynamicResource
{

public:
    /**
    Default constructor
    @param logger input logger instance for this resource
    @param obj_name input the Light Object name
    @param res_name input the Light Resource name
    @param observable input the resource is Observable (default: FALSE)
    */
    LightResource(const Logger *logger,const char *obj_name,const char *res_name,const bool observable = false) : DynamicResource(logger,obj_name,res_name,"Light",M2MBase::GET_PUT_ALLOWED,observable) {
    }

    /**
    Get the value of the Light
    @returns string containing either "0" (light off) or "1" (light on)
    */
    virtual string get() {
        string result(OFF);
        if (__light) result = ON;
        return result;
    }

    /**
    Set the value of the Light
    @param string input the string containing "0" (light off) or "1" (light on)
    */
    virtual void put(const string value) {
        if (value.compare(string(OFF)) == 0) __light = 0;
        else __light = 1;
    }
};

#endif // __LIGHT_RESOURCE_H__


