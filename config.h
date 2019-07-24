#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>

class Config {
public:
    ~Config();

	static Config *getInstance();
	
    bool load(std::string path="./config.json");
    void writejsonfile();
    std::string json();
protected:
    template <typename PrettyWriter>
    void serialize(PrettyWriter &writer) const;

public:
    std::string m_path;

    std::string version;
    std::string host_name;
    std::string user;
    std::string password;

	std::string save_path;
	std::string feature1;
    std::string feature2;
    std::string feature3;
    std::string feature4;
    std::string feature5;
	std::string feature6;
	std::string feature7;
	std::string feature8;
    std::string rtmpUrl;
    std::string rtspUrl;
    std::string httpUrl;
    std::string fileUrl;
	float th;
	int width;
	int height;

private:
	Config();

	static Config *instance;
};

#endif
