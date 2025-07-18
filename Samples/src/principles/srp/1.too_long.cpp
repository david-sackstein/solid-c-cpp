#include <string>
#include <vector>
#include <map>

// Data structs
struct RawDataRow {
    int id;
    std::string name;
    double value;
};

struct DTO {
    int id;
    std::string name;
    double value;
};

struct Stats {
    double averageValue;
    int count;
};

class Processor {
public:
    void runProcess() {
        // Step 1: Connect to DB
        std::vector<RawDataRow> rawData;
        rawData.push_back({1, "Alice", 10.0});
        rawData.push_back({2, "Bob", 20.0});
        rawData.push_back({3, "Alice", 30.0});

        // Step 2: Join tables (simulate join by map)
        std::map<int, std::string> idToCategory;
        idToCategory[1] = "A";
        idToCategory[2] = "B";
        idToCategory[3] = "A";

        for (auto& row : rawData) {
            if (idToCategory.find(row.id) != idToCategory.end()) {
                row.name += "-" + idToCategory[row.id];
            }
        }

        // Step 3: Create DTOs
        std::vector<DTO> dtos;
        for (const auto& row : rawData) {
            DTO dto;
            dto.id = row.id;
            dto.name = row.name;
            dto.value = row.value;
            dtos.push_back(dto);
        }

        // Step 4: Analyze data - compute stats
        double sum = 0.0;
        int count = 0;
        for (const auto& dto : dtos) {
            sum += dto.value;
            count++;
        }
        Stats stats;
        stats.averageValue = (count > 0) ? (sum / count) : 0.0;
        stats.count = count;

        // Step 5: Read config file
        std::string configPath = "config.ini";
        bool errorOccurred = false;
        if (configPath.empty()) {
            errorOccurred = true;
        }

        // Step 6: Send notification for error or completion
        if (errorOccurred) {
            sendNotification("Error reading config");
        } else {
            sendNotification("Process completed. Average value: " + std::to_string(stats.averageValue));
        }
    }

private:
    void sendNotification(const std::string& msg) {
        // Not implemented stub
    }
};
