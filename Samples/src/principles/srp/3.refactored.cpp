// Step4_RunProcessHighLevel.cpp

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
        auto dtos = loadData();
        auto stats = analyze(dtos);
        notify(stats);
    }

private:
    // Phase 1: load raw data and enrich it with categories, return DTOs
    std::vector<DTO> loadData() {
        auto rawData = fetchRawDataFromDb();
        auto categories = loadCategoryMapping();
        enrichRawData(rawData, categories);
        return convertToDTOs(rawData);
    }

    // Phase 2: analyze statistics from DTOs
    Stats analyze(const std::vector<DTO>& dtos) {
        if (dtos.empty()) return {0.0, 0};
        double sum = 0.0;
        for (const auto& dto : dtos) sum += dto.value;
        return {sum / dtos.size(), static_cast<int>(dtos.size())};
    }

    // Phase 3: notify based on configuration and stats
    void notify(const Stats& stats) {
        if (!loadConfig("config.ini")) {
            notifyError();
        } else {
            notifySuccess(stats);
        }
    }

    // Low-level details:

    std::vector<RawDataRow> fetchRawDataFromDb() {
        return {
            {1, "Alice", 10.0},
            {2, "Bob", 20.0},
            {3, "Alice", 30.0}
        };
    }

    std::map<int, std::string> loadCategoryMapping() {
        return {{1, "A"}, {2, "B"}, {3, "A"}};
    }

    void enrichRawData(std::vector<RawDataRow>& rawData, const std::map<int, std::string>& categories) {
        for (auto& row : rawData) {
            auto it = categories.find(row.id);
            if (it != categories.end()) {
                row.name += "-" + it->second;
            }
        }
    }

    std::vector<DTO> convertToDTOs(const std::vector<RawDataRow>& rawData) {
        std::vector<DTO> dtos;
        for (const auto& row : rawData) {
            dtos.push_back({row.id, row.name, row.value});
        }
        return dtos;
    }

    bool loadConfig(const std::string& path) {
        return !path.empty();
    }

    void notifyError() {
        sendNotification("Error reading config");
    }

    void notifySuccess(const Stats& stats) {
        sendNotification("Process completed. Average value: " + std::to_string(stats.averageValue));
    }

    void sendNotification(const std::string&) {
        // Not implemented stub
    }
};
