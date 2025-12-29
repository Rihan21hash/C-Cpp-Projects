#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    string city;
    string apiKey = "ea9472f28d648a2b36d869715e1d16b0";
    cout << "Enter city name: ";
    getline(cin, city);

    string url = "https://api.openweathermap.org/data/2.5/weather?q=" 
                 + city + "&appid=" + apiKey + "&units=metric";

    CURL* curl;
    CURLcode res;
    string response;

    curl = curl_easy_init();
    if (!curl) {
        cerr << "CURL init failed\n";
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        cerr << "Failed to fetch weather data\n";
        return 1;
    }

    try {
        json data = json::parse(response);

        cout << "\n--- Weather Report ---\n";
        cout << "City: " << data["name"] << endl;
        cout << "Temperature: " << data["main"]["temp"] << " °C\n";
        cout << "Feels Like: " << data["main"]["feels_like"] << " °C\n";
        cout << "Humidity: " << data["main"]["humidity"] << " %\n";
        cout << "Weather: " 
             << data["weather"][0]["description"] << endl;
    }
    catch (...) {
        cerr << "Error parsing JSON response\n";
    }

    return 0;
}
