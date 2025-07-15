//#include <inject_logger/StandardCalculator.h>
//#include <inject_logger/BusinessCalculator.h>
//#include <inject_logger/logger/RecordingLogger.h>
//
//#include <gtest/gtest.h>
//
//using namespace inject_logger;
//
//void characteristicTest() {
//    RecordingLogger recLogger;
//
//    StandardCalculator stdCalc(recLogger);
//    BusinessCalculator bizCalc(recLogger);
//
//    stdCalc.calculateAndStore(3, 4); // multiply
//    stdCalc.setMode("engineering");
//
//    bizCalc.calculateAndStore(10, 5); // subtract
//    bizCalc.calculateAndStore(3, 7);  // subtract negative
//
//    // Snapshot output verification
//    const auto& logs = recLogger.getLogs();
//    std::cout << "=== Recorded Output ===" << std::endl;
//    for (const auto& line : logs) {
//        std::cout << line << std::endl;
//    }
//    std::cout << "========================" << std::endl;
//}
//
//TEST(CharacteristicTests, Record) {
//    std::cout << "";
//    characteristicTest();
//}
