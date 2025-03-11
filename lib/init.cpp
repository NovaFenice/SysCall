#include "init.h"

string version = "1.0";
string link_repo = "https://github.com/NovaFenice/SysCall";

size_t WriteCallback(void*contents, size_t size, size_t nmemb, string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

pair<bool, string> githubCall(const string& current_version) {
    string url = "https://api.github.com/repos/NovaFenice/SysCall/tags";
    string response;
    string latest_version = current_version;

    CURL* curl = curl_easy_init();
    if (!curl) {
        return make_pair(false, string_to_error("Error: Impossible initialize cURL"));
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        return make_pair(false, string_to_error("Error: request HTTP: " + string(curl_easy_strerror(res))));
    }

    if (http_code != 200) {
        return make_pair(false, string_to_error("Error: GitHub API returned status code " + to_string(http_code)));
    }

    if (response.empty()) {
        return make_pair(false, string_to_error("Error: GitHub response body is empty."));
    }

    try {
        json tags = json::parse(response);
        if (!tags.empty() && tags[0].contains("name")) {
            string latest_version = tags[0]["name"];
        } else {
            return make_pair(false, string_to_error("Error: not found name in json of github."));
        }
    } catch (json::exception& e) {
        return make_pair(false, string_to_error("Error parsing JSON: " + string(e.what())));
    }

    if ((double) stod(current_version) < (double) stod(latest_version)) {
        return make_pair(true, setColor(0, 255, 0) + current_version + " -> " + latest_version + resetColor());
    }

    return make_pair(true, current_version);
}

void init_credits() {
    auto version_github = githubCall(version);
    
    if (version_github.first) {
        version = version_github.second;
    } else {
        cout << version_github.second<<endl<<endl<<endl;
    }

    cout << setColor(0, 75, 143) <<"███████╗██╗   ██╗███████╗ ██████╗ █████╗ ██╗     ██╗     "<< resetColor() <<endl;
    cout << setColor(0, 86, 163) <<"██╔════╝╚██╗ ██╔╝██╔════╝██╔════╝██╔══██╗██║     ██║     "<< resetColor() <<endl;
    cout << setColor(0, 97, 184) <<"███████╗ ╚████╔╝ ███████╗██║     ███████║██║     ██║     "<< resetColor() <<endl;
    cout << setColor(0, 110, 207)<<"╚════██║  ╚██╔╝  ╚════██║██║     ██╔══██║██║     ██║     "<< resetColor() <<endl;
    cout << setColor(0, 121, 227)<<"███████║   ██║   ███████║╚██████╗██║  ██║███████╗███████╗"<< resetColor() <<endl;
    cout << setColor(0, 134, 252)<<"╚══════╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝"<< resetColor() <<endl;
    cout << setColor(0, 145, 255)<<"Link repo: "<<link_repo<<resetColor()<<endl;
    cout << setColor(0, 158, 255)<<"Version: "<<version<<resetColor()<<endl;
    cout << setColor(0, 169, 255)<<"Developers: NovaFenice, 0xDomyy"<<resetColor()<<endl;
}