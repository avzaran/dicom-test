#include "DicomSeriesLoader.h"
#include <dcmtk/dcmdata/dctk.h>
#include <QDir>

std::shared_ptr<DicomSeries> DicomSeriesLoader::load(const QString& dir) {
    auto series = std::make_shared<DicomSeries>();
    QDir directory(dir);
    auto files = directory.entryList(QStringList() << "*.dcm" << "*.dicom", QDir::Files);
    series->sliceCount = files.size();
    // Here you would read with DCMTK and store pixel data
    return series;
}
