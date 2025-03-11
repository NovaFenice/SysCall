#ifndef INIT_H
#define INIT_H
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "funcionts.h"
#include "manage_errors.h"
#include <vector>
#include <utility>

using namespace std;
using json = nlohmann::json;

extern string version;
extern string link_repo;

size_t WriteCallback(void*contents, size_t size, size_t nmemb, string* output);

string githubCall();

void init_credits();

#endif