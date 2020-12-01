#ifndef APICALLER
#define APICALLER

#include "HealthPlan.hpp"
#include "APIHandler.hpp"
#include <sstream> 

class APICaller : public APIHandler { 
	private:
	protected:
	public: 
		json CallAPI(HealthPlan* plan) {
			/*
			curl -H "Authorization: Token 4bcc206865aff5431894a6bd1fd5efd69134013d" 
			-H "Accept: application/json; indent=4" 
			-X GET https://wger.de/api/v2/exercise/?language=2
			*/

			std::string API_token = plan->getAPItoken(); 
			std::string API_url = plan->getAPIurl(); 

			try
			{
				// That's all that is needed to do cleanup of used resources (RAII style).
				curlpp::Cleanup myCleanup;

				// Our request to be sent.
				curlpp::Easy myRequest;

				std::list<std::string> header; 
				header.push_back("Authorization: Token " + API_token); 
				header.push_back("Accept: application/json; indent=4"); 
				myRequest.setOpt(curlpp::options::HttpHeader(header)); 

				// Set the URL.
				myRequest.setOpt(curlpp::Options::Url(API_url));

				// Send request and get a result.
				// By default the result goes to standard output.
				//myRequest.perform();


				std::ostringstream os;

				os << myRequest;

				// parsing json
				// this->ExerciseData = json::parse(os.str()); 

				// this->ExerciseData = this->ExerciseData["results"];

				// Should expect a results property
				return json::parse(os.str())["results"];
			}

			catch(curlpp::RuntimeError & e)
			{
				std::cout << e.what() << std::endl;
			}

			catch(curlpp::LogicError & e)
			{
				std::cout << e.what() << std::endl;
			}

			return json(); 

		}
};


#endif // APICALLER