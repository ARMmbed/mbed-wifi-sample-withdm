/**
 * @file    TemperatureResource.h
 * @brief   mbed CoAP Endpoint Temperature sensor resource supporting CoAP GET
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

#ifndef __TEMPERATURE_RESOURCE_H__
#define __TEMPERATURE_RESOURCE_H__

// Base class
#include "mbed-connector-interface/DynamicResource.h"

// our Temperature sensor
#include "LM75B.h"
LM75B __temp_sensor(D14,D15);

/** 
 * TemperatureResource class
 */
class TemperatureResource : public DynamicResource
{
public:
    /**
    Default constructor
    @param logger input logger instance for this resource
    @param obj_name input the Temperature Object name
    @param res_name input the Temperature Resource name
    @param observable input the resource is Observable (default: FALSE)
    */
    TemperatureResource(const Logger *logger,const char *obj_name,const char *res_name,const bool observable = false) : DynamicResource(logger,obj_name,res_name,"Temperature",M2MBase::GET_ALLOWED,observable) {
    }

    /**
    Get the value of the Temperature sensor
    @returns string containing the temperature sensor value
    */
    virtual string get() {
    	char buf[10];
    	sprintf(buf,"%.2f",__temp_sensor.temp());
        return string(buf);
    }
};

#endif // __TEMPERATURE_RESOURCE_H__

