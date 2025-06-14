#pragma once
#include <memory>
#include <QString>
class DicomSeries {
public:
    // placeholder for actual data
    int sliceCount = 0;
};

class DicomSeriesLoader {
public:
    static std::shared_ptr<DicomSeries> load(const QString& dir);
};
