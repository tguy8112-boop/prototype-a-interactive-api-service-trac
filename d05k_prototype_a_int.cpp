#include <iostream>
#include <string>
#include <map>
#include <vector>

// Configuration Struct for API Service Tracker
struct APIServiceTrackerConfig {
    std::string apiEndpoint;
    int updateInterval; // in seconds
    std::vector<std::string> trackedServices;
    std::map<std::string, std::string> headers;
};

// Interactive API Service Tracker Class
class InteractiveAPIServiceTracker {
private:
    APIServiceTrackerConfig config;
    std::map<std::string, std::string> serviceStatus;

public:
    InteractiveAPIServiceTracker(const APIServiceTrackerConfig& config) : config(config) {}

    void startTracking() {
        std::cout << "Started tracking API services..." << std::endl;
        updateServiceStatus();
    }

    void updateServiceStatus() {
        // Implement API call to update service status
        // For demonstration purposes, just update the status map
        serviceStatus["service1"] = "UP";
        serviceStatus["service2"] = "DOWN";
        serviceStatus["service3"] = "UP";
    }

    void displayServiceStatus() {
        std::cout << "API Service Status:" << std::endl;
        for (const auto& service : serviceStatus) {
            std::cout << service.first << ": " << service.second << std::endl;
        }
    }

    void interact() {
        char input;
        while (true) {
            std::cout << "Enter 'u' to update service status, 'd' to display service status, or 'q' to quit: ";
            std::cin >> input;
            switch (input) {
                case 'u':
                    updateServiceStatus();
                    break;
                case 'd':
                    displayServiceStatus();
                    break;
                case 'q':
                    return;
                default:
                    std::cout << "Invalid input. Try again!" << std::endl;
            }
        }
    }
};

int main() {
    APIServiceTrackerConfig config;
    config.apiEndpoint = "https://api.example.com/services";
    config.updateInterval = 30;
    config.trackedServices.push_back("service1");
    config.trackedServices.push_back("service2");
    config.trackedServices.push_back("service3");
    config.headers["Authorization"] = "Bearer YOUR_API_KEY";

    InteractiveAPIServiceTracker tracker(config);
    tracker.startTracking();
    tracker.interact();

    return 0;
}