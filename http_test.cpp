#include <stdio.h>
#include <iostream>
#include "httplib.h"
using namespace httplib;

void http_callback(const Request& req,Response& resp)
{
		//(void)req;
		//std::string body="<html>linux so easy</html>";
		//resp.set_content(body.c_str(),body.size(),"text/html");
		printf("httplib server recv a req: %s,%s,%s,%s,%s,%s\n ", req.path.c_str(),req.method.c_str(),req.body.c_str(),req.remote_addr.c_str(),req.version.c_str(),req.target.c_str());
		resp.set_content("<html><h1>gxd </h1></html>","text/html");
		
}

int main()
{

		Server svr;
		svr.Get("/api/get_other_equipment_info",http_callback);
		svr.listen("0.0.0.0",8000);
		system("pause");
		return 0;
}
