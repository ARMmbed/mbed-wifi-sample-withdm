/**
 * @file    MMAccelerometerResource.h
 * @brief   mbed CoAP Endpoint MMAccelerometer sensor resource supporting CoAP GET
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

#ifndef __MM_ACCELEROMETER_RESOURCE_H__
#define __MM_ACCELEROMETER_RESOURCE_H__

// Base class
#include "mbed-connector-interface/DynamicResource.h"

// our Acceleromter sensor
#include "MMA7660.h"
static MMA7660 __accel(PTE25, PTE24);

/** 
 * MMAccelerometerResource class
 */
class MMAccelerometerResource : public DynamicResource
{
public:
    /**
    Default constructor
    @param logger input logger instance for this resource
    @param obj_name input the MMAccelerometer Object name
    @param res_name input the MMAccelerometer Resource name
    @param observable input the resource is Observable (default: FALSE)
    */
    MMAccelerometerResource(const Logger *logger,const char *obj_name,const char *res_name,const bool observable = false) : DynamicResource(logger,obj_name,res_name,"Accelerometer",M2MBase::GET_ALLOWED,observable) {        
        // initialize the accelerometer
        __accel.setSampleRate(64);
        __accel.setActive(true);
    }

    /**
    Get the value of the MMAccelerometer sensor
    @returns string containing the acclerometer sensor value
    */
    virtual string get() {
        char buffer[128] = "";
                            
        // fill the value of the accelerometer
        sprintf(buffer,"{\"accelX\":%3.1f,\"accelY\":%3.1f,\"accelZ\":%3.1f}", __accel.x(), __accel.y(),__accel.z());
        return string(buffer);
    }
};

#endif // __MM_ACCELEROMETER_RESOURCE_H__
