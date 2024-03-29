
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <iostream>
#include "config.h"

using namespace std;
using namespace rapidjson;

Config *Config::instance = 0;

Config *Config::getInstance()
{
	if(!instance)
	{
		instance = new Config();
	}
	return instance;
}

Config::Config()
{
	load();
}

Config::~Config() {
	if(instance)
	{
		delete instance;
		instance = NULL;
	}
}
void Config::writejsonfile()
{
	std::string jsondata;
	long size;
	jsondata = json();
	ofstream file(m_path, ios::out|ios::binary|ios::trunc);
	size = jsondata.size();
	file.write(jsondata.c_str(),size);
	file.close();
	dzlog_debug("+++ config.json writejsonfile() success.");
}
std::string readjsonfile(const char * jsonfile)
{
	std::ifstream fin;
	std::string jsondata = " ";
	fin.open(jsonfile,std::ifstream::in);
	if (!fin.is_open())
	{
		dzlog_error("--- read json file error.");
	}
	std::string line;
	while (getline(fin,line)) {
		jsondata.append(line + "\n");
	}
	return jsondata;
}

bool Config::load(std::string path) {
	
	std::string json;
	json = readjsonfile((char *)path.c_str());
	m_path = path;
	
	Document doc;

	doc.Parse(json.c_str());
	if (doc.IsObject())
	{
		if (doc.HasMember("version"))
		{
			if (doc["version"].IsString())
			{
				version = doc["version"].GetString();
			}
		}
		if (doc.HasMember("host_name"))
		{
			if (doc["host_name"].IsString())
			{
				host_name = doc["host_name"].GetString();
			}
		}
		if (doc.HasMember("user"))
		{
			if (doc["user"].IsString())
			{
				user = doc["user"].GetString();
			}
		}
		if (doc.HasMember("password"))
		{
			if (doc["password"].IsString())
			{
				password = doc["password"].GetString();
			}
		}
		if (doc.HasMember("save_path"))
		{
			if (doc["save_path"].IsString())
			{
				save_path = doc["save_path"].GetString();
			}
		}
		if (doc.HasMember("feature1"))
		{
			if (doc["feature1"].IsString())
			{
				feature1 = doc["feature1"].GetString();
			}
		}
		if (doc.HasMember("feature2"))
		{
			if (doc["feature2"].IsString())
			{
				feature2 = doc["feature2"].GetString();
			}
		}
		if (doc.HasMember("feature3"))
		{
			if (doc["feature3"].IsString())
			{
				feature3 = doc["feature3"].GetString();
			}
		}
		if (doc.HasMember("feature4"))
		{
			if (doc["feature4"].IsString())
			{
				feature4 = doc["feature4"].GetString();
			}
		}	
		if (doc.HasMember("feature5"))
		{
			if (doc["feature5"].IsString())
			{
				feature5 = doc["feature5"].GetString();
			}
		}
		if (doc.HasMember("feature6"))
		{
			if (doc["feature6"].IsString())
			{
				feature6 = doc["feature6"].GetString();
			}
		}
		if (doc.HasMember("feature7"))
		{
			if (doc["feature7"].IsString())
			{
				feature7 = doc["feature7"].GetString();
			}
		}
		
		if (doc.HasMember("feature8"))
		{
			if (doc["feature8"].IsString())
			{
				feature8 = doc["feature8"].GetString();
			}
		}
		if (doc.HasMember("rtmpUrl"))
		{
			if (doc["rtmpUrl"].IsString())
			{
				rtmpUrl = doc["rtmpUrl"].GetString();
			}
		}
		if (doc.HasMember("rtspUrl"))
		{
			if (doc["rtspUrl"].IsString())
			{
				rtspUrl = doc["rtspUrl"].GetString();
			}
		}
		if (doc.HasMember("httpUrl"))
		{
			if (doc["httpUrl"].IsString())
			{
				httpUrl = doc["httpUrl"].GetString();
			}
		}
		if (doc.HasMember("fileUrl"))
		{
			if (doc["fileUrl"].IsString())
			{
				fileUrl = doc["fileUrl"].GetString();
			}
		}
		if (doc.HasMember("th"))
		{
			if (doc["th"].IsFloat())
			{
				th = doc["th"].GetFloat();
			}
		}
		if (doc.HasMember("width"))
		{
			if (doc["width"].IsUint())
			{
				width = doc["width"].GetUint();
			}
		}
		if (doc.HasMember("height"))
		{
			if (doc["height"].IsUint())
			{
				height = doc["height"].GetUint();
			}
		}
	}
	else
	{
		dzlog_error("---There is nonstandard jsondata.");
		
	}
	
	printf("config: %s\n", m_path.c_str());
	printf("version: %s\n", version.c_str());
    printf("host_name: %s\n", host_name.c_str());
    printf("user: %s\n", user.c_str());
    printf("password: %s\n", password.c_str());
    printf("save_path: %s\n", save_path.c_str());
    printf("feature1: %s\n", feature1.c_str());
    printf("feature2: %s\n", feature2.c_str());
    printf("feature3: %s\n", feature3.c_str());
    printf("feature4: %s\n", feature4.c_str());
    printf("feature5: %s\n", feature5.c_str());
	printf("feature6: %s\n", feature6.c_str());
	printf("feature7: %s\n", feature7.c_str());
	printf("feature8: %s\n", feature8.c_str());
	printf("rtmpUrl: %s\n", rtmpUrl.c_str());
	printf("rtspUrl: %s\n", rtspUrl.c_str());
	printf("httpUrl: %s\n", httpUrl.c_str());
	printf("fileUrl: %s\n", fileUrl.c_str());
	printf("th: %f\n", th);
	printf("width: %d\n", width);
	printf("height: %d\n", height);
    return true;
}
template <typename PrettyWriter>

void Config::serialize(PrettyWriter &writer) const {
	writer.StartObject();

	writer.Key("version");
	writer.String(version.c_str());

	writer.Key("host_name");
	writer.String(host_name.c_str());

	writer.Key("user");
	writer.String(user.c_str());

	writer.Key("password");
	writer.String(password.c_str());

	writer.Key("save_path");
	writer.String(save_path.c_str());

	writer.Key("feature1");
	writer.String(feature1.c_str());

	writer.Key("feature2");
	writer.String(feature2.c_str());

	writer.Key("feature3");
	writer.String(feature3.c_str());

	writer.Key("feature4");
	writer.String(feature4.c_str());

	writer.Key("feature5");
	writer.String(feature5.c_str());

	writer.Key("feature6");
	writer.String(feature6.c_str());

	writer.Key("feature7");
	writer.String(feature7.c_str());
	
	writer.Key("feature8");
	writer.String(feature8.c_str());

	writer.Key("rtmpUrl");
	writer.String(rtmpUrl.c_str());

	writer.Key("rtspUrl");
	writer.String(rtspUrl.c_str());

	writer.Key("httpUrl");
	writer.String(httpUrl.c_str());

	writer.Key("fileUrl");
	writer.String(fileUrl.c_str());

	writer.String("th");
	writer.Double(th);

	writer.String("width");
	writer.Uint(width);

	writer.String("height");
	writer.Uint(height);

	writer.EndObject();	
}

std::string Config::json() {
	StringBuffer sb;
	PrettyWriter<StringBuffer> writer(sb);
	serialize(writer);
	return sb.GetString();
}
