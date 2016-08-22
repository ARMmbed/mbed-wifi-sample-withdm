/**
 * @file    SampleDynamicResource.h
 * @brief   mbed CoAP Endpoint example dynamic resource supporting CoAP GET and PUT, POST, DELETE
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

#ifndef __SAMPLE_DYNAMIC_RESOURCE_H__
#define __SAMPLE_DYNAMIC_RESOURCE_H__

// Base class
#include "mbed-connector-interface/DynamicResource.h"

// We are a simple counter
static int _sample_counter = 0;

/** SampleDynamicResource class
 */
class SampleDynamicResource : public DynamicResource
{

public:
    /**
    Default constructor
    @param logger input logger instance for this resource
    @param obj_name input the sample object name
    @param res_name input the sample resource name
    @param observable input the resource is Observable (default: FALSE)
    */
    SampleDynamicResource(const Logger *logger,const char *obj_name,const char *res_name,const bool observable = false) : DynamicResource(logger,obj_name,res_name,"Counter",M2MBase::GET_PUT_POST_DELETE_ALLOWED,observable) {
    }

    /**
    Get the value of the Sample Resource
    @returns string representing the current value of this resource
    */
    virtual string get() {
        //this->logger()->log("SampleDynamicResource: GET() called");
    	char buf[7];
    	memset(buf,0,7);
    	sprintf(buf,"%d",_sample_counter);
    	++_sample_counter;
        return string(buf);
    }
    
     /**
    Put the value of the Sample Resource
    */
    virtual void put(const string value) {
        //this->logger()->log("SampleDynamicResource: PUT(%s) called",value.c_str());
    	sscanf(value.c_str(),"%d",&_sample_counter );
    }
    
     /**
    Post the value of the Sample Resource
    */
    virtual void post(void *args) {
    	int increment = 0;
    	
    	M2MResource::M2MExecuteParameter* param = (M2MResource::M2MExecuteParameter*)args;
    	if (param != NULL) {
	    	// use parameters
	    	String object_name = param->get_argument_object_name();
	    	//int instance_id = (int)param->get_argument_object_instance_id();
	    	String resource_name = param->get_argument_resource_name();
	    	string value = this->coapDataToString(param->get_argument_value(),param->get_argument_value_length());
	 		//this->logger()->log("SampleDynamicResource:  post(resource: [%s/%d/%s], value: [%s]) called",object_name.c_str(),instance_id,resource_name.c_str(),value.c_str());
	 		
	 		// scan into incrementer
	 		sscanf(value.c_str(),"%d",&increment);
	 	}
	 	else {
	 		//this->logger()->log("SampleDynamicResource: post(NULL) called");
	 		increment = 20;
	 	}
    	_sample_counter += increment;
    }
    
    /**
    Delete the value of the Sample Resource
    */
    virtual void del(void *args) {
        M2MResource::M2MExecuteParameter* param = (M2MResource::M2MExecuteParameter*)args;
    	if (param != NULL) {
	    	// use parameters
	    	String object_name = param->get_argument_object_name();
	    	//int instance_id = (int)param->get_argument_object_instance_id();
	    	String resource_name = param->get_argument_resource_name();
	    	string value = this->coapDataToString(param->get_argument_value(),param->get_argument_value_length());
	 		//this->logger()->log("SampleDynamicResource:  delete(resource: [%s/%d/%s], value: [%s]) called",object_name.c_str(),instance_id,resource_name.c_str(),value.c_str());
	 	}
	 	else {
	 		//this->logger()->log("SampleDynamicResource: delete(NULL) called");
	 	}
    	_sample_counter = 0;
    }
};

#endif // __SAMPLE_DYNAMIC_RESOURCE_H__
