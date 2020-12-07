#ifndef APIHANDLER
#define APIHANDLER

#include "HealthPlan.hpp"

#include <nlohmann/json.hpp>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

using json = nlohmann::json;

class HealthPlan;

class APIHandler { 
	private:
	protected:
	public: 
		virtual json CallAPI(HealthPlan* plan) = 0; 
};


#endif // APIHANDLER