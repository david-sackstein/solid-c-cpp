// Step2_ExtractedParts.cpp

#include <string>
#include <vector>
#include <map>

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
        auto rawData = loadRawData();
        joinData(rawData);

        auto dtos = createDTOs(rawData);

        auto stats = analyzeData(dtos);

        bool errorOccurred = !readConfig("config.ini");

        if (errorOccurred) {
            sendNotification("Error reading config");
        } else {
            sendNotification("Process completed. Average value: " +
				std::to_string(stats.averageValue));
        }
    }

private:
    std::vector<RawDataRow> loadRawData() {
        std::vector<RawDataRow> data;
        data.push_back({1, "Alice", 10.0});
        data.push_back({2, "Bob", 20.0});
        data.push_back({3, "Alice", 30.0});
        return data;
    }

    void joinData(std::vector<RawDataRow>& rawData) {
        std::map<int, std::string> idToCategory = loadIdToCategoryMap();
        for (auto& row : rawData) {
            if (idToCategory.find(row.id) != idToCategory.end()) {
                row.name += "-" + idToCategory[row.id];
            }
        }
    }

    std::map<int, std::string> loadIdToCategoryMap() {
        std::map<int, std::string> map;
        map[1] = "A";
        map[2] = "B";
        map[3] = "A";
        return map;
    }

    std::vector<DTO> createDTOs(const std::vector<RawDataRow>& rawData) {
        std::vector<DTO> dtos;
        for (const auto& row : rawData) {
            dtos.push_back({row.id, row.name, row.value});
        }
        return dtos;
    }

    Stats analyzeData(const std::vector<DTO>& dtos) {
        double sum = 0.0;
        int count = 0;
        for (const auto& dto : dtos) {
            sum += dto.value;
            count++;
        }
        return Stats{(count > 0 ? sum / count : 0.0), count};
    }

    bool readConfig(const std::string& path) {
        return !path.empty();
    }

    void sendNotification(const std::string&) {
        // Not implemented stub
    }
};
