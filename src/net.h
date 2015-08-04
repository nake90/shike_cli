#ifndef NET_H
#define NET_H

#include "ofMain.h"

class networking
{
public:
	networking(string token = "");
	~networking();

	bool request_token(); // Ask the server for a new token
	
	string get_token(){return m_token;} // Token of the current project


private:
	const string m_host = "shike.nakerium.com"; // Host to query

	string m_token; // Unique token
};



#endif // NET_H
