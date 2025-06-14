#include "StudyManager.h"
#include "DicomSeriesLoader.h"

StudyManager::StudyManager(QObject* parent) : QObject(parent) {}

std::shared_ptr<DicomSeries> StudyManager::loadSeries(const QString& dir) {
    auto series = DicomSeriesLoader::load(dir);
    if (series) {
        m_series.push_back(series);
    }
    return series;
}

void StudyManager::onSliceChanged(int slice) {
    if (m_block) return;
    m_block = true;
    emit sliceChanged(slice);
    m_block = false;
}

void StudyManager::onZoomChanged(double zoom) {
    if (m_block) return;
    m_block = true;
    emit zoomChanged(zoom);
    m_block = false;
}
