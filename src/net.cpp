#include "net.h"

#include <cstdlib>

networking::networking(string token)
{
	m_token = token;

}

networking::~networking()
{

}



bool networking::request_token()
{
	string url = "http://" + m_host + "/get_token.php";

	ofHttpResponse resp = ofLoadURL(url);

	ofLogWarning(resp.data);
	m_token = resp.data;

	return true;
}


